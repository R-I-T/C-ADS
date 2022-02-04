#include<stdio.h>
#include<stdlib.h>
struct node{
 struct node *rep;
 struct node *next;
 int data;
}*heads[50],*tails[50];
static int countRooot=0;
void makeSet(int x){
struct node *new=(struct node *)malloc(sizeof(struct node));
new->rep=new;
new->next=NULL;
new->data=x;
heads[countRooot]=new;
tails[countRooot++]=new;
}
struct node* fnd(int a){
int i;
struct node *tmp=(struct node *)malloc(sizeof(struct node));
for(i=0;i<countRooot;i++){
tmp=heads[i];
while(tmp!=NULL){
if(tmp->data==a)
return tmp->rep;
tmp=tmp->next;
}
}
return NULL;
}
void unionSets(int a,int b){
int i,pos,flag=0,j;
struct node *tail2=(struct node *)malloc(sizeof(struct node));
struct node *rep1=fnd(a);
struct node *rep2=fnd(b);
if(rep1==NULL||rep2==NULL){
printf("Element not present in the DS");
return;
}
if(rep1!=rep2){
for(j=0;j<countRooot;j++){
if(heads[j]==rep2){
pos=j;
flag=1;
countRooot-=1;
tail2=tails[j];
for(i=pos;i<countRooot;i++){
heads[i]=heads[i+1];
tails[i]=tails[i+1];
}}
if(flag==1)
break;
}
for(j=0;j<countRooot;j++){
if(heads[j]==rep1){
tails[j]->next=rep2;
tails[j]=tail2;
break;
}}
while(rep2!=NULL){
rep2->rep=rep1;
rep2=rep2->next;
}}}
int search(int x){
int i;
struct node *tmp=(struct node *)malloc(sizeof(struct node));
for(i=0;i<countRooot;i++){
tmp=heads[i];
if(heads[i]->data==x)
return 1;
while(tmp!=NULL){
if(tmp->data==x)
return 1;
tmp=tmp->next;
}}
return 0;
}
void main(){
int choice,x,i,j,y,flag=0;
do{
printf("\n.......MENU.......1.Make Set......2.Display set
representatives.....3.Union.....4.Find Set....5.Exit....");
printf("\nEnter your choice : ");
scanf("%d",&choice);
switch(choice){
case 1:
printf("Enter new element : ");
scanf("%d",&x);
if(search(x)==1)
printf("Element already present in the disjoint set DS");
else
makeSet(x);
break;
case 2:
for(i=0;i<countRooot;i++)
printf("%d ",heads[i]->data);
break;
case 3:
printf("Enter frst element : ");
scanf("%d",&x);
printf("Enter second element : ");
scanf("%d",&y);
unionSets(x,y);
break;
case 4:
printf("Enter the element");
scanf("%d",&x);
struct node *rep=(struct node *)malloc(sizeof(struct node));
rep=fnd(x);
if(rep==NULL)
printf("\nElement not present in the DS");
else
printf("\nThe representative of %d is %d",x,rep->data);
break;
case 5:
exit(0);
default:
printf("\nWrong choice");
break;
}}
while(1);
 };