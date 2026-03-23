#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //deletion at the end
    //deletion at the end operation involves removing the last node of the linked list
    /*1)Check if the list is empty.
      2)If the list has only one node.
      3)Traverse the list to find the second last node.
      4)Update the next pointer to the second last node to NULL.
      5)Delete the last node.
    */

    Node *delete_last(Node *head){
        if(head == NULL){
            cout<<"\nList is empty !\n";
            return NULL;
        }
        if(head->next == NULL){
            cout<<"\nList has only Head node : "<<head->data;
            cout<<"\nDeleting the Head node : "<<head->data;
            delete head;
            return NULL;
        }
        //find the second last node
        Node *secondlast = head;
        while(secondlast->next != NULL){
            secondlast = secondlast->next; //assigning address for next node
        }
        //deleting last node
        cout<<"\nDeleting the last node!\n";
        delete secondlast->next;

        //assigning NULL to second last node
        secondlast->next = NULL;

        return head;
    }

    //displaying the linked list
    void display(Node *head){
        Node *temp = head;
        cout<<"\nLinked-list elements are: "<<endl;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }cout<<endl;
    }
};

int main(){
    //creating an empty list
    //Node *head = NULL;

    //creating a head node only
    // Node *head = new Node(10);
    // head = head->delete_last(head);

    //creating a list
   
    // int i = 0, n = 10;
    // while(i <= n){}

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    head->display(head);
    head = head->delete_last(head);
    head->display(head);
}