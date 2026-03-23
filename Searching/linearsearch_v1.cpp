#include<iostream>
using namespace std;

int Search_char(char arr[], int size, char alpha){
    for(int i = 0; i < size; i++){
        if(arr[i] == alpha){
            return i;
        }
    }
    return -1;
}

int main(){
    char A[] = {'A','B','C','D','E','F'};
    int size = sizeof(A)/sizeof(A[0]);

    // for(int i = 0; i < size; i++){
    //     if(A[i] == 'B'){
    //         cout<<A[i]<<endl;
    //     }
    // }

    //calling the function
    int letter_index = Search_char(A, size, 'L');
    if(letter_index != -1){
        cout<<"The present letter is present at : "<<letter_index<<endl;
        cout<<"The present letter is : "<<A[letter_index]<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }

}