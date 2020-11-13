#include <iostream>
using namespace std;
#define MAX 10
// ^^^ Macro. Not stored. At runtime any reference to Max gets replaced with value of 10. Does not take any memory.

int main() {
    int var = 10;
    int another = 5;
    int *pal; //friendly kind of variable

    /*
     * pal is a pointer variable
     * pal can only store addresses, and never literal values
     */

    //referencing a pointer
    pal = &var; //now, pal knows the address, and never literal values

    //var = var + 10
    //*pal = differencing a pointer
    *pal = *pal + 10; // pal pays a visit to var and changes the value of the var to 20

    cout << "Value of var after pal paid a visit: " << var << endl;

    cout << "Value of the variable: " << var << endl;
    cout << "Address of this variable> " << &var << endl;
    cout << "Address of this variable> " << &pal << endl;

    //======================================
    //now lets get pal to grab the address of another
    // (meaning pal will forget about var

    pal = &another;
    *pal += 500; //pal is now equal to 505
    cout << "Another is now: " << another << endl;

    if(var > 0){
        int canYouSeeMe = 10;
        cout << "Withing the if block: " << canYouSeeMe << endl;
    }


}