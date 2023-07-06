//2023/07/06
//先使用merge sort排序，因為他的worst case時間複雜度O(nlogn)很優。接著做map跟出現次數計算的hash，因爲我希望可以O(1)就確認第三個數字是否存在於數列當中
//一直TLE是因為剛開始prime設太小了，哭
void merge(int arr[],int l,int m,int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m; 
    int L[n1],R[n2];

    for(i=0;i<n1;i++) L[i]=arr[l+i];
    for(j=0;j<n2;j++) R[j]=arr[m+1+j];
 
    i = 0;
    j = 0;

    k = l;
    while(i<n1 && j<n2){
        if (L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
 
    while (i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[],int l,int r){
    if (l<r){
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i,j,temp,a1,a2,a3,h;
    int prime=100003;

    //sorting
    mergeSort(nums,0,numsSize-1);
    int acc[200006]={0};
    int nnums[numsSize];
    int nnumsSize=1;
    nnums[0]=nums[0];
    for(i=0;i<numsSize;i++){
        //accumulated amount
        if(nums[i]>0) acc[prime+nums[i]%prime]++;
        else acc[(nums[i]-2*nums[i])%prime]++;
        //map
        if(i!=0 && nums[i]!=nums[i-1]){
            nnums[nnumsSize]=nums[i];
            nnumsSize++;
        }
    }

    int space=512;
    *returnSize=0;
    *returnColumnSizes=(int*)malloc(sizeof(int*)*4096);
    int** ans=(int**)malloc(sizeof(int*)*4096);
    for(i=0;i<nnumsSize;i++){
        //if(i==nnumsSize/30) return ans;
        if(nnums[i]>0) return ans;
        for(j=i;j<nnumsSize;j++){
            temp=0-(nnums[i]+nnums[j]);
            if(temp>nnums[nnumsSize-1] || temp<nnums[i] || temp<nnums[j]) continue;

            if(temp>0) a3=acc[prime+temp%prime];
            else a3=acc[(temp-2*temp)%prime];
            if(nnums[i]>0) a1=acc[prime+nnums[i]%prime];
            else a1=acc[(nnums[i]-2*nnums[i])%prime];
            if(nnums[j]>0) a2=acc[prime+nnums[j]%prime];
            else a2=acc[(nnums[j]-2*nnums[j])%prime];
            if(a1==0 || a2==0 || a3==0) continue;

            //all same
            if(nnums[i]==nnums[j] && nnums[i]==temp && nnums[j]==temp && a1<3) continue;
            //two same
            if((nnums[i]==nnums[j] && nnums[i]!=temp && a1<2) || (nnums[i]==temp && nnums[j]!=temp && a3<2) || (nnums[j]==temp && nnums[i]!=nnums[j] && a2<2)) continue;

            if(a3>0){
                if((*returnSize)!=0 && (*returnSize)>=4096 && (*returnSize)%space==0){
                    *returnColumnSizes=(int*)realloc(*returnColumnSizes,sizeof(int*)*((*returnSize)+space));
                    ans=(int**)realloc(ans,sizeof(int*)*((*returnSize)+space));
                }
                (*returnColumnSizes)[*returnSize]=3;
                ans[*returnSize]=(int*)malloc(sizeof(int)*3);
                ans[*returnSize][0]=nnums[i];
                ans[*returnSize][1]=nnums[j];
                ans[*returnSize][2]=temp;
                (*returnSize)++;
            }
        }
    }
    return ans;
}
