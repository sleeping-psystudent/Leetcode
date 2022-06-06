class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()<2) return;
        k%=nums.size();
        
        for(int i=0;i<nums.size()/2;i++){
            int temp=nums[i];
            nums[i]=nums[nums.size()-1-i];
            nums[nums.size()-1-i]=temp;
        }
        for(int j=0;j<k/2;j++){
            int temp_front=nums[j];
            nums[j]=nums[k-1-j];
            nums[k-1-j]=temp_front;
        }
        for(int m=k;m<k+((nums.size()-k)/2);m++){
            int temp_back=nums[m];
            nums[m]=nums[nums.size()-(m-k)-1];
            nums[nums.size()-(m-k)-1]=temp_back;
        }
    }
};
