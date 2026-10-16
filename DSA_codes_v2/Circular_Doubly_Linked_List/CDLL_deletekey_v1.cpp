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

    //delete the key
    Node *delete_key(Node *head, int key){
        //storing head in temp for deletion
        Node *temp = head;

        //if list is empty
        if(head == NULL){
            cout<<"List is empty"<<endl;
            return NULL;
        }

        //if key is at head node
        if(head->data == key){
            //update the head node pointers
            head->prev->next = head->next;
            head->next->prev = head->prev;
            //update head node
            head = head->next;
            //delete the previous head node
            delete temp;
            //return updated head node
            return head;
        }

        //traverse till the key
        Node *current_node = head;
        Node *previous_node = NULL;
        while(current_node->data != key){
            previous_node = current_node;
            current_node = current_node->next;

            if(current_node == head){
                cout<<"key not found"<<endl;
                return head;
            }
        }
        //after the key is found, delete the node
        //update previous node's pointer
        previous_node->next = current_node->next;
        //update current_node's pointers
        current_node->next->prev = current_node->prev;
        //deleting the current node
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

    head = head->delete_key(head,10);
    head->display(head);
}