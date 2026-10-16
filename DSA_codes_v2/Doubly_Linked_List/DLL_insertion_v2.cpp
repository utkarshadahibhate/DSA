#include<iostream>
using namespace std;

//Insertion at the end of DLL
/*1)create a new_node with the given data and set its next and previous to null.
  2)Check if the list is empty, set the new node as head node
  3)otherwise traverse the entire list until we reach the last node, say curr.
  4)Then, set the last node's next to new node and new node's previous to last node,
    making the new node the last element in the list.
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
    //Inserting element at the end
    Node *insert_at_end(Node *head, int data){
        //creating a new node
        Node *new_node = new Node(data);

        //to check if list is empty
        if(head == NULL){
            head = new_node;
            return head;
        }
        else{
            //traverse the list
            Node *last_node = head;
            while(last_node->next != NULL){
                last_node = last_node->next;
            }
            //set last node's next to new node
            last_node->next = new_node;

            //set new_node's previous to last node
            new_node->prev = last_node;

            return head;
        }
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
//creating a new node
Node *head = NULL;

//creating 1st node
head = new Node(10);

//creating 2nd node
head->next = new Node(20);
head->next->prev = head;

//creating 3rd node
head->next->next = new Node(30);
head->next->next->prev = head->next;

//creating 4th node
head->next->next->next = new Node(40);
head->next->next->next->prev = head->next->next;

//creating 5th node
//H-N-N-N-N
head->next->next->next->next = new Node(50);
head->next->next->next->next->prev = head->next->next->next;

//adding element
head = head->insert_at_end(head, 180);

//to display DLL
head->display(head);


}