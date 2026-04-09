#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    //cnstructor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    //search a key in the list
    bool search_key(Node *head, int key){
        //storing head in temp
        Node *temp = head;

        //if list is empty
        if(head == NULL){
            cout<<"list is empty"<<endl;
            return NULL;
        }

        //traverse the list
        while(temp->next != head){
            temp = temp->next;
            //if key is found
            if(temp->data == key){
                return true;
            }
        }
        return false;
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

    //head->display(head);

    int key = 30;
    bool result = head->search_key(head,key);

    if(result){
        cout<<"Key found : "<<key<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    head->display(head);
}