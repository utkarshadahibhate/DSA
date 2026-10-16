#include<iostream>
using namespace std;

//Insertion at a specific position in DLL
/*1)If position = 1, create a new node and make it the head of the linked list
    and return it.
  2)Otherwise, traverse the list to reach the node at position-1 i.e.(n-1),
    say curr.
  3)If the position is valid, create a new node with given data, say new_node.
  4)Update the next pointer of new node to the next of current node and prev
    pointer of new node to current node.
  5)Similarly, update next pointer of the current node to new node.
  6)If the new node is not the last node, update pre pointer of new node's next
    to the new node.
*/
class Node{
    public:
    Node *prev;
    int data;
    Node *next;

    //constructor
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    int count_nodes(Node *head){
        int count = 0;
        Node *temp = head;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }

    Node *insert_at_position(Node *head, int data, int pos){
        //creating a new node
        Node *new_node = new Node(data);

        //1st condition: insertion at the beginnning
        if(pos == 1){
            new_node->next = head;

            //within this if the linked list is not empty
            //set the previous of the head node to new_node
            if(head != NULL){
                head->prev = new_node;
            }
            //set the new node as the head of the linked list
            head = new_node;
            //return the updated head
            return head;
        }

        //2nd condition: insertion at a specific position
        Node *curr = head;
        if(pos > count_nodes(head)){
            cout<<"Invalid position!, nodes out of bound"<<endl;
        }
        else{
            for(int i = 1; i < pos-1 && curr != NULL; i++){
                curr = curr->next; //one position behind of the actual position
            }

            //if the position is out of bounds
            if(curr == NULL){
                delete new_node;
                return head;
            }

            //updating new_node pointers
            //set the previous of new node to curr
            new_node->prev = curr;

            //set next of new node to next of curr
            new_node->next = curr->next;

            //Updating current node pointer
            //Update the next of current node to new node
            curr->next = new_node;

            //Updating new_node's next node pointer
            //if the new_node is not the last node
            //update prev of next node to new node
            if(new_node->next != NULL){
                new_node->next->prev = new_node;
            }

            //return the updated head
            return head;
        }

        //3rd condition: insertion at the end
        Node *last_node = head;
        while(last_node->next != NULL){
            last_node = last_node->next;
        }
        //assign last node next to new_node
        last_node->next = new_node;
        //assign new_node's previous to last node
        new_node->prev = last_node;

        //Atlast return head
        return head;
    }

    //to display the list (foward traversing)
    void display(Node *head){
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
};

int main(){
    //creating an empty node
    //Node *head = NULL;

    //1st Node
    Node *head = new Node(11);

    //2nd Node
    head->next = new Node(22);
    head->next->prev = head;

    //3rd Node
    head->next->next = new Node(33);
    head->next->next->prev = head->next;

    //4th Node
    head->next->next->next = new Node(44);
    head->next->next->next->prev = head->next->next;

    //5th Node
    head->next->next->next->next = new Node(55);
    head->next->next->next->next->prev = head->next->next->next;

    //Position = 1
    //cout<<"for Position = 1"<<endl;
    head = head->insert_at_position(head, 99, 1);
    head = head->insert_at_position(head, 88, 6);
    head = head->insert_at_position(head, 111, 6);


    //to display list
    head->display(head);
}
