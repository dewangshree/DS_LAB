#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* crete(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
struct node* push(struct node* head,int data){
    if(head==NULL){
        return crete(data);
    }
    struct node* newnode=crete(data);
    newnode->next=head;
    return newnode;
}
struct node* pop(struct node* head){
    if(head==NULL){
        printf("stack is empty");
        return NULL;
    }
    if(head->next==NULL){
        printf("%d is poped \n",head->data);
        free(head);
        return NULL;
    }
    struct node* temp=head->next;
     printf("%d is poped \n",head->data);
     free(head);
     return temp;
}
void display(struct node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
void main(){
    struct node* head=NULL;
  int data,choice;
   while(choice!=4){
    printf("enter 1 for push \n 2 for pop \n 3 for dispaly\n 4 for exit \n");
    scanf("%d",&choice);
    switch(choice){
        case 1: printf("enter data to push\n");
                scanf("%d",&data);
                head=push(head,data);
                break;
        case 2: head=pop(head);
                break;
        case 3: display(head);
                break;
        case 4: printf("Exiting the program");
         break;                
    }
   }
}
