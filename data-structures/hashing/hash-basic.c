#include<stdio.h>
#define HASH_SIZE 100

struct DATA{
    int value;
    char *key;
};

int hash(char *s);

int main(){
    int hash_table[HASH_SIZE];
    struct DATA data, data2;
    
    char key[] = "one", key2[] = "nine";
    data.key = key; data.value = 123;
    data2.key = key2; data2.value = 234;
    int index = hash(data.key);
    int index2 = hash(data2.key);

    hash_table[index] = data.value;
    hash_table[index2] = data2.value;

    printf("index: %d, key(%s)\n", index, data.key);
    printf("index2: %d, key(%s)\n", index2, data2.key);
    printf("hash_table[index]: %d\n", hash_table[index]);
}

int hash(char *s){
    int i = 0;
    while(*s){
        i += *s++;
    }

    return i % HASH_SIZE;
}