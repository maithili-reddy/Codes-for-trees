
/*This C code implements the basic binary search tree*/
#include<stdio.h>
typedef struct{
int data;
struct node* lc;
struct node* rc;
}node;
node* msearch(node *root,int k){
node *temp=NULL;
while(root){
if(root->data==k)
    return NULL;
else if(k<root->data){
    temp=root;
    root=root->lc;
}
else{
    temp=root;
    root=root->rc;
}
}
return temp;
}
void insertion(node **tree,int k){
node *temp,*temp1;
temp1=*tree;
temp=msearch(temp1,k);
if(temp || !(*tree)){
    temp1=(node*)malloc(sizeof(node));
    temp1->lc=NULL;
    temp1->rc=NULL;
    temp1->data=k;
    if(*tree){
        if(k<temp->data)
            temp->lc=temp1;
        if(k>temp->data)
            temp->rc=temp1;
    }
    else
        *tree=temp1;
}
}
void inorder(node *root){
    if(root){
inorder(root->lc);
printf("%d ",root->data);
inorder(root->rc);
    }
}
int main(){
    node *tree=NULL;
    int opt,k;
    while(1){
        printf("Enter 1.insert 2.inorder 3.exit\n");
        scanf("%d",&opt);
        switch(opt){
        case 1:printf("Enter the data\n");
               scanf("%d",&k);
               insertion(&tree,k);
               break;
        case 2:inorder(tree);
               break;
        case 3:exit(1);
        }
    }
return 0;
}
