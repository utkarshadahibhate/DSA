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
    int pos;

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
        //to check if list is empty or not and pos = 1
        if(head != NULL and pos == 1){
            new_node->next = head;
            head->prev = new_node;
            return head;
        }

        //2nd condition: insertion at a specific position
        if(pos > count_nodes(head)){
            cout<<"Invalid position!, nodes out of bound"<<endl;
        }
        else{
            Node *curr = head;
            for(int i = 1; i < pos-1; i++){
                curr->next = curr;
            }
            //update current pointers
            curr->next = new_node;
            curr->next->prev = new_node;

            //assign new_node pointers
            new_node->next = curr->next;
            new_node->prev = curr;

            return head;
        }

        //3rd condition: insertion at the end
        Node *last_node = head;
        while(last_node->next != NULL){
            last_node->next = last_node;
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
    Node *head = NULL;

    //1st Node
    head = new Node(11);

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
    head->insert_at_position(head, 99, 1);

    //to display list
    head->display(head);
}
