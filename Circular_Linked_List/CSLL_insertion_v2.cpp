#include<iostream>
using namespace std;

/*To insert a new node at the end of a circular linked list, first create a new node
and allocate memory for it.
If the list is empty(mean last or tail pointer being NULL), initialise the list
with the new node and making it to point itself to form a circular structure.
If the list already contains nodes then set the new node's next pointer to point
to the current head (which is tail->next), then update current tail's next pointer
to point to the new node.
Finally update the tail pointer to the new node.
*/

/*1)create a new node with the given value.
  2)Check empty list, if last is NULL the initialize the list with the new node and
    make it point to itself.
  3)Otherwise set the new node's next to the head node.
  4)Update the current last's next to point to the head node.
  5)Update the last node to new node.
*/


class Node{
    public:
    int data;
    Node *next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //insert at the beginning
    Node *insert_at_front(Node *head, int data){
        Node *new_node = new Node(data);

        if(head == NULL){
            new_node->next = new_node;
            head = new_node;
            return head;
        }
        else{
            //traverse till the last node
            Node *last_node = head;
            while(last_node->next != head){
                last_node = last_node->next;
            }
            //update the last node pointer
            last_node->next = new_node;
            //update new_node pointer
            new_node->next = head;
            //make/assign new_node as head
            //head = new_node; //the only difference between insertion at front 
            //  and insertion at the end.

            //return updated head
            return head;
        }
    }

    //to display the list
    void display(Node *head){
        if(head == NULL){
            return;
        }

        //take a temp node as head
        Node *temp = head;

        //first jump to the next node and then loop
        cout<<"Circular singly linked list elements are :"<<endl;
        do{
            cout<<temp->data;
            temp = temp->next;
            if(temp != head){
                cout<<" -> ";
            }
        }while(temp != head);
        cout<<endl;
    }
};

int main(){
    Node *head = NULL;
    int num, ele;
    cout<<"Enter the number of elements to be added : ";
    cin>>num;
    for(int i = 1; i <= num; i++){
        cout<<"Enter element "<<i<<" : ";
        cin>>ele;
        head = head->insert_at_front(head, ele);
    }
    head->display(head);
}