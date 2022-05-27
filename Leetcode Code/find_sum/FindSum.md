# Find two numbers
## Description
https://leetcode.cn/problems/two-sum/
## Code *1*
```C
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                int* ret = malloc(sizeof(int) * 2);
                ret[0] = i, ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
```

下面的写法有问题，一个是这样是一种用malloc定义数组大小的方法，可以不用预设较大的数组。另一个是我们只能返回指针，这种写法无法返回。

```C
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                int ret[2];
                ret[0] = i, ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
```

关于这个地方，知乎有答案是：
![[image.png]]
讲到了[malloc函数](https://www.zhihu.com/question/511379052)的的内容。
他提到应该这样写:
```C
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
	            // add (int*)
                int* ret = (int*) malloc(sizeof(int) * 2);
                ret[0] = i, ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
```
因为ret的类型是int$*$ ，指向的对象的值应该是int类型，而malloc返回一个void，所以前面要先转换类型在Leetcode 中的编译运行效果其实时而快时而慢，内存消耗也没有体现较大的区别。
## Code *2*
这是使用哈希表的方法
```C
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
        struct hashTable* tmp = malloc(sizeof(struct hashTable));
        tmp->key = ikey, tmp->val = ival;
        HASH_ADD_INT(hashtable, key, tmp);
    } else {
        it->val = ival;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    hashtable = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hashTable* it = find(target - nums[i]);
        if (it != NULL) {
            int* ret = malloc(sizeof(int) * 2);
            ret[0] = it->val, ret[1] = i;
            *returnSize = 2;
            return ret;
        }
        insert(nums[i], i);
    }
    *returnSize = 0;
    return NULL;
}
```
#HashTable
必须的定义
```C
struct hashTable{
	int key;
	int val;
	UT_hash_handle hh;
};

struct hashTable* hashtable = NULL;
```
查找
```C
struct hashTable* find(struct hashTable** hashtable, int key){
    struct hashTable* tem = malloc(sizeof(struct hashTable));
    HASH_FIND_INT(*hashtable, &key, tem);
    return tem;
}
```
插入
```C
void insert(struct hashTable** hashtable, int key, int val){
    struct hashTable* tem = malloc(sizeof(struct hashTable));
    tem->val = val;
    tem->key = key;
    HASH_ADD_INT(*hashtable, key, tem);
    //"key" 是具体的键名, 会在编译的时候被宏替换
}
```
-   HASH_ADD_INT表示添加的键值为int类型。
-   HASH_ADD_STR表示添加的键值为字符串类型。
-   HASH_ADD_PTR表示添加的键值为指针类型。
-   HASH_ADD表示添加的键值可以是任意类型。
- 删除C
```C
void del(struct hashTable** hashtable, int key){
    struct hashTable* tem = find(hashtable, key);
    HASH_DEL(*hashtable, tem);
    free(tem);
}
```
