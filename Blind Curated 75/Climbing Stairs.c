//2023/07/20
//一階時只有一種解法，兩階時有兩種（1+1, 2），三階可以看作是走兩階再走一階，以此做選擇上的組合
int climbStairs(int n){
    int s1=1;
    int s2=2;
    if(n==1) return s1;
    else if(n==2) return s2;

    int ans;
    for(int i=s2+1;i<=n;i++){
        ans=s1+s2;
        s1=s2;
        s2=ans;
    }
    return ans;
}
