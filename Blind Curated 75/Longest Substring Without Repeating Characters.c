//2023/07/01
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
