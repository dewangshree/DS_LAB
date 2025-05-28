#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* create(int data){
 struct node* newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=data;
 newnode->next=NULL;
 newnode->prev=NULL;
 return newnode;
}
struct node* insertrear(struct node* head,int data){
    if(head==NULL){
       return create(data);
    }
    struct node* temp=head;
    struct node* newnode=create(data);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    return head;
    
}
struct node* deletefront(struct node* head){
    if(head==NULL){
        printf("empty\n");
        return NULL;
    }
    if(head->next==NULL){
        printf("%d is deleted \n",head->data);
        free(head);
        return NULL;
    }
    struct node* temp=head;
    struct node* ptr=temp->next;
    ptr->prev=NULL;
    printf("%d is deleted \n",temp->data);
    free(temp);
    head=ptr;
    return head;
}
void display(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
struct node* head=NULL;
int data,choice;
while(choice!=4){
    printf("enter 1 for insert  rear \n 2 for delete front \n 3 for display \n 4 for exit \n");
    scanf("%d",&choice);
    switch(choice){
        case 1:printf("enter data to insert \n");
               scanf("%d",&data);
               head=insertrear(head,data);
               break;
        case 2:head=deletefront(head);
               break;
        case 3: display(head);
               break;
        case 4:printf("exiting \n");
               break;       
    }
}

return 0;
}
