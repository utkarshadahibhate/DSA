#include<iostream>
using namespace std;

//Operations on array
/*  1) Traversal
    2) Insertion
    3) Deletion
    4) Searching
    5) Sorting
    6) Updating   */

//creating a class array
class Array{
    //data members
    int size; //Actual size of an array
    int capacity; //capacity of an array
    int lastindex; 
    int element; //element to be added/deleted/searched
    int *ptr; //pointer for dynamic array


    public:
    //function declaration
    Array(); //constructor
    Array(int cap); //constructor with size of array
    void creat_array(int capacity);
    void display_array(Array &arr);
    void insert_in_array(int ele, int index);
    void delete_array(int index, int lastindex);
    void append_inarray(int ele, int capacity);
    int search_in_array(int ele, int cap);
    int sort_array(int cap);
    //void update_array(int ele);
};

//function definition

//Array Creation
Array :: Array(){   //creating a null pointer array
    ptr = NULL;
}

Array :: Array(int cap){
    capacity = cap;
    lastindex = -1;     //Initializing the lastindex data member
    ptr = new int[capacity];    //creating an empty array
}

void Array :: creat_array(int cap){
    if(ptr != NULL){
        delete[] ptr;
    }
    capacity = cap;
    lastindex = -1;     //initializing the lastindex data member
    ptr = new int[capacity];    //creating an empty array
}

// To display an array
void Array :: display_array(Array &arr){    //displaying an array
    for(int i=0; i<capacity; i++){
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
}

// To insert an element in an existing array
void Array :: insert_in_array(int ele, int index){  //To insert an element in an array
    if(index < 0 || index > lastindex){     //To ensure to have a contiguous insertion of elements
        cout<<"Invalid data\n recheck the index bounds! "<<endl;
    }
    else if(lastindex >= capacity - 1){
        cout<<"Array Overflow "<<endl;
    }
    else{
        for(int i=lastindex; i>=index; i--){
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = ele;
        //updating lastindex
        lastindex++;
        cout << "Element inserted at position "<<index<<" successfully...\n";
    }
}

// To delete an element from an existing array
void Array :: delete_array(int index, int lastindex){
    if(index < 0 || index > lastindex){
        cout<<"Invalid data\n recheck the index bounds! "<<endl;
    }else{
        for(int i = index; i>lastindex; i++){
            ptr[i+1] = ptr[i];
        }
        //updating lastindex
        lastindex--;
    }
}

// To append an element in an existing array
void Array :: append_inarray(int ele, int capacity){    //to append an element in the array
    if(lastindex == capacity - 1){      //to check for array overflow
        cout<<"Array overflow ! "<<endl;
    }else{
        ptr[lastindex + 1] = ele;   //appending element 
        lastindex++;        //updating the lastindex
    }
}

// To search an element in an existing array
int Array :: search_in_array(int ele, int cap){
    capacity = cap;
    for(int i=0; i<cap; i++){
        if(ptr[i] == ele){
            return i;
        }
    }
    return -1;
}

// To sort an array (bubble sort)
int Array :: sort_array(int cap){
    capacity = cap;
    int i,j,temp;
    for(i = 0; i < cap; i++){
        for(j = 0; j < cap - i -1; j++){
            if(ptr[j + 1] > ptr[j]){
                //apply swapping
                temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
}

int main(){
    /*  Switch case options for array operations
        1) Create an array - i) without capacity 
                            ii) with capacity 
                            iii) by replacing an existing array
        2) Insert an element.
        3) delete an element.
        4) Append element.
        5) Search an element.
        6) Sort an array.
        7) Display array (after every operation)*/

        Array result; //creating class object
        //Array capacity;

        int choice, size, cap;
        
        while(true)
        {
            cout<<"Enter your choice \nSelect the operation on Array"<<endl;
            cout<<"1.Create Array \n2.Insert an element \n3.Delete an element \n4.Append an element\n5.Search an element \n6.Sort the array \n7.Display the array"<<endl;
            cin>>choice;
    
            //Swich case for options
            switch(choice)
            {
            case 1:
                int choice_1;
                cout<<"To create an array, select one option:\n1.Without capacity \n2.with capacity \n3.By replacing existing one"<<endl;
                cin>>choice_1;
                switch(choice_1)
                    {
                    case 1:
                        cout<<"Creating an array without capacity"<<endl;
                        Array();
                        break;

                    case 2:
                        //int cap;
                        cout<<"Creating with capacity"<<endl;
                        cout<<"Enter a capacity value: ";
                        cin>>size;
                        Array(size);
                        break;

                    case 3:
                        cout<<"By replacing an existing array"<<endl;
                        cout<<"Give a capacity value: ";
                        cin>>cap;
                        result.creat_array(cap);
                        break;

                    default:
                        cout<<"Enter a valid option! "<<endl;
                        break;
                    }
                break;

                case 2:
                    cout<<"To insert an element in an array";
                    int ele, index;
                    cout<<"Give an element and index value : ";
                    cin>>ele>>index;
                    result.insert_in_array(ele,index);
                    break;

                case 3:
                    cout<<"To delete an element from an array";
                    int lastindex,size;
                    cout<<"Give the element's index and size of array";
                    cin>>index>>size;
                    lastindex = size - 1;
                    result.delete_array(index,lastindex);
                    break;

                case 4:
                    cout<<"Append an element"<<endl;
                    cout<<"Give the element and size of array: ";
                    cin>>ele>>size;
                    result.append_inarray(ele,size);
                    break;

                case 5:
                    cout<<"Search an element"<<endl;
                    cout<<"Give an element and size of array: ";
                    cin>>ele>>size;
                    result.search_in_array(ele, size - 1);
                    break;

                case 6:
                    cout<<"Sort the array"<<endl;
                    cout<<"Give the size of array: ";
                    cin>>size;
                    result.sort_array(size-1);
                    break;

                case 7:
                    cout<<"To display array: "<<endl;
                    result.display_array(result);
                    break;
            }
            }

}
