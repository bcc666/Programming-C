#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI_d 3.14159

int main()
{
    /*
    float a,b,c,s,area;
    printf("Input a,b,c:");
    scanf("%f,%f,%f",&a,&b,&c);
    s = (a+b+c)/2;
    area = (float)sqrt(s*(s-a)*(s-b)*(s-c));
    printf("area = %f\n",area);
    */
    process3_5();
    return 0;
}
void process3_2(){
    int a;
    printf("input a number:");
    scanf("%d",&a);
    if(a<0)
        a=-a;
    printf("%d",a/100+((a%100)/10)*10+((a%100)%10)*100);
}

void process3_3(){
    double rate = 1.0225;
    int n;
    double capital;
    printf("输入存款期及本金：");
    scanf("%d,%lf",&n,&capital);
    double deposit = capital*pow(rate,n);
    printf("%d年后本利之和：%lf",n,deposit);
}

void process3_4(){
    printf("输入一元二次方程abc的值：");
    float a,b,c;
    scanf("%f %f %f",&a,&b,&c);
    double delta=pow(b*b-4*a*c,0.5);
    double r1 = (-b+delta)/2*a;
    double r2 = (-b-delta)/2*a;
    printf("两个根为：%lf，%lf",r1,r2);
}

void process3_5(){
    const double PI_c = 3.14159;
    double r;
    printf("输入球的半径：");
    scanf("%lf",&r);
    double v = ((double)4/(double)3)*PI_c*pow(r,3);
    double s = 4*PI_d*pow(r,2);
    printf("球的体积为%lf，表面积为%lf",v,s);
}
