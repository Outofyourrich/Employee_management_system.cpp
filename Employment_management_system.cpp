#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string name;
    int id;
    int salary;
    Node* next;
    Node(string name, int id, int salary) {
        this->name = name;
        this->id = id;
        this->salary = salary;
        this->next = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, int id , int salary, string name) {
    Node* newnode = new Node(name, id, salary);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void search_by_id(Node* head, int id) {
    if (head == NULL) {
        cout << "No employees in the list.\n";
        return;
    }
    Node* root = head;
    while (root != NULL) {
        if (root->id == id) {
            cout << "Employee Found → ID: " << root->id 
                 << ", Name: " << root->name 
                 << ", Salary: " << root->salary << endl;
            return; 
        }
        root = root->next;
    }
    cout << "Employee with ID " << id << " not found.\n";
}

void delete_by_id(Node* &head, Node* &tail, int id) {
    if (head == NULL) {
        cout << "No employee in the list.\n";
        return;
    }
    if (head->id == id) {
        Node* tmp = head;
        head = head->next;
        if (tmp == tail) tail = NULL;
        delete tmp;
        return;
    }
    Node* root = head;
    while (root->next != NULL) {
        if (root->next->id == id) {
            Node* deletenode = root->next;
            root->next = root->next->next;
            if (deletenode == tail) tail = root; 
            delete deletenode;
            return;
        }
        root = root->next;
    }
    cout << "Employee ID " << id << " not found.\n";
}

void sort_the_list(Node* &head) {
    for (Node* i = head; i != NULL && i->next != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->id > j->id) {
                swap(i->id, j->id);
                swap(i->name, j->name);
                swap(i->salary, j->salary);
            }
        }
    }
}

void display_the_list(Node* head) {
    if (head == NULL) {
        cout << "No employees to display.\n";
        return;
    }
    Node* tmp = head;
    int num = 1;
    while (tmp) {
        cout << num << ". Name: " << tmp->name 
             << " ID: " << tmp->id 
             << " Salary: " << tmp->salary << endl; 
        tmp = tmp->next;
        num++;
    }
}

int total(Node* head) {
    int total = 0;
    Node* tmp = head;
    while (tmp != NULL) {
        total += tmp->salary;
        tmp = tmp->next;
    }
    return total;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter employee details (id, name, salary). Use -1 as id to stop." << endl;
    int id, salary; 
    string name;
    while (true) {
        cin >> id;
        if (id == -1) break;
        cin.ignore();
        getline(cin, name);
        cin >> salary;
        insert_at_tail(head, tail, id, salary, name);
    }

    cout << "Enter an employee ID to search: " << endl;
    int iid; 
    cin >> iid;
    search_by_id(head, iid);

    cout << "Enter an employee ID to delete: " << endl;
    int idd; 
    cin >> idd;
    delete_by_id(head, tail, idd);

    cout << "Employees (sorted by ID): " << endl;
    sort_the_list(head);  
    display_the_list(head);
    cout << "Total Salary Expense: " << total(head) << endl;

    cout << "Do you want to add more employees? (YES/NO): " << endl;
    string s;
    cin >> s;
    if (s == "YES" || s == "yes") 
    {
        cout << "Enter employee details (id, name, salary). Use -1 as id to stop." << endl;
        int ID, SALARY; 
        string NAME;
        while (true) 
        {
            cin >> ID;
            if (ID == -1) break;
            cin.ignore();
            getline(cin, NAME);
            cin >> SALARY;
            insert_at_tail(head, tail, ID, SALARY, NAME);  
        }

        cout << "\nUpdated list after inserting employees: " << endl;
        sort_the_list(head);
        display_the_list(head);
        cout << "Updated Total Salary Expense: " << total(head) << endl;
    }



    return 0;
}
