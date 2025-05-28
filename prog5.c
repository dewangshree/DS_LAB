#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 15
struct Stack{
    char item[max];
    int top;
};
int input(char op){
    switch(op){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '^':
        case '$': return 6;
        case '(': return 9;
        case ')': return 0;
        default: printf("envalid");
    }
}
int stack(char op){
    switch(op){
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '$':
        case '^': return 5;
        case '(': return 0;
        case '#': return -1;
    }
}
void push(struct Stack *st,int ele){
    if(st->top==max-1){
        printf("FULL");
    }
    else{
        st->top++;
        st->item[st->top]=ele;
    }
}
int pop(struct Stack *st){
    if(st->top==-1){
        printf("empty");
        return 0;
    }
    return st->item[st->top--];
}
void infixtopostfix(char infix[],char postfix[]){
    struct Stack st;
    st.top=-1;
    push(&st,'#');
    int i=0,j=0;
    char symb,data;
    for(i=0;i<strlen(infix);i++){
        symb=infix[i];
        if(isalnum(symb)){
            postfix[j]=infix[i];
            j++;
        }
        else{
            while(input(infix[i]) < stack(st.item[st.top])){
                data=pop(&st);
                postfix[j]=data;
                j++;
            }
            if(input(infix[i]) != stack(st.item[st.top])){
                push(&st,symb);
            }
        
        else{
            symb=pop(&st);
        }
    }}
    while(st.item[st.top]!='#'){
        data=pop(&st);
        postfix[j]=data;
        j++;
    }
    postfix[j]='\0';

}
void main(){
    char infix[200], postfix[200];
    printf("enter infix expn");
    scanf("%s",infix);
    infixtopostfix(infix,postfix);
    printf(" post fix exprn of %s is :- %s ",infix,postfix);
}
