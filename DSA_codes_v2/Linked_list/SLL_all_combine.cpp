#include<iostream>
using namespace std;

//Combining all the operations of DLL

/*1)Insertion operation - at beginning, at end, at specific location
  2)Deletion opearation - at beginning, at end, at specific location
  3)Searching
*/

class Node{
  public:
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

//constructor
Node :: Node(int data){
  this->data = data;
  this->next = NULL;
}

//Insertion operations
//1)Insertion at the beginning
Node *Node :: insert_at_front(Node *head, int data){
  Node *new_node = new Node(data);
  new_node->next = head;
  head = new_node;
  return head;
}

//2)Insertion at the end
Node *Node :: insert_at_end(Node *head, int data){
  Node *new_node = new Node(data);

  if(head == NULL){
    return new_node;
  }

  //traverse the last node
  Node *lastnode = head;
  while(lastnode->next != NULL){
    lastnode = lastnode->next;
  }
  //update the lastnode pointer
  lastnode->next = new_node;

  return head;
}

//3)Insert at specific position
Node *Node :: insert_at_pos(Node *head, int data, int pos){
  Node *new_node = new Node(data);
  if(pos < 1){
    return head;
  }

  if(pos == 1){
    new_node->next = head;
    head = new_node;

    return head;
  }

  //traverse the list
  if(pos > count_nodes(head)){
      cout<<"Invalid position, nodes out of bounds !"<<endl;
      return head;
  }
  else{
    //traverse to one before the position
    Node *curr = head;
    for(int i = 1; i < pos-1 && curr != NULL; i++){
      curr = curr->next;
    }
    //if position out of list
    if(curr == NULL){
      return head;
    }
    //update new_node pointer
    new_node->next = curr->next;
    //update current node pointer
    curr->next = new_node;

    return head;
  }
}

//Deletion Operations
//1) Deletion at the beginning
Node *Node :: delete_at_start(Node *head){
  //for temporary storage
  Node *temp = head;

  if(head == NULL){
    return head;
  }
  //shift the head to next node
  head = head->next;
  delete temp;
  //return the updated head
  return head;
}

//2) Deletion at the end
Node *Node :: delete_at_end(Node *head){
  if(head == NULL){
    cout<<"List is empty."<<endl;
    return head;
  }
  if(head->next == NULL){
    cout<<"\nList has only Head node : "<<head->data;
    cout<<"\nDeleting the Head node : "<<head->data;
    delete head;
    return NULL;
  }
  //traverse till the secondlast node
  Node *secondlast = head;
  while(secondlast->next->next != NULL){
    secondlast = secondlast->next;
  }
  //delete the last node
  delete secondlast->next;
  //update secondlast node pointer
  secondlast->next = NULL;

  //return updated head
  return head;
}

//3) Deletion at a specific position
Node *Node :: delete_at_pos(Node *head, int pos){
  //for temporary storage
  Node *temp = head;

  if(head == NULL){
    cout<<"List is empty."<<endl;
    return head;
  }

  if(pos == 1){
    head = temp->next;
    delete temp;
    return head;
  }
  //only head node present
  if(head->next == NULL){
      cout<<"\nList has only Head node : "<<head->data;
      cout<<"\nDeleting the Head node : "<<head->data;
      delete head;
      return NULL;
  }

  //traverse till described position
  if(pos > count_nodes(head)){
    cout<<"Invalid position, nodes out of bounds !"<<endl;
    return head;
  }
  else{
    //traverse till that position
    Node *previous_node = NULL;
    for(int i = 1; i < pos ; i++){
      previous_node = temp; //storing one before the pos
      temp = temp->next; //storing the exact pos
    }
    //update the previous node pointer
    previous_node->next = temp->next;

    delete temp;
    //return the updated head
    return head;
  }
}

bool Node :: search_key(Node *head, int key){
  Node *current = head;
  while(current->next != NULL){
    if(current->data == key){
      return true;
    }
    current = current->next;
  }
  return false;
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
    cout<<"\nLL elements are : "<<endl;
    if(temp == NULL){
        cout<<"\nList is empty! "<<endl;
    }
    while(temp != NULL){
        cout<<temp->data;
        if(temp->next != NULL){
            cout<<" "<<" -> ";
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
        cout<<"1)Creating a LL \n2)Inserting an element \
        \n3)Deleting an element \n4)Search an element \
        \n5)Display LL \n6)Exit....."<<endl;
        cin>>choice;

        //switch case for above cases
        switch(choice){
            //1)Creating a LL
            case 1:
            int nodes_num, ele, insert_choice;
            bool result;
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

            //search an element
            case 4:
            cout<<"Give an element to be searched : ";
            cin>>ele;
            result = head->search_key(head, ele);
            if(result){
              cout<<"\nKey "<<ele<<" is found : "<<endl;
            }else{
              cout<<"\nKey not found"<<endl;
            }
            head->display(head);
            break;

            //to display
            case 5:
            head->display(head);
            break;

            //exit case
            case 6:
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

