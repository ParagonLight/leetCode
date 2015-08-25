int singleNumber(int* nums, int numsSize) {
    int ones = 0, twos = 0, threes = 0; 
    for(int i = 0; i < numsSize; i ++){
        int v = nums[i];
        threes = twos & v;
        twos = (ones & v | twos) & (~threes);
        ones = (v | ones) & (~threes);
    }
    return ones;
}
