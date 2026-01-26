#include <iostream>
#include <math.h>

using namespace std;

//9-3
void SwapInt(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

//9-4
void Ex9_4(void){
    int a[10];
    for(int i=0;i<10;i++)
        a[i]=rand()%20;
    int min_idx=0,max_idx=0;
    for(int i=0;i<10;i++){
        if(a[i] < a[min_idx])
            min_idx=i;
        if(a[i] > a[max_idx])
            max_idx=i;
    }
    printf("最小值下标：%d\n最大值下标：%d\n",min_idx,max_idx);
    SwapInt(&a[min_idx],&a[max_idx]);
    printf("交换数组位置后：最小值下标：%d\t值为%d\n最大值下标：%d\t值为%d\n",min_idx,a[min_idx],max_idx,a[max_idx]);
}

//9-5
int DayofYear(int year,int month,int day){
    int sum=0;
    if(month<1 ||month>12)
        return -1;
    int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        a[2]=29;
    }
    else{
        a[2]=28;
    }
    for(int i=1;i<month;i++){
        sum+=a[i];
    }
    sum+=day;
    return sum;
}

void MonthDay(int year,int yearDay,int *pMonth,int *pDay){
    int a[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
    int i;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        for(i=2;i<13;i++)
            a[i]++;
    }
    for(i=1;i<13;i++){
        if(yearDay>a[i-1] && yearDay<a[i])
            break;
    }
    *pMonth=i;
    *pDay=yearDay-a[i-1];
}

void Ex9_5Mission(void){
    printf("\n1.year/ month/ day ->yearDay\n2.yearDay ->year/ month/ day\n3.Exit\nPlease enter your choice:\n");
    int control=0;
    int year,month,day,yearDay;
    scanf("%d",&control);
    switch (control)
    {
    case 1:
        printf("1.year/ month/ day ->yearDay\n");
        scanf("%d/ %d/ %d",&year,&month,&day);
        yearDay=DayofYear(year,month,day);
        printf("%d/ %d/ %d ->%d\n",year,month,day,yearDay);
        break;
    case 2:
        printf("2.yearDay ->year/ month/ day\nPlease enter year and yearDay:\n");
        scanf("%d/ %d",&year,&yearDay);
        MonthDay(year,yearDay,&month,&day);
        printf("%d ->%d/ %d/ %d\n",yearDay,year,month,day);
        break;
    case 3:
        exit(0);
    default:
        printf("输入正确的值\n");
    }
}

void Ex9_5(void){
    while(1)
        Ex9_5Mission();
}

//9-6
float Y1(float x){
    return x*x+1;
}

float Y2(float x){
    return x/(1+x*x);
}

float Integral(float (*f)(float x),float a,float b){
    float delta=0.005;
    float sum=0,a_delta;
    for(a_delta=a+delta;a_delta<b;a_delta+=delta)
        sum+=((*f)(a_delta)+(*f)(a_delta-delta))*delta/2;
    return sum;
}

void Ex9_6(void){
    printf("y1=%f\ny2=%f\n",Integral(Y1,0,1),Integral(Y2,0,3));
}

int main()
{
    Ex9_6();
    return 0;
}
