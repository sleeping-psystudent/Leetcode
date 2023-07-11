//2023/07/11
//利用sort，將字串進行排序
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define max_string 101

struct strStore{
    char original[max_string];
    char sorted[max_string];
};

int cmp(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}

int cmp2(const void*a, const void* b){
    const struct strStore** ptr_a = (const struct strStore**)a;
    const struct strStore** ptr_b = (const struct strStore**)b;
    return strcmp((*ptr_a)->sorted,(*ptr_b)->sorted);
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    int i,j;
    //Storage
    struct strStore* arr[strsSize];
    for(i=0;i<strsSize;i++){
        //sorting the string
        char backup[strlen(strs[i])+1];
        strcpy(backup,strs[i]);
        qsort(backup,strlen(strs[i]),sizeof(char),cmp);
        //struct input
        arr[i]=malloc(sizeof(struct strStore));
        strcpy(arr[i]->original,strs[i]);
        strcpy(arr[i]->sorted,backup);
    }
    //sorting the whole strs
    qsort(arr,strsSize,sizeof(struct strStore*),cmp2);
    //testing
    //for(i=0;i<strsSize;i++) printf("%s %s\n", arr[i]->original, arr[i]->sorted);

    *returnSize=0;
    *returnColumnSizes=(int*)malloc(sizeof(int*)*10000);;
    char*** ans=(char***)malloc(sizeof(char*)*10000);
    j=1;
    for(i=1;i<strsSize;i++){
        if(strcmp(arr[i]->sorted, arr[i-1]->sorted)==0) j++;
        else{
            (*returnColumnSizes)[*returnSize]=j;
            ans[*returnSize]=(char**)malloc(sizeof(char*)*j);
            while(j>0){
                ans[(*returnSize)][j-1]=arr[i-j]->original;
                j--;
            }
            (*returnSize)++;
            j=1;
        }
    }
    (*returnColumnSizes)[*returnSize]=j;
    ans[*returnSize]=(char**)malloc(sizeof(char*)*j);
    while(j>0){
        ans[(*returnSize)][j-1]=arr[i-j]->original;
        j--;
    }
    (*returnSize)++;

    /*
    bat abt -> arr[0] -> ans[0][0]
    eat aet -> arr[1] -> ans[1][0]
    tea aet -> arr[2] -> ans[1][1]
    ate aet -> arr[3] -> ans[1][2]
    tan ant -> arr[4] -> ans[2][0]
    nat ant -> arr[5] -> ans[2][1]
    */
    return ans;
}
