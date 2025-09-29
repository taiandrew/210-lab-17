// COMSC 210 | Lab 17 | Sept 29 2025
// IDE used: VS Code

#include <iostream>
using namespace std;

const int SIZE = 7;  

// Linked list node struct
struct Node {
    float value;
    Node *next;
};

// ------
// Fn prototypes
// ------
void output(Node *);
void insertHead(Node *&, float);
void deleteIthNode(Node *&, int);
void insertNode(Node *&, int, float);
void deleteList(Node *&);

// ------
// Main
// ------
int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        insertHead(head, tmp_val);        
    }
    output(head);

    // deleting a node
    Node *current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    deleteIthNode(head, entry);
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    insertNode(head, entry, 10000);


    // deleting the linked list
    deleteList(head);
    output(head);

    return 0;
}

// ------
// Programmer fns
// ------

void insertHead(Node *& head, float val) {
    // adds node at head
    // args: reference to head pointer, value to insert

    Node *newVal = new Node;
    if (!head) { // if this is the first node, it's the new head
        head = newVal;
        newVal->next = nullptr;
        newVal->value = val;
    }
    else { // its a second or subsequent node; place at the head
        newVal->next = head;
        newVal->value = val;
        head = newVal;
    }
}

void deleteIthNode(Node *& head, int entry) {
    // deletes the ith node in the linked list
    // args: reference to head pointer, index of node to delete

    // If entry is 1, delete head
    if (entry == 1) {
        Node *tmp = head;
        head = head->next;
        delete tmp;
        tmp = nullptr;
        return;
    }

    // traverse that many times and delete that node
    Node *current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
}

void insertNode(Node *& head, int entry, float val) {
    // inserts a node with val after the ith node
    // args: reference to head pointer, index of node to insert after, value to insert

    // Traverse to index
    Node *current = head;
    Node *prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = val;
    newnode->next = current;
    prev->next = newnode;
    output(head);
}

void deleteList(Node *& head) {
    // deletes the entire linked list
    // args: reference to head pointer

    Node *current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}