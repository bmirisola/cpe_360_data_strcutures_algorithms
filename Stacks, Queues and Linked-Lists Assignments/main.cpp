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

class Stack {
public:
    Chunk *head;

    Stack() {
        head = NULL;
    }

    void push(int value) {
        Chunk *another;
        another = new Chunk;
        another->value = value;
        if (head == NULL) {
            head = another;
        } else {
            another->next = head;
            head = another;
        }
    }

    void pop() {
        Chunk *another;
        another = head;
        if (head == NULL) {
            cout << "The Stack is empty. There is nothing to delete" << endl;
        } else {
            head = head->next;
            cout << another->value << " will be deleted" << endl;
            delete another;
        }
    }

    void displayContents() {
        if (head == NULL) {
            cout << "Stack empty. Nothing to display";
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

class Queue {
public:
    Chunk *head;
    Chunk *tail;

    Queue() {
        head = NULL;
        tail = NULL;
    }

    void enqueue(int value) {
        Chunk *temp = new Chunk();
        temp->value = value;
        if (tail == NULL) {
            tail = temp;
            head = temp;
        } else {
            temp->next = tail;
            tail = temp;
        }
    }

    void dequeue() {
        if (tail == NULL) {
            cout << "Empty Que. Nothing to delete. Please leave" << endl;
        } else if (tail->next == NULL) {
            cout << "Deleting: " << tail->value << endl;
            delete tail;
            tail = NULL;
        } else {
            Chunk *temp = tail;
            while (temp->next != head) {
                temp = temp->next;
            }
            head = temp;
            temp = temp->next;
            cout << "Deleting: " << temp->value << endl;
            head->next = NULL;
            delete temp;
        }
    }

    void printContents() {

        if (tail == NULL) {
            cout << "Empty Q, nothing to display" << endl;
        } else {
            Chunk *temp;
            temp = tail;
            while (temp != NULL) {
                cout << temp->value << "--->";
                temp = temp->next;
            }
            cout << "NULL" << endl;
            cout << "----------------------------" << endl;
        }
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
            }

            else {
                Chunk *temp, *slow;
                temp = slow = head;

                if(position == length){
                    for (int i = 1; i < position; i++) {
                        slow = temp;
                        temp = temp->next;
                    }

                    slow->next = NULL;
                    delete temp;
                }
                else{
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
    Stack myStack;
    Queue q;
    int value, choice, position, dataStructureChoice;

    cout << "What data Structure do you want to play with?" << endl;
    cout << "Press 1 to create a stack" << endl;
    cout << "Press 2 to create a queue" << endl;
    cout << "Press 3 to create a Linked List" << endl;
    cout << "Press anything else to quit" << endl;
    cin >> dataStructureChoice;

    if (dataStructureChoice == 1) {
        while (1) {
            cout << "Press 1 to add" << endl;
            cout << "Press 2 to pop" << endl;
            cout << "Press 3 to display contents" << endl;
            cout << "Anything else to quit" << endl;
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Add what?" << endl;
                    cin >> value;
                    myStack.push(value);
                    break;

                case 2:
                    myStack.pop();
                    break;

                case 3:
                    cout << "----------------" << endl;
                    myStack.displayContents();
                    cout << "----------------" << endl;
                    break;

                default:
                    cout << "Exiting" << endl;
                    exit(1);
            }
        }
    } else if (dataStructureChoice == 2) {
        while (1) {
            cout << "Press 1 to enqueue" << endl;
            cout << "Press 2 to dequeue" << endl;
            cout << "Press 3 to print Contents" << endl;
            cout << "Anything else to quit" << endl;
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Add what?" << endl;
                    cin >> value;
                    q.enqueue(value);
                    break;

                case 2:
                    q.dequeue();
                    break;

                case 3:
                    cout << "----------------" << endl;
                    q.printContents();
                    cout << "----------------" << endl;
                    break;

                default:
                    cout << "Exiting" << endl;
                    exit(1);
            }
        }
    } else if (dataStructureChoice == 3) {
        while (1) {
            cout << "Press 1 to add at head" << endl;
            cout << "Press 2 to add at position" << endl;
            cout << "Press 3 to remove from a position" << endl;
            cout << "Press 4 to display " << endl;
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
                default:
                    cout << "Goodbye" << endl;
                    exit(1);
            }
        }
    } else {
        cout << "Ba-bye!" << endl;
    }
}