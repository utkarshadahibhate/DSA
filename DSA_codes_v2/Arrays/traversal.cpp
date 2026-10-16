#include<iostream>
using namespace std;

int array_traverse(int arr[], int size){
    //int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"Traversing the array elements : "<<endl;
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int A[10] = {10,20,30,40,50,60,70,80,90,100};
    int size = sizeof(A) / sizeof(A[0]);

    // cout<<"Traversing the array elements : "<<endl;

    // for(int i = 0; i < size; i++){
    //     cout<<A[i]<<" ";
    // }

    //calling the function
    array_traverse(A, size);


}