#include<iostream>
using namespace std;

//Deletion at the end (removal of last node)
//given a DLL, the task is to delete the last node of the given linked list

//To perform the deletion operation at the end of doubly linked list, we need 
//to traverse the list to find the second last node, then set its next pointer
//to NULL.

/*1)Check if the DLL is empty. If it is empty, then there is nothing to delete.
  2)If the list is not empty, then move to the last node of the DLL, say curr.
  3)Update the second-to-last node's next pointer to NULL.
  4)Free the memory allocated for the node that was deleted.
*/

class Node{
    public:
    Node *prev;
    int data;
    Node *next;

    //construct
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    //deletion at the end
    Node *delete_at_end(Node *head){
        //store head to temp
        Node *temp = head;
        
        //to check if the list is empty
        if(head == NULL){
            return head;
        }

        //if only head is present
        if(head->next == NULL){
            delete head;
            return NULL;
        }

        //traverse the list to the last
        if(head != NULL){
            while(temp->next != NULL){
                temp = temp->next;
            }
        }
        //updating the previous node's next pointer
        temp->prev->next = NULL;

        //deleting the temp
        delete temp;

        //return the updated head
        return head;
    }
};