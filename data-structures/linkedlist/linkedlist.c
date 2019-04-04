#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int value;
};

int add (int value, struct node *head) {
    struct node *p, *curr;
    if( (p = malloc(sizeof(struct node))) == NULL ) return -1;

    curr = head;
    while(curr->next != NULL)
	curr = curr->next;

    p->value = value;
    p->next = NULL;
    curr->next = p;

    return 1;
}

int insert (int value, struct node *tar, struct node *head) {
    struct node *p, *curr, *tmp;
    if( (p = malloc(sizeof(struct node))) == NULL ) return -1;

    curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
        if(curr == tar) break;
    }

    p->value = value;

    tmp = curr->next;
    curr->next = p;
    p->next = tmp;

    return 1;
}

int update(int value, struct node *tar, struct node *head) {
    struct node *curr;
    int found = 0;

    curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
        if(curr == tar) {
            found = 1;
            break;
        } 
    }
    if(!found) return 0;

    curr->value = value;

    return 1;
}

int delete(struct node *tar, struct node *head) {
    struct node *curr, *prev;
    int found = 0;

    curr = head;
    while(curr->next != NULL) {
        prev = curr;
        curr = curr->next;
        if(curr == tar) {
            found = 1;
            break;
        }
    }
    if(!found) return 0;

    prev->next = curr->next;
    curr->next = NULL;

    free(curr);

    return 1;
}

void draw (struct node *head) {
    struct node *p;

    for(p=head->next; p!=NULL; p=p->next)
        printf("%d, ", p->value);

    printf("\n");
}

int main() {
    struct node head;
    head.next = NULL;

    add(1, &head);  add(2, &head);  add(3, &head);
    insert(4, head.next, &head);
    update(5, head.next, &head);
    delete(head.next->next->next, &head);

    draw(&head);
}
