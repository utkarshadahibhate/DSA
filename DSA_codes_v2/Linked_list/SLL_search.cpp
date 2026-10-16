#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //Search an element in the linked list
    //Given a head of linked list and key, determine whether the key exists
    //by traversing through the nodes sequentially.
    /*1)Initialise a node pointer curr=head
      2)Do the following while curr is not null
            i)If the current value(i.e. curr->key) is equal to the key being 
                searched return true.
            ii)Otherwise move to the next node(curr = curr->next)
      3)If the key is not found return false.
    */

    bool search_key(Node *head, int key){
        Node *current = head;

        while(current != NULL){
            if(current->data == key){
                return true;
            }
            current = current->next;
        }
        return false;
    }

    //displaying the linked list
    void display(Node *head){
        Node *temp = head;
        cout<<"\nLinked-list elements are: "<<endl;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }cout<<endl;
    }
};

int main(){
    //creating a list
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    int key;
    cout<<"Give a key to be searched for: ";
    cin>>key;
    bool result = head->search_key(head,key);
    if(result){
        cout<<"\nKey "<<key<<" is found"<<endl;
    }else{
        cout<<"\nKey not found"<<endl;
    }

    head->display(head);
}