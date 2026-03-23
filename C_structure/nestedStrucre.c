#include<stdio.h>
#include<string.h>

// Nested Separate
struct address
{
    char city[20],state[20],country[20];
};


struct student{

    int id;
    char name[30];

    // Nested Embedded
    struct dob{
        int date;
        int month;
        int year;
    } d1;
    struct address a1;
    struct student *partner;
};




void show(struct student s){
    printf("Student ID : %d\n",s.id);
    printf("Student Name : %s\n",s.name);
    printf("Student's DOB : %d/%d/%d\n",s.d1.date,s.d1.month,s.d1.year);
    printf("Student's Address : %s, %s, %s\n",s.a1.city,s.a1.state,s.a1.country);
    printf("Partner Name : %s",s.partner->name);
}


int main(){
    struct student s1;
    struct student s2;

    s1.id = 101;
    strcpy(s1.name,"jhon");
    s1.d1.date = 12;
    s1.d1.month = 12;
    s1.d1.year = 2012;
    strcpy(s1.a1.city,"pune");
    strcpy(s1.a1.state,"MH");
    strcpy(s1.a1.country,"India");
    s1.partner = &s2;


     s2.id = 102;
    strcpy(s2.name,"jane");
    s2.d1.date = 13;
    s2.d1.month = 13;
    s2.d1.year = 2013;
    strcpy(s2.a1.city,"mumbai");
    strcpy(s2.a1.state,"MH");
    strcpy(s2.a1.country,"India");
    s2.partner = &s1;

    show(s1);

    printf("\n---------------\n");
    show(s2);

}


