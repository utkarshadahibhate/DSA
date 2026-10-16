#include<iostream>
using namespace std;

//Creating DLL with four nodes
/*1)create a head node
    Allocate a node and set head to it. Its prev and next should be null.
  2)create next node and link it to head
    head->next = new Node (value 2)
    head->next->perv = head.
  3)create further nodes the same way
    for third node
    head->next->next = new Node (value 3)
    head->next->next->perv = head->next.
    repeat until required nodes
  4)the last node created must have next==null
*/

class Node{
    public:
    Node *perv;
    int data;
    Node *next;

    //constructor
    Node(int data){
        this->perv = NULL;
        this->data = data;
        this->next = NULL;
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
    head->next->perv = head; //storing object address

    //creating 3rd node next->next to head
    head->next->next = new Node(30);
    head->next->next->perv = head->next; //storing the object address

    //creating 4th node next->next->next to head
    head->next->next->next = new Node(40);
    head->next->next->next->perv = head->next->next;

    head->display(head);

}