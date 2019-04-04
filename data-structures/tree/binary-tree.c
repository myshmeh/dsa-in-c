#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *left;
    struct node *right;
    char         label;
};

void preorder(struct node *p){
    if(p == NULL)
        return;
    printf("arrived at node %c\n", p->label);
    preorder(p->left);
    preorder(p->right);
}

void inorder(struct node *p){
    if(p == NULL)
        return;
    inorder(p->left);
    printf("arrived at node %c\n", p->label);
    inorder(p->right);
}

void postorder(struct node *p){
    if(p == NULL)
        return;
    postorder(p->left);
    postorder(p->right);
    printf("arrived at node %c\n", p->label);
}

int main(){
    struct node *a, *b, *c, *d;

    if( (a = malloc(sizeof(struct node))) == NULL ) return -1;
    if( (b = malloc(sizeof(struct node))) == NULL ) return -1;
    if( (c = malloc(sizeof(struct node))) == NULL ) return -1;
    if( (d = malloc(sizeof(struct node))) == NULL ) return -1;

    a->label = 'a';
    a->left = b;
    a->right = c;

    b->label = 'b';
    b->left = d;
    b->right = NULL;

    c->label = 'c';
    c->left = NULL;
    c->right = NULL;

    d->label = 'd';
    d->left = NULL;
    d->right = NULL;

    preorder(a);
    printf("\n");
    inorder(a);
    printf("\n");
    postorder(a);

    free(a); free(b); free(c); free(d);
}