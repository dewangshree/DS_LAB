#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* create(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=data;
    return newnode;
}
struct node* insertpos(struct node* head,int data,int pos){
    if(head==NULL){
        return create(data);
    }
    int n=0;
    struct node *temp1=head;
    while(temp1!=NULL){
        temp1=temp1->next;
        n++;
    }
    if(pos>n){
        printf("enter the valid position\n");
        return head;
    }
    if(pos==1){
          struct node* newnode=create(data);
          newnode->next=head;
          return newnode;
    }
    struct node* temp=head;
    pos--;
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    struct node* newnode=create(data);
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}
struct node* deleterear(struct node* head){
    if(head==NULL){
        printf("list is null");
        return NULL;
    }
    if(head->next==NULL){
        printf("%d is deleted \n",head->data);
        free(head);
        return NULL;
    }
    struct node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    struct node* ptr=temp->next;
    temp->next=NULL;
    printf("%d is deleted \n",ptr->data);
    free(ptr);
    return head;
}
void display(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
struct node* head=NULL;
int data,choice,pos;
while(choice!=4){
    printf("enter 1 for insert  at pos \n 2 for delete rear \n 3 for display \n 4 for exit \n");
    scanf("%d",&choice);
    switch(choice){
        case 1:printf("enter data to insert \n");
               scanf("%d",&data);
               printf("enter the position \n");
               scanf("%d",&pos);
               head=insertpos(head,data,pos);
               break;
        case 2:head=deleterear(head);
               break;
        case 3: display(head);
               break;
        case 4:printf("exiting \n");
               break;       
    }
}

return 0;
}
