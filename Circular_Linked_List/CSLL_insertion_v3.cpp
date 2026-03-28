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

