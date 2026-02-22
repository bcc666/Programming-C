#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#define NO 120
#define SIZE 20

using namespace std;
//例13-4
int ReadFromFile(char fileName[],char msg[][SIZE]){
    FILE *fp=fopen(fileName,"r");
    if(fp==NULL){
        printf("can not open file %s\n",fileName);
        return -1;
    }
    int i=0;
    while(fgets(msg[i],sizeof(msg[i]),fp))
        i++;
    fclose(fp);
    return i;
}

void PrizeDraw(char msg[][SIZE],int total){
    int i=0;
    int k;
    while(1){
        k=i%total;
        if(kbhit()){
            system("cls");
            printf("恭喜:%s",msg[k]);
            system("pause");
        }
        else{
            printf("%s",msg[k]);
        }
        i++;
    }
}

void Eg13_4(void){
    char msg[NO][SIZE];
    char fileName[SIZE];
    printf("请输入抽奖者信息文件名：");
    scanf("%s",fileName);
    int total=ReadFromFile(fileName,msg);
    printf("总计%d名学生\n",total);
    PrizeDraw(msg,total);
}

//13-1
int ReadType(char fileName[], int fil[]) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("can not open file %s\n", fileName);
        return -1;
    }

    int num = 0;
    int a, b, c;
    while (num < NO) {  // 防止数组越界
        int scannum = fscanf(fp, "%1d%1d%1d", &a, &b, &c);

        // 情况1：读取不足3个数字（文件末尾或格式错误）
        if (scannum < 3) {
            if (scannum == 2) {
                fil[num++] = a * 10 + b;
            } else if (scannum == 1) {
                fil[num++] = a;
            }
            break;  // 处理完剩余数字后直接跳出循环，避免后续错误逻辑
        }

        // 情况2：成功读取3个数字，正常处理
        int three_digit = a * 100 + b * 10 + c;
        if (three_digit > 255) {
            fil[num++] = a * 10 + b;
            // 回溯1个字符（第3个数字留给下一次读取），并判断是否成功
            if (fseek(fp, -1, SEEK_CUR) != 0) {
                printf("文件指针回溯失败！\n");
                break;
            }
        } else {
            fil[num++] = three_digit;
        }
    }
    fclose(fp);
    return num;
}

void ASCIIDraw(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", (char)a[i]);
    }
    printf("\n");
}

void Ex13_1(void) {
    int filecontent[NO] = {0};
    char fileName[SIZE];
    printf("请输入需要转换的文件名：");
    scanf("%s", fileName);

    int total = ReadType(fileName, filecontent);
    //如果文件打开失败，不执行后续操作
    if (total == -1) {
        printf("文件读取失败！\n");
        return;
    }

    printf("总计%d个字符\n", total);
    ASCIIDraw(filecontent, total);
}

//13-2
typedef struct date{
    int year;
    int month;
    int day;
}DATE;
typedef struct student{
    long studentID;
    char studentName[10];
    char stuGender;
    DATE birthday;
    int score[4];
    float aver;
}STUDENT;


void Ex13_2(void){
    STUDENT stu[4]={{100310121,"王刚",'M',{1991,5,19},{72,83,90,82}},
                    {100310122,"李晓明",'M',{1992,8,6},{88,83,90,82}},
                    {100310123,"王力宏",'F',{1991,9,19},{56,83,90,82}},
                    {100310124,"陈丽丽",'F',{1991,5,19},{92,83,90,82}}
                    };
    for(int i=0;i<4;i++){
        stu[i].aver=0;
        for(int j=0;j<4;j++){
            stu[i].aver+=stu[i].score[j];
        }
        stu[i].aver/=4.0;
    }
    FILE *fp=fopen("score.txt","w");
    for(int i=0;i<4;i++){
        fprintf(fp,"%10ld%8s%3c%7d/ %02d/ %02d%4d%4d%4d%4d%6.1f\n",
            stu[i].studentID,
            stu[i].studentName,
            stu[i].stuGender,
            stu[i].birthday.year,
            stu[i].birthday.month,
            stu[i].birthday.day,
            stu[i].score[0],
            stu[i].score[1],
            stu[i].score[2],
            stu[i].score[3],
            stu[i].aver);
    }
    fclose(fp);
}

//13-3查找学号
FILE *FindId(FILE *fp,long tar_id){
    if(fp==NULL)
        return NULL;

    rewind(fp);
    STUDENT temp;
    long pos;

    while (1) {
        // 1. 先记录当前文件指针位置（该行的起始位置）
        pos = ftell(fp);
        if (pos == -1) {  // 获取指针位置失败
            break;
        }

        // 2. 按结构体格式读取一行数据
        int read_count = fscanf(fp, "%10ld%8s%3c%7d/ %02d/ %02d%4d%4d%4d%4d%6.1f\n",
                               &temp.studentID,
                               temp.studentName,
                               &temp.stuGender,
                               &temp.birthday.year,
                               &temp.birthday.month,
                               &temp.birthday.day,
                               &temp.score[0],
                               &temp.score[1],
                               &temp.score[2],
                               &temp.score[3],
                               &temp.aver);

        // 3. 判断读取状态：读取失败/文件末尾 → 跳出循环
        if (read_count != 11) {  // 结构体共11个字段（学号+姓名+性别+生日3个+成绩4个+平均分）
            break;
        }

        // 4. 找到目标学号 → 回退指针到该行开头，返回指针
        if (temp.studentID == tar_id) {
            fseek(fp, pos, SEEK_SET);  // 指针移回该行起始位置
            return fp;
        }
    }

    // 遍历完文件未找到目标学号
    return NULL;
}

//13-4
int CopyFile(const char *srcName,const char *dstName){
    FILE *fpSrc=NULL,*fpDst=NULL;
    int ch, rval = 1;
    if((fpSrc=fopen(srcName,"r"))==NULL) goto ERROR;
    if((fpDst=fopen(dstName,"w"))==NULL) goto ERROR;
    while((ch=fgetc(fpSrc))!=EOF){
        if(fputc(ch,fpDst)==EOF) goto ERROR;
    }
    fflush(fpDst);
    goto EXIT;
ERROR:
    rval=0;
EXIT:
    if(fpSrc!=NULL) fclose(fpSrc);
    if(fpDst!=NULL) fclose(fpDst);
    return rval;
}

//13-5
int AppendFile(const char *srcName,const char *dstName){
    FILE *fpSrc=NULL,*fpDst=NULL;
    int ch, rval = 1;
    if((fpSrc=fopen(srcName,"r"))==NULL) goto ERROR;
    if((fpDst=fopen(dstName,"a"))==NULL) goto ERROR;
    while((ch=fgetc(fpSrc))!=EOF){
        if(fputc(ch,fpDst)==EOF) goto ERROR;
    }
    fflush(fpDst);
    goto EXIT;
ERROR:
    rval=0;
EXIT:
    if(fpSrc!=NULL) fclose(fpSrc);
    if(fpDst!=NULL) fclose(fpDst);
    return rval;
}

//13-6
void SwapStudent(STUDENT *stu1,STUDENT *stu2){
    STUDENT t=*stu1;
    *stu1=*stu2;
    *stu2=t;
}
void ScoreSort(const char *fileName){
    FILE *fp=fopen(fileName,"r");
    int n=0;//从文件里读出共有几个学生
    STUDENT stu[NO];
    for(int i=0;i<4;i++){
        fscanf(fp, "%10ld%8s%3c%7d/ %02d/ %02d%4d%4d%4d%4d%6.1f\n",
                               &stu[i].studentID,
                               stu[i].studentName,
                               &stu[i].stuGender,
                               &stu[i].birthday.year,
                               &stu[i].birthday.month,
                               &stu[i].birthday.day,
                               &stu[i].score[0],
                               &stu[i].score[1],
                               &stu[i].score[2],
                               &stu[i].score[3],
                               &stu[i].aver);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(stu[j].aver>stu[i].aver)
                SwapStudent(&stu[j],&stu[i]);
        }
    }
    fclose(fp);
}

//13-7
void PrizeDraw1(char msg[][SIZE],int total,int prizesNum){
    int i=0;
    int j=0;
    int k;
    while(j!=prizesNum){
        k=i%total;
        if(kbhit()){
            j++;
            system("cls");
            printf("恭喜第%d位中奖者:%s",j,msg[k]);
            system("pause");
        }
        else{
            printf("%s",msg[k]);
        }
        i++;
    }
}

//13-8
void PrizeDraw2(char msg[][SIZE],int total,int prizesNum){
    int i=0;
    int j=0;
    int k;
    int flag[total]={0};
    while(j!=prizesNum){
        k=i%total;
        if(kbhit()&&flag[k]==0){
            j++;
            system("cls");
            printf("恭喜第%d位中奖者:%s",j,msg[k]);
            flag[k]=1;
            system("pause");
        }
        else{
            printf("%s",msg[k]);
        }
        i++;
    }
}

int main() {
    Ex13_2();
    return 0;
}
