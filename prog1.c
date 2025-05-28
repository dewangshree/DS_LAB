#include<stdio.h>
#include<stdlib.h>
#define max 2
struct students{
    char name[20];
    char usn[20];
    int age;
    float cgpa;
};
void getdetails(struct students *student){
    printf("enter the name");
    scanf("%s",student->name);
    printf("enter the usn ");
    scanf("%s",student->usn);
    printf("enter age ");
    scanf("%d",&student->age);
    printf("enter the cgpa");
    scanf("%f",&student->cgpa);
}
void display(struct students student[],int n){
for(int i=0;i<n;i++){
    printf("details of student %d \n",i+1);
    printf("name is :- %s \n usn of the student :- %s \n age of the student :- %d\n cgpa of the student is:- %f\n",student[i].name,student[i].usn,student[i].age,student[i].cgpa);

}}
void thersholdcgpadisplay(struct students student[],int n,float thershold){
for(int i=0;i<n;i++){
   if(student[i].cgpa >= thershold){ printf("details of student %d \n",i+1);
    printf("name is :- %s \n usn of the student :- %s \n age of the student :- %d\n cgpa of the student is:- %f\n",student[i].name,student[i].usn,student[i].age,student[i].cgpa);
   }
}

}
void main(){

    struct students student[max];
    for(int i=0;i<max;i++){
        printf("enter detals of student %d \n",i+1);
        getdetails(&student[i]);
    }
    display(student,max);
    float thershold;
    printf("enter the thershold cgpa");
    scanf("%f",&thershold);

    thersholdcgpadisplay(student,max,thershold);
}
