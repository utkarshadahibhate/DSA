#include<iostream>
using namespace std;

/*SLL insertion at the end
1) new node
2) check if the head node is null or not
    if null, assign newnode as head
    otherwise traverse through the LL untill null node is found
    (i.e the lastnode) and assign lastnode's next to newnode*/

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    Node *addlast(Node *head, int data){
        Node *newnode = new Node(data);

        if(head == NULL){
            return newnode;
        }

        Node *lastnode = head;
        while(lastnode->next != NULL){
            lastnode = lastnode->next;
        }
        lastnode->next = newnode ;
        return head;
    }


Node *insertPos(Node *head, int pos, int val) {

    if (pos < 1)
        return head;

    // head will change if pos=1
    if (pos == 1) { //if position is 1
        Node *newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }

    Node *curr = head;

    // Traverse to the node that will be
    // present just before the new node
    for (int i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    // If position is greater than the 
    // number of nodes
    if (curr == NULL)
        return head;

    Node *newNode = new Node(val);

    // update the next pointers
    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

    //display the linked list
    void display(Node *head){
        Node *temp = head;
        cout<<"Printing Elements:";
        while(temp != NULL){

            cout<<temp->data<<" ";
            temp = temp->next;
        }cout<<endl;
    }

};

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);

    head->addlast(head,30);
    head->insertPos(head,2,15);
    head->display(head);
}