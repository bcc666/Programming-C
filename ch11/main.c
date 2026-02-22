#include <stdio.h>
#include <stdlib.h>
#define N 3
#define M 2

//11-3
void Ex11_3(void){
    char *month[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};
    int n;
    scanf("%d",&n);
    printf("%s",month[n-1]);
}

//11-4
void Swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Transpose1(int a[][N],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            Swap(&a[i][j],&a[j][i]);
        }
    }
}

void Transpose2(int (*a)[N],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            Swap(a[i]+j,a[j]+i);
        }
    }
}

void Transpose3(int *a,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            Swap(a+i*n+j,a+j*n+i);
        }
    }
}
// 打印n阶矩阵（辅助函数，用于验证结果）
void PrintMatrix(int *matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", *(matrix + i * n + j));
        }
        printf("\n");
    }
    printf("-------------------------\n");
}

// 测试三个转置函数的主逻辑
void Ex11_4(void) {
    // 初始化测试矩阵（3阶矩阵）
    int matrix1[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix3[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printf("原始矩阵：\n");
    PrintMatrix((int *)matrix1, N);

    // 测试Transpose1
    Transpose1(matrix1, N);
    printf("Transpose1 转置后：\n");
    PrintMatrix((int *)matrix1, N);

    // 测试Transpose2
    Transpose2(matrix2, N);
    printf("Transpose2 转置后：\n");
    PrintMatrix((int *)matrix2, N);

    // 测试Transpose3
    Transpose3((int *)matrix3, N);
    printf("Transpose3 转置后：\n");
    PrintMatrix((int *)matrix3, N);
}

//11-5
void Transpose4(int a[][N], int at[][M], int m, int n) {
    // 非方阵转置核心：遍历原矩阵所有元素，a[i][j] → at[j][i]
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            at[j][i] = a[i][j];
        }
    }
}

// 方法5：数组指针形式的非方阵转置
void Transpose5(int (*a)[N], int (*at)[M], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            *(at[j] + i) = *(a[i] + j);
        }
    }
}

// 方法6：一维指针形式的非方阵转置
// a: 原矩阵一维指针, at: 转置矩阵一维指针, m: 原行数, n: 原列数
void Transpose6(int *a, int *at, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            *(at + j * m + i) = *(a + i * n + j);
        }
    }
}

// 通用打印矩阵函数（适配非方阵：rows行 cols列）
void PrintMatrix1(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", *(matrix + i * cols + j));
        }
        printf("\n");
    }
    printf("-------------------------\n");
}

void Ex11_5(void) {
    // 初始化测试矩阵：2行3列（非方阵）
    int matrix1[M][N] = {{1, 2, 3}, {4, 5, 6}};
    int matrix2[M][N] = {{1, 2, 3}, {4, 5, 6}};
    int matrix3[M][N] = {{1, 2, 3}, {4, 5, 6}};

    // 转置矩阵：3行2列（原2行3列 → 转置后3行2列）
    int at4[N][M] = {0};
    int at5[N][M] = {0};
    int at6[N][M] = {0};

    printf("原始矩阵（2行3列）：\n");
    PrintMatrix1((int *)matrix1, M, N);  // M=2行, N=3列

    // 测试Transpose4
    Transpose4(matrix1, at4, M, N);
    printf("Transpose4 转置后（3行2列）：\n");
    PrintMatrix1((int *)at4, N, M);  // N=3行, M=2列

    // 测试Transpose5
    Transpose5(matrix2, at5, M, N);
    printf("Transpose5 转置后（3行2列）：\n");
    PrintMatrix1((int *)at5, N, M);

    // 测试Transpose6
    Transpose6((int *)matrix3, (int *)at6, M, N);
    printf("Transpose6 转置后（3行2列）：\n");
    PrintMatrix1((int *)at6, N, M);
}

//11-6
void InputArray(int *p,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",p+i*n+j);
        }
    }
}

int FindMax(int *p,int m,int n,int *pRow,int *pCol){
    int max=*p;
    *pRow=0;
    *pCol=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(*(p+i*n+j)>max){
                max=*(p+i*n+j);
                *pRow=i;
                *pCol=j;
            }
        }
    }
    return max;
}

void Ex11_6(void){
    int matrix1[M][N];
    InputArray((int *)matrix1,M,N);
    int i,j,max;
    max=FindMax((int *)matrix1,M,N,&i,&j);
    printf("最大值是：%d行%d列的%d;%d",i+1,j+1,matrix1[i][j],max);

}

//11-7
void Ex11_7(void){
    int m,n;
    printf("请输入一个班有几个学生:");
    scanf("%d",&n);
    printf("请输入共有几个班:");
    scanf("%d",&m);
    int *pi=(int *)calloc(m*n,sizeof(int));
    InputArray(pi,m,n);
    int i,j,max;
    max=FindMax(pi,m,n,&i,&j);
    printf("最高分为%d班%d号学生：%d分",i+1,j+1,max);
    free(pi);
}

int main() {
    Ex11_7();
    return 0;
}
