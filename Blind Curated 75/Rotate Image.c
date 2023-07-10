//2023/07/11
//小心不要重複交換
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i,j,temp;
    *matrixColSize=matrixSize;

    //rotate
    for(i=0;i<matrixSize;i++){
        for(j=0;j<i;j++){
            temp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }

    //switch col
    for(i=0;i<matrixSize;i++){
        for(j=0;j<matrixSize/2;j++){
            temp=matrix[i][j];
            matrix[i][j]=matrix[i][matrixSize-j-1];
            matrix[i][matrixSize-j-1]=temp;
        }
    }
}

/*
matrix
(0,0)(1,0)(2,0)
(0,1)(1,1)(2,1)
(0,2)(1,2)(2,2)

(1)(2)(3)   rotate       (1)(4)(7)   switch col   (7)(4)(1)
(4)(5)(6) -------------> (2)(5)(8) -------------> (8)(5)(2) 
(7)(8)(9)                (3)(6)(9)                (9)(6)(3)
*/
