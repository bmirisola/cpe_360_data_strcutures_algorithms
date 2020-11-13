#include <iostream>

using namespace std;

//chunk
class Chunk {
public:
    int value;
    Chunk *next;

    Chunk() {
        value = 0;
        next = NULL;
    }
};

//Que of "chunks"
class Queue {
public:
    Chunk *head;

    Queue() {
        head = NULL;
    }

    //1. Add chunks to the Q (enqueue)
    void enqueue(int x) {
        Chunk *temp = new Chunk();
        temp->value = x;
        if (head == NULL) {
            head = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }

    //2. Remove a chunk from the Q (dequeue)
    //remove from the end: find out the last chunk and get rid of it
    void dequeue() {
        if (head == NULL) {
            cout << "Empty Que. Nothing to delete. Please leave" << endl;
        } else if (head->next == NULL) {
            //only one chunk! Super easy: delete it, and set head to NULL
            cout << "Deleting: " << head->value << endl;
            delete head;
            head = NULL;
        } else {
            Chunk *chase, *follow;
            chase = follow = head;
            while (chase->next != NULL) {
                follow = chase;
                chase = chase->next;
            }
            follow->next = NULL;
            cout << "Deleting: " << chase->value << endl;
            delete chase;
        }

    }

    //3. Display the contents of the Q
    void displayContents() {

        if (head == NULL) {
            cout << "Empty Q, nothing to display" << endl;
        } else {
            Chunk *temp;
            temp = head;
            while (temp != NULL) {
                cout << temp->value << "--->";
                temp = temp->next;
            }
            cout << "NULL" << endl;
            cout << "----------------------------" << endl;
        }
    }

};

int main() {

}