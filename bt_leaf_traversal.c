
/*Leaf traversal is sequence of leaves traversed from left to right.
The problem is to check if leaf traversals of two given Binary Trees are same or not.
e.g Input: Roots of below Binary Trees
      1
	 / \
    2   3
  /   /  \
 4   6    7

     0
	/  \
    5   8
    \  / \
     4 6  7
Output: same
Leaf order traversal of both trees is 4 6 7

NOTE: please enter 2 for inorder after completion of inserting nodes.Enter 1 for inserting childnodes and 0 for not inserting*/
#include<stdio.h>
typedef struct{
int data;
struct node *lc,*rc;
}node;
node *stck[100]={0};
node *que[100]={0};
int f=-1,r=-1;
int top=-1;
int arr1[100];
int arr2[100];
int i=0,j=0;
void push(node *temp){
stck[++top]=temp;
}
node* pop(){
return stck[top--];
}
void addq(node *temp){
    if(f>r){
        r=-1;
        f=-1;
    }
que[++r]=temp;
}
node* delq(){
return que[++f];
}
void insert(node **root){
node *temp,*temp1;
int opt;
*root=(node*)malloc(sizeof(node));
(*root)->lc=NULL;
(*root)->rc=NULL;
printf("Enter the root data\n");
scanf("%d",&((*root)->data));
temp=*root;
addq(temp);
for(;;){
    temp=delq();
    if(!temp)
        break;
    printf("Do you want to enter lc of %d\n",temp->data);
    scanf("%d",&opt);
    if(opt==1){
            temp1=(node*)malloc(sizeof(node));
            temp1->lc=NULL;
            temp1->rc=NULL;
       printf("Enter data\n");
        scanf("%d",&temp1->data);
        temp->lc=temp1;
        addq(temp1);
    }
    printf("Do you want to enter rc of %d\n",temp->data);
    scanf("%d",&opt);
    if(opt==1){
        temp1=(node*)malloc(sizeof(node));
        temp1->lc=NULL;
        temp1->rc=NULL;
        printf("Enter data\n");
        scanf("%d",&temp1->data);
        temp->rc=temp1;
        addq(temp1);
    }
}
}
void inorder(node **root,int seq){
node *temp;
temp=*root;
for(;;){
    for(;temp;temp=temp->lc)
      push(temp);
      temp=pop();
      if(!temp)
        break;
        if(!(temp->rc)&&!(temp->lc)){
                if(seq==1)
            arr1[i++]=temp->data;
                else
                 arr2[j++]=temp->data;
        }

      temp=temp->rc;
}
}
main(){
node **root1,**root2;
int opt,f=0,k;
printf("tree1\n");
while(1){
    printf("Enter 1.insert 2.inorder 3.exit\n");
    scanf("%d",&opt);
    switch(opt){
    case 1:insert(&root1);
           break;
    case 2:inorder(&root1,1);
           break;
    case 3:break;
    }
    if(opt==3)
        break;
}
printf("tree2\n");
while(1){
    printf("Enter 1.insert 2.inorder 3.exit\n");
    scanf("%d",&opt);
    switch(opt){
    case 1:insert(&root2);
           break;
    case 2:inorder(&root2,2);
           break;
    case 3:break;
    }
    if(opt==3)
        break;
}
for(k=0;k<i;k++)
    printf("%d ",arr1[k]);
printf("\n");
for(k=0;k<j;k++)
    printf("%d ",arr2[k]);
for(k=0;k<j;k++){
    if(arr1[k]!=arr2[k]){
        f=1;
        printf("not same\n");
        break;
    }
}
if(f==0)
    printf("same\n");
}
