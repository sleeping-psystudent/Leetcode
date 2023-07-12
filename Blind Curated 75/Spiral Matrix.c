//2023/07/13
//四邊都走一段，一直旋轉
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    *returnSize=matrixSize*(*matrixColSize);

    int* ans=malloc(sizeof(int)*(*returnSize));
    int n=0;
    int c;
    //以較短的一邊決定要轉幾次
    int bound;
    if((*matrixColSize)>matrixSize) bound=matrixSize;
    else bound=(*matrixColSize);
    bound=(bound+1)/2;
    for(int i=0;i<bound;i++){
        if(i==matrixSize-i-1){
            c=i;
            while(c<=(*matrixColSize)-i-1) ans[n++]=matrix[i][c++];
        }
        else if(i==(*matrixColSize)-i-1){
            c=i;
            while(c<=matrixSize-i-1) ans[n++]=matrix[c++][(*matrixColSize)-i-1];
        }
        else{
            //往右
            c=i;
            while(c<(*matrixColSize)-i-1) ans[n++]=matrix[i][c++];
            //往下
            c=i;
            while(c<matrixSize-i-1) ans[n++]=matrix[c++][(*matrixColSize)-i-1];
            //往左
            c=(*matrixColSize)-i-1;
            while(c>i) ans[n++]=matrix[matrixSize-i-1][c--];
            //往上
            c=matrixSize-i-1;
            while(c>i) ans[n++]=matrix[c--][i];
        }
    }
    return ans;
}

/*
(0,0)(1,0)(2,0)
(0,1)(1,1)(2,1)
(0,2)(1,2)(2,2)

(0,0)(1,0)(2,0)(3,0)
(0,1)(1,1)(2,1)(3,1)
(0,2)(1,2)(2,2)(3,2)

(0,0)(1,0)(2,0)
(0,1)(1,1)(2,1)
(0,2)(1,2)(2,2)
(0,3)(1,3)(2,3)
(0,4)(1,4)(2,4)
*/
