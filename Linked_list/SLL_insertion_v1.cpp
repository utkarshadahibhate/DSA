#include<iostream>
using namespace std;

//Singly linked-list node structure
//creating a class Node
class Node{
    public:
    int data;
    Node *next;

    //Insertion operations

    //1)At begining
    //constructor to initialise new node at begining
    Node(int data){
        this->data = data;
        this->next = NULL; //so that end node is null
    }

    // //2)At the end
    // Node *insert_at_end(Node *head, int data){
    //     //create a new node and set its next to null
    //     Node *newnode = new Node(data);

    //     //if the linked list is empty make the newnode as head
    //     if(head == NULL){
    //         head = newnode;
    //         return newnode; //for returning this apply * to func name
    //     }

    //     //otherwise traverse to the last node
    //     Node *lastnode = head;
    //     while(lastnode->next != NULL){
    //         lastnode = lastnode->next;
    //     }
    //     //when the lastnode reaches null the loop will break
    //     //after reaching null node assign the lastnode' next to newnode.
    //     lastnode->next = newnode;
    //     return head;
    // }

    //To display the linked list
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
    //creating head of the list
    Node *head = new Node(10);

    //linking the second node
    head->next = new Node(20);

    //linking the 3rd node
    head->next->next = new Node(30);

    //linking the 4th node
    head->next->next->next = new Node(40);

    //inserting at the end
    //Node *newnode = insert_at_end(head, 80);

    head->display(head);




    // //printing linked list
    // //creating a temporary node for traversal
    // Node *temp = head;  //pointing temp to first node i.e head node
    // //traversing till null pointer is reached
    // cout<<"Linked-list elements are: "<<endl;
    // while(temp != NULL){
    //     cout<<temp->data<<" ";
    //     temp = temp->next;  //assigning temp's next to temp which is pointing towards next node
    // }cout<<endl;

}