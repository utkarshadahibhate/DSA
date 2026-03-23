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

    int no_of_nodes(Node *head){
        Node *countnode = head;
        int count = 0;
        while(countnode != NULL){
            countnode = countnode->next;
            count++;
        }
        return count;
    }


    //Deletion at specified Position of linked list
    //Deletion at a specified position int the linked list involves removing
    //a node from a specific index/position, which can be first, middle or last.
    /*1)Check if the position is valid.
      2)Traverse the list to find the node just before the one to be deleted.(n-1)th position
      3)Update the next pointer of the (n-1)th node to point to the node after the target node.
      4)Delete the target node.
    */

    Node *delete_at_position(Node *head, int position){
        if(head == NULL){
            cout<<"\nList is empty !\n";
            return NULL;
        }

        //if head is to be deleted // in this case no previous node is available for address shift
        Node *temp = head;
        if(position == 1){
            cout<<"\ndeleting position 1 Node i.e. Head Node..\n"<<endl;
            head = temp->next;
            delete temp;
            return head;
        }

        //only head node present
        if(head->next == NULL){
            cout<<"\nList has only Head node : "<<head->data;
            cout<<"\nDeleting the Head node : "<<head->data;
            delete head;
            return NULL;
        }

        //to check total number of nodes in the linked list
        int nodes = no_of_nodes(head);

        //to check valid position
        if(position > nodes){
            cout<<"\nPosition out of Nodes !\n"<<endl;
        }
        //else{
        //traversing through the linked list
        //Node *temp = head;
        Node *one_previous = NULL;
        for(int i = 1; i < position; i++){
            one_previous = temp; //storing the previous one
            temp = temp->next; //looping the next one
            //temp will store the positioned node just before the termination of loop.
        }
        //assigning position->next node to previous node
        one_previous->next = temp->next;

        //deleting next to the previous node
        delete temp;

        return head;
        //}
    }

    //displaying the linked list
    void display(Node *head){
        Node *temp = head;
        cout<<"\nLinked-list elements are: "<<endl;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }cout<<endl;
    }
};

int main(){
    //creating an empty node
    // Node *head = NULL;
    // head = head->delete_at_position(head,2);

    // //creating a head node only
    // Node *head = new Node(10);
    // head = head->delete_at_position(head,2);

    //creating a list
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    //head = head->delete_at_position(head,10); //out of bound position

    // head->display(head);
    // head = head->delete_at_position(head,3); //in-bound position
    // head->display(head);

    //deleting position 1 node
    head->display(head);
    head = head->delete_at_position(head,1);
    head->display(head);
}