/**
 *  * Return an array of size *returnSize.
 *   * Note: The returned array must be malloced, assume caller calls free().
 *    */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int n = nums[0];
    for(int i = 1; i < numsSize; i ++){
        n = n^nums[i];
    }
    int d[32];
    int j = 0;
    for (int i = 0; i < 32; i++) {  // assuming a 32 bit int
        d[i] = n & (1 << i) ? 1 : 0;
    }
    while(j < 32){
        if(d[j] == 1)
            break;
        j ++;
    }
    int base = 1;
    for(int k = 0; k < j; k ++){
        base *= 2;
    }
    *returnSize = 2;
    int *re = malloc(sizeof(int) * 2);
    re[0] = 0;
    re[1] = 0;
    int temp = 0;
    for(int i = 0; i < numsSize; i ++){
        temp = nums[i]&base;
        if(temp == base){
            re[0] = re[0]^nums[i];
        }
        else{
            re[1] = re[1]^nums[i];
        }
    }
    return re;
}

