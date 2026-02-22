#include <iostream>
#include <string.h>

using namespace std;

//10-2
//main(){char * a = "main(){char *a = %c%s%c;printf(a,34,a,34);}";printf(a,34,a,34);}

//10-4
long Ex10_4Misssion(char *p){
    long sum=0;
    for(;*p!='\0';p++){
        if(isalpha(*p))
            continue;
        if(*p==' ')
            sum++;
    }
    return sum+1;
}

void Ex10_4(void){
    char a[]="Hello world! Welcome to China!";
    printf("%ld",Ex10_4Misssion(a));
}

//10-5
void Ex10_5_1(char a[],char ch){
    for(int i=0;a[i]!='\0';i++){
        if(a[i]==ch){
            for(int j=i;a[j]!='\0';j++)
                a[j]=a[j+1];
        }
    }
}

void Ex10_5_2(char *p,char ch){
    for(;*p!='\0';p++){
        if(*p==ch){
            for(char *q=p;*q!='\0';q++)
                *q=*(q+1);
        }
    }
}

void Ex10_5(void){
    char a[20]="Hello everyone";
    Ex10_5_1(a,'e');
    for(int i=0;a[i]!='\0';i++)
        printf("%c",a[i]);
}

//10-6
void Ex10_6_1(char a[],int maxlen){
    int i,len=0;
    while(a[len]!='\0'&&len<maxlen)
        len++;
    int edidx=2*len-1;
    if(edidx+1>maxlen){
        printf("数组长度不够");
        return;
    }
    for(i=len-1;i!=0;i--){
        a[i*2]=a[i];
    }
    for(i=1;i<edidx;i+=2)
        a[i]=' ';
    a[edidx]='\0';
}

void Ex10_6_2(char *p,int maxlen){
    char *start=p;
    int len=0;
    while(*p!='\0'&&len<maxlen){
        len++;
        p++;
    }
    char *end = start + 2*len*sizeof(char)-1;
    if(2*len>maxlen){
        printf("数组长度不够");
        return;
    }
    char *q=end-1;
    p=start+len-1;
    while(p>start){
        *q=*(p--);
        q-=2;
    }
    for(p=start+1;p<end;p+=2)
        *p=' ';
    *end='\0';
}

void Ex10_6(void){
    char a[50]="Helloeveryone";
    Ex10_6_2(a,50);
    for(int i=0;a[i]!='\0';i++)
        printf("%c",a[i]);
}

//10-7
void Swapch(char *a,char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}

void Ex10_7_1(char a[],int maxlen){
    int i,j,len=0;
    while(a[len]!='\0'&&len<maxlen)
        len++;
    for(i=0,j=len-1;i!=j;i++,j--){
        Swapch(&a[i],&a[j]);
    }
}

void Ex10_7_2(char *p,int maxlen){
    char *q=p;
    int len=0;
    while(*q!='\0'&&len<maxlen){
        len++;
        q++;
    }
    q--;
    while(p<q){
        Swapch(q--,p++);
    }
}

void Ex10_7(void){
    char a[50]="Helloeveryone";
    Ex10_7_2(a,50);
    for(int i=0;a[i]!='\0';i++)
        printf("%c",a[i]);
}


//10-8
void Ex10_8strcat(char *a,char *b){
    while(*a!='\0')
        a++;
    while(*b!='\0')
        *(a++)=*(b++);
}

void Ex10_8(void){
    char a[20]="Hello ";
    char b[20]="world";
    Ex10_8strcat(a,b);
    for(int i=0;a[i]!='\0';i++)
        printf("%c",a[i]);
}

//10-9
void Ex10_9Mission(char str[][10],int n){
    char temp[10];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp(str[j],str[i])<0){
                strcpy(temp,str[j]);
                strcpy(str[j],str[i]);
                strcpy(str[i],temp);
            }
        }
    }
}

void Ex10_9(void){
    char name[10][10];
    int n=0;
    printf("输入一共几个国家：\n");
    scanf("%d",&n);
    getchar();//读走回车
    printf("请依次用英文输入国家名：\n");
    for(int i=0;i<n;i++){
        gets(name[i]);
    }
    putchar('\n');
    Ex10_9Mission(name,n);
    for(int i=0;i<n;i++){
        puts(name[i]);
    }
}

//10-10
int Daycmp(char a[]){
    char chart[7][10] = {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"
    };
    int i;
    for(i=0;i<7;i++){
        if(strcmp(a,chart[i])==0)
            return i;
    }
    return i;
}

void Ex10_10(void){
    char a[10];
    printf("请输入星期：\n");
    gets(a);
    int i=Daycmp(a);
    if(i<7)
        printf("%d",i);
    else
        printf("请检查输入！\n");
}

int main()
{
    Ex10_10();
    return 0;
}

