#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //deletion at head
    Node *delete_at_head(Node *tail){
        //if list is empty
        if(tail == NULL){
            cout<<"List is empty"<<endl;
            return NULL;
        }

        //if only one node is present
        Node *head = tail->next;
        if(head == tail){
            cout<<"only one node present"<<endl;
            tail = NULL;    //first make tail null
            delete head;
        }
        else{
            //if more than one node is present
            //then move tail's next to current head's next and delete head
            tail->next = head->next;
            delete head;
        }
        return tail;
    }

    //deletion at the end
    Node *delete_at_tail(Node *tail){
        //if list is empty
        if(tail == NULL){
            cout<<"List is empty"<<endl;
            return NULL;
        }

        //if only one node is present
        Node *head = tail->next;
        if(head == tail){
            cout<<"Only one node is present"<<endl;
            delete tail;
            tail = NULL;
            return tail; //check
        }

        //if more than one node is present
        //traverse till the second last node
        Node *current_node = head;
        while(current_node->next != tail){
            current_node = current_node->next;
        }
        //update current node's pointer to point to head node
        current_node->next = head;
        //delete the last node
        delete tail;
        //set current node as new last node
        tail = current_node;
        //return updated tail
        return tail;
    }

    //delete from a specific node
    Node *delete_specific_node(Node *tail, int key){
        //if list is empty
        if(tail == NULL){
            return NULL;
        }

        //set the current node as last->next for traversal
        //set previous node as last node
        Node *current_node = tail->next;    //current is head now
        Node *previous_node = tail;

        //if only one node is present
        if(current_node == tail && current_node->data == key){
            delete current_node;
            tail = NULL;
            return tail;
        }

        //if the node to be deleted is the first node i.e. head node
        if(current_node->data == key){ //since current node is head only so just check for key
            tail->next = current_node->next;
            delete current_node;
            return tail;
        }

        //Travers the list to find the node to be deleted
        while(current_node != tail && current_node->data != key){
            previous_node = current_node; //store the previous node first
            current_node = current_node->next;
        }
        //if the node to be deleted is found
        //check for its key
        if(current_node->data == key){
            previous_node->next = current_node->next;
            //if the current node is the last node
            //then set the previous node as the new last node
            if(current_node == tail){
                tail = previous_node;
            }
            //delete the current node
            delete current_node;
        }else{
            cout<<"key Not found"<<endl;
        }
        return tail;
    }

    //to display list
    void display(Node *tail){
        if(tail == NULL){
            return;
        }

        //take a temp node as head
        Node *temp = tail->next;

        //first jump to the next node and then loop
        cout<<"Circular singly linked list elements are :"<<endl;
        do{
            cout<<temp->data;
            temp = temp->next;
            if(temp != tail->next){
                cout<<" -> ";
            }
        }while(temp != tail->next);
        cout<<endl;
    }
};

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    Node *tail = head->next->next->next->next;
    tail->next = head;

    tail->display(tail);

    tail = tail->delete_at_head(tail);
    tail->display(tail);

    tail = tail->delete_at_tail(tail);
    tail->display(tail);

    cout<<"\ndelete 40"<<endl;
    tail = tail->delete_specific_node(tail, 40);
    tail->display(tail);

    cout<<"\ndelete 90"<<endl;
    tail = tail->delete_specific_node(tail, 90);
    //tail->display(tail);

}
