#include <iostream>

using namespace std;

class Chunk {
public:
    int value;
    Chunk *next;

    Chunk() {
        value = 0;
        next = NULL;
    }
};

class LinkedList {
public:
    Chunk *head;
    int length;

    LinkedList() {
        head = NULL;
        length = 0;
    }

    void insertAtHead(int value) {
        Chunk *another;
        another = new Chunk;
        another->value = value;
        if (head == NULL) {
            head = another;
        } else {
            another->next = head;
            head = another;
        }
        length++;
    }

    void insertAtPosition(int value, int position) {
        if (position > 0 && position <= length + 1) {
            Chunk *temp = new Chunk;
            temp->value = value;
            if (position == 1) {
                temp->next = head;
                head = temp;
            } else if (position > 1 && position <= length) {
                Chunk *helper = head;
                for (int i = 1; i < position - 1; i++) {
                    helper = helper->next;
                    cout << "Helper at: " << helper->value << endl;
                }
                temp->next = helper->next;
                helper->next = temp;

            } else {
                Chunk *helper = head;
                while (helper->next != NULL) {
                    helper = helper->next;
                }
                helper->next = temp;
            }
            length++;
        } else {
            cout << "Can't do that, invalid position" << endl;
        }
    }

    void removeFromPosition(int position) {
        if (position > 0 && position <= length) {
            if (position == 1 && length == 1) {
                delete head;
                head = NULL;
            } else if (position == 1 && length > 1) {
                Chunk *temp = head;
                head = head->next;
                delete temp;
            } else {
                Chunk *temp, *slow;
                temp = slow = head;

                if (position == length) {
                    for (int i = 1; i < position; i++) {
                        slow = temp;
                        temp = temp->next;
                    }

                    slow->next = NULL;
                    delete temp;
                } else {
                    for (int i = 1; i <= position; i++) {
                        slow = temp;
                        temp = temp->next;
                    }
                    slow->next = temp->next;
                    delete temp;
                }

            }
            length--;
        } else {
            cout << "Invalid Position" << endl;
        }
    }

    void reverseLinkedList() {
        Chunk *previous = NULL;
        Chunk *current = head;
        Chunk *next = NULL;

        if (head == NULL) {
            cout << "Linked List empty. Nothing to reverse" << endl;
        } else if (head->next == NULL) {
            cout << "Only one item in linked list. Cannot reverse" << endl;
        } else {
            while (current != NULL) {
                next = current->next;
                current->next = previous;
                previous = current;
                current = next;
            }
            head = previous;

            cout << "Reversed linked list" << endl;
        }
    }

    void removeEveryOtherNode() {
        if (head == NULL) {
            cout << "Linked List empty. Nothing to delete" << endl;
        } else if (head->next == NULL) {
            cout << "Only one item in linked list. Cannot delete alternate numbers if there are none." << endl;
        } else {
            Chunk *previous = head;
            Chunk *another = head->next;
            while (previous != NULL && another != NULL) {
                previous->next = another->next;
                delete (another);
                previous = previous->next;
                length--;
                if (previous != NULL) {
                    another = previous->next;
                }
            }
        }
    }

    void displayContents() {
        if (head == NULL) {
            cout << "Linked List empty. Nothing to display" << endl;
        } else {
            Chunk *another;
            another = head;

            while (another != NULL) {
                cout << another->value << "------> ";
                another = another->next;
            }

            cout << "NULL" << endl;
        }
    }
};

int main() {
    LinkedList ll;
    int value, choice, position;
    while (1) {
        cout << "Press 1 to add at head" << endl;
        cout << "Press 2 to add at position" << endl;
        cout << "Press 3 to remove from a position" << endl;
        cout << "Press 4 to display " << endl;
        cout << "Press 5 to reverse the linked list" << endl;
        cout << "Press 6 to delete every other Chunk" << endl;
        cout << "Press anything else to quit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Add what?" << endl;
                cin >> value;
                ll.insertAtHead(value);
                break;
            case 2:
                cout << "Add what?" << endl;
                cin >> value;
                cout << "At what position?" << endl;
                cin >> position;
                ll.insertAtPosition(value, position);
                break;
            case 3:
                cout << "Remove from what position?" << endl;
                cin >> position;
                ll.removeFromPosition(position);
                break;
            case 4:
                ll.displayContents();
                break;
            case 5:
                ll.reverseLinkedList();
                break;
            case 6:
                ll.removeEveryOtherNode();
                break;
            default:
                cout << "Goodbye" << endl;
                exit(1);
        }
    }
    return 0;
}