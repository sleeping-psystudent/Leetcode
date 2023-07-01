//2023/07/01
//Hash,單純在賭不會collision
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int prime=99991;
    int i,iv,temp;
    int* arr=calloc(2*prime, sizeof(int));

    //hashing
    for(i=0;i<numsSize;i++){
        if(nums[i]>0) arr[prime+nums[i]%prime]=i+1;
        else arr[(nums[i]-2*nums[i])%prime]=i+1;
    }
    for(i=0;i<numsSize;i++){
        temp=target-nums[i];
        if(temp>0) iv=arr[prime+temp%prime];
        else iv=arr[(temp-2*temp)%prime];

        if(iv!=0 && i!=iv-1){
        	int* result=malloc(2*sizeof(int));
            result[0]=i;
            result[1]=iv-1;
            *returnSize=2;
            return result;
        }
        else continue;
    }
    *returnSize=0;
    return NULL;
}
