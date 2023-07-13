//2023/07/13
//聽說是dp但我看不出來
bool canJump(int* nums, int numsSize){
    int max=0;
    for(int i=0;i<numsSize;i++){
        if(i>max) return false; //max無法走到目前的所在地
        if(max>numsSize) return true; //可以走到終點
        
        if(nums[i]+i>max) max=nums[i]+i; //紀錄走過的點中能到達的最遠位置
    }
    return true;
}
