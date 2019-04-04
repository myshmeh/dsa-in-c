#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} NODE;

NODE *root = NULL;

NODE *search(int value){
    NODE *p;

    p = root;
    while(p != NULL){
        if(value == p->value)
            return p;
        else if(value < p->value)
            p = p->left;
        else
            p = p->right;
    }
    return NULL;
}

NODE *insert(int value){
    NODE **p, *node;

    p = &root;
    while(*p != NULL) {
        if(value == (*p)->value)
            return NULL;
        else if(value < (*p)->value)
            p = &(*p)->left;
        else
            p = &(*p)->right;
    }
    if( (node = malloc(sizeof(NODE))) == NULL )
        perror("out of memory");
    node->left = NULL;
    node->right = NULL;
    node->value = value;
    *p = node;
    return node;
}

int insert2(int value){ //this wouldn't work
    NODE *p, node;

    p = root;
    while(p != NULL) {
        if(value == p->value)
            return 0;
        else if(value < p->value)
            p = p->left;
        else
            p = p->right;
    }

    node.left = NULL;
    node.right = NULL;
    node.value = value;
    p = &node;
    return 1;
}

NODE *extract_min(NODE **p){
    NODE *node;

    while((*p)->left != NULL)
        p = &(*p)->left;
    
    node = *p;
    *p = (*p)->right;

    return node;
}

int delete(int value) {
    NODE **p, *node;

    p = &root;
    while(*p != NULL) {
        if(value == (*p)->value) {
            node = *p;
            if(node->left == NULL && node->right == NULL) // node is leaf, then just disconnect it from tree
                *p = NULL;
            else if(node->left == NULL) // node has right branch only, then replace with right child node
                *p = (*p)->right;
            else if(node->right == NULL) // node has left branch only, then replace with left child node
                *p = (*p)->left;
            else {
                *p = extract_min(&node->right);
                (*p)->right = node->right;
                (*p)->left = node->left;
            }
            free(node);
            return 1;
        }
        else if (value < (*p)->value)
            p = &(*p)->left;
        else
            p = &(*p)->right;
    }

    return 0;
}

int main(){
    insert(7); insert(10); insert(5);
    printf("%d at %p\n", search(10)->value, search(10));
    printf("%d at %p\n", search(5)->value, search(5));
    printf("deleting node(5)...\n");
    delete(5);
    printf("%d at %p\n", search(10)->value, search(10));
    printf("%d at %p\n", 5, search(5));
}