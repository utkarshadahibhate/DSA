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

    //to delete at a specific position
    Node *delete_at_pos(Node *head, int pos){
        //storing head in temp for deletion
        Node *temp = head;

        //if list is empty
        if(head == NULL){
            cout<<"List is empty"<<endl;
            return NULL;
        }

        if(pos == 1){
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
            delete temp;
            return head;
        }

        //traverse to the position
        Node *current_node = head;
        Node *previous_node = NULL;
        for(int i = 1; i < pos; i++){
            previous_node = current_node; //will have pos-1 node
            current_node = current_node->next; //will terminate at pos node
        }
        //after reaching the pos node
        //update the previous node's pointer
        previous_node->next = current_node->next;
        //update current node's next node's pointer
        current_node->next->prev = current_node->prev;
        //deleting current node
        delete current_node;
        //return updated head
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

    head = head->delete_at_pos(head,3);
    head->display(head);
}