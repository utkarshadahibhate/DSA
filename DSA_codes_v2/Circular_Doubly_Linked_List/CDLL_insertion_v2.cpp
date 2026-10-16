#include<iostream>
using namespace std;

//insertion at the end
/*To insert a new node at the end of doubly circular linked list
  1)Allocate memory for the new node.
  2)if the list is empty, set the new node's next and prev pointer to point to 
    itself, and update the head to this new node.
  3)for a non-empty list, insert the new node:
    -find the current last node (the node whose next pointer points to the head).
    -set the new node's next pointer to point to the head.
    -set the new node's prev pointer to point to current last node.
    -Update the current last node's next pointer to point to new node.
    -Update the head's prev pointer to point to the new node.
*/

class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    //constructor
    Node(int data){
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    //insertion at the end
    Node *insert_at_end(Node *head, int data){
        Node *new_node = new Node(data);

        //if list is empty
        if(head == NULL){
            //update new node's pointers
            new_node->next = new_node;
            new_node->prev = new_node;
            //assign new node as head
            head = new_node;
            //return upated head
            return head;
        }
        else{
            //when list is not empty
            //introduce last node as
            Node *tail = head->prev;

            //insert new node
            //update new node's pointers
            new_node->next = head;
            new_node->prev = tail;
            //update tail node's pointer
            tail->next = new_node;
            //update head node's pointer
            head->prev = new_node;

            //update tail
            //tail = new_node;

            //return updated head
            return head;
        }
    }

    //to display
    void display(Node *head){
        if(head == NULL){
            cout<<"List is empty"<<endl;
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
    head->next = new Node(30);
    head->next->prev = head;

    head->next->next = new Node(50);
    head->next->next->prev = head->next;

    head->next->next->next = head;
    head->prev = head->next->next;

    head = head->insert_at_end(head, 110);
    head = head->insert_at_end(head, 160);
    head->display(head);
}