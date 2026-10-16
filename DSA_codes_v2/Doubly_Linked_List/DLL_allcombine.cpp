#include<iostream>
using namespace std;

//Combining all the operations of DLL

/*1)Insertion operation - at beginning, at end, at specific location
  2)Deletion opearation - at beginning, at end, at specific location
*/

class Node{
    public:
    int data;
    Node *prev;
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

    //to count nodes
    int count_nodes(Node *head);

    //to display the list
    void display(Node *head);

};

//function definitions
//return_type class_name :: function_name(...)
//[Return Type] [Scope (Class)] :: [Function Name] (parameters)
/*So here:

Node* → return type
Node:: → function belongs to class Node
insert_at_front → function name
Node* Node::insert_at_front(Node *head, int data)
*/

//constructor
Node::Node(int data){
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
}

//Insertion operations
//1)Insertion at the beginning
Node* Node :: insert_at_front(Node *head,int data){
    Node *new_node = new Node(data);

    new_node->next = head;

    if(head != NULL){ //means nodes are present
        head->prev = new_node;
    }
    return new_node; 
}

//2)Insertion at the end
Node* Node :: insert_at_end(Node *head, int data){
    Node *new_node = new Node(data);

    if(head == NULL){
        head = new_node;
        return head;
    }
    else{
        Node *last_node = head;
        while(last_node->next != NULL){
            last_node = last_node->next;
        }
        //update last node pointers
        last_node->next = new_node;
        //update new_node pointers
        new_node->prev = last_node;

        return head;
    }
}

//3)Insert at specific position
Node* Node :: insert_at_pos(Node *head, int data, int pos){
    Node *new_node = new Node(data);

    if(pos == 1){ //insert before head
        new_node->next = head;

        if(head != NULL){
            head->prev = new_node;
        }
        head = new_node;
        return head;
    }

    if(pos > count_nodes(head)){
        cout<<"Invalid position, nodes out of bounds !"<<endl;
        return head;
    }
    else{
        Node *curr = head;
        for(int i = 1; i < pos - 1 && curr != NULL; i++){
            curr = curr->next;  //just before the actual position
        }
        //pos out of bounds
        if(curr == NULL){
            delete new_node;
            return head;
        }
        //updating new_node pointers
        new_node->prev = curr;
        new_node->next = curr->next;

        //updating curr pointers
        curr->next = new_node;

        //updating new_node's next node pointers
        if(new_node->next != NULL){
        new_node->next->prev = new_node;
        }
        return head;
    }
}

//Deletion operations
//1)Deletion at the beginning
Node* Node :: delete_at_start(Node *head){
    Node *temp = head;

    if(head == NULL){
        return head;
    }

    head = head->next;
    if(head->next != NULL){
        head->prev = NULL;
    }

    delete temp;
    return head;
}

//2)Deletion at the end
Node* Node :: delete_at_end(Node *head){
    Node *lastnode = head;

    if(head == NULL){
        return head;
    }

    if(head->next == NULL){ //if only head node present
        delete head;
        return NULL;
    }
    //traverse till last node
    if(head != NULL){
        while(lastnode->next != NULL){
            lastnode = lastnode->next;
        }
    }
    //update second last node pointers
    lastnode->prev->next = NULL;

    delete lastnode;
    return head;
}

//3)Deletion at specific position
Node* Node :: delete_at_pos(Node *head, int pos){
    Node *temp = head;

    if(head == NULL){
        return head;
    }

    if(pos == 1){
        head = head->next;
        if(head->prev != NULL){
            head->prev = NULL;
        }
    }
    delete temp;
    return head;

    if(pos > count_nodes(head)){
        cout<<"\nInvalid position, nodes out of bounds !"<<endl;
        return head;
    }
    else{
        Node *curr = head;
        for(int i = 1; i < pos && curr != NULL; i++){
            curr = curr->next;  //at the position
        }
        //if curr is NULL
        if(curr == NULL){
            return head;
        }

        //update the backward pointer
        if(curr->prev != NULL){
            curr->prev->next = curr->next;
        }
        //update the forward pointer
        if(curr->next != NULL){
            curr->next->prev = curr->prev;
        }

        delete curr;
        return head;
    }

}

//to count nodes
int Node :: count_nodes(Node *head){
    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

//to display the list
void Node :: display(Node *head){
    Node *temp = head;
    cout<<"\nDLL elements are : "<<endl;
    if(temp == NULL){
        cout<<"\nList is empty! "<<endl;
    }
    while(temp != NULL){
        cout<<temp->data;
        if(temp->next != NULL){
            cout<<" "<<" <-> ";
        }
        temp = temp->next;
    }cout<<endl;
}

int main(){
    Node *head = NULL;
    int choice;
    // cin>>choice;
    // cout<<"Select a option :"<<endl;
    // cout<<"1)Creating a DLL \n2)Inserting an element \
    // \n3)Deleting an element"<<endl;

    while(true){
        cout<<"\nSelect a option :"<<endl;
        cout<<"1)Creating a DLL \n2)Inserting an element \
        \n3)Deleting an element \n4)Display DLL \n5)Exit....."<<endl;
        cin>>choice;

        //switch case for above cases
        switch(choice){
            //1)Creating a DLL
            case 1:
            int nodes_num, ele, insert_choice;
            cout<<"\nGive the number of nodes to be added : ";
            cin>>nodes_num;
            cout<<"\nSelect one \n1)Forward Insertion\n2)Backward Insertion"<<endl;
            cin>>insert_choice;
            for(int i = 1; i <= nodes_num; i++){
                cout<<"give the element no "<<i<<": ";
                cin>>ele;
                if(insert_choice == 1){
                    head = head->insert_at_front(head, ele);
                }
                else if(insert_choice == 2){
                    head = head->insert_at_end(head, ele);
                }
                else{
                    cout<<"Give a valid choice !"<<endl;
                }
            }
            head->display(head);
            break;

            //2)Inserting an element
            case 2:
            //int insert_choice, ele, pos;
            int pos;
            cout<<"\nSelect one \n1)Insert at front \n2)Insert at the end \
            \n3)Insert at specific position"<<endl;
            cin>>insert_choice;
            cout<<"Give an element to be added : ";
            cin>>ele;
            //cases
            if(insert_choice == 1){
                head = head->insert_at_front(head,ele);
            }
            else if(insert_choice == 2){
                head = head->insert_at_end(head,ele);
            }
            else if(insert_choice == 3){
                cout<<"Give a position number : ";
                cin>>pos;
                head = head->insert_at_pos(head,ele,pos);
            }
            else{
                cout<<"Give a valid choice !"<<endl;
            }
            head->display(head);
            break;

            //3)Deleting an element
            case 3:
            cout<<"\nSelect one \n1)Delete at beginning \n2)Delete at the end \
            \n3)Delete at specific position"<<endl;
            cin>>insert_choice;
            //cout<<"Give the element to be deleted : ";
            //cin>>ele;
            //cases
            if(insert_choice == 1){
                head = head->delete_at_start(head);
            }
            else if(insert_choice == 2){
                head = head->delete_at_end(head);
            }
            else if(insert_choice == 3){
                cout<<"Give a position number : ";
                cin>>pos;
                head = head->delete_at_pos(head,pos);
            }
            else{
                cout<<"Give a valid choice !"<<endl;
            }
            head->display(head);
            break;

            //to display
            case 4:
            head->display(head);
            break;

            //exit case
            case 5:
            goto exit_loop;

            //default case
            default:
            cout<<"\nInvalid input, please try again !"<<endl;
            break;
        }
        cout<<endl;
    }
    exit_loop:
    cout<<"Exited the loop."<<endl;
}