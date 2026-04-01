#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    //constructor
    Node(int data);

    //insertion operation without using head
    Node *insert_at_head(Node *tail, int data);
    Node *insert_at_tail(Node *tail, int data);
    Node *insert_at_pos(Node *tail, int pos, int data);

    //deletion operation without using head
    Node *delete_at_head(Node *tail);
    Node *delete_at_tail(Node *tail);
    Node *delete_specific_node(Node *tail, int key);

    //to display the list
    void display(Node *tail);

    //to search an element
    bool search_element(Node *tail,int key);

};

//constructor
Node :: Node(int data){
    this->data = data;
    this->next = NULL;
}

//insertion operations
Node* Node :: insert_at_head(Node *tail, int data){
    Node *new_node = new Node(data);

    if(tail == NULL){
        new_node->next = new_node;
        return new_node; //new head
    }
    else{
        new_node->next = tail->next;
        tail->next = new_node;
        return tail;
    }
}

Node* Node :: insert_at_tail(Node *tail, int data){
    Node *new_node = new Node(data);

    if(tail == NULL){
        new_node->next = new_node;
        tail = new_node;
        return tail;
    }
    else{
        new_node->next = tail->next;
        tail->next = new_node;
        tail = new_node;
        return tail;
    }
}
Node* Node :: insert_at_pos(Node *tail, int pos, int data){
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        Node *new_node = new Node(data);
        new_node->next = new_node;
        tail = new_node;
        return tail;
    }

    Node *new_node = new Node(data);
    Node *current_node = tail->next;

    if(pos == 1){
        new_node->next = current_node;
        tail->next = new_node;
        return tail;
    }

    for(int i = 1; i < pos - 1; i++){
        current_node = current_node->next;

        if(current_node == tail->next){
            cout<<"invalid position"<<endl;
            return tail;
        }
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
    if(current_node == tail){
        tail = new_node;
        return tail;
    }
    return tail;
}

//deletion operations
Node* Node :: delete_at_head(Node *tail){
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return NULL;
    }

    Node *head = tail->next;
    if(head == tail){
        cout<<"Only one node is present"<<endl;
        delete tail;
        tail = NULL;
    }
    else{
        tail->next = head->next;
        delete head;
    }
    return tail;

}
Node* Node :: delete_at_tail(Node *tail){
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return NULL;
    }

    Node *head = tail->next;
    if(head == tail){
        cout<<"only one node present"<<endl;
        delete tail;
        tail = NULL;
        return tail;
    }

    Node *current_node = head;
    while(current_node->next != tail){
        current_node = current_node->next; //second last node
    }
    current_node->next = head;
    delete tail;
    tail = current_node;
    return tail;
}

Node* Node :: delete_specific_node(Node *tail, int key){
    if(tail == NULL){
        return NULL;
    }

    Node *current_node = tail->next;
    Node *previous_node = tail;

    if(current_node == tail && current_node->data == key){
        delete current_node;
        tail = NULL;
        return tail;
    }

    if(current_node->data == key){ //for head node
        tail->next = current_node->next;
        delete current_node;
        return tail;
    }
    //traverse
    while(current_node != tail && current_node->data != key){
        previous_node = current_node;
        current_node = current_node->next;
    }
    if(current_node->data == key){
        previous_node->next = current_node->next;
        if(current_node == tail){
            tail = previous_node;
        }
        delete current_node;
    }
    else{
        cout<<"Key not found"<<endl;
    }
    return tail;
}

//to search for an element
bool Node :: search_element(Node *tail,int key){
        //node for traversal
        Node *temp = tail->next;

        if(tail == NULL){
            cout<<"List is empty"<<endl;
        }

        do{
            if(temp->data == key){
                return true;
            }
            temp = temp->next;
        }while(temp != tail->next); //i.e. again head
        return false;
    }

//display list
void Node :: display(Node *tail){
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

    int main(){
        Node *head = NULL;
        Node *tail = NULL;
        // int choice;
        // cout<<"Select one option"<<endl;
        // cout<<"1)Create a CSLL \n2)Inserting an element \n3)Deleting an element \
        //         \n4)Search an element \n5)Display CSLL \n6)Exit....."<<endl;
        // cin>>choice;
        
        while(true){
            int choice;
            cout<<"Select one option"<<endl;
            cout<<"1)Create a CSLL \n2)Inserting an element \n3)Deleting an element \
                \n4)Search an element \n5)Display CSLL \n6)Exit....."<<endl;
            cin>>choice;

            //switch case for above cases
            switch(choice){
                //
                case 1:
                int nodes, choice_num;
                cout<<"Give the number of nodes to be added";
                cin>>nodes;
                cout<<"Select one \n1)Forward insertion \n2)Backward insertion \n3)";
                
            }

        }
    }