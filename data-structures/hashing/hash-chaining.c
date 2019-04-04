#include<stdio.h>
#include<stdlib.h>
#define BUCKET_SIZE 50

typedef struct cell {
    char *key;
    int data;
    struct cell *next;
}CELL;
CELL *table[BUCKET_SIZE];

void init(){
    int i;
    for(i=0; i<BUCKET_SIZE; i++)
        table[i] = NULL;
}

int hash(char *key){
    int i = 0;
    while(*key){
        i += *key++;
    }

    return i % BUCKET_SIZE;
}

int keyequal(char *key, char *key2){
    while(*key && *key2){
        if(*key != *key2)
            return 0;
        *key++;
        *key2++;
    }

    return 1;
}

int *find(char *key){
    CELL *p;
    for(p = table[hash(key)]; p != NULL; p = p->next)
        if(keyequal(key, p->key))
            return &p->data;
    
    return NULL;
}

int insert(char *key, int *data){
    CELL *p;
    int h;
    
    if(find(key) != NULL)
        return 0;
    if((p = malloc(sizeof(CELL))) == NULL){
        fprintf(stderr, "out of memory\n");
        exit(2);
    }
    h = hash(key);
    p->key = key;
    p->data = *data;
    p->next = table[h];
    table[h] = p;
    return 1;
}

int delete(char *key){
    int h;
    CELL *p, *q;

    h = hash(key);
    if(table[h] == NULL)
        return 0;
    if(keyequal(key, table[h]->key)){
        p = table[h];
        table[h] = p->next;
        free(p);
        return 1;
    }
    for(q = table[h], p = q->next; p != NULL; q = p, p = p->next){
        if(keyequal(key, p->key)){
            q->next = p->next;
            free(p);
            return 1;
        }
    }

    return 0;
}

int main(){
    init();

    int num = 5, num2 = 1, num3 = 9;
    insert("five", &num);
    insert("one", &num2);
    insert("nine", &num3);

    printf("five: %d\n", *find("five"));
    printf("one: %d\n", *find("one"));
    printf("nine: %d\n", *find("nine"));

    return 0;
}