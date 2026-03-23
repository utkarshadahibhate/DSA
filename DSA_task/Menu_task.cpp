#include<iostream>
using namespace std;

//Displaying an array
void display_arr(int arr[], int size){
    //cout<<"Printing array elements --"<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//Sorting an array (bubble sort)
int bubble_sort(int arr[], int size){
    int i,j,temp;
    for(i=0; i<size; i++){
        for(j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
//Searching element in an array (linear search)
int linear_search(int arr[], int size, int key){
    for(int i=0; i<size; i++){
        if(key == arr[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int A[6] = {30,60,40,10,50,20};
    // bubble_sort(A,6);
    // linear_search(A,6,44);
    // display_arr(A,6);

    //cout<<"Enter a ";
    int choice,result;

    while (true)
    {
        cout<<"\n1.Display \n2.Sorting \n3.Searching\n4.Exit\n"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            display_arr(A,6);
            break;
        case 2:
            cout<<"\nSorting the array :"<<endl;
            display_arr(A,6);
            result = bubble_sort(A,6);
            display_arr(A,6);
            break;
        case 3:
            int key;
            cout<<"\nEnter a value to be searched for : ";
            cin>>key;
            result = linear_search(A,6,key);
            if(result == -1){
                cout<<"\nElement is not present in the array"<<endl;
            }
            else{
                cout<<"\nElement is present at position : "<<result<<endl;
            }
            break;
        case 4:
        goto last;
        break;
        default:
        cout<<"Enter a valid menu number!"<<endl;
        break;
    }

    }

    last:
    cout<<"Exit..."<<endl;
    
}