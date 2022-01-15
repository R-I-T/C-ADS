#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    struct node *next;
    int data;
};
struct node *head;
void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
void display();
void search();
void main ()
{
int c ;
    while(1)
    {
     printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete from random location\n7.Search\n8.display\n9.Exit");
        printf("\nEnter your choice?");
        scanf("\n%d",&c);
        switch(c)
        {
            case 1:
            insertion_beginning();
            break;
            case 2:
                    insertion_last();
            break;
            case 3:
            insertion_specified();
            break;
           case 4:
            deletion_beginning();
            break;
            case 5:
            deletion_last();
            break;
            case 6:
            deletion_specified();
            break; 
            case 7:
            search();
            break;
            case 8:
            display();
            break;
            case 9:
            exit(0);
            break;
            default:
            printf("Please enter valid choice..");
        }
    }
}
void insertion_beginning()
{
   struct node *new;
   int item;
  new = (struct node *)malloc(sizeof(struct node));
   if(new == NULL)
   {
       printf("memory out of space");
   }
   else
   {
    printf("\nEnter Item value");
    scanf("%d",&item);

   if(head==NULL)
   {
       new->next = NULL;
      new->prev=NULL;
       new->data=item;
       head=new;
   }
   else
   {
       new->data=item;
      new->prev=NULL;
       new->next = head;
       head->prev=new;
       head=new;
   }
   printf("\nNode inserted\n");
}

}
void insertion_last()
{
   struct node *new,*temp;
   int item;
   new = (struct node *) malloc(sizeof(struct node));
   if(new == NULL)
   {
       printf("memory out of space");
   }
   else
   {
       printf("\nEnter value");
       scanf("%d",&item);
        new->data=item;
       if(head == NULL)
       {
           new->next = NULL;
          new->prev = NULL;
           head = new;
       }
       else
       {
          temp = head;
          while(temp->next!=NULL)
          {
              temp = temp->next;
          }
          temp->next = new;
          new ->prev=temp;
         new->next = NULL;
          }

       }
     printf("\nnode inserted\n");
    }
void insertion_specified()
{
   struct node *new,*temp;
   int item,loc,i;
  new= (struct node *)malloc(sizeof(struct node));
   if(new == NULL)
   {
       printf("memory out of space");
   }
   else
   {
       temp=head;
       printf("Enter the location");
       scanf("%d",&loc);
       for(i=1;i< loc-1;i++)
       {
           temp = temp->next;
           if(temp == NULL)
           {
               printf("\n There are less than %d elements", loc);
               return;
           }
       }
    printf("Enter value");
       scanf("%d",&item);
       new->data = item;
       new->next = temp->next;//points new node to node after temp 
       new-> prev = temp;//new node points to next
       temp->next = new;//temp points to new node
       temp->next->prev=new;//node after temp points to new node
       printf("\nnode inserted\n");


   }
}
void deletion_beginning()
{
    struct node *new;
    if(head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if(head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }
    else
    {
        new = head;
        head = head -> next;
        head -> prev = NULL;
        free(new);
        printf("\nnode deleted\n");
    }

}
void deletion_last()
{
    struct node *new;
    if(head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if(head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }
    else
    {
        new = head;
        while(new->next != NULL)
        {            new =new -> next;
        }
        new-> prev -> next = NULL;//secondlast node next null
        free(new);
        printf("\nnode deleted\n");
    }
}
void deletion_specified()
{
    struct node *del, *temp;
    int pos,i;
   printf("enter the position to be deleted");
    scanf("%d", &pos);
i=1;
    del = head;
    while(del ->next != NULL){
if(i==pos)
  break;
i++;
temp=del;
del=del->next;
}
  temp->next=del->next;
free(del);
   printf("\nnode deleted\n");
}
  void display()
{
    struct node *ptr;
    ptr = head;
    if(ptr==NULL)
    printf("list is empty");
    else{
    printf("\n printing values...\n");
    
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    }
}
void search()
{
    struct node *ptr;
    int item,i=0,flag;
    ptr = head;
    if(ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d",&item);
        while (ptr!=NULL)
        {
            if(ptr->data == item)
            {
                printf("\nitem found at location %d ",i+1);
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        if(flag==1)
        {
            printf("\nItem not found\n");
        }
    }

}


