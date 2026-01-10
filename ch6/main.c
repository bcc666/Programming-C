#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define EPS 1e-5

void eg6_9(){
    int magic, guess,counter;
    srand(time(NULL));
    magic=rand()%100;
    printf("猜一个0到99之间的数字：");
    for(counter=1;counter<=10;counter++){
        while(scanf("%d",&guess)!=1){
            while(getchar()!='\n');
            printf("请输入有效数字：");
        }
        if(magic==guess){
            printf("猜对了！共猜了%d次\n",counter);
            break;
        }
        else if(guess < magic)
            printf("猜错了，往大猜：");
        else
            printf("猜错了，往小猜：");
        if(counter ==10)
            printf("10次次数用尽，挑战失败!!\n");
    }

}

void ex6_3(){
    int x = 1,find = 0;
    while(!find){
        if(x%2==1 && x%3==2 && x%5==4 && x%6==5 && x%7==0){
            printf("x = %d\n",x);
            find=1;
        }
        x++;
    }
}

void ex6_4(int n){
    for(int i=1;i<=n;i++)
        printf("%d的平方是%d，%d的立方是%d\n",i,i*i,i,i*i*i);
}

void ex6_5(){
    float c_temp,f_temp;
    for(f_temp=0;f_temp<=300;f_temp++){
        c_temp=((float)5/(float)9)*(f_temp-32);
        printf("%.2f华氏摄氏度对应的标准摄氏度是：%.2f\n",f_temp,c_temp);
    }
}

void ex6_6(){
    float MonthInterest=0.001875;
    float YearInterest = 12*MonthInterest+1;
    float x=0;
    for(int i=0;i<5;i++){
        x=(x+1000)/YearInterest;
        //printf("%f\n",x);
    }
    printf("第一年应存入%f",x);
}

void ex6_7(float rate){
    float benjin = 1e6;
    int n=1;
    rate+=1;
    while(benjin<2*1e6)
    {
        benjin*=rate;
        n++;
    }
    printf("%d年后翻一番为%f",n,benjin);
}

void ex6_8(double x){
    int n=0;
    double sum=0,term=x;
    do{
        term = pow(-1,n)*x/(double)(2*n+1);
        sum+=term;
        n++;
    }while(fabs(term)>EPS);
    printf("%lf",4*sum);
}

void ex6_9(double x){
    int n=1;
    double sum=1,term=1;
    do{
        term = (term*x)/n;
        sum+=term;
        n++;
    }while(fabs(term)>EPS);
    printf("%lf",sum);
}

void ex6_10(){
    for(int i=100;i<1000;i++){
        int a,b,c;
        a=i/100;
        b=(i-a*100)/10;
        c=i-a*100-b*10;
        if(pow(a,3)+pow(b,3)+pow(c,3)==i)
            printf("%d\n",i);
    }
}

void ex6_11(int m){
    if(m<=1){
        printf("不存在");
        exit(0);
    }
    int n=1,temp=1,i=1;
    do{
        temp*=++i;
        n+=temp;
    }while(n<m);
    printf("%d",i-1);
}

void ex6_12(){
    int a,sum=0;
    while(1){
        scanf("%d",&a);
        if(a>0){
            sum+=a;
        }else{
            break;
        }
    }
    printf("%d",sum);
}

void ex6_13(){
        int a,sum=0;
    while(1){
        scanf("%d",&a);
        if(a>0){
            sum+=a;
        }
        else if(a<0){
            continue;
        }
        else{
            break;
        }
    }
    printf("%d",sum);
}

void ex6_14(){
    int f,m;
    for(f=0;f<=30;f++){
        for(m=0;m<=30;m++){
            if((m*3+f*2+30-m-f)==50){
                printf("男人%d个，女人%d个，孩子%d个\n",m,f,30-m-f);
                //exit(0);
            }
        }
    }
}

void ex6_15(){
    for(int i=0;i<=98;i++){
        for(int j=0;j<=98;j++){
            if((i*4+j*2)==386)
                printf("%d只兔子%d只鸡\n",i,j);
        }
    }
}

void ex6_16(){
    for(int i=0;i<=33;i++){
        for(int j=0;j<=100;j++){
            if((100-j-i*3) >= 0 && (i+j*3+(100-j-i*3)*5)==100)
                printf("%d只公鸡%d只母鸡%d只小鸡\n",100-j-i*3,j,i*3);
        }
    }
}

void ex6_17(){
    for(int i=1;i<50;i++){
        for(int j=1;j<50;j++){
            if((i*10+j*5+(50-i-j))==100){
                printf("%d张10元，%d张5元，%d张1元",i,j,50-i-j);
            }
        }
    }
}

void ex6_18_1(){
    for(int i=1;i<10;i++)
        printf(" %-2d",i);
    printf("\n");
    for(int i=1;i<10;i++)
        printf(" - ");
    printf("\n");
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            printf(" %-2d",i*j);
        }
    printf("\n");
    }
}

void ex6_18_2(){
    for(int i=1;i<10;i++)
        printf(" %-2d",i);
    printf("\n");
    for(int i=1;i<10;i++)
        printf(" - ");
    printf("\n");
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            printf(" %-2d",i*j);
            if(i==j)
                break;
        }
    printf("\n");
    }
}

void ex6_18_3(){
    for(int i=1;i<10;i++)
        printf(" %-2d",i);
    printf("\n");
    for(int i=1;i<10;i++)
        printf(" - ");
    printf("\n");
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            if(j<i){
                printf("   ");
                continue;
            }
            printf(" %-2d",i*j);
        }
    printf("\n");
    }
}

void ex6_19(){
    double sum1=0,sum2=0;
    double a=0.01,b=1e5;
    for(int i=0;i<30;i++){
        sum1+=a;
        a*=2;
        sum2+=b;
    }
    printf("陌生人给富翁%.2lf元\n富翁给陌生人%.2lf元",sum2,sum1);
}

void ex6_20_1(){
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            if(i==j)
                continue;
            for(int k=1;k<319;k++){
                if(pow(k,2)==(i*1000+i*100+j*10+j)){
                    printf("%d\n",i*1000+i*100+j*10+j);
                    break;
                }
            }
        }
    }
}

void ex6_20_2(){
    int t,h,s,g;
    for(int i=32;i<100;i++){
        int b=i*i;
        t=b/1000;
        h=(b/100)%10;
        s=(b/10)%10;
        g=b%10;
        if(t==h && s==g && t!=s){
            printf("%d",b);
        }
    }
}

void ex6_21(){
    int n=21*3;
    for(int i=0;i<147;i++){
        if(i%5==0 && i%6==0 && i%7==0){
            n-=2;
            continue;
        }
        if(i%5==0 && i%7==0)
            n--;
        if(i%6==0 && i%7==0)
            n--;
    }
    printf("%d",n);
}

void ex6_22(){
    double temp = 1,s1=0;
    for(int i=0;i<64;i++){
        s1+=temp;
        temp*=2;
    }
    double s2=pow(2,64)-1;
    printf("第一种方法：%e\n第二种方法：%e\n",s2,s1);
    printf("和%e立方米",s1/(1.42*(1e8)));
}

void ex6_23(){
    int f[12];
    f[0]=1;
    f[1]=2;
    for(int i=2;i<12;i++){
        f[i]=f[i-1]+f[i-2];
    }
    printf("%d",f[11]);
}

int main()
{
    ex6_23();
    //对例6.10测试
    /*
    for(int i=1;i!=0;i++){
        printf("欢迎第%d次游玩猜数游戏！\n",i);
        eg6_9();
        if(i>=1){
            printf("是否继续猜数（ Y / y or N / n )\n");
            char ch;
            scanf(" %c",&ch);
            if(ch=='N' || ch == 'n')
                i=-1;
        }
    }
    */
    return 0;
}
