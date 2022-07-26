void reverseString(char* s, int sSize){
    int left=0, right=sSize-1;
    char temp;
    while(left<right){
        temp=s[left];
        s[left]=s[right];
        s[right]=temp;
        left++;
        right--;
    }
}
