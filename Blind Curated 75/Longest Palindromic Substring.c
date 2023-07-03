//2023/07/03
//畫一個strlen(s)*strlen(s)大小的表格，因為迴文字串去頭去尾一定還是迴文字串。依照這個想法，只要中間確定是迴文，就僅需檢查新的頭尾是否相同就可以確定它是迴文
char * longestPalindrome(char * s){
    int i,j;
    int start=0;
    int end=0;
    int max=1;
    int len=strlen(s);
    bool dp[len][len];
    for(i=0;i<len;i++) dp[i][i]=true;
    for(i=1;i<len;i++){
        for(j=0;j<i;j++){
            if(i-j==1){
                if(s[i]==s[j]){
                    dp[i][j]=true;
                    if(i-j+1>max){
                        max=i-j+1;
                        start=j;
                        end=i;
                    }
                }
                else dp[i][j]=false;
            }
            else if(dp[i-1][j+1]==true){
                if(s[i]==s[j]){
                    dp[i][j]=true;
                    if(i-j+1>max){
                        max=i-j+1;
                        start=j;
                        end=i;
                    }
                }
                else dp[i][j]=false;               
            }
            else dp[i][j]=false;
        }
    }

    char *returnString=malloc((max+1)*sizeof(char));
    int c=0;
    for(i=start;i<=end;i++){
        returnString[c]=s[i];
        c++;
    }
    returnString[max]='\0';
    return returnString;
}
