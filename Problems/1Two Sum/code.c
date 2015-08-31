typedef struct HashNode{
    int val;
    int key;
} HashNode;

typedef struct HashMap{
    int size;
    HashNode** storage;
} HashMap;

HashMap* hash_create(int size);
void hash_destroy(HashMap* hashMap);
void hash_set(HashMap* hashMap, int key, int value);
HashNode* hash_get(HashMap* hashMap, int key);

HashMap* hash_create(int size){
    HashMap* hashMap = malloc(sizeof(HashMap));
    hashMap->size = size;
    hashMap->storage = calloc(size, sizeof(HashNode*));
    return hashMap;
}

void hash_destroy(HashMap* hashMap){
    for(int i = 0; i < hashMap->size; i ++){
        HashNode* node = hashMap->storage[i];
        if(node){
            free(node);
        }
    }
    free(hashMap->storage);
    free(hashMap);
}

void hash_set(HashMap* hashMap, int key, int value){
    int hash = abs(key) % hashMap->size;
    HashNode* node;
    while((node = hashMap->storage[hash])){
        if(hash < hashMap->size - 1){
            hash ++;
        }else{
            hash = 0;
        }
    }
    node = malloc(sizeof(HashNode));
    node->val = value;
    node->key = key;
    hashMap->storage[hash] = node;
}

HashNode* hash_get(HashMap* hashMap, int key){
    int hash = abs(key) % hashMap->size;
    HashNode* node;
    while((node = hashMap->storage[hash])){
        if(node->key == key){
            return node;
        }
        if(hash < hashMap->size - 1){
            hash ++;
        }else{
            hash = 0;
        }
    }
    return NULL;
}

/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
int* twoSum(int* nums, int numsSize, int target) {
    int* results = malloc(sizeof(int) * 2);
    HashMap* hashMap;
    HashNode* node;
    hashMap = hash_create(numsSize * 2);
    int rest;
    for(int i = 0; i < numsSize; i ++){
        rest = target - nums[i];
        node = hash_get(hashMap, rest);
        if(node){
            results[0] = node->val + 1;
            results[1] = i + 1;
            hash_destroy(hashMap);
            return results;
        }else{
            hash_set(hashMap, nums[i], i);
        }
    }
}
