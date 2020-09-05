/******************************************************************************
*******************************************************************************/

#include <iostream>

using namespace std;
struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
};
struct node *root=NULL;
struct node* rinsert(struct node *p,int key)
{
    struct node *t=NULL;
    if(p==NULL)
    {
        t =new node;
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    else if(key < p->data)
    {
        p->lchild=rinsert(p->lchild,key);
    }
    else if(key > p->data)
    {
        p->rchild=rinsert(p->rchild,key);
    }
}


void inorder(struct node *p)
{
    if(p!=NULL)
    {
        inorder(p->lchild);
        cout<<p->data<<endl;
        inorder(p->rchild);
        
    }
    
}

int height(struct node *p)
{
    int x,y;
    if(p==0)
    {
        return 0;
    }
    x=height(p->lchild);
    y=height(p->rchild);
    
    if(x>y){
        return x+1;
    }
    else{
        return y+1;
    }
}

struct node* inpredecessor(struct node *p)
{
    while(p!=0 && p->rchild!=NULL)
    {
        p=p->rchild;
    }
    return p;
}

struct node* insuccessor(struct node *p)
{
    while(p!=0 && p->lchild!=NULL)
    {
        p=p->lchild;
    }
    return p;
}




struct node* Delete(struct node* p,int key)
{
    int x;
    struct node *temp;
    if(p->data ==key)
    {
        if(p->lchild==NULL && p->rchild==NULL)
        {
            x=p->data;
            free(p);
            return NULL;
        }
        
        else if(height(p->lchild) > height(p->rchild))
        {
            temp=inpredecessor(p->lchild);
            p->data=temp->data;
            p->lchild=Delete(p->lchild,temp->data);
        }
        else if(height(p->lchild) < height(p->rchild))
        {
            temp=insuccessor(p->rchild);
            p->data=temp->data;
            p->rchild=Delete(p->rchild,temp->data);
        }
        
    }
    
    else if(key < p->data)
    {
        p->lchild=Delete(p->lchild,key);
    }
    else if(key > p->data)
    {
        p->rchild=Delete(p->rchild,key);
    }
    return p;
}

int main()
{
    root=rinsert(root,10);
    rinsert(root,20);
    rinsert(root,30);
    rinsert(root,33);
    rinsert(root,2);
    rinsert(root,100);
    rinsert(root,65);
    rinsert(root,11);
    inorder(root);
    cout<<endl;
    
    Delete(root,20);
    inorder(root);
    
    return 0;
}
