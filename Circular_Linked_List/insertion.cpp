#include<iostream>
using namespace std;

//Insertion and deletion operations without head
class Node{
    public:
    int data;
    Node *next;

    //constructor
    Node(int data);

    //insertion operation
    Node *insert_at_head(Node *tail, int data);
    Node *insert_at_tail(Node *tail, int data);
    Node *insert_at_pos(Node *tail, int pos, int data);

    //to display the list
    void display(Node *tail);

};

Node::Node(int data){
        this->data = data;
        this->next = NULL;
    }

Node* Node :: insert_at_head(Node *tail, int data){
        //first create a new node
        Node *new_node = new Node(data);

        //if head or tail is null i.e. list is empty
        if(tail == NULL){
            new_node->next = new_node;
            return new_node;
        }
        else{
            //new_node's next would be tail's previously stored next
            //update new_node's next
            new_node->next = tail->next;
            //update tail's next;
            tail->next = new_node;

            //return the updated tail
            return tail;
        }
    }

Node* Node :: insert_at_tail(Node *tail, int data){
        //create a new node
        Node *new_node = new Node(data);

        //if the head or tail is empty i.e. list is empty
        if(tail == NULL){
            //initialise a new node
            tail = new_node;
            //update new node's pointer
            new_node->next = new_node;
        }
        else{
            //insert the new node after the current tail
            //and update the tail pointer
            //new node points to the head node

            //first assign the pointer of new node to previous tail's next
            new_node->next = tail->next; //this tail is currently pointing to head
            
            //update tail's pointer
            tail->next = new_node;

            //now the new tail is new node
            tail = new_node;
        }
        return tail;
    }

//insertion at specific position
Node* Node :: insert_at_pos(Node *tail, int pos, int data){
        //first create a node
        //Node *new_node = new Node(data);

        //if head or tail is null i.e. empty list
        if(tail == NULL){
            Node *new_node = new Node(data);
            tail = new_node; //assigning neww node
            tail->next = tail; //pointing to itself

            //return updated tail
            return tail;
        }

        Node *new_node = new Node(data);
        //for traversing
        //current will point to head initially
        Node *current_node = tail->next;

        //insert at the head
        if(pos == 1){
            //assign new node's next to current node i.e. head
            new_node->next = current_node;
            //update tail's pointer
            tail->next = new_node;
            //return updated tail
            return tail;
        }

        //For any specific position 
        for(int i = 1; i < pos - 1; i++){
            current_node = current_node->next; //terminate one before the pos
            
            //after receiving the current node
            //if position is out of bounds
            if(current_node == tail->next){ //i.e head == head
                //i.e current_node == termination point i.e head
                cout<<"Invalid position!"<<endl;
                return tail;
            }
            //if the above termination condition fails then only current_node
            //will return out of the code section, use that for inserting node
        }
        //insert the new node at the desired position
        //update new node's pointer
        new_node->next = current_node->next;
        //update current node's pointer
        current_node->next = new_node;

        //update the tail node if the new node is inserted at the end
        //Note: no need for pointer update for below if condition as it is already
        //      done above, just assign the new node as tail.
        if(current_node == tail){
            tail = new_node;
            return tail;
        }
        return tail;
    }


void Node :: display(Node *tail){
        if(tail == NULL){
            return;
        }

        //take a temp node as head
        Node *temp = tail->next;

        //first jump to the next node and then loop
        cout<<"Circular singly linked list elements are :"<<endl;
        do{
            cout<<temp->data;
            temp = temp->next;
            if(temp != tail->next){
                cout<<" -> ";
            }
        }while(temp != tail->next);
        cout<<endl;
    }

int main(){
    // //create circular linked list
    // Node *head = new Node(10);
    // head->next = new Node(20);
    // head->next->next = new Node(30);

    // Node *tail = head->next->next;
    // tail->next = head;
    // tail->display(tail);

    // tail = tail->insert_at_head(tail,90); //save the updated head
    // tail->display(tail);

    // tail = tail->insert_at_tail(tail,100);
    // tail->display(tail);

    // tail = tail->insert_at_pos(tail,2,80);
    // tail->display(tail);

    // tail = tail->insert_at_pos(tail,10,50);
    // tail->display(tail);

    // tail = tail->insert_at_pos(tail,5,120);
    // tail->display(tail);

    Node *tail_2 = NULL;
    tail_2 = tail_2->insert_at_pos(tail_2,1,10);
    tail_2->display(tail_2);

    tail_2 = tail_2->insert_at_pos(tail_2,2,30);
    tail_2->display(tail_2);

    tail_2 = tail_2->insert_at_pos(tail_2,3,60);
    tail_2->display(tail_2);
}