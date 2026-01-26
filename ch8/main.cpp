#include <iostream>
#include <math.h>
#define MAXNUM 40
#define ROW 3
#define COL 2

using namespace std;

int Bujige(int a[],int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]<60){
            count++;
        }
    }
    return count;
}
//8-3
void Ex8_3(void){
    int a[MAXNUM],n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d",Bujige(a,n));
}

//8-4
int ReadScore1(int a[]){
    int i;
    for(i=0;i<MAXNUM;i++){
        printf("请输入分数：");
        scanf("%d",&a[i]);
        if(a[i]<0)
            break;
    }
    return i;
}

int Average(int a[],int n){
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i];
    return sum/n;
}

int Ex8_4Mission(int a[],int n,int average){
    int count=0;
    for(int i=0;i<n;i++)
        if(a[i]<average)
            count++;
    return count;
}

void Ex8_4(void){
    int a[MAXNUM],n;
    n=ReadScore1(a);
    printf("%d",Ex8_4Mission(a,n,Average(a,n)));
}

//8-5
int ReadScore2(long Id[],int score[]){
    int i;
    for(i=0;i<MAXNUM;i++){
        printf("请输入学号 分数：");
        scanf("%ld %d",&Id[i],&score[i]);
        if(score[i]<0 || Id[i]<0){
            break;
        }
    }
    return i;
}

int FindMax(int score[],int n){
    int i=0,max=score[0],k=0;
    while(i<n){
        if(score[i]>max)
        {
            k=i;
            max=score[i];
        }
        i++;
    }
    return k;
}

void Ex8_5(void){
    long Id[MAXNUM];
    int score[MAXNUM],n;
    n=ReadScore2(Id,score);
    printf("%d",score[FindMax(score,n)]);
}

//8-6
void swap1(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}

int Ex8_6Mission(int a[],int n){
    int j=0,k=0;
    int max=a[0],min=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
            j=i;
        }
        if(a[i]<min){
            min=a[i];
            k=i;
        }
    }
    swap1(a[j],a[k]);
    return 0;
}

void Ex8_6(void){
    int a[]={1,2,3,4,5,6,7,8,9,10};
    Ex8_6Mission(a,10);
    for(int i=0;i<10;i++)
        printf("%4d",a[i]);
}

//8-7
void Ex8_7(void){
    int student[40],grade[10],i;
    for(i=0;i<40;i++)
        student[i]=rand()%10+1;
    for(i=0;i<10;i++)
        grade[i]=0;
    for(i=0;i<40;i++)
        grade[student[i]-1]++;
    printf("Grade\tCount\tHistogram\n");
    for(i=0;i<10;i++){
        printf("%3d  \t%3d  \t",i+1,grade[i]);
        for(int j=0;j<grade[i];j++)
            printf(" * ");
        printf("\n");
    }
}

//8-8
void Ex8_8Sort(int a[],int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        k=i;
        for(j=i+1;j<n;j++){
            if(a[j]>a[k])
            k=j;
        }
        if(k!=i)
            swap1(a[k],a[i]);
    }
}

float Ex8_8Mean(int a[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    return (float)sum/(float)n;
}

float Ex8_8Median(int a[],int n){
    float median;
    Ex8_8Sort(a,n);
    if(n%2==0){
        median=(float)(a[n/2-1]+a[n/2])/2.0;
    }
    else{
        median = a[n/2];
    }
    return median;
}

int Ex8_8Mode(int a[],int n){
    int max=a[0],j=0;
    for(int i=0;i<n;i++)
        if(a[i]>max){
            max=a[i];
            j=i;
        }
    return j+1;
}

void Ex8_8(void){
    int student[40],grade[10],i;
    for(i=0;i<40;i++)
        student[i]=rand()%10+1;
    for(i=0;i<10;i++)
        grade[i]=0;
    for(i=0;i<40;i++)
        grade[student[i]-1]++;
    printf("Grade\tCount\tHistogram\n");
    for(i=0;i<10;i++){
        printf("%3d  \t%3d  \t",i+1,grade[i]);
        for(int j=0;j<grade[i];j++)
            printf(" * ");
        printf("\n");
    }
    printf("平均值：%.2f\n中位数：%.2f\n众数：%d\n",Ex8_8Mean(student,40),Ex8_8Median(student,40),Ex8_8Mode(grade,10));
}

//8-9
int Ex8_9Mission(int a[MAXNUM][MAXNUM]){
    int result=0;
    for(int i=0;i<MAXNUM;i++)
        result+=a[i][i]+a[i][MAXNUM-i-1];
    return result;
}

void Ex8_9(void){
    int i,j,a[MAXNUM][MAXNUM];
    for(i=0;i<MAXNUM;i++)
        for(j=0;j<MAXNUM;j++)
            a[i][j]=rand()%10+1;
    printf("%d",Ex8_9Mission(a));
}

//8-10
void Ex8_10Mission(int a[ROW][COL],int b[ROW][COL],int c[ROW][COL]){
    for(int i=0;i<ROW;i++)
        for(int j=0;j<COL;j++)
            c[i][j]=a[i][j]+b[i][j];
}

void Ex8_10(void){
    int i,j,a[ROW][COL],b[ROW][COL],c[ROW][COL];
    for(i=0;i<ROW;i++)
        for(j=0;j<COL;j++){
            a[i][j]=rand()%10+1;
            b[i][j]=rand()%10+1;
        }
    Ex8_10Mission(a,b,c);
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++)
            printf("%-3d",c[i][j]);
        putchar('\n');
    }
}

//8-11
void Ex8_11_Initial(int a[7][7]){
    int i,j;
    for(i=0;i<7;i++){
        for(j=0;j<=i;j++){
            if(j==0)
                a[i][j]=1;
            else if(i==j)
                a[i][j]=1;
            else
                a[i][j]=a[i-1][j]+a[i-1][j-1];
        }
    }
}

void Ex8_11(void){
    int i,j,a[7][7];
    Ex8_11_Initial(a);
    for(i=0;i<7;i++){
        for(j=0;j<=i;j++)
            printf("%-4d",a[i][j]);
        putchar('\n');
    }
}

//8-12
void Ex8_12(void){
    int a[12];
    a[0]=1;
    a[1]=2;
    for(int i=2;i<12;i++)
        a[i]=a[i-1]+a[i-2];
    printf("%d",a[11]);
}

//8-13
void Ex8_13(void){
    int i,a[6000],num[6];
    for(i=0;i<6000;i++)
        a[i]=rand()%6+1;
    for(i=0;i<6;i++)
        num[i]=0;
    for(i=0;i<6000;i++)
        num[a[i]-1]++;
    for(i=0;i<6;i++)
        printf("%d出现次数：%d\n",i+1,num[i]);
}

//8-14
int Ex8_14Suiji(){
    int a,b,c,d;
    a=rand()%10;
    b=rand()%10;
    while(b==a){
        b=(b+1)%10;
    }
    c=rand()%10;
    while(c==a||c==b){
        c=rand()%10+1;
    }
    while(d==a||d==b||d==c){
        d=rand()%10;
    }
    return a*1000+b*100+c*10+d;
}

int Ex8_14IsRightA(int suiji,int guess){
    int a[2][4];
    for(int i=0;i<4;i++){
        if(i==0){
            a[0][i]=suiji/1000;
            a[1][i]=guess/1000;
        }
        if(i==1){
            a[0][i]=(suiji/100)%10;
            a[1][i]=(guess/100)%10;
        }
        if(i==2){
            a[0][i]=(suiji/10)%10;
            a[1][i]=(guess/10)%10;
        }
        if(i==3){
            a[0][i]=suiji%10;
            a[1][i]=guess%10;
        }
    }
    int count=0;
    for(int i=0;i<4;i++){
        if(a[0][i]==a[1][i])
            count++;
    }
    return count;
}

int Ex8_14IsRightB(int suiji,int guess){
    int i,a[2][4];
    for(i=0;i<4;i++){
        if(i==0){
            a[0][i]=suiji/1000;
            a[1][i]=guess/1000;
        }
        if(i==1){
            a[0][i]=(suiji/100)%10;
            a[1][i]=(guess/100)%10;
        }
        if(i==2){
            a[0][i]=(suiji/10)%10;
            a[1][i]=(guess/10)%10;
        }
        if(i==3){
            a[0][i]=suiji%10;
            a[1][i]=guess%10;
        }
    }
    int number[10];
    for(i=0;i<10;i++)
        number[i]=0;
    for(i=0;i<4;i++)
        number[a[0][i]]++;
    int count=0;
    for(i=0;i<4;i++)
        if(number[a[1][i]]==1)
            count++;
    return count;
}

int Ex8_14(void){
    int suiji=Ex8_14Suiji(),guess;
    int a,b,n=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&guess);
        a=Ex8_14IsRightA(suiji,guess);
        b=Ex8_14IsRightB(suiji,guess);
        printf("%dA%dB\n",a,b);
        if(guess==suiji){
            printf("答对了！\n");
            return 1;
        }
    }
    printf("失败，随机数是%d",suiji);
    return 0;
}

//8-15
int Ex8_15Insert(int a[],int n,int x){
    int low=0,high=n;
    int mid=(low+high)/2;
    while(low<high){
        if(a[mid]<x){
            low=mid+1;
        }
        else if(a[mid]>x){
            high=mid-1;
        }
        else
            break;
        mid=(low+high)/2;
    }
    for(int i=n;i>=mid;i--)
        a[i+1]=a[i];
    a[mid]=x;
    return 0;
}

void Ex8_15(void){
    int a[MAXNUM];
    for(int i=0;i<10;i++){
        a[i]=i;
    }
    Ex8_15Insert(a,10,6);
    for(int i=0;i<11;i++)
        printf("%d",a[i]);
}

//8-16
void Ex8_16BubbleSort(int a[],int n){
    int i,j;
    for(i=0; i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap1(a[j],a[j+1]);
            }
        }
    }
}

void Ex8_16(void){
    int a[MAXNUM];
    for(int i=0;i<10;i++)
        a[i]=rand()%40;
    for(int i=0;i<10;i++)
        printf("%3d",a[i]);
    Ex8_16BubbleSort(a,10);
    putchar('\n');
    for(int i=0;i<10;i++)
        printf("%3d",a[i]);
}

//8-17
void Ex8_17(void){
    // 用数组存储大整数，低位在前（arr[0]=个位，arr[1]=十位...）
    int factorial[50] = {0};
    // 初始值：1! = 1，有效位数为1
    factorial[0] = 1;
    int digit_count = 1;  // 记录当前阶乘的有效位数

    // 计算1~40的阶乘
    for (int n = 1; n <= 40; n++) {
        int carry = 0;  // 进位值

        // 数组整体乘以当前数n，处理每一位
        for (int i = 0; i < digit_count; i++) {
            int product = factorial[i] * n + carry;
            factorial[i] = product % 10;  // 保留当前位
            carry = product / 10;         // 更新进位
        }

        // 处理剩余的进位（可能有多位）
        while (carry > 0) {
            factorial[digit_count] = carry % 10;
            carry = carry / 10;
            digit_count++;
        }

        // 输出当前n的阶乘结果（从高位到低位打印）
        printf("%2d! = ", n);
        for (int i = digit_count - 1; i >= 0; i--) {
            printf("%d", factorial[i]);
        }
        printf("\n");
    }
}

//8-18
void Ex8_18Dafen(int a[][5],int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j]=rand()%11;
        }
    }
}

void Ex8_18Tongfen(int a[][5],int n,int m,float avgscore[][2]){
    int max,min,sum,j;
    for(int i=0;i<n;i++){
        max=a[i][0];
        min=a[i][0];
        sum=0;
        for(j=0;j<m;j++){
            if(max<a[i][j])
                max=a[i][j];
            if(min>a[i][j])
                min=a[i][j];
            sum+=a[i][j];
        }
        avgscore[i][0]=i+1;
        avgscore[i][1]=(float)(sum-max-min)/(float)(m-2);
    }
}

void swapF(float &a,float &b){
    float temp=a;
    a=b;
    b=temp;
}
/*
void Ex8_18HuojiangList(float a[][2],int n){
    for(int i=0;i<n;i++){
        float max=a[i][1],k=a[i][0];
        for(int j=i;j<n;j++){
            if(max<a[j][1]){
                max=a[j][1];
                k=a[i][0];
            }
        }
        swapF(max,a[i][1]);
        swapF(k,a[i][0]);
    }
}
*/
void Ex8_18HuojiangList(float a[][2],int n){
    // 选择排序：外层循环确定第i个位置的元素
    for(int i=0;i<n-1;i++){
        int max_idx = i;  // 记录当前最大值的下标
        // 内层循环找i到n-1中平均分最高的元素下标
        for(int j=i+1;j<n;j++){
            if(a[max_idx][1] < a[j][1]){
                max_idx = j;  // 更新最大值下标
            }
        }
        // 交换：把最大值放到第i个位置（同时交换编号和分数）
        swapF(a[i][0], a[max_idx][0]);  // 交换学生编号
        swapF(a[i][1], a[max_idx][1]);  // 交换平均分
    }
}

void Ex8_18Pingwei(float score[][2],int patc[][5],float pingwei[][2],int n){
    for(int i=0;i<5;i++){//控制评委循环
        pingwei[i][0]=i+1;
        pingwei[i][1]=0;
        for(int j=0;j<n;j++){//控制参赛循环
            pingwei[i][1]+=fabs(patc[j][i]-score[i][1]);
        }
    }
    Ex8_18HuojiangList(pingwei,5);
    for(int i=0;i<5;i++){
        printf("第%d名：%d号评委\n",i+1,(int)pingwei[i][0]);
    }
}

void Ex8_18(void){
    int n=3;
    int patc[n][5];//学生得分表
    Ex8_18Dafen(patc,3,5);
    printf("学生得分表如下:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++)
            printf("%3d",patc[i][j]);
        putchar('\n');
    }
    putchar('\n');
    float avgscore[n][2];//平均分表
    float pingwei[5][2];
    printf("评委得分表如下:\n");
    Ex8_18Pingwei(avgscore,patc,pingwei,3);
    putchar('\n');
    Ex8_18Tongfen(patc,3,5,avgscore);//按得分高低排名
    printf("学生均分表\n");
    for(int i=0;i<n;i++){
        printf("第%d号学生均分：%6.3f\n",(int)avgscore[i][0],avgscore[i][1]);
    }
    putchar('\n');
    Ex8_18HuojiangList(avgscore,n);
    for(int i=0;i<n;i++){
       printf("第%d名是第%d个学生，分数为%6.2f\n",i+1,(int)avgscore[i][0],avgscore[i][1]);
    }
}

int main()
{
    Ex8_18();
    return 0;
}
