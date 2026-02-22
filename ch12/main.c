#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

//12-1
typedef struct{
    int hour;
    int minute;
    int second;
}Time;

void Update(Time *p){
    p->second++;
    if(p->second==60){
        p->second=0;
        p->minute++;
    }
    if(p->minute==60){
        p->minute=0;
        p->hour++;
    }
    if(p->hour==24)
        p->hour=0;
}

void Display(Time *p){
    printf("%d:%d:%d\r",p->hour,p->minute,p->second);
    fflush(stdout);
}

void Delay(void){
    Sleep(10);
}

void Ex12_1(void){
    Time time;
    time.hour=time.minute=time.second=0;
    while(1){
        Update(&time);
        Display(&time);
        Delay();
    }
}

//12-2
void Update1(Time *p){
    p->second++;
    p->minute +=(p->second / 60);
    p->second%=60;
    p->hour += (p->minute /60);
    p->minute%=60;
    p->hour%=24;
}

void Ex12_2(void){
    Time time;
    time.hour=time.minute=time.second=0;
    while(1){
        Update1(&time);
        Display(&time);
        Delay();
    }
}

//12-3
struct Candidate{
    int zhang;
    int li;
    int wang;
};

void tongji(struct Candidate *p){
    char name[10];
    printf("请输入要投给谁：");
    scanf("%s",name);
    if(strcmp("zhang",name)==0)
        p->zhang++;
    else if(strcmp("li",name)==0)
        p->li++;
    else if(strcmp("wang",name)==0)
        p->wang++;
    else;
    system("cls");
}

void Ex12_3(void){
    struct Candidate candidate;
    candidate.zhang=0;
    candidate.li=0;
    candidate.wang=0;
    for(int i=0;i<10;i++)
        tongji(&candidate);
    printf("===== 投票结束！最终结果 =====\n");
    printf("zhang：%d 票\n", candidate.zhang);
    printf("li：%d 票\n", candidate.li);
    printf("wang：%d 票\n", candidate.wang);
}

//12-4
typedef struct Card{
    char suit[10];
    char face[10];
}Card;

void InitialCard(Card *p){
    // 定义4种花色
    const char *suits[] = {"Spades", "Hearts", "Clubs", "Diamonds"};
    // 定义13种牌面
    const char *faces[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    int card_idx = 0;  // 扑克牌索引（0-51）
    // 遍历4种花色
    for (int i = 0; i < 4; i++) {
        // 遍历13种牌面
        for (int j = 0; j < 13; j++) {
            // 给当前牌赋值花色（用strcpy复制字符串，不能直接=）
            strcpy(p[card_idx].suit, suits[i]);
            // 给当前牌赋值牌面
            strcpy(p[card_idx].face, faces[j]);
            card_idx++;  // 下一张牌
        }
    }
}

void Ex12_4(void){
    Card puke[52];
    InitialCard(puke);
    for(int i=0;i<52;i++)
        printf("%-8s:%s\n",puke[i].suit,puke[i].face);
}

//12-5
typedef struct node{
    int type;
    union{
    int ival;
    double dval;
    }dat;
}NodeType;

int main()
{
    Ex12_4();
    return 0;
}
