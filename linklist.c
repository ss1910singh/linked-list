#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};


int i;
struct node *head,*temp,*temp1,*new_node;
void creation();
void insert();
void delete();
void display();
void beginning();
void end();
void after();
void before();
void first();
void last();
void spe();


int main()
{
    int choice;
    while(1)
    {
        printf("Operation to be performed on Linklist:-\n1.creation\n2.insert\n3.delete\n4.display\n5.exit\nenter your choise:-");
        scanf("%d",&choice);
        switch(choice)
        {
         case 1:
            creation();
            break;
        case 2:
            insert();
            break;
        case 3:
            delete();
            break;
       case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nInvalid choice!!");
        }
    }
    return 0;
}

void display()
{   if(head==0)
    {
        printf("No Node present\n");
    }
    else
    {
    temp=head;
    while (temp->next!=0)
    {
        printf(" %d ",temp->data);
        temp=temp->next;
    }
    printf(" %d ",temp->data);
    }
    printf("\n");
}

void creation()
{
do
{
new_node=(struct node*)malloc(sizeof(struct node));
new_node->next=0;
printf("Enter data:-");
scanf("%d",&new_node->data);
if(head==0)
{
    head=temp=new_node;
}
else
{
temp->next=new_node;
temp=new_node;
}
printf("To continue press 1 else press 2:-");
scanf("%d",&i);
} while (i!=2);
}

void insert()
{
    int i;
    do
    {
        int choice;
    printf("Enter where new node to be added:-\n1.At beginning\n2.At end\n3.Insertion after a specific node\n4.Insertion before a specific node\nEnter ur choice:-");
    scanf("%d",&choice);
    switch(choice)
        {
         case 1:
            beginning();
            break;
        case 2:
            end();
            break;
        case 3:
            after();
            break;
       case 4:
            before();
            break;
        default:
            printf("\nInvalid choice!!");
        }
        printf("To continue press 1 else press 2:-");
        scanf("%d",&i);
    } while (i!=2);
    
}

void beginning()
{
new_node=(struct node*)malloc(sizeof(struct node));
printf("Enter data:-");
scanf("%d",&new_node->data);
if(head==0)
{
    head=new_node;
    new_node->next=0;
}
else
{
new_node->next=head;
head=new_node;
}  
}

void end()
{
new_node=(struct node*)malloc(sizeof(struct node));
new_node->next=0;
printf("Enter data:-");
scanf("%d",&new_node->data);
if(head==0)
{
    head=new_node;
    new_node->next=0;
}
else
{
temp=head;
while (temp->next!=0)
{
    temp=temp->next;
}
temp->next=new_node;
}
}

void after()
{
int val;
new_node=(struct node*)malloc(sizeof(struct node));
new_node->next=0;
printf("Enter data of new node:-");
scanf("%d",&new_node->data);
if(head==0)
{
    head=new_node;
    new_node->next=0;
}
else
{
    temp=head;
    printf("\nenter data after which new node to be inserted:-");
    scanf("%d",&val);
    while (temp->data!=val)
    {
        temp=temp->next;
    }
    temp1=temp->next;
    new_node->next=temp1;
    temp->next=new_node;
} 
}

void before()
{
int val;
new_node=(struct node*)malloc(sizeof(struct node));
new_node->next=0;
printf("Enter data:-");
scanf("%d",&new_node->data);
if(head==0)
{
    head=new_node;
    new_node->next=0;
}
else
{
    printf("\nenter data after which new node to be inserted:-");
    scanf("%d",&val);
    temp=head;
    while (temp->data!=val)
    {
        temp1=temp;
        temp=temp->next;
    }
    new_node->next=temp;
    temp1->next=new_node;
} 
}

void delete()
{
    int choice;
    int i;
    do
    {
    printf("which node you want to delete:-\n1.First node\n2.Last node\n3.Specific node\nEnter your choice:-");
    scanf("%d",&choice);
    switch(choice)
        {
         case 1:
            first();
            break;
        case 2:
            last();
            break;
        case 3:
             spe();
            break;
        default:
            printf("\nInvalid choice!!");
        }
        printf("To continue press 1 else press 2:-");
        scanf("%d",&i);
    } while (i!=2);
    
}

void first()
{
if(head==0)
{
    printf("no node present\n");
}
else
{
    temp=head;
    head=temp->next;
    free(temp);
}
}

void last()
{
    temp1=temp=head; 
    if(head==0)
    {
        printf("no node present\n");
    }
    else
    {
    while(temp->next!=0)
    {
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=0;
    free(temp);
    }
}

void spe()
{
    if(head==0)
    {
         printf("no node present\n");
    }
    else
    {
        temp=head;
        int val;
         printf("Enter vale of a node to be deleted:-");
         scanf("%d",&val);
         printf("\n");
        while(temp->data!=val)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=temp->next;
        free(temp);
    }
}