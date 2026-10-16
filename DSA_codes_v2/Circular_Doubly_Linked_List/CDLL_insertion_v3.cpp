#include<iostream>
using namespace std;

//insertion at a specific position in doubly circular linked list
/*To insert a new node at a specific position in doubly circular linked list,
1)Allocate memory for new node.
2)Initialise a pointer current pointer to the head node and start traversing the
    list till we reach the node just before the desired position. Use a counter to
    keep track of the current position.
3)Insert new node:
    - Set new node->next to current->next
    - Set new node->prev to current
    - Update current ->next->prev to new node
    - Update current ->next to new node.
4)Update Head(if the insertion is at position 0 and the list is empty), set head
    to new node.*/

class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    //constrcutor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    //to insert at the specific position
    Node *insert_at_pos(Node *head, int pos, int data){
        //create a new node
        Node *new_node = new Node(data);

        //if the list is empty
        if(head == NULL){
            if(pos > 1){
                return NULL;
            }
            //else if the position is one then insert new node
            new_node->prev = new_node;
            new_node->next = new_node;
            //make new node as new head node
            head = new_node;
            //return updated head node
            return new_node;
        }

        //insert at the beginning i.e. pos == 1
        if(pos == 1){
            //update new node pointers
            new_node->next = head;
            new_node->prev = head->prev;
            //update head node pointer
            head->prev = new_node;
            //update tail node pointer
            head->prev->next = new_node;
            //make new node as head node
            head = new_node;
            //return updated head node
            return head;
        }

        //insert at the specific position
        //Traverse to the (p-1) position
        Node *current_node = head;
        for(int i = 1; i < pos - 1; i++){
            current_node = current_node->next;
            //if it traverse back to head again
            if(current_node == head){
                cout<<"Position out of bound"<<endl;
                return head;
            }
        }
        //after reaching (pos-1) position
        //insert the node after the current node(at the given position)
        //update new node pointers
        new_node->next = current_node->next;
        new_node->prev = current_node;
        //update current's next node pointer
        current_node->next->prev = new_node;
        //update current node pointer
        current_node->next = new_node;

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

    head = head->insert_at_pos(head,3,40);
    head->display(head);
}