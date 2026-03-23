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