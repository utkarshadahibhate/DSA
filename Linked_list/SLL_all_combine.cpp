#include<iostream>
using namespace std;

//Combining all the operations of DLL

/*1)Insertion operation - at beginning, at end, at specific location
  2)Deletion opearation - at beginning, at end, at specific location
  3)Searching
*/

class Node{
    int data;
    Node *next;

    //function declarations
    //constructor
    Node(int data);
    
    //Insertion functions declarations
    Node *insert_at_front(Node *head,int data);
    Node *insert_at_end(Node *head, int data);
    Node *insert_at_pos(Node *head, int data, int pos);

    //Deletion functions declarations
    Node *delete_at_start(Node *head);
    Node *delete_at_end(Node *head);
    Node *delete_at_pos(Node *head, int pos);

    //To search an element
    bool search_key(Node *head, int key);

    //to count nodes
    int count_nodes(Node *head);

    //to display the list
    void display(Node *head);
};