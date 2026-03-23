#include<iostream>
using namespace std;

class Array {
    int capacity;
    int lastIndex;
    int *ptr; //for creating dynamic array

public:
    Array();
    Array(int);
    void createArray(int);
    void insertInArray(int, int);
    void deleteFromAnArray(int, int);
    void appendToArray(int, int);
    void display_arr(Array &arr);
};

Array::Array() {
    ptr = NULL;
}

Array::Array(int cap) {
    capacity = cap;
    lastIndex = -1;
    ptr = new int[capacity];
    cout << "Array is Created...\n";
}

void Array::createArray(int cap) {
    if (ptr != NULL) {
        delete[] ptr;
    }
    capacity = cap;
    lastIndex = -1;
    ptr = new int[capacity];
}

void Array::insertInArray(int index, int data) {
    if (index < 0 || index > lastIndex) {
        cout << "Invalid Data\n";
    }
    else if (lastIndex == capacity - 1) {
        cout << "Overflow\n";
    }
    else {
        for (int i = lastIndex; i >= index; i--) {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = data;
        lastIndex++;
        cout << "Element inserted at position "<<index<<" successfully...\n";
    }
}

void Array::deleteFromAnArray(int index, int lastIdx) {
    if (index < 0 || index > lastIdx) {
        cout << "Invalid Data\n";
    }
    else {
        for (int i = index; i < lastIdx; i++) {
            ptr[i] = ptr[i + 1];
        }
        lastIndex--;
        cout << "Element Deleted Successfully..\n";
    }
}

void Array::appendToArray(int data, int cap) {
    if (lastIndex == cap - 1) {
        cout << "Overflow..\n";
    }
    else {
        ptr[lastIndex + 1] = data;
        lastIndex++;
    }
}

void Array::display_arr(Array &arr){
    //cout<<"Printing array elements --"<<endl;
    for(int i=0; i<capacity; i++){
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    Array();
    Array(10);
    Array A1;

    //creating an array
    A1.createArray(10);

    //appending elements in an array
    int i, ele = 10, cap = 8;
    for(int i=0; i<cap; i++){
        A1.appendToArray(ele,cap);
        ele = ele + 10;
    }

    //insering element in an array
    A1.insertInArray(3,80);

    //deleting element from an array
    A1.deleteFromAnArray(3,10);

    //displaying an array
    A1.display_arr(A1);

    return 0;
}


