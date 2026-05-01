#include<iostream>
using namespace std;

//to create a node with the given data 
class Node{
    public:
    int data;
    Node *next;

    //constructor
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

//to initialise front and rear end
//Also to create funtions for queue operations

class Queue{
    public:
    Node *front, *rear;

    //constructor
    Queue(){
        front = NULL;
        rear = NULL;
    }
};

//function to insert an element
void enqueue(Queue *Q, int data){
    //to create a new node
    Node *new_node = new Node(data);

    //if the queue is empty, assign new_node, 
    //otherwise assign new_node next to rear
    if(Q->front == NULL){ //Q->front, accessing pointer through object, 
        //as the function is out of the class (not a member of class)
        Q->front = new_node; 
    }
    else{
        Q->rear->next = new_node;
    }
    //update rear and new_node's pointer
    Q->rear = new_node; //make new_node as rear end
    Q->rear->next = Q->front;
}

//functon to delete and element
void dequeue(Queue *Q){
    //if the queue is empty
    if(Q->front == NULL){
        cout<<"Queue is empty!(underflow)"<<endl;
    }
    
    //if this is the last node to be deleted
    int num;
    if(Q->front == Q->rear){
        num = Q->front->data;
        delete (Q->front);
        //after deleting re-initialise the front and rear end
        Q->front = NULL;
        Q->rear = NULL;
    }
    else{
        //queue contains more than one node
        Node *temp = Q->front; //store in temp
        num = temp->data;
        Q->front = Q->front->next; //make 2nd node as new front
        Q->rear->next = Q->front; //assign rear next to new front
        delete(temp);
    }
}

//function to return the front value
int front(Queue *Q){
    Node *front = Q->front; //creating a pointer to point to current front

    //if queue is empty
    if(Q->front == NULL){
        return -1;
    }
    return front->data;
}

//function to return the rear value
int rear(Queue *Q){
    Node *rear = Q->rear;

    //if Queue is empty
    if(Q->rear == NULL){
        return -1;
    }
    return rear->data;
}

//function to display queue elements
void display(Queue *Q){
    Node *temp = Q->front;

    do{
        cout<<temp->data<<" ";
        temp = temp->next;
        if(temp != Q->front){
            cout<<" <-> ";
        }
    }while(temp != Q->front);
    cout<<endl;
}

int main(){
    Queue *Q1 = new Queue;

    enqueue(Q1, 10);
    enqueue(Q1, 20);
    enqueue(Q1, 30);
    enqueue(Q1, 40);
    enqueue(Q1, 50);
    enqueue(Q1, 60);

    display(Q1);

}