#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 10
struct stack{
    int top;
    int arr[max];
};
// int isempty(struct stack *st){
//     if(st->top==-1){
       
//     return 1;}
//     return 0;
// }
// int isfull(struct stack *st){
//     if (st->top == max-1){
        
//         return 1;
//     }
//     return 0;
// }
void push(struct stack *st,int data){
    if(st->top == max-1){
     printf("stack is full\n");
    }
    else{
        st->top++;
        st->arr[st->top]=data;
    }
}
void pop(struct stack *st){
    if(st->top ==-1){
 printf("EMPTYYY\n");
    }
    else{
        printf("%d is poped \n",st->arr[st->top--]);

    }
}
void display(struct stack *st){
    if(st->top ==-1){
 printf("EMPTYYY\n");
    }
    else{
    for(int i=st->top;i>=0;i--){
        printf("%d ",st->arr[i]);
    }}

}
void main(){
    struct stack st;
    st.top=-1;
    int element,choice;
    while (choice != 4) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(&st, element);
                break;
            case 2:
                pop(&st);
                break;
            case 3:
                display(&st);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    } 

    //return 0;
}
