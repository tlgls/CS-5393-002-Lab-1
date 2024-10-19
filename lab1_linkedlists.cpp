#include <iostream>
#include <string>

using namespace std;

class SingleLinkedList {
public:
    SingleLinkedList() : head(nullptr) {} // initializes list with no elements

    ~SingleLinkedList() { // cleans up the dynamically allocated nodes
        Node* current = head;
        while (current) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }

    void insert(char data) { // inserts new character into list
        if (!head) {
            head = new Node(data); // first node
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next; // traverses to end of the list
        }
        temp->next = new Node(data); // appends new node to the end
    }

    void display() const { // displays list
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }

private:
    class Node { // provides structure used for the SingleLinkedList
    public:
        char data; // data stored in node
        Node* next; // pointer to next node
        Node(char val) : data(val), next(nullptr) {} // initializes node
    };

    Node* head; // pointer to the first node in list
};

// double linked list class
class DoubleLinkedList {
public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {} // initializes list

    ~DoubleLinkedList() { // cleans up dynamically allocated nodes
        Node* current = head;
        while (current) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
    void insert(char data) { // inserts new character into list
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode; // initialize head and tail with new node
        } else {
            tail->next = newNode; // appends new node to the end
            newNode->prev = tail; // sets previous pointer of the new node
            tail = newNode; // updates tail pointer
        }
    }

    void displayReverse() const { // displays list in reverse order
        Node* temp = tail;
        while (temp) {
            cout << temp->data;
            temp = temp->prev;
        }
        cout << endl;
    }

private:
    class Node { // node structure used in double linked list
    public:
        char data; // data stored in node
        Node* next; // pointer to next node
        Node* prev; // pointer to the previous node
        Node(char val) : data(val), next(nullptr), prev(nullptr) {} // initializes node
    };

    Node* head; // pointer to first node in list
    Node* tail; // pointer to last node in list
};

// Circular Linked List
class CircularLinkedList {
public:
    CircularLinkedList() : head(nullptr) {} // initializes list

    ~CircularLinkedList() { // cleans up dynamically allocated nodes
        if (!head) return;
        Node* current = head;
        Node* nextNode;
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head); // continues and circle back to head
    }

    void insert(char data) { // insert new character into list
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            head->next = head; // circular reference
        } else {
            Node* temp = head;
            while (temp->next != head) { // traverse to the node before head
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // set circular reference
        }
    }

    void displayTwice() const { // displays list twice
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data;
            temp = temp->next;
        } while (temp != head);
        // print the list again
        temp = head;
        do {
            cout << temp->data;
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

private:
    class Node { // structure in circular linked list
    public:
        char data; // data stored in node
        Node* next; // pointer to next node
        Node(char val) : data(val), next(nullptr) {} // initializes node
    };

    Node* head; // pointer to first node in list
};

// Main function
int main() {
    string input = "I know how to use a linked list now!";

    // single Linked List
    cout << "Single Linked List:" << endl;
    SingleLinkedList singleList;
    for (char c : input) {
        singleList.insert(c);
    }
    singleList.display(); // output the text exactly the same

    // double Linked List
    cout << "Double Linked List (reversed):" << endl;
    DoubleLinkedList doubleList;
    for (char c : input) {
        doubleList.insert(c);
    }
    doubleList.displayReverse(); // outputs the text backwards

    // circular Linked List
    cout << "Circular Linked List (twice):" << endl;
    CircularLinkedList circularList;
    for (char c : input) {
        circularList.insert(c);
    }
    circularList.displayTwice(); // outputs the text twice

    return 0;
}
