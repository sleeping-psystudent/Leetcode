//2023/07/06
//stack用好用滿
bool isValid(char * s){
    int c=0;
    char stack[strlen(s)];
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{') stack[c++]=s[i];
        else{
            if(c>0 && ((stack[c-1]=='(' && s[i]==')') || (stack[c-1]=='[' && s[i]==']') || (stack[c-1]=='{' && s[i]=='}'))) c--;
            else return false;
        }
    }
    if(c!=0) return false;
    return true;
}
