#include <iostream>

using namespace std;

class AmazonItemsForSale {
public:
    //1.What is the physical look and feel of items of this type?
    //(attributes)
 float price;
    int sellerID;

//2. When we create a new object, what does it look like?
// constructor: special function that "initializes to a default value
public: AmazonItemsForSale() {
    price = 0.0;
    sellerID = 100;
}

private:
//3. What functions are allowed for items of this type
    void Byyyeeee(){
        //implement this function
    }

public:
    void addThisItemToCart(){
        //implement this function
    }
};


int main() {
    int x;
    AmazonItemsForSale item1;

    cout << "Price of the item is: " << item1.price << endl;
    item1.price = 38.5;
    item1.sellerID = 900;
    item1.addThisItemToCart();

    //==================================================
    //Creating variables that have no name
    //These kinds of variables reside in the "Heap": a special zone in the memory
    //==================================================

    //First create a pointer
    AmazonItemsForSale *customer;

    //get a new item from the heap
    customer = new AmazonItemsForSale; //nameless.. just an address

    customer->price = 38.50;
    customer->sellerID = 900;

    //My own thing
    AmazonItemsForSale *customer2;

    customer = new AmazonItemsForSale;

    customer2 -> price = 912.30;
    customer2 -> sellerID = 123;

    cout << "First box in the heap!" <<endl;
    cout << customer-> price << " " << customer->sellerID << endl;
    cout << "Second box in the heap!!!" << endl;
    cout << customer2-> price << " " << customer2->sellerID << endl;

    customer = NULL;
}