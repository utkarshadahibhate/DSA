#include<iostream>
using namespace std;

//insertion at a specific position in doubly circular linked list
/*To insert a new node at a specific position in doubly circular linked list,
1)Allocate memory for new node.
2)Initialise a pointer current pointer to the head node and start traversing the
    list till we reach the node just before the desired position. Use a counter to
    keep track of the current position.
3)Insert new node:
    - Set new node->next to current->next
    - Set new node->prev to current
    - Update current ->next->prev to new node
    - Update current ->next to new node.
4)Update Head(if the insertion is at position 0 and the list is empty), set head
    to new node.*/