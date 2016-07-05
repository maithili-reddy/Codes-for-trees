/*This is a C program for the implementation of a basic tree. After constructing the tree using insert operation,
Levelorder,inorder traversals of tree is displayed based on the option choosen.*/

#include<stdio.h>
typedef struct{
int data;
struct node *lc,*rc;
}node;
node *que[100]={0};
node *stck[100]={0};
int f=-1,r=-1,top=-1;
void push(node *temp){
stck[++top]=temp;
}
node* del(){
return stck[top--];
}
void addq(node *temp){
    if(f>r)
        r=-1;
que[++r]=temp;

}
node* pop(){

    if(f>r)
        f=-1;
return que[++f];
}
void levelorder(node *root){
node *temp;
temp=root;
addq(temp);
while(1){
    temp=pop();
    if(!temp)
        break;
    printf("%d ",temp->data);
    if(temp->lc)
        addq(temp->lc);
    if(temp->rc)
        addq(temp->rc);
}
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
while(1){
    temp=pop();
    if(!temp)
        break;
    printf("Do you want to enter lc of %d\n",temp->data);
    scanf("%d",&opt);
    if(opt==1){
        temp1=(node*)malloc(sizeof(node));
        temp1->lc=NULL;
        temp1->rc=NULL;
        printf("Enter data\n");
        scanf("%d",&(temp1->data));
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
        scanf("%d",&(temp1->data));
        temp->rc=temp1;
        addq(temp1);
    }
}
}
void inorder(node *root){
node *temp;
temp=root;
for(;;){
while(temp){
    push(temp);
    temp=temp->lc;
}
temp=del();
if(!temp)
    break;
printf("%d ",temp->data);
temp=temp->rc;
}
}
main(){
node **root=NULL;
int opt;
while(1){
    printf("Enter 1.insert 2.levelorder 3.inorder 4.exit\n");
    scanf("%d",&opt);
    switch(opt){
    case 1:insert(&root);
           break;
    case 2:levelorder(root);
           break;
    case 3:inorder(root);
           break;
    case 4:exit(1);
    }
}
}
