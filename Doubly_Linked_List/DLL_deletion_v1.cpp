#include<iostream>
using namespace std;

//Deletion at the beginning (removal of first node)
//given a doubly linked list, the task is to delete the node from the beginningof the linked list.

//The idea is to update the head of the DLL to the node next to head node
//and if the new head is not NULL, then set the previous pointer of new head to NULL.

/*1)Check if the list is empty, there is nothing to delete, return.
  2)Store the head pointer in a variable, say temp.
  3)Update the head of linked list to the node next to the current head.
  4)If the new head is not NULL, update the previous pointer of new head to NULL.
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

    //Deletion at the beginning
    Node *delete_at_start(Node *head){
        //store head in temp for deletion later
        Node *temp = head;

        //check if the list is empty
        if(head == NULL){
            return head;
        }

        //move head to next node
        head = head->next;

        //Set prev of the new head
        if(head != NULL){
            head->prev = NULL;
        }

        //delete the temp node
        delete temp;

        //return the updated head
        return head;
    }
};