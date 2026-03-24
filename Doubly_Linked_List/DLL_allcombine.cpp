#include<iostream>
using namespace std;

//Combining all the operations of DLL

/*1)Insertion operation - at beginning, at end, at specific location
  2)Deletion opearation - at beginning, at end, at specific location
*/

class Node{
    public:
    int data;
    Node *prev;
    Node *next;

    //function declarations
    //constructor
    Node(int data);
    
    //Insertion functions declarations
    Node *insert_at_front(Node *head,int data);
    Node *insert_at_end(Node *head, int data);
    Node *insert_at_pos(Node *head, int data, int pos);

    //Deletion functions declarations
    Node *delete_at_start(Node *head);
    Node *delete_at_end(Node *head);
    Node *delete_at_pos(Node *head, int pos);

    //to count nodes
    int count_nodes(Node *head);

    //to display the list
    void display(Node *head);

};

//function definitions
//return_type class_name :: function_name(...)
//[Return Type] [Scope (Class)] :: [Function Name] (parameters)
/*So here:

Node* → return type
Node:: → function belongs to class Node
insert_at_front → function name
Node* Node::insert_at_front(Node *head, int data)
*/

//constructor
Node::Node(int data){
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
}

//Insertion operations
//1)Insertion at the beginning
Node* Node :: insert_at_front(Node *head,int data){
    Node *new_node = new Node(data);

    new_node->next = head;

    if(head != NULL){ //means nodes are present
        head->prev = new_node;
    }
    return new_node; 
}

//2)Insertion at the end
Node* Node :: insert_at_end(Node *head, int data){
    Node *new_node = new Node(data);

    if(head == NULL){
        head = new_node;
        return head;
    }
    else{
        Node *last_node = head;
        while(last_node->next != NULL){
            last_node = last_node->next;
        }
        last_node->next = new_node;

        new_node->prev = last_node;

        return head;
    }
}

//3)Insert at specific position
Node* Node :: insert_at_pos(Node *head, int data, int pos){
    Node *new_node = new Node(data);

    if(pos == 1){ //insert before head
        new_node->next = head;

        if(head != NULL){
            head->prev = new_node;
        }
        return head;
    }

    if(pos > count_nodes(head)){
        cout<<"Invalid position, nodes out of bounds !"<<endl;
        return head;
    }
    else{
        Node *curr = head;
        for(int i = 1; i < pos - 1 && curr != NULL; i++){
            curr = curr->next;  //just before the actual position
        }
        //pos out of bounds
        if(curr == NULL){
            delete new_node;
            return head;
        }
        //updating new_node pointers
        new_node->prev = curr;
        new_node->next = curr->next;

        //updating curr pointers
        curr->next = new_node;

        //updating new_node's next node pointers
        if(new_node->next != NULL){
        new_node->next->prev = new_node;
        }
        return head;
    }
}

//Deletion operations
//1)Insertion at the beginning
Node* Node :: delete_at_start(Node *head){}

//2)Insertion at the end
Node* Node :: delete_at_end(Node *head){}

//3)Insert at specific position
Node* Node :: delete_at_pos(Node *head, int pos){}

//to count nodes
int Node :: count_nodes(Node *head){
    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

//to display the list
void Node :: display(Node *head){
    Node *temp = head;
    cout<<"DLL elements are : "<<endl;
    if(temp == NULL){
        cout<<"List is empty! "<<endl;
    }
    while(temp != NULL){
        cout<<temp->data;
        if(temp->next != NULL){
            cout<<" "<<" <-> ";
        }
        temp = temp->next;
    }cout<<endl;
}

int main(){}