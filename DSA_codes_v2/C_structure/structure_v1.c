#include<stdio.h>
#include<string.h>

typedef struct employee{
    int id;
    char name[50];
}emp; //declaring e1 variable/object of struct



int main(){
    //storing employee information
    emp e1;
    e1.id = 2011;
    strcpy(e1.name, "kelly"); //copying the string

    //displaying the information
    printf("\nwithout pointer-- \n");
    printf("Employee id : %d\n", e1.id);
    printf("Employee name : %s\n", e1.name);
    printf("\n");

    //using a struct pointer
   emp *e2 = &e1;
    
    //displaying the information
    printf("\nwith pointer-- \n");
    printf("Employee id : %d\n", e2->id);
    printf("Employee name : %s\n", e2->name);

    //copying the structure
    emp e3 = e1;

    //displaying the information
    printf("\nwith copy structure object-- \n");
    printf("Employee id : %d\n", e3.id);
    printf("Employee name : %s\n", e3.name);

    return 0;
}