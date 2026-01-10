#include <stdio.h>
#include <stdlib.h>

int main()
{
    ex4_4();
    return 0;
}

void eg4_1(){
    char ch;
    printf("Press a key and then press Enter:");
    ch = getchar();
    ch = ch + 32;
    putchar(ch);
    putchar('\n');
}

void eg4_2(){
    char ch;
    printf("Press a key and then press Enter:");
    ch = getchar();
    ch = ch + 32;
    printf("%c, %d",ch,ch);
}

void eg4_4(){
    int a, b;
    scanf("%d%*c%d",&a,&b);
    printf("a = \"%d\", b = \"%d\"\n",a,b);
}

void ex4_2(){
    int a,b;
    float x,y;
    scanf("%d, %d",&a,&b);
    scanf("%5f, %5f",&x,&y);
    printf("a = %d, b = %d\n",a,b);
    printf("x = %f, y = %f\n",x,y);
}

void ex4_3(){
    char a,b;
    int c;
    scanf("%c%*c%c%*c%d",&a,&b,&c);
    printf("%2c,%2c,%d\n",a,b,c);
}

void ex4_4(){
    char ch;
    ch=getchar();
    ch = ch + ('A'-'a');
    printf("%c,%d",ch,ch);
}
