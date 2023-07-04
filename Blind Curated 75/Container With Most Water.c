//2023/07/04
//利用兩個指標，一個從左往右方向移動，另一個從右往左移動，藉此找到數列中最適合的兩個數（水池邊界高）。同時間需考量面積，所以並不是最大的兩個數就一定是答案。
int maxArea(int* height, int heightSize){
    int temp;
    int l=0;
    int r=heightSize-1;
    int max=0;
    while(l!=r){
        if(height[l]>height[r]){
            temp=(r-l)*height[r];
            r=r-1;
        }
        else{
            temp=(r-l)*height[l];
            l=l+1;
        }

        if(temp>max) max=temp;
    }
    return max;
}
