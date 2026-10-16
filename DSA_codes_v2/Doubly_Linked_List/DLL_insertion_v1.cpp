#include<iostream>
using namespace std;

//Insertion at the beginning in DLL
/*1)create a new node with the given data and set its previous pointer to 
    null, new_node->prev = null.
  2)Set the next pointer of the new node to current head
    new_node->next = head.
  3)if the list is not empty, update the previous pointer to current head
    to new node, head->prev = new_node
  4)Return the new_node as the head of the update linked list
*/

class Node{
    public:
    Node *prev;
    int data;
    Node *next;

    //constructor
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    //Inserting element at the beginning
    Node *insert_at_front(Node *head, int data){
        //creating new node (anyhow) (also if the list is empty)
        Node *insert_node = new Node(data);
        //assign address of head
        insert_node->next = head;

        //when head node is not empty
        if(head != NULL){   //means nodes are present
            head->prev = insert_node;
        }
        //return node as the head of the DLL
        return insert_node; //as new_node will be the new head node
    }

    //displaying a DLL in forward direction
    void display(Node *head){
        Node *temp = head;
        cout<<"DLL elements are : "<<endl;
        while(temp != NULL){
            cout<<temp->data;
            if(temp->next != NULL){
                cout<<" "<<"<->"<<" ";
            }
            temp = temp->next;
        }cout<<endl;
    }
};

int main(){
    //creating a head node
    Node *head = new Node(10);

    //creating 2nd node next to head
    head->next = new Node(20);
    head->next->prev = head; //storing object address

    //creating 3rd node next->next to head
    head->next->next = new Node(30);
    head->next->next->prev = head->next; //storing the object address

    //creating 4th node next->next->next to head
    head->next->next->next = new Node(40);
    head->next->next->next->prev = head->next->next;

    //Node *head = NULL;

    head->display(head);

    //inserting at the beginning
    head = head->insert_at_front(head, 70);
    head->display(head);

}
