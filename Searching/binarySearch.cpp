#include<iostream>

using namespace std;

int binarySearch(int arr[],int start, int end,int key){
    int mid;

    if(end>=start){
        mid = (start+end)/2;


        if(arr[mid]==key){
            return mid;
        }else if(key>arr[mid]){
            binarySearch(arr,mid+1,end,key);
        }else{
            binarySearch(arr,start,mid-1,key);

        }
    }else{
        return -1;
    }
}


int main(){

    int arr[5] = {1,22,33,44,55};

    int res= binarySearch(arr,0,4,55);
    cout<<res<<endl;
    if(res>0){
        cout<<"Element Found At "<<res<<endl;
    }else{
        cout<<"Element Not Found."<<endl;
        
    }
}