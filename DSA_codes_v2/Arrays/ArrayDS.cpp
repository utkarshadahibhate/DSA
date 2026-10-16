#include <iostream>
using namespace std;

class Array
{
    int capacity;
    int lastIndex;
    int *ptr;

public:
    Array();
    Array(int);
    void createArray(int);
    void insertInArray(int, int);
    void deleteFromAnArray(int);
    void appendToArray(int);
    void display_array();
    void sort();

    int search_in_array(int);
};

Array::Array()
{
    ptr = NULL;
}

Array::Array(int cap)
{
    capacity = cap;
    lastIndex = -1;
    ptr = new int[capacity];
    cout << "Array is Created...";
}

void Array::createArray(int cap)
{
    if (ptr != NULL)
    {
        delete[] ptr;
    }
    capacity = cap;
    lastIndex = -1;
    ptr = new int[capacity];
}

void Array::insertInArray(int index, int data)
{
    if (index < 0 || index > lastIndex)
    {
        cout << "Invalid Data";
    }
    else if (lastIndex == capacity - 1)
    {
        cout << "Overflow";
    }
    else
    {
        for (int i = lastIndex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = data;
        lastIndex++;
        cout << "Element inserted at position successfully...";
    }
}

void Array::deleteFromAnArray(int index)
{
    if (index < 0 || index > lastIndex)
    {
        cout << "Invalid Data";
    }
    else
    {
        for (int i = index; i < lastIndex; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        lastIndex--;
        cout << "Element Deleted Successfully..";
    }
}

void Array::appendToArray(int data)
{
    if (lastIndex == capacity - 1)
    {
        cout << "Overflow..";
    }
    else
    {
        ptr[lastIndex + 1] = data;
        lastIndex++;
    }
}

// To display an array
void Array::display_array()
{ // displaying an array
    cout<<"******************"<<endl;
    for (int i = 0; i < capacity; i++)
    {
        cout << ptr[i] << " ";
    }cout<<endl;
}

// To sort an array (bubble sort)
void Array::sort()
{

    int i, j, temp;
    for (i = 0; i < capacity; i++)
    {
        for (j = 0; j < capacity - i - 1; j++)
        {
            if (ptr[j + 1] > ptr[j])
            {
                // apply swapping
                temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
    cout<<"\n*****Sorted Array******"<<endl;
    display_array();
}


int Array :: search_in_array(int ele){
    for(int i=0; i<capacity; i++){
        if(ptr[i] == ele){
            return i;
        }
    }
    return -1;
}

int main()
{
    Array a;
 

    int choice, size, cap, res;

    while (true)
    {
        cout << "\nEnter your choice \nSelect the operation on Array" << endl;
        cout << "\n1.Create Array \n2.Insert an element \n3.Delete an element \n4.Append an element\n5.Search an element \n6.Sort the array \n7.Display the array \n8.Exit......."<< endl;
        cin >> choice;
          int data, index;
        switch (choice)
        {
        case 1:
            cout << "\nEnter the Size of array or -1 to skip : ";
            cin >> size;
            if (size > 0)
            {
                a.createArray(size);
            }
            else
            {
                a = Array(5);
            }
            break;

        case 2:
            cout << "\nEnter Index Position :";
            cin >> index;
            cout << "Enter Data : ";
            cin >> data;
            a.insertInArray(index, data);
            break;

        case 3:
            cout << "\nEnter Index Position :";
            cin >> index;
            a.deleteFromAnArray(index);
            break;

        case 4:
            cout << "\nEnter Data : ";
            cin >> data;
            a.appendToArray(data);
            break;

        case 5:
            cout << "\nEnter Data to search: ";
            cin >> data;
            res = a.search_in_array(data);
            if(res > 0){
            cout<<"\nElement found at location "<<res+1;
            }else{
            cout<<"Element Not found\n";

    }
            break;

        case 6:
            a.sort();
            break;

        case 7:
            a.display_array();
            break;

        case 8:
            goto exit;
            break;

        default:
            cout<<"\nEnter a valid choice ...";
            break;
        }
    }

    exit:
    cout<<"\nExit......"<<endl;
  
    return 0;
}
