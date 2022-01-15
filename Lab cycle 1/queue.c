
#include<stdio.h>
#include<stdlib.h>
#define size 4
void insert();
void delete();
void traversal();
void search();
int rear=-1,front=-1;

int queue[size],item;

void main()
{
int c;
while(1)
{
printf("\n1.insert\n2.delete\n3.traversal\n4.search\n5.exit");
printf("\nenter the case number:");
scanf("%d",&c);
switch(c)
{
case 1:insert();
break;
case 2:delete();
break;
case 3:traversal();
break;
case 4:search();
break;
case 5:exit(0);
break;
}
}
}


void insert()
{

if(front==(rear+1)%size)
{
printf("overflow");
return;
}
 if(front==-1 && rear==-1)
{
 front=front+1;
 rear=0;

}
else
rear=(rear+1)%size;

printf("enter the element");
scanf("%d",&item);
queue[rear]=item;
}

void delete()
{
 if(front==-1 && rear==-1)
    {
    printf("underflow");
    return;
    }
 else if(front == rear)
  {

 item=queue[front];
 front=rear=-1;
 }

else
{
item=queue[front];
front=(front+1)%size;
}
}



void traversal()
{
if(front==-1 && rear==-1)
{
printf("queue empty");
}
else
{
for(int i=front;i<=rear;i++)
 printf("\t%d",queue[i]);
}
}
void search()
{
    int key,flag=0,i;
 printf("\nEnter element to search: ");
    scanf("%d", &key);
    for(i=front; i<=rear; i++)
    {

        if(queue[i] == key)
        {
            flag = 1;
            break;
        }
    }
    if(flag==1)
    printf("element is found at position%d",i+1);
    else
    printf("element not found ");
}
