#include<iostream>

using namespace std;

int linearSearch(int arr[],int size,int key){
    int i=0;
    for(i=0;i<size;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}


int main(){
    int data[6] = {10,45,2,99,7,21};
    int res = linearSearch(data,6,9);
    if(res > 0){
        cout<<"Element found at location "<<res+1;
    }else{
        cout<<"Element Not found";

    }
}