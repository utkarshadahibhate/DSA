#include<stdio.h>
#include<string.h>

struct Student{
    int id;
    char name[30];
    float marks;
};


int main(){

    struct Student s1;


    s1.id = 101;
    strcpy(s1.name,"jhon");
     
    s1.marks = 90.5;

    printf("ID :%d\n",s1.id);
    printf("ID :%s\n",s1.name);
    printf("ID :%f\n",s1.marks);
}