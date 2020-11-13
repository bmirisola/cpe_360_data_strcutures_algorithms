#include <iostream>
using namespace std;


class Chunk{
public:
    int value; // amazon would use product recommendations

    Chunk *next;

    Chunk(){
        value = 0;
        next = NULL;
    }
};

class Stack{
public:
    Chunk *top;

    Stack(){
        top = NULL;
    }

    //1. PUSH: add a new element
    void push (int x){
        //add this value: 'x' in the structure
        Chunk *another;
        another = new Chunk;
        another -> value = x;
        //case1: structure is empty: simply make this new value the "top"
        if (top == NULL){
            top = another;
        }

        else{
            another ->next = top;
            top = another;
        }
    }
    //2. POP: remove an element

    void pop (){
        Chunk *another;
        another = top;
        if (top == NULL){
            cout << "The Stack is empty, nothing to delete!" << endl;
            return;
        } else{
            top = top->next;
            cout << "About to delete: " << another ->value << endl;
            delete another;
        }
    }
    //3. DISPLAY: show the contents

    void display(){
        if(top == NULL){
            cout << "Stack empty. Nothing to display";
            return;
        }

        else{
            Chunk *another;
            another = top;

            while(another != NULL){
                cout << another -> value << "------> ";
                another = another->next;
            }

            cout << "NULL" << endl;
        }
    }
};

int main() {
    Stack myStack;

    int choice, value;

    myStack.push(5);
    myStack.push(6);
    myStack.push(3);
    myStack.push(9);
    myStack.push(10);
    myStack.display();

    while(1){
        cout << "Press 1 to add" << endl;
        cout << "Press 2 to pop" << endl;
        cout << "Press 3 to display" << endl;
        cout << "Anything else to quit" << endl;
        cin >> choice;

        switch(choice){
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
                myStack.display();
                cout << "----------------" << endl;
                break;

            default:
                cout << "Exiting" << endl;
                exit(1);
        }
    }
}