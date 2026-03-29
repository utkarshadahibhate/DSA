//insertion at specific position
    // Node *insert_at_pos(Node *tail, int pos, int data){
    //     //first create a node
    //     Node *new_node = new Node(data);

    //     //if head or tail is null i.e. empty list
    //     if(tail == NULL){
    //         tail = new_node; //assigning neww node
    //         tail->next = tail; //pointing to itself

    //         //return updated tail
    //         return tail;
    //     }

    //     //for traversing
    //     //current will point to head initially
    //     Node *current_node = tail->next;

    //     //insert at the head
    //     if(pos == 1){
    //         //assign new node's next to current node i.e. head
    //         new_node->next = current_node;
    //         //update tail's pointer
    //         tail->next = new_node;
    //         //return updated tail
    //         return tail;
    //     }

    //     //For any specific position 
    //     for(int i = 1; i < pos - 1; i++){
    //         current_node = current_node->next; //terminate one before the pos
            
    //         //after receiving the current node
    //         //if position is out of bounds
    //         if(current_node == tail->next){ //i.e head == head
    //             //i.e current_node == termination point i.e head
    //             cout<<"Invalid position!"<<endl;
    //             return tail;
    //         }
    //         //if the above termination condition fails then only current_node
    //         //will return out of the code section, use that for inserting node
    //     }
    //     //insert the new node at the desired position
    //     //update new node's pointer
    //     new_node->next = current_node->next;
    //     //update current node's pointer
    //     current_node->next = new_node;

    //     //update the tail node if the new node is inserted at the end
    //     if(current_node == tail){
    //         new_node->next = tail->next;
    //         tail->next = new_node;
    //         tail = new_node;

    //         return tail;
    //     }
    // }
