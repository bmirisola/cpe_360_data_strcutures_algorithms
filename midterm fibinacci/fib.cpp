#include <iostream>
using namespace std;
int getNthTermFibonnaci(int terms) {
    if(terms==1 || terms==0) {
        return(terms);
    }else {
        return(getNthTermFibonnaci(terms-1)+ getNthTermFibonnaci(terms-2));
    }
}

int main() {
    int terms;
    int count;
    cout << "How many terms do you want to print? ";
    cin >> terms;

    if(terms > 0){
        cout << "The Fibonnaci Series is as follows: ";
        while(count < terms) {
            cout << " " << getNthTermFibonnaci(count);
            count++;
        }
    }

    else{
        cout << "You must select a number higher than 0!!!";
    }
    return 0;
}