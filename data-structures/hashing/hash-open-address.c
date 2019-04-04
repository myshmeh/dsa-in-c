#include<stdio.h>
#include<stdlib.h>
#define EMPTY "__emp__"
#define DELETED "__del__"
#define BUCKET_SIZE 10

typedef struct bucket {
    char *key;
    int value;
} BUCKET;
BUCKET table[BUCKET_SIZE];

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
        *key++; *key2++;
    }

    return 1;
}

int rehash(int hash_val){
    return (hash_val + 1) % BUCKET_SIZE;
}

void init(){
    for(int i=0; i<BUCKET_SIZE; i++)
        table[i].key = EMPTY;
}

int *find(char *key){
    char *key_;
    int hash_val, count;
    
    count = 0;
    hash_val = hash(key);
    while( !keyequal((key_ = table[hash_val].key), EMPTY) ){
        if( !keyequal(key_, DELETED) && keyequal(key, key_) )
            return &table[hash_val].value;
        if(++count > BUCKET_SIZE)
            return NULL;
        hash_val = rehash(hash_val);
    }

    return NULL;
}

int insert(char *key, int *value){
    int hash_value, count;
    char *key_;

    count = 0;
    hash_value = hash(key);
    while( !keyequal((key_ = table[hash_value].key), EMPTY) && !keyequal(key_, DELETED) ){
        if(keyequal(key, key_))
            return 0;
        if(++count > BUCKET_SIZE){
            fprintf(stderr, "hash table overflow\n");
            exit(1);
        }
        hash_value = rehash(hash_value);
    }

    table[hash_value].key = key;
    table[hash_value].value = *value;

    return 1;
}

int delete(char *key){
    int hash_value, count;
    char *key_;

    count = 0;
    hash_value = hash(key);
    while( !keyequal((key_ = table[hash_value].key), EMPTY) ){
        if( !keyequal(key_, DELETED) && keyequal(key, key_)){
            table[hash_value].key = DELETED;
            return 1;
        }
        if(++count > BUCKET_SIZE)
            return 0;
        
        hash_value = rehash(hash_value);
    }

    return 0;
}

void display(){
    for(int i=0; i<BUCKET_SIZE; i++){
        if( keyequal(table[i].key, EMPTY) )
            printf("%2d| [empty], \n", i);
        else if( keyequal(table[i].key, DELETED) )
            printf("%2d| [deleted], \n", i);
        else
            printf("%2d| %s: %d, \n", i, table[i].key, table[i].value);
    }
}

int main() {
    int nums[BUCKET_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    init();

    insert("zero", &nums[0]);
    insert("one", &nums[1]);
    insert("two", &nums[2]);
    insert("three", &nums[3]);
    insert("four", &nums[4]);
    insert("five", &nums[5]);
    insert("six", &nums[6]);
    insert("seven", &nums[7]);
    insert("eight", &nums[8]);
    insert("nine", &nums[9]);
    display();

    printf("\n'two' bucket has value of: %d\n", *find("two"));

    delete("six");
    delete("nine");
    insert("nine", &nums[9]);
    printf("\ndeleted 'six' bucket and 'nine' bucket, and then inserted 'nine' bucket\n");
    display();
}