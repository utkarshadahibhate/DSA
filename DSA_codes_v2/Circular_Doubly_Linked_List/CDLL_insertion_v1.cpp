#include<iostream>
using namespace std;

//insertion at the beginning
/*To insert a new node at the front of the doubly circular linked list
  1)Allocate memory for new node.
  2)if the list is empty, set the new node's next and prev to point to itself,
    and update the head to this new node.
  3)For a non-empty list, insert the new node :
    -set the new node's next to the current head.
    -set the new node's prev to the last node.
    -update the current head's pre to the new node.
    -update the last node's next to the new node.
  4)Set the last node's next to the new node.
*/

class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    //insertion at the beginning
    Node *insert_at_front(Node *head, int data){
        Node *new_node = new Node(data);

        //if list is empty
        if(head == NULL){
            //update new_node's pointers
            new_node->next = new_node;
            new_node->prev = new_node;
            //assign new node as head
            head = new_node;
            //return updated head
            return head;
        }
        else{
            //when list is not empty
            //introduce a last node as
            Node *tail = head->prev;

            //insert new node
            //update new node's pointers
            new_node->next = head;
            new_node->prev = tail;
            //update head node's pointer
            head->prev = new_node;
            //update tail node's pointer
            tail->next = new_node;

            //update new head
            head = new_node;

            //return updated head
            return head;
        }
    }

    //to display list
    void display(Node *head){
        //if list is empty
        if(head == NULL){
            return;
        }

        Node *temp = head;
        do{
            cout<<temp->data;
            temp = temp->next;
            if(temp != head){
                cout<<" <-> ";
            }
        }while(temp != head);
        cout<<endl;
    }
};

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;

    head->next->next = new Node(30);
    head->next->next->prev = head->next;

    head->next->next->next = head;
    head->prev = head->next->next;



    head = head->insert_at_front(head,100);
    head->display(head);

}

