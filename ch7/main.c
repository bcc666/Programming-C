#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int hour,minute,second;

void Update(void){
    second++;
    if(second==60){
        second=0;
        minute++;
    }
    if(minute==60){
        minute=0;
        hour++;
    }
    if(hour==24)
        hour=0;
}

void Display(void){
    printf("%d:%d:%d\n",hour,minute,second);
}

void Delay(void){
    int t;
    for(t=0;t<100000000;t++);
}

int Ex7_2(int a,int b){
    return a > b ? a : b;
}

int Ex7_3(int a, int b){
    for(int i=1;i<1e8;i++){
        if(i%a==0 && i%b==0)
            return i;
    }
    return 0;
}

long Ex7_4(int a){
    long result=1;
    for(int i=1;i<=a;i++){
        result*=i;
    }
    return result;
}

long Ex7_5(int a){
    long result=1,term=1;
    printf("1! ");
    if(a==1){
        return 1;
    }
    for(int i=2;i<=a;i++){
        printf(" + %d! ",i);
        term*=i;
        result+=term;
    }
    return result;
}

int Ex7_6_1(int a,int b){
    int t = a > b ? b:a;
    for(int i=t;i>0;i--){
        if(a%t==0 && b%t==0)
            return t;
    }
    return 1;
}

int Ex7_6_2(int a,int b){
    int r=a%b;
    if(r==0)
        return b;
    return Ex7_6_2(b,r);
}

int Ex7_6_3(int a,int b){
    if(a>b)
        return Ex7_6_3(a-b,b);
    if(a<b)
        return Ex7_6_3(a,b-a);
    return a;
}

int Ex7_7(int n){
    int i=1;
    float x=1,y;
    y=n*x+1;
    do{
        y=y*n/(n-1)+1;
        i++;
        if(y!=(int)y){
            x=x+1;
            y=n*x+1;
            i=1;
        }
    }while(i<n);
    return (int)y;
}

int Ex7_8(int n){
    int result=10;
    if(n==1)
        return result;
    for(int i=1;i<n;i++)
        result+=2;
    return result;
}

int Ex7_9(int result){
    for(int a=0;a<10;a++)
        for(int b=0;b<10;b++)
            for(int c=0;c<10;c++)
                if(result==a*122+b*212+c*221)
                    return a*100+c*10+b;
    return 0;
}

int RandNum(void){
    srand(time(NULL));
    return rand();
}

void Ex7_10(void){
    int count=0,first=0,temp=0,cunchu;
    srand(time(NULL));
    int suiji = rand()%100;
    if(suiji%2==0){
        printf("生成的随机数是%d，为偶数，计算机先报数\n",suiji);
        first=0;
    }
    else{
        printf("生成的随机数是%d，为奇数，玩家先报数（从1开始）\n",suiji);
        first=1;
    }
    while(count<30){
        if((30-count)%3==1){
            printf("可以报1个数：");
            temp=1;
        }
        else if((30-count)%3==2){
            printf("可以报2个数：");
            temp=2;
        }
        else{
            srand(time(NULL));
            suiji = (rand()%2)+1;
            temp=suiji;
            printf("可以报%d个数：",temp);
        }
        while(temp>0){
            if(first==0){
                //计算机报数
                printf("%d\n",++count);
                temp--;
                if(temp==0)
                    first=1;//将报数权转移
            }
            else{
                /*
                if(scanf("%d",&cunchu)!=1)
                    printf("请报正确数字");
                if(cunchu!=++count){
                    printf("请报正确数字");
                    continue;
                }
                */
                scanf("%d",&cunchu);
                count++;
                temp--;
                if(temp==0)
                    first=0;
            }
        }
    }
    if(first==0){
        printf("恭喜玩家获得胜利");
    }
    else{
        printf("计算机获得胜利");
    }
}

void Move(int n,char a,char b){
    printf("Move %d : From %c to %c\n",n,a,b);
}

void Hanoi(int n,char a,char b,char c){
    if(n==1)
        Move(n,a,b);
    else{
        Hanoi(n-1,a,c,b);
        Move(n,a,b);
        Hanoi(n-1,c,b,a);
    }
}

void Ex7_11(void){
    Hanoi(3,'a','b','c');
}

int IsPrime_1(int n){
    if(n<=1)
        return 0;
    for(int i=2;i<n;i++)
        if(n%i==0)
            return 0;
    return 1;
}

int IsPrime_2(int n){
    if(n<=1)
        return 0;
    for(int i=2;i<pow(n,0.5);i++)
        if(n%i==0)
            return 0;
    return 1;
}

void Ex7_12_Mission3(int n){
    int result=0;
    for(int i=1;i<=n;i++){
        if(IsPrime_2(i)){
            result+=i;
            printf("%d",i);
        }
    }
    printf("%d",result);
}

void Ex7_12_Mission4(int m){
    if(IsPrime_2(m))
        printf("素数");
    else{
        for(int i=2;i<m;i++){
            if(m%i==0)
                printf("%d ",i);
        }
    }
}

int IsPerfect(int m){
    int sum=0;
    for(int i=1;i<m;i++){
        if(m%i==0)
            sum+=i;
    }
    if(sum==m)
        return 1;
    return 0;
}

void Ex7_12_Mission6(int m){
    if(IsPrime_2(m)){
        printf("是素数");
    }
    else{
        printf("%d=",m);
        int i;
        while(m!=1){
            for(i=2;i<m;i++){
                if(m%i==0)
                break;
            }
            m=m/i;
            if(m==1)
                printf("%d ",i);
            else
                printf("%d* ",i);
        }
    }
}


void Ex7_12(void){
    Ex7_12_Mission6(90);
}

void Ex7_13_Shuchu(int status){
    int a = RandNum()%4;
    if(status==1){
        switch (a){
        case 0:
            printf("Very good!\n");
            break;
        case 1:
            printf("Excellent!\n");
            break;
        case 2:
            printf("Nice work!\n");
            break;
        default:
            printf("Keep up the good work!\n");
        }
    }
    else if(status ==0){
        switch (a){
        case 0:
            printf("No. Please try again.\n");
            break;
        case 1:
            printf("Wrong. Try once more.\n");
            break;
        case 2:
            printf("Don't give up.\n");
            break;
        default:
            printf("Not correct. Keep trying.\n");
        }
    }
}

void Ex7_13_Mission1(){
    int a,b,c;
    a = RandNum()%10+1;
    b = RandNum()%10+1;
    printf("%d*%d = ?\n",a,b);
    while(1){
        scanf("%d",&c);
        if(c==a*b){
            printf("算对了！");
            break;
        }
        else{
            printf("算错了，重新输入答案：\n");
        }
    }
}

void Ex7_13_Mission2(){
    int a,b,c,flag=3;
    a = RandNum()%10+1;
    b = RandNum()%10+1;
    printf("%d*%d = ?\n",a,b);
    while(flag--){
        scanf("%d",&c);
        if(c==a*b){
            printf("算对了！");
            break;
        }
        else{
            if(flag)
                printf("第%d次算错了，重新输入答案：\n",3-flag);
            else
                printf("次数用完了，游戏结束");
        }
    }
}

int Ex7_13_Mission3_1(void){
    int a,b,c;
    a = RandNum()%10+1;
    b = RandNum()%10+1;
    printf("%d*%d = ?\n",a,b);
    scanf("%d",&c);
    if(c==a*b){
        printf("算对了！\n");
        return 10;
    }
    printf("算错了\n");
    return 0;
}

void Ex7_13_Mission3(){
    int score=0;
    for(int i=0;i<10;i++){
        printf("第%d题：",i+1);
        score += Ex7_13_Mission3_1();
    }
    printf("总分为%d",score);
}

int Ex7_13_Mission4_1(void){
    int a,b,c,d;
    a = RandNum()%10+1;
    b = RandNum()%10+1;
    d = RandNum()%4;
    if(d==0){
        printf("%d+%d = ?\n",a,b);
        scanf("%d",&c);
        if(c==a+b){
            Ex7_13_Shuchu(1);
            return 10;
        }
    }else if(d==1){
        printf("%d-%d = ?\n",a,b);
        scanf("%d",&c);
        if(c==a-b){
            Ex7_13_Shuchu(1);
            return 10;
        }
    }else if(d==2){
        printf("%d*%d = ?\n",a,b);
        scanf("%d",&c);
        if(c==a*b){
            Ex7_13_Shuchu(1);
            return 10;
        }
    }else{
        printf("%d/%d = ?\n",a,b);
        scanf("%d",&c);
        if(c==a/b){
            Ex7_13_Shuchu(1);
            return 10;
        }
    }
    Ex7_13_Shuchu(0);
    return 0;
}

void Ex7_13_Mission4(){
    int score=0;
    for(int i=0;i<10;i++){
        printf("第%d题：",i+1);
        score += Ex7_13_Mission4_1();
    }
    printf("总分为%d",score);
}

void Ex7_13_Mission5(){
    int score;
    do{
        score=0;
        for(int i=0;i<10;i++){
            printf("第%d题：",i+1);
            score += Ex7_13_Mission4_1();
        }
        printf("正确率为 %d%%",score);
        if(score<75)
            printf("低于75分，重测！\n");
        else
            printf("高于75分，通过！\n");
    }while(score<75);
}

void Ex7_13(void){
    Ex7_13_Mission5();
}

int main()
{
    Ex7_10();
    //printf("%d",Ex7_9(1999));
    /*Ex7_1
    int i;
    hour = minute = second=0;
    for(i=0;i<1e6;i++){
        Update();
        Display();
        Delay();
    }*/
    return 0;
}
