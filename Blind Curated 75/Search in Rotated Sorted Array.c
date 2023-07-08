//2023/07/08
//使用binary search，劃分當前元素是否與target在「同一邊」，並做不同處理確保指標可以往正確位置移動
int search(int* nums, int numsSize, int target){
    int l=0;
    int r=numsSize-1;
    int m;
    while(l<=r){
        m=(l+r)/2;
        if(nums[m]==target) return m;

        //nums[0]跟nums[m]比較才能知道nums[m]在左半邊（大於等於）還右半邊（小於）
        if(nums[0]<=nums[m]){
            //確認target是不是在同一邊
            if(nums[0]<=target){
                //同一邊
                if(nums[m]<target) l=m+1;
                else r=m-1;
            }
            else{
                //不是同一邊，將nums[m]視作-inf
                nums[m]=-10001;
                if(nums[m]<target) l=m+1;
                else r=m-1;           
            }
        }
        else{
            //確認target是不是在同一邊
            if(nums[0]>target){
                //同一邊
                if(nums[m]<target) l=m+1;
                else r=m-1;
            }
            else{
                //不是同一邊，將nums[m]視作inf
                nums[m]=10001;
                if(nums[m]<target) l=m+1;
                else r=m-1;           
            }
        }
    }
    return -1;
}
