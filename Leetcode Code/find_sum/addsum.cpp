#include "uthash.h"
#include <stdio.h>
#include <stdlib.h>
		
struct hashTable {
    int key;
    int val;
    UT_hash_handle hh;
};

struct hashTable* hashtable;

struct hashTable* find(int ikey) {
    struct hashTable* tmp;
    HASH_FIND_INT(hashtable, &ikey, tmp);
    return tmp;
}

void insert(int ikey, int ival) {
    struct hashTable* it = find(ikey);
    if (it == NULL) {
        struct hashTable* tmp = (struct hashTable*) malloc(sizeof(struct hashTable));
        tmp->key = ikey, tmp->val = ival;
        HASH_ADD_INT(hashtable, key, tmp);
    } else {
        it->val = ival;
    }
}
//int* twoSum(int* nums, int numsSize, int target) {
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    hashtable = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hashTable* it = find(target - nums[i]);
        if (it != NULL) {
            int* ret = (int*)malloc(sizeof(int) * 2);
            ret[0] = it->val, ret[1] = i;
            *returnSize = 2;
            return ret;
        }
        insert(nums[i], i);
    }
    *returnSize = 0;
    return NULL;
}

int main(){
	int a[7]= {1,2,3,4,5,6,7};
	int target = 9;
	int* returnSize = (int*) malloc(sizeof(int)); 
	int* ret = (int*) malloc(sizeof(int)*2);
	ret = twoSum(a,sizeof(a),target,returnSize);
	printf("第%d和第%d位加起来等于%d。",ret[0]+1,ret[1]+1,target);
	return 0;
} 






























