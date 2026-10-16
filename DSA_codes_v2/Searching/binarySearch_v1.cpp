#include<iostream>
using namespace std;

int  bin_search(int arr[], int start, int end, int key){
    while(start <= end){
        int mid = (start + end)/2;

        if(key == arr[mid]){
            return mid;
        }
        else if(key < arr[mid]){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return -1;
}

int main(){
    int A[11] = {10,20,30,40,50,60,70,80,90,100,110};
    int start = 0;
    int end = 10;
    int key;
    int mid;

    cout<<"Give a key value to search for : "<<endl;
    cin>>key;
    int found = 0;
    while(start <= end){
        mid = (start + end)/2;
        
        if(A[mid] == key){
            cout<<"Value found at: "<<mid<<"\nAnd it is: "<<A[mid]<<endl;
            found =1;
            goto ans;
            break;
        }
        else if(key>A[mid]){
            start = mid + 1;
        }
        else if(key<A[mid]){
            end = mid - 1;
        }
    
    }
    cout<<"Value not found !"<<endl;
    if(found){
        ans :
        cout<<"Value found at "<<mid;
        //cout<<"Value not found !"<<endl;
    }

    // int result = bin_search(A,start,end,key);

    // if(result>0){
    //     cout<<"\nValue found at position : "<<result<<" it is: "<<A[result]<<endl;
    // }
    // else{
    //     cout<<"\nValue not found!,  try another key value"<<endl;
    // }

}
