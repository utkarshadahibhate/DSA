#include<iostream>
using namespace std;

//Stack class to create stack
class Stack{
    int *arr;   //dynamic array to store elements
    int capacity;   //to assign maximum size to the stack
    int top;    //index of top element

    public:
    //constructor
    Stack(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        top = -1;    //initializing with -1 (refering empty)
    }

    //Stack operations---------------
    //1)Push operation
    void push(int data){
        if(top == capacity - 1){
            cout<<"Stack overflow.....stack is full!"<<endl;
            return;
        }
        top++;
        arr[top] = data;
        cout<<"element pushed : "<<arr[top]<<endl;
    }

    //2)Pop operation
    int pop(){
        if(top == -1){
            cout<<"Stack underflow......stack is empty!"<<endl;
            return -1;
        }
        cout<<"element to be poped : "<<arr[top]<<endl;
        //--top;
        return arr[--top];
    }

    //3)Top/peak operation
    int peak(){
        if(top == -1){
            cout<<"Stack is empty!"<<endl;
            return -1;
        }
        return arr[top];
    }

    //isEmpty operation
    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }

    //isFull operation
    bool isFull(){
        if(top != -1){
            return true;
        }
        return false;
    }


    //to display elements of the stack
    void display(){
        cout<<"stack elements are : "<<endl;
        for(int i = 0 ; i < capacity ; i++){
            cout<<arr[i]<<" | ";
        }cout<<endl;
    }
};

int main(){
    Stack s1 = Stack(8);
    s1.push(20);
    s1.push(30);
    s1.push(10);
    s1.push(50);
    //s1.display();

    s1.push(90);
    s1.display();

    s1.pop();
    s1.display();

    cout<<"peak element : "<<s1.peak()<<endl;
    //s1.display();
    // if(s1.isEmpty()){
    //     cout<<"Yes stack is empty"<<endl;
    // }
    // cout<<"No stack is not empty"<<endl;

    // if(s1.isFull()){
    //     cout<<"Yes stack is full"<<endl;
    // }
    // cout<<"No stack is not full"<<endl;

}