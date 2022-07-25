void moveZeroes(int* nums, int numsSize){
    int slow=0;
    int temp;
    for(int fast=0;fast<numsSize;fast++){
        if(nums[slow]==0 && nums[fast]!=0){
            temp=nums[slow];
            nums[slow]=nums[fast];
            nums[fast]=temp;
        }
        if(nums[slow]!=0) slow++;
    }
}
