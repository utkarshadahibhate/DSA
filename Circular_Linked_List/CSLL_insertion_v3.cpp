#include<iostream>
using namespace std;

//Insertion at a specific position in a circular linked list
/*1)Check if the list is empty:
    -if the position is not 1, print error message (since the position doesn't exist
        in an empty list).
    -if the position is 1, create the new node and make its next pointer to point 
    -itself(since it is the only node).
  2)If the list is not empty: create the new node with the given data.
  3)For insertion at position 1 (insert at the beginning):
    -Traverse the list to find the last node(the node whose next pointer points to the
        head).
    -Set the new node's next pointer to the current head.
    -Set the next pointer of the last node to the new node.
    -Update the head to point to the new node.
  4)For insertion at position other than 1:
    -Traverse the list to reach the node just before the desired position i.e.
        (position -1)
    -Once reach the node, set the new node's next pointer to point to the node that
        was previously at the desired position.
    -Set the (position-1)-th node's next pointer to the new node
  5)If the new node is inserted at the end:
    -Update the last node's next pointer to point to the new node, maintaining the
        circular nature of the list
    -Ensure the new node's next pointer points to the head, completing the circle
    -This process ensures that the circular structure of the linked list is preserved
        after every insertion.
*/

class Node{
    public:
    int data;
    Node *next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //count of nodes
    int count_nodes(Node *head){
        Node *temp = head;
        int count = 0;

        do{
            count++;
            temp = temp->next;
        }while(temp->next != head);
        
        return count;
    }

    Node *insert_at_pos(Node *head, int pos, int data){
        Node *new_node = new Node(data);

        if(head == NULL){
            new_node->next = new_node;
            head = new_node;
            return head;
        }
        
        //for pos = 1
        if(pos == 1){
            Node *last_node = head;
            while(last_node->next != head){
                last_node = last_node->next;
            }
            last_node->next = new_node;
            new_node->next = head;
            head = new_node;
            return head;
        }

        //for any specific position
        Node *current_node = head;
        if(pos > count_nodes(head)){
            cout<<"Invalid position, nodes out of bounds!"<<endl;
            return head;
        }
        else{
            for(int i = 1; i < pos - 1; i++){
                current_node = current_node->next;
            }
            //update new node's pointer
            new_node->next = current_node->next;
            //update current node's pointer
            current_node = new_node;

            //return updated head
            return head;
        }
    }

    //to display the list
    void display(Node *head){
        if(head == NULL){
            return;
        }

        //take a temp node as head
        Node *temp = head;

        //first jump to the next node and then loop
        cout<<"Circular singly linked list elements are :"<<endl;
        do{
            cout<<temp->data;
            temp = temp->next;
            if(temp != head){
                cout<<" -> ";
            }
        }while(temp != head);
        cout<<endl;
    }
};

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    Node *last = head->next->next->next;
    last->next = head;

    // cout<<"Enter for position "<<endl;
    // cin>>pos;
    // cout<<"give the number : ";
    // cin>>data;
    head = head->insert_at_pos(head,5,80);
    head->display(head);

    head = head->insert_at_pos(head,10,90);
    head->display(head);

    head = head->insert_at_pos(head,6,100);
    head->display(head);

    //head = head->insert_at_pos(head,1,90);
    //head->display(head);
}