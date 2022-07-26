char * reverseWords(char * s){
    int slow=0;
    for(int fast=0;fast<=strlen(s);fast++){
       if(s[fast]==' '||s[fast]=='\0'){
           int left=slow, right=fast-1;
            char temp;
            while(left<right){
                temp=s[left];
                s[left]=s[right];
                s[right]=temp;
                left++;
                right--;          
            }
           slow=fast+1;
       }
    }
    return s;
}
