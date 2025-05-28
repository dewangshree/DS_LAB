#include<stdio.h>
#include<stdlib.h>
void getdetails(float marks[],int n){
    for(int i=0;i<n;i++){
        printf("Enter the marks of student %d:-\n",i+1);
        scanf("%f",&marks[i]);
        }    }
    void displaymarks(float marks[],int n){
   for(int i=0;i<n;i++){
    printf("Marks of student %d is :- %f ",i+1,marks[i]);
   }
    }
    void main(){
        int n;
        printf("enter the number of students \n");
        scanf("%d",&n);
        float *marks;
        marks=(float *)malloc(n*sizeof(float));
        getdetails(marks,n);
        displaymarks(marks,n);
        char choice;
        printf("you want enter more student details then give inpuct Y , y");
        scanf(" %c",&choice);
        if(choice == 'Y' || choice == 'y'){
            printf("enter number of extra students \n");
            int extra;
            scanf("%d",&extra);
            marks= (float *)realloc(marks,(n+extra)*sizeof(float));
            getdetails(marks+n,extra);
            int newsize=n+extra;
            displaymarks(marks,newsize);

        }
    }
