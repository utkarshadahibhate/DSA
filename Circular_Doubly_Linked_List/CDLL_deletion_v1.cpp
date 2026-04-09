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

    //to delete at head
    Node *delete_at_head(Node *head){
        //storing head in temp for deletion
        Node *temp = head;

        if(head == NULL){
            cout<<"list is empty"<<endl;
            return NULL;
        }
        
        //update tail's pointer
        head->prev->next = head->next;
        //update head's next node's pointer
        head->next->prev = head->prev;
        //update to new head
        head = head->next;
        //delete the temp head
        delete temp;
        //return updated head
        return head;
    }

    //to display
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

    head = head->delete_at_head(head);
    head->display(head);
}