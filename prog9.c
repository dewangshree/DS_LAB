#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
int data;
struct node* next;
};
struct node* create(int data){
struct node* newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=NULL;
return newnode;
}
struct node* inserthead(struct node* head,int data){
if(head==NULL){
    return create(data);
}
struct node* newnode=create(data);
newnode->next=head;
head=newnode;
return head;
}
struct node* deletenode(struct node* head,int item){
    struct node *temp=head;
    struct node* prev=NULL;
    if (temp->data == item) {
        head = temp->next; // Changed head
        printf("%d item is deleted \n", temp->data);
        free(temp);
        return head;
    }
    while (temp!=NULL && temp->data!=item)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("element not present \n");
        return head;
    }
     prev->next=temp->next;
        printf("%d item is deleted \n",temp->data);
        free(temp);
    return head;
    
}
void display(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void main(){
    struct node* head;
    head=NULL;
    int choice=0,data,item;
    while(choice!=4){
        printf("enter 1 for insert at front \n 2 for delete node of given element \n 3 for display\n 4 for exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("enter data to insert ");
                    scanf("%d",&data);
                    head=inserthead(head,data);
                    break;
            case 2: printf("enter item to delete ");
                    scanf("%d",&item);
                    head=deletenode(head,item);
                    break;
            case 3: display(head);  
                    break;
            case 4: printf("Exiting the program.\n");
                    exit(0);
            default: printf("Invalid choice. Please enter a number between 1 and 4.\n");
                    break;

        }
    }
}
