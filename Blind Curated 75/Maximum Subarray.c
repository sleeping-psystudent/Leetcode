//2023/07/11
//Kadane's algorithm
int maxSubArray(int* nums, int numsSize){
    int now=0;
    int maxSubSum=-10001;
    for(int i=0;i<numsSize;i++){
        now+=nums[i];
        if(now>maxSubSum) maxSubSum=now;
        if(now<0) now=0;
    }
    return maxSubSum;
}
