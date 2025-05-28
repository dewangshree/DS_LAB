#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* front=NULL;
struct node* rear=NULL;
struct node* create(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
struct node* enque(struct node* head,int data){
if(front==NULL && rear==NULL ){
    front=rear=create(data);
    return front;
}
else{
    struct node* newnode= create(data);
    rear->next=newnode;
    rear=newnode;
    return head;
}
}
struct node* dequeue(struct node* head){
    // if(head==NULL){
    //     printf("emptyyyy\n");
    //     return NULL;
    // }
    if(front==NULL){
        printf("queue is empty\n");
        return NULL;
    }
    else{
        struct node* temp=front;
        front=front->next;
        printf("%d is deleted \n",temp->data);
        free(temp);
        return front;
    }
}
void display(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void main(){
    struct node* head=NULL;
   int data,choice;
   while(choice!=4){
    printf("enter 1 for enque \n 2 for dequeue\n 3 for dispaly\n 4 for exit \n");
    scanf("%d",&choice);
    switch(choice){
        case 1: printf("enter data to insert\n");
                scanf("%d",&data);
                head=enque(head,data);
                break;
        case 2: head=dequeue(head);
                break;
        case 3: display(head);
                break;
        case 4: printf("Exiting the program");
         break;                
    }
   }
}
