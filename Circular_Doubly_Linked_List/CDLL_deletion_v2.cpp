#include<iostream>
using namespace std;

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

    //delete at the tail
    Node *delete_at_tail(Node *head){
        //storing head in temp for deletion
        Node *temp = head;

        //if list is empty
        if(head == NULL){
            cout<<"list is empty"<<endl;
            return NULL;
        }

        //traverse till the last node
        Node *last_node = head;
        while(last_node->next != head){
            last_node = last_node->next;
        }
        //after reaching the last node
        //update the last_node's previous node's pointer
        last_node->prev->next = last_node->next;
        last_node->next->prev = last_node->prev;
        //delete the last_node
        delete last_node;
        //return the updated head
        return head;
    }

    //to display list
    void display(Node *head){
        Node *temp = head;

        if(head == NULL){
            cout<<"List is empty"<<endl;
            return;
        }

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

    head->display(head);

    head = head->delete_at_tail(head);
    head->display(head);
}