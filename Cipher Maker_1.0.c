/**
***   v1.0
**/
#include <stdio.h>
#include <stdlib.h>
#define STAR "\t\t*******************************************************"

void number(int length);    //打印出指定长度的数字密码 1
void lowerchar(int length);    //打印出指定长度的小写字母密码 2
void upperchar(int length);    //打印出指定长度的大写字母密码 3
void lower_number(int length);    //打印出指定长度的小写字母和数字密码 4
void upper_number(int length);    //打印出指定长度的大写字母和数字密码 5
void lower_upper_number(int length);    //打印出指定长度的小写字母和数字密码 6
void allchar(int length);    //打印出指定长度的所有字符的密码 7

int i,password;

int main(void)
{
    int length,choice,test;
    
    length=1;
    
    while( length != 0 )
    {
        printf("\t\t请输入密码长度(输入0结束):");
        while( scanf("%d",&length) != 1 || length < 0 )
        {
            printf("\t\t请输入正确的密码长度(输入0结束):");
            getchar();
        }
        if ( length == 0 )
        {
            system("pause");
            exit(0);
        }
        do
        {
            system("cls");
            getchar();
            printf("%s",STAR);
            printf("\n\t\t请选择密码强度:\n");
            printf("\t\t\t\t1.数字:\n");
            printf("\t\t\t\t2.小写字母:\n");
            printf("\t\t\t\t3.大写字母:\n");
            printf("\t\t\t\t4.数字+小写字母:\n");
            printf("\t\t\t\t5.数字+大写字母:\n");
            printf("\t\t\t\t6.数字+大写字母+小写字母:\n");
            printf("\t\t\t\t7.数字+大写字母+小写字母+特殊符号:\n"); 
            printf("%s\n",STAR);
            printf("\n\t\t请选择:");
            test = scanf("%d",&choice);
            if ( choice < 1 || choice > 7 )
                test = 0;
        }while( test !=1 );
        switch(choice)
        {
        case 1:
            number(length);
            break;
        case 2:
            lowerchar(length);
            break;
        case 3:
            upperchar(length);
            break;
        case 4:
            lower_number(length); 
            break;
        case 5:
            upper_number(length);
            break;
        case 6:
            lower_upper_number(length);
            break;
        case 7:
            allchar(length);
            break;
        default :
            printf("输入错误!\n");
            break;
        }
    }
    system("pause");
    return 0;
}



void number(int length)    //打印出指定长度的数字密码 1
{

    
    srand(time(0));     /* 生成随机种子 */
    
    system("cls");    /* 清除屏幕 */
    printf("\n\t\t生成%d位的密码为：",length);
    for(i = 0;i < length;)
    {
        password=rand()%128;    /* 随机生成128以内的数 */
        if ( password >= 48 && password <= 57 )   //这里控制输出的字符是否符合要求
        {
            printf("%c",password);
            i++;
        } 
    }
    
    printf("\n");
    printf("\n");
}

void lowerchar(int length)    //打印出指定长度的小写字母密码 2
{
    
    
    srand(time(0));
    
    system("cls");    /* 清除屏幕 */
    printf("\n\t\t生成%d位的密码为：",length);
    for(i = 0;i < length;)
    {
        password=rand()%128;
        if ( password >= 97 && password <= 122 )   //这里控制输出的字符是否符合要求
        {
            printf("%c",password);
            i++;
        } 
    }
    
    printf("\n");
    printf("\n");
}

void upperchar(int length)     //打印出指定长度的大写字母密码 3
{
    
    
    srand(time(0));
    
    system("cls");    /* 清除屏幕 */
    printf("\n\t\t生成%d位的密码为：",length);
    for(i = 0;i < length;)
    {
        password=rand()%128;
        if ( password >= 65 && password <= 90 )   //这里控制输出的字符是否符合要求
        {
            printf("%c",password);
            i++;
        } 
    }
    
    printf("\n");
    printf("\n");
}

void lower_number(int length)    //打印出指定长度的小写字母和数字密码 4
{
    
    
    srand(time(0));
    
    system("cls");    /* 清除屏幕 */
    printf("\n\t\t生成%d位的密码为：",length);
    for(i=0;i<length;)
    {
        password=rand()%128;
        if ( ( password >= 97 && password <= 122 ) || ( password >= 48 && password <= 57 ) )   //这里控制输出的字符是否符合要求
        {
            printf("%c",password);
            i++;
        } 
    }
    
    printf("\n");
    printf("\n");
}

void upper_number(int length)    //打印出指定长度的大写字母和数字密码 5
{
    
    
    srand(time(0));
    
    system("cls");    /* 清除屏幕 */
    printf("\n\t\t生成%d位的密码为：",length);
    for(i=0;i<length;)
    {
        password=rand()%128;
        if ( ( password >= 65 && password <= 90 ) || ( password >= 48 && password <= 57 ) )   //这里控制输出的字符是否符合要求
        {
            printf("%c",password);
            i++;
        } 
    }
    
    printf("\n");
    printf("\n");
}

void lower_upper_number(int length)    //打印出指定长度的小写字母和数字密码 6
{
    
    
    srand(time(0));
    
    system("cls");    /* 清除屏幕 */
    printf("\n\t\t生成%d位的密码为：",length);
    for(i=0;i<length;)
    {
        password=rand()%128;
        if ( (( password >= 97 && password <= 122 ) || ( password >= 48 && password <= 57 )) || ( password >= 65 && password <= 90 ) )   //这里控制输出的字符是否符合要求
        {
            printf("%c",password);
            i++;
        } 
    }
    
    printf("\n");
    printf("\n");
}

void allchar(int length)    //打印出指定长度的所有字符的密码 7
{
    
    
    srand(time(0));
    
    system("cls");    /* 清除屏幕 */
    printf("\n\t\t生成%d位的密码为：",length);
    for(i=0;i<length;)
    {
        password=rand()%128;
        if ( password >= 32 && password <= 126 )   //这里控制输出的字符是否符合要求
        {
            printf("%c",password);
            i++;
        } 
    }
    
    printf("\n");
    printf("\n");
    
    
}
