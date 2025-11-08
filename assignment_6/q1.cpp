#include <iostream>
using namespace std;

/*-----------------------------
   DOUBLY LINKED LIST SECTION
-----------------------------*/
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList() { head = nullptr; }

    // Insert at beginning
    void insertAtBeginning(int val) {
        DNode* newNode = new DNode{val, nullptr, head};
        if (head) head->prev = newNode;
        head = newNode;
        cout << "Inserted " << val << " at beginning.\n";
    }

    // Insert at end
    void insertAtEnd(int val) {
        DNode* newNode = new DNode{val, nullptr, nullptr};
        if (!head) {
            head = newNode;
        } else {
            DNode* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Inserted " << val << " at end.\n";
    }

    // Insert after a specific node
    void insertAfter(int key, int val) {
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found!\n";
            return;
        }
        DNode* newNode = new DNode{val, temp, temp->next};
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
        cout << "Inserted " << val << " after " << key << ".\n";
    }

    // Insert before a specific node
    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found!\n";
            return;
        }
        DNode* newNode = new DNode{val, temp->prev, temp};
        temp->prev->next = newNode;
        temp->prev = newNode;
        cout << "Inserted " << val << " before " << key << ".\n";
    }

    // Delete specific node
    void deleteNode(int key) {
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found!\n";
            return;
        }
        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
        cout << "Deleted node " << key << ".\n";
    }

    // Search node
    void searchNode(int key) {
        DNode* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found!\n";
    }

    // Display list
    void display() {
        cout << "Doubly Linked List: ";
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

/*-----------------------------
   CIRCULAR LINKED LIST SECTION
-----------------------------*/
struct CNode {
    int data;
    CNode* next;
};

class CircularLinkedList {
    CNode* last;
public:
    CircularLinkedList() { last = nullptr; }

    // Insert at beginning
    void insertAtBeginning(int val) {
        CNode* newNode = new CNode{val, nullptr};
        if (!last) {
            newNode->next = newNode;
            last = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
        cout << "Inserted " << val << " at beginning.\n";
    }

    // Insert at end
    void insertAtEnd(int val) {
        CNode* newNode = new CNode{val, nullptr};
        if (!last) {
            newNode->next = newNode;
            last = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
        cout << "Inserted " << val << " at end.\n";
    }

    // Insert after specific node
    void insertAfter(int key, int val) {
        if (!last) return;
        CNode* temp = last->next;
        do {
            if (temp->data == key) {
                CNode* newNode = new CNode{val, temp->next};
                temp->next = newNode;
                if (temp == last) last = newNode;
                cout << "Inserted " << val << " after " << key << ".\n";
                return;
            }
            temp = temp->next;
        } while (temp != last->next);
        cout << "Node " << key << " not found!\n";
    }

    // Delete specific node
    void deleteNode(int key) {
        if (!last) {
            cout << "List is empty!\n";
            return;
        }

        CNode *curr = last->next, *prev = last;
        do {
            if (curr->data == key) {
                if (curr == last && curr->next == last) {
                    last = nullptr;
                } else {
                    if (curr == last->next) last->next = curr->next;
                    if (curr == last) last = prev;
                    prev->next = curr->next;
                }
                delete curr;
                cout << "Deleted node " << key << ".\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);

        cout << "Node " << key << " not found!\n";
    }

    // Search node
    void searchNode(int key) {
        if (!last) {
            cout << "List is empty!\n";
            return;
        }
        CNode* temp = last->next;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != last->next);
        cout << "Node " << key << " not found!\n";
    }

    // Display list
    void display() {
        if (!last) {
            cout << "List is empty!\n";
            return;
        }
        CNode* temp = last->next;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << "\n";
    }
};

/*-----------------------------
   MAIN MENU
-----------------------------*/
int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, type;

    while (true) {
        cout << "\n------ MENU ------\n";
        cout << "1. Doubly Linked List Operations\n";
        cout << "2. Circular Linked List Operations\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> type;

        if (type == 3) break;

        if (type == 1) {
            cout << "\n--- DOUBLY LINKED LIST ---\n";
            cout << "1. Insert at beginning\n2. Insert at end\n3. Insert after node\n4. Insert before node\n";
            cout << "5. Delete node\n6. Search node\n7. Display\n8. Back\nEnter choice: ";
            cin >> choice;
            int val, key;

            switch (choice) {
                case 1: cout << "Enter value: "; cin >> val; dll.insertAtBeginning(val); break;
                case 2: cout << "Enter value: "; cin >> val; dll.insertAtEnd(val); break;
                case 3: cout << "After which node? "; cin >> key; cout << "Enter value: "; cin >> val; dll.insertAfter(key, val); break;
                case 4: cout << "Before which node? "; cin >> key; cout << "Enter value: "; cin >> val; dll.insertBefore(key, val); break;
                case 5: cout << "Enter node value to delete: "; cin >> key; dll.deleteNode(key); break;
                case 6: cout << "Enter value to search: "; cin >> key; dll.searchNode(key); break;
                case 7: dll.display(); break;
                default: break;
            }
        }

        else if (type == 2) {
            cout << "\n--- CIRCULAR LINKED LIST ---\n";
            cout << "1. Insert at beginning\n2. Insert at end\n3. Insert after node\n4. Delete node\n";
            cout << "5. Search node\n6. Display\n7. Back\nEnter choice: ";
            cin >> choice;
            int val, key;

            switch (choice) {
                case 1: cout << "Enter value: "; cin >> val; cll.insertAtBeginning(val); break;
                case 2: cout << "Enter value: "; cin >> val; cll.insertAtEnd(val); break;
                case 3: cout << "After which node? "; cin >> key; cout << "Enter value: "; cin >> val; cll.insertAfter(key, val); break;
                case 4: cout << "Enter node value to delete: "; cin >> key; cll.deleteNode(key); break;
                case 5: cout << "Enter value to search: "; cin >> key; cll.searchNode(key); break;
                case 6: cll.display(); break;
                default: break;
            }
        }
    }

    cout << "Exiting program...\n";
    return 0;
}
