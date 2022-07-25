/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int* Ans = (int*)malloc(2*sizeof(int));
    int left=0,right=numbersSize-1;
    
    while(left<right){
        int com=numbers[left]+numbers[right];
        if(com>target) right--;
        else if(com<target) left++;
        else{
            Ans[0]=left+1;
            Ans[1]=right+1;
            *returnSize=2;
            return Ans;
        }
    }
    
    *returnSize=0;
    return 0;
}
