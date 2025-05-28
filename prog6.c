#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define max 200
 struct Stack{
    int top;
    int items[max];
 };

 void push(struct Stack *st,int data){
    if(st->top==max-1){
        printf("FULL");

    }
    else{
        st->top++;
        st->items[st->top]=data;
    }
 }
 int pop(struct Stack *st){
    if(st->top ==-1){
        printf("empty");
        return 0;
    }
    return st->items[st->top--];
 }
 int postfixeval(char postfix[]){
   struct Stack st;
   st.top=-1;
   char data;
   int op1,op2,result;
   for(int i=0;i<strlen(postfix);i++){
    data=postfix[i];
    if(isalnum(data)){
        push(&st, data -'0');
    }
   
   else{
    op2=pop(&st);
    op1=pop(&st);
    switch(data){
        case '+': push(&st,op1+op2);
                  break;
        case '-': push(&st,op1-op2);
                  break;
        case '*': push(&st,op1*op2);
                  break;
        case '/': push(&st,op1/op2);
                 break;                              
    }
   }}
   return pop(&st);
 }
 void main(){
    char postfix[40];
    printf("enter the postfix");
    scanf("%s",postfix);
    int data=postfixeval(postfix);
    printf("%d is ans",data);
 }
