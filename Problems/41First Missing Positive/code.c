int firstMissingPositive(int* nums, int numsSize) {
    if(numsSize == 0)
        return 1;
    int x = 0;
    for(int i = 0; i < numsSize; i ++){
        if(nums[i] > 0){
            x = nums[i];
            while(x > 0 && x != nums[x - 1] && x <= numsSize){          
                nums[i] = nums[x - 1];                                  
                nums[x - 1] = x;
                x = nums[i];
            }
        }
    }
    int first = 0;
    for(int i = 0; i < numsSize; i ++){
        if(nums[i] <= 0 || nums[i] != (i + 1))
            return i + 1;
    }
    return numsSize + 1;
}

