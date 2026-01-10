#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-6

int max1(int a,int b){
    return a>b?a:b;
}

float Jisuanqi(float a,char op,float b){
    float result;
    switch(op){
    case '+':
        result=a+b;
        break;
    case '-':
        result=a-b;
        break;
    case '/':
        if(b==0) printf("除数不能为0");
        else result = a/b;
        break;
    case '^':
        result = pow(a,b);
        break;
    case '*':
    case 'x':
    case 'X':
        result = a*b;
        break;
    default:
        printf("非法操作符");
        exit(0);
    }
    return result;
}

void IsTriangle(float a,float b,float c){
    int flag =1;//是否是一般三角形
    if(a+b>c && a+c>b && b+c>a){
        if(fabs(a-b)<=EPS || fabs(a-c)<=EPS || fabs(b-c)<=EPS){
            if(fabs(a-b)<=EPS && fabs(a-c)<=EPS && fabs(b-c)<=EPS){
                printf("等边");
                flag=0;
            }
            else{
                printf("等腰");
                flag=0;
            }
        }
        if(fabs(a*a+b*b-c*c)<=EPS || fabs(a*a+c*c-b*b)<=EPS || fabs(c*c+b*b-a*a)<=EPS){
            printf("直角");
            flag=0;
        }
        if(flag) printf("一般");
        printf("三角形");
    }
    else
        printf("不是三角形");
}

float ex5_1(float a){
    if(a<0)
        return -a;
    return a;
}

void ex5_2(int a){
    if(a%2)
        printf("是奇数");
    else
        printf("是偶数");
}

void ex5_3(float a,float b,float c){
    if(a+b>c && a+c>b && b+c>a){
        float s,area;
        s = (a+b+c)/2;
        area = (float)sqrt(s*(s-a)*(s-b)*(s-c));
        printf("area = %f\n",area);
    }
    else{
        printf("不是三角形");
    }
}

void ex5_4(float benjin,int nianxian){
    float lilv=1;
    switch (nianxian){
    case 1:
        lilv+=0.0225;
        break;
    case 2:
        lilv+=0.0243;
        break;
    case 3:
    case 4:
        lilv+=0.0270;
        break;
    case 5:
    case 6:
    case 7:
        lilv+=0.0288;
        break;
    default:
        lilv+=0.03;
    }
    printf("本息共：%f",benjin*pow(lilv,nianxian));
}

void ex5_5(int year){
    int flag=0;
    if(((year%4)==0&&((year%100)!=0))||year%400==0)
        flag=1;
    else
        flag=0;
    if(flag)
        printf("%d是闰年",year);
    else
        printf("%d不是闰年",year);
}

void ex5_6(int year){
    int flag;
    flag=(((year%4)==0&&((year%100)!=0))||year%400==0)?1:0;
    if(flag)
        printf("%d是闰年",year);
    else
        printf("%d不是闰年",year);
}

void ex5_7(char ch){
    if(ch<91)
        ch+=32;
    else
        ch-=32;
    putchar(ch);
}

void ex5_8(char ch){
    if(ch>=48 && ch<=57)
        printf("数字字符");
    else if(ch>=65 && ch<=90)
        printf("大写字符");
    else if(ch>=97 && ch<=122)
        printf("小写字符");
    else if(ch==32)
        printf("空格");
    else
        printf("其他字符");
}

void ex5_9(float score){
    if(score<0 || score>100)
        printf("输入有效成绩");
    else{
        if(score>=90)
            printf("A");
        else if(score>=80)
            printf("B");
        else if(score>=70)
            printf("C");
        else if(score>=60)
            printf("D");
        else
            printf("E");
    }
}

void ex5_10(int year,int month){
    int flag;
    if(((year%4)==0&&((year%100)!=0))||year%400==0)
        flag=1;
    else
        flag=0;
    if(flag){
        switch (month){
            case 1:
                printf("1月有31天\n");
                break;
            case 2:
                printf("2月有29天\n");
                break;
            case 3:
                printf("3月有31天\n");
                break;
            case 4:
                printf("2月有30天\n");
                break;
            case 5:
                printf("2月有31天\n");
                break;
            case 6:
                printf("2月有30天\n");
                break;
            case 7:
                printf("2月有31天\n");
                break;
            case 8:
                printf("2月有31天\n");
                break;
            case 9:
                printf("2月有30天\n");
                break;
            case 10:
                printf("2月有31天\n");
                break;
            case 11:
                printf("2月有30天\n");
                break;
            case 12:
                printf("2月有31天\n");
                break;
            default:
                printf("请输入有效月份");
        }
    }
    else{
        switch (month){
            case 1:
                printf("1月有31天\n");
                break;
            case 2:
                printf("2月有28天\n");
                break;
            case 3:
                printf("3月有31天\n");
                break;
            case 4:
                printf("2月有30天\n");
                break;
            case 5:
                printf("2月有31天\n");
                break;
            case 6:
                printf("2月有30天\n");
                break;
            case 7:
                printf("2月有31天\n");
                break;
            case 8:
                printf("2月有31天\n");
                break;
            case 9:
                printf("2月有30天\n");
                break;
            case 10:
                printf("2月有31天\n");
                break;
            case 11:
                printf("2月有30天\n");
                break;
            case 12:
                printf("2月有31天\n");
                break;
            default:
                printf("请输入有效月份");
        }
    }
}

void ex5_11(char sex,float faHeight,float moHeight,char sports,char diet){
    float height;
    switch (sex){
    case 'M':
        height = (faHeight+moHeight)*0.54;
        break;
    case 'F':
        height = (faHeight*0.923+moHeight)/2;
        break;
    default:
        printf("请输入有效性别");
    }
    if(sports=='Y')
        height*=1.02;
    if(diet=='Y')
        height*=1.015;
    printf("孩子的身高可能为%.2f",height);
}

void ex5_12(float h,float w){
    float t = w/(h*h);
    printf("您的体脂数为：%d\n",(int)t);
    if(t<18)
        printf("低体重");
    else if(t<25)
        printf("标准体重");
    else if(t<27)
        printf("超重体重");
    else
        printf("肥胖");
}
int main()
{
    ex5_12(1.78,75);

    //ex5_11('M',178,160,'Y','Y');

    /*
    //测试计算器
    float a,b;
    char ch;
    scanf("%f %c%f",&a,&ch,&b);
    printf("%.2f%c%.2f=%.2f",a,ch,b,Jisuanqi(a,ch,b));
    */

    //测试三角形
    //IsTriangle(3,4,5);

    /*
    //测试scanf
    int a, b, max,ret;
    printf("Input a,b:");
    ret = scanf("%d,%d",&a,&b);
    if(ret!=2){
        printf("Input ERROR!\n");
    }
    else{
        printf("max = %d\n",max1(a,b));
    }
    */
    return 0;
}
