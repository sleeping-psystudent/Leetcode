//2023/06/27
//暴力法，特別的是這題需要返回陣列長度，也就是returnSize的功用
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i=0;i<numsSize;i++) {
        for (int j=i+1;j<numsSize;j++) {
            if (nums[i]+nums[j]==target) {
                int* result=malloc(2*sizeof(int));
                result[0]=i;
                result[1]=j;
                *returnSize=2;
                return result;
            }
        }
    }
    *returnSize=0;
    return NULL;
}
