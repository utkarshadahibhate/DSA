#include<iostream>
using namespace std;

int main(){
    int A[6] ={6,3,8,2,9,1};
    int i,j,temp;
    bool isSwapped = false; //flag
    int n = sizeof(A)/sizeof(A[0]);

    //before sorting
    for(i=0; i<n; i++){
        cout<<A[i]<<" ";
    }

    for(i=0; i<n; i++){
        //cout<<"iteration : "<<i<<" ";
        isSwapped = false;
        for(j=0; j<n-i-1; j++){
            //cout<<"iteration : "<<j<<" ";
            if(A[j] > A[j + 1]){
                isSwapped = true;
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
        if(!isSwapped){
            break;
        }
    }

    //After sorting
    cout<<endl;
    for(i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}