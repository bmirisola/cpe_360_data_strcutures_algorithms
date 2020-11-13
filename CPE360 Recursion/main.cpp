#include <iostream>
using namespace std;
char s = 'S';
char i = 'I';
char d = 'D';
int numOfTowers;

//number of moves is equal to (2^n) - 1

void towerOfHanoi(int numOfTowers, char s, char i, char d) {
    static int counter = 0; // creates only one instance of the variable the first time hanoi is called

    if (numOfTowers == 1) {
        cout << "Move disc " << numOfTowers << " from " << s << " ------> " << d << endl;
    } else {
        towerOfHanoi(numOfTowers-1, s, d, i); //n-1 from S-->I
        cout << "Step #" << counter << ": "
        << "Move disc " << numOfTowers << " from " << s << " -----> " << d << endl; //n
        towerOfHanoi(numOfTowers-1, i, s, d);
    }

}

    int factorial(int x){
        //anchor value or base case
        if( x == 0){
            return 1;
        }

        else{
            factorial(x-1)*x;
        }
    }

int main() {
    cout << "How many discs?" << endl;
    cin >> numOfTowers;
    towerOfHanoi(numOfTowers,s,i,d);
    return 0;
}