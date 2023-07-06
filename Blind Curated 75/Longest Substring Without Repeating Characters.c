//2023/07/01
//character這個陣列會紀錄每個字母上一次出現的位置，當前字母上一次出現的位置如果在現有子字串內（比start也就是起始點還大），就將字串起點改成該字母上一次出現位置的下一個元素
int lengthOfLongestSubstring(char * s){
    int i;
    int start=0;
    int length=0;
    int longest=0;
    int character[128]={0};
    for(i=0;i<strlen(s);i++){
        if(character[s[i]]!=0 && character[s[i]]>=start){
            start=character[s[i]];
            length=i+1-start;
        }
        else length++;
        character[s[i]]=i+1;

        if(length>longest) longest=length;
    }
    return longest;
}
