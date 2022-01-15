#include<stdio.h>
#include<stdlib.h>

struct node
	{
	int data;
	struct node*link;
	}*top=NULL;

void push();
void pop();
void traversal();
void search();

void main()
{
int c;
while(1)
{
printf("\n1.push\n2.pop\n3.traversal\n4.search\n5.exit");
printf("\nenter the case number:");
scanf("%d",&c);
switch(c)
{
case 1:push();
break;
case 2:pop();
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

//push
void push()
{
struct node*new;
new=(struct node*)malloc(sizeof(struct node));
if(new==NULL)
{
printf("memory out of space");
exit(0);
}
else
{
printf("enter the data");
scanf("%d",&new->data);
new->link=NULL;
if(top==NULL)
top=new;
else
{
new->link=top;
top=new;
}
}
}
//pop
void pop()

{
struct node *temp;
if(top==NULL)
{
printf("stack underflow");
return;
}
temp=top;
top=top->link;
temp->link=NULL;
free(temp);
}

void search()
{
struct node*temp;
int value,pos=1,flag=0;
printf("enter the value");
scanf("%d",&value);
temp=top;
while(temp!=NULL)
{
if(value==temp->data)
{
printf("found at position %d",pos);
flag=1;
}
pos++;
temp=temp->link;
}
if(flag==0)
printf("value is not found\n");
}

//traversal
void traversal()
{
struct node *temp;
if(top==NULL)
printf("list is empty");
temp=top;
while(temp!=NULL)
{
printf("%d\t",temp->data);
temp=temp->link;
}
}
