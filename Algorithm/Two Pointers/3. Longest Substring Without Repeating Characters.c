int lengthOfLongestSubstring(char * s){
    int temp;
    int start=0, max=0;
    int character[128];
    memset(character, -1, 128*sizeof(character[0]));
    
    int i;
    for(i=0;i<strlen(s);i++){
        temp=character[s[i]];
        character[s[i]]=i;
        
        if(temp>=start){
            if(max>(i-start)) max=max;
            else max=i-start;
            start=temp+1;
        }
    }
    if(max>(i-start)) max=max;
    else max=i-start;
    return max;
}
