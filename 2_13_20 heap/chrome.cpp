#include <iostream>
using namespace std;
class Chrometab{
public:
    //attributes
    int length;
    int width;
    Chrometab *next;

    //constructor
    Chrometab(){
        length = 100;
        width = 50;
        next = NULL;
    }

    //function: let's not bother just yet
};

int main() {
  Chrometab *first = new Chrometab;

  //length now = 200 in this pointer
  first ->length = 200;
  first ->width = 100;

  //second tab
  first ->next = new Chrometab;

  first ->next->length = 400;
  first -> next-> width = 1200;

  //third tab
  first ->next->next = new Chrometab;
  first -> next ->next->length = 1500;
  first -> next -> next -> width = 1000;

  //let's add a new chunk, such that this is now the FIRST tab
  Chrometab *another;
  another = new Chrometab;

  //lets' get this new (another) tab to point to the current
  another ->next = first;
  first = another;

  //let's add something in the Middle
  another = new Chrometab;
  another ->next = first -> next -> next;
  first -> next -> next = another;

  //delete the last tab
  delete first->next-> next-> next -> next;
  first ->next ->next -> next -> next = NULL;

  another = first ->next ->next;
  first ->next->next = first ->next ->next->next;
  delete another;

  //let's just loop through the structure and print stuff
  another = first;
  while (another != NULL){
      cout << "-----" << endl;
      cout << "Length: " << another ->length << endl;
      cout << "Width: " << another ->width << endl;
      another = another ->next;
  }
}