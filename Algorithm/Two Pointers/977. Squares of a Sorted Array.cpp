class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int low=0, high=nums.size()-1;
        vector<int> ans(nums.size());
        int i=nums.size()-1;
        while(i>=0){
            if((nums[low]*nums[low])<(nums[high]*nums[high])){
                ans[i]=(nums[high]*nums[high]);
                i--;
                high-=1;
            }
            else{
                ans[i]=(nums[low]*nums[low]);
                i--;
                low+=1;
            }
        }
        return ans;
    }
};
