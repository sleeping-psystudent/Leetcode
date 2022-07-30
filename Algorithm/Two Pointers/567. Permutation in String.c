bool checkInclusion(char * s1, char * s2){
    int idx1[26], idx2[26];
    memset(idx1, 0, 26*sizeof(idx1[0]));
    memset(idx2, 0, 26*sizeof(idx2[0]));
    
    for(int i=0;i<strlen(s1);i++){
        idx1[s1[i]-'a']+=1;
    }
    for(int j=0;j<strlen(s2);j++){
        idx2[s2[j]-'a']+=1;
        if(j>=strlen(s1)) idx2[s2[j-strlen(s1)]-'a']-=1;
        for(int k=0;k<26;k++){
            if(idx1[k]!=idx2[k]) break;
            else if(k==25&&idx1[25]==idx2[25]) return true;
        }
    }
    return false;
}
