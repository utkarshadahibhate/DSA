#include<iostream>
using namespace std;

class Queue{
    int *arr; //dynamic array
    int front; //index of front element
    int rear;   //index of rear element
    int capacity;   //maximum capacity
    //static int size;   //current number of elements

    public:
    static int size;   //current number of elements

    //constructor
    Queue(int cap){
        capacity = cap;
        arr = new int[capacity]; //dynamic array
        front = -1;
        rear = -1;
        size = 0;
    }

    //isfull
    bool isfull(int front, int rear){
        if(((front == 0 && rear == capacity - 1))||((front == rear + 1))) {
            return true;
        }
        return false;
    }

    //isempty
    bool isempty(){
        if(front == -1 || rear == -1){
            return true;
        }
        return false;
    }

    //enqueue operation
    void enqueue(int data){
        //to check overflow condition
        if(isfull(front,rear)){
            cout<<"Queue is full (overflow)"<<endl;
            return;
        }
        else{
            //check for front and rear index
            //if front == rear == -1, then set front = rear = 0 for 1st insertion
            //otherwise increment rear index by 1.
            if(front == -1 and rear == -1){
                front = 0;
                rear = 0;
            }
            else{
                rear = (rear + 1) % capacity;
            }
            //after getting the index position assign the element
            arr[rear] = data;
            cout<<"Element inserted in the queue : "<<arr[rear]<<endl;
            size++;
        }
    }

    //dequeue operation
    void dequeue(){
        //to check underflow condition
        if(isempty()){
            cout<<"Queue is empty (overflow)!"<<endl;
            return;
        }
        else{
            //save the element to be deleted
            int num = arr[front];
            //display the element to be deleted
            cout<<"Element deleted from the queue : "<<arr[front]<<endl;
            //after deletion update the indexes
            //if front and rear reaches the end, then reinitialse it by -1
            if(front == rear){
                front = -1;
                rear = -1;
            }
            else{
                //otherwise update the front by incrementing its index by 1
                front = (front + 1) % capacity;
            }
        }
    }

    //to display queue elements
    void display(){
        if(isempty()){
            cout<<"Queue id empty! (underflow)"<<endl;
            return;
        }
        else{
            //if queue is not empty
            //check whether the front <= rear i.e. front does not exceeds rear
            cout<<"Queue elements are : "<<endl;
            if(front <= rear){
                for(int i = front; i <= rear; i++){
                    cout<<arr[i]<<" ";
                }
            }
            else{
                //if rear exceeds the capacity and reaches to initial index
                //in this case front will be greater than rear
                //print from front to capacity then from 0 to rear
                for(int i = front; i < capacity ; i++){
                    cout<<arr[i]<<" ";
                }
                for(int j = 0; j <= rear ; j++){
                    cout<<arr[j]<<" ";
                }
            }cout<<endl;
        }
    }

    //to display front element of the queue
    void front_ele(){
        if(isempty()){
            cout<<"Queue is empty!"<<endl;
        }
        cout<<"Front element is : "<<arr[front]<<endl;
    }
};

int Queue :: size = 0;

int main(){
    Queue Q1(5); //initializing the queue capacity
    Q1.enqueue(20);
    Q1.enqueue(30);
    Q1.enqueue(40);
    Q1.enqueue(50);
    Q1.enqueue(60);
    Q1.enqueue(70);
    Q1.display();
    cout<<"Number of elements in the queue : "<<Queue::size<<endl;
}
