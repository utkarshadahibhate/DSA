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

    //deletion at the begining
    //deletion at the begining operation involves removing the first node of the linked list
    /*1)check if the list is empty
      2)Update the head pointer to the second node
      3)Delete the original head */

    Node *delete_node(Node *head){
        if(head == NULL){
            return NULL;
        }

        //store the current head to temporary variable
        //and then update the current head to second node
        Node *temp = head;
        head = head->next;

        //free the memory of the temp node
        delete temp;

        return head;
    }

    //displaying the linked list
    void display(Node *head){
        Node *temp = head;
        cout<<"Linked-list elements are: "<<endl;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }cout<<endl;
    }
};

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->display(head);

    //deletion at begining
    cout<<"Linked list after deleting the head node :"<<endl;
    head = head->delete_node(head);
    head->display(head);
}