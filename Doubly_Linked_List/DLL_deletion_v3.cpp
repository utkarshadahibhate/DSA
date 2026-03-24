#include<iostream>
using namespace std;

//Deletion at a specific position
//Given the head of a DLL and an integer x, delete the node at the x-th position
//(1-based index) from the beginning of the list.
//if x = 1, dlete the head node and update the head pointer.
//if x is greater than the length of the list, no deletion should be performed.

/* Ensure that the list remains valid after deletion,i.e. the previous and the next
pointers of the remaining nodes are correclty updated.*/

/*Find the node at the given position and remove it by updating the links of the
nodes before and after it, so the list stays connected.
If the node to delete is the head, just move head to the next node.*/

/*1)If the list is empty, there is nothing to delete, so just return head.
  2)Go through the list to find the xth node. If x is larger than the number of
    nodes, just return the head as it is.
  3)If x is 1, we need to remove the head: move the head to the next node and make
    sure its previous link is null, then delete the old head.
  4)For any other node, link its previous node to its next node, and if there is
    a next node, link it back to the previous node, then remove the current node.
  5)Return the head of the updated list.
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

  //Node count
  int count_nodes(Node *head){
    int count = 0;
    Node *temp = head;
    while(temp != NULL){
      temp = temp->next;
      count++;
    }
    return count;
  }

  //Delete from a specific position
  Node *delete_at_pos(Node *head, int pos){
    //storing head in temp
    Node *temp = head;

    //if the list is empty
    if(head == NULL){
      return head;
    }

    //if position is 1
    if(pos == 1){
      //set next node as head
      head = head->next;

      //set the previous of head node as NULL
      if(head->prev != NULL){
        head->prev = NULL;
      }
      //delete the old head node
      delete temp;
      //return updated head
      return head;
    }

    //for specific position
    //check for valid position
    if(pos > count_nodes(head)){
      cout<<"Invalid position, nodes out of bound!"<<endl;
      return head;
    }
    else{
      //traverse through the list
      Node *curr = head;
      for(int i = 1; i < pos && curr != NULL; i++){
        curr = curr->next;
      }
      //if the position is out of bound
      if(curr == NULL){
        return head;
      }

      //updating backward node pointers
      if(curr->prev != NULL){
        curr->prev->next = curr->next;
      }

      //updating forward node pointers
      if(curr->next != NULL){
        curr->next->prev = curr->prev;
      }
      //deleting the current node
      delete curr;

      //return the update head
      return head;
    }
  }

  //to display the list
  void display(Node *head){
    Node *temp = head;
    cout<<"DLL elements are: "<<endl;
    if(temp == NULL){
      cout<<"List is empty! "<<endl;
    }
    while(temp != NULL){
      cout<<temp->data;
      if(temp->next != NULL){
        cout<<" <-> ";
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

    //to display list
    head->display(head);

    //Position = 1
    cout<<"\nto delete Position = 1"<<endl;
    head = head->delete_at_pos(head,1);
    head->display(head);

    cout<<"\nto delete position = 10"<<endl;
    head = head->delete_at_pos(head,10);
    head->display(head);
    cout<<"\nto delete position = 2"<<endl;
    head = head->delete_at_pos(head,2);
    head->display(head);

}