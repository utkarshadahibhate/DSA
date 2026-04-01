#include<iostream>
using namespace std;

//Searching an element in a circular linked list
/*1)Keep a pointer to the head of the circular linked list.
  2)Now traverse the linked list one by one and check if the element is present or not.
  3)if the element is present return true.
  4)Now, if the element is not present and the traversal pointer reaches the head again,
    it means the element is not present in the CLL. Therefore return false.
*/

class Node{
    public:
    int data;
    Node *next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //to search for an element
    bool search_element(Node *tail,int key){
        //node for traversal
        Node *temp = tail->next;

        if(tail == NULL){
            cout<<"List is empty"<<endl;
        }

        do{
            if(temp->data == key){
                return true;
            }
            temp = temp->next;
        }while(temp != tail->next); //i.e. again head
        return false;
    }

    //to display
    void display(Node *tail){
        if(tail == NULL){
            return;
        }

        //take a temp node as head
        Node *temp = tail->next;

        //first jump to the next node and then loop
        cout<<"Circular singly linked list elements are :"<<endl;
        do{
            cout<<temp->data;
            temp = temp->next;
            if(temp != tail->next){
                cout<<" -> ";
            }
        }while(temp != tail->next);
        cout<<endl;
    }
};

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    Node *tail = head->next->next->next;
    tail->next = head;

    int key = 30;
    bool result = tail->search_element(tail,key);

    if(result){
        cout<<"Key found : "<<key<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    //cout<<result<<endl;
    tail->display(tail);
}
