/**
***   v1.0
**/
#include <stdio.h>
#include <stdlib.h>
#define STAR "\t\t*******************************************************"

void number(int length);    //��ӡ��ָ�����ȵ��������� 1
void lowerchar(int length);    //��ӡ��ָ�����ȵ�Сд��ĸ���� 2
void upperchar(int length);    //��ӡ��ָ�����ȵĴ�д��ĸ���� 3
void lower_number(int length);    //��ӡ��ָ�����ȵ�Сд��ĸ���������� 4
void upper_number(int length);    //��ӡ��ָ�����ȵĴ�д��ĸ���������� 5
void lower_upper_number(int length);    //��ӡ��ָ�����ȵ�Сд��ĸ���������� 6
void allchar(int length);    //��ӡ��ָ�����ȵ������ַ������� 7

int i,password;

int main(void)
{
    int length,choice,test;
    
    length=1;
    
    while( length != 0 )
    {
        printf("\t\t���������볤��(����0����):");
        while( scanf("%d",&length) != 1 || length < 0 )
        {
            printf("\t\t��������ȷ�����볤��(����0����):");
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
            printf("\n\t\t��ѡ������ǿ��:\n");
            printf("\t\t\t\t1.����:\n");
            printf("\t\t\t\t2.Сд��ĸ:\n");
            printf("\t\t\t\t3.��д��ĸ:\n");
            printf("\t\t\t\t4.����+Сд��ĸ:\n");
            printf("\t\t\t\t5.����+��д��ĸ:\n");
            printf("\t\t\t\t6.����+��д��ĸ+Сд��ĸ:\n");
            printf("\t\t\t\t7.����+��д��ĸ+Сд��ĸ+�������:\n"); 
            printf("%s\n",STAR);
            printf("\n\t\t��ѡ��:");
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
            printf("�������!\n");
            break;
        }
    }
    system("pause");
    return 0;
}



void number(int length)    //��ӡ��ָ�����ȵ��������� 1
{

    
    srand(time(0));     /* ����������� */
    
    system("cls");    /* �����Ļ */
    printf("\n\t\t����%dλ������Ϊ��",length);
    for(i = 0;i < length;)
    {
        password=rand()%128;    /* �������128���ڵ��� */
        if ( password > 48 && password < 57 )   //�������������ַ��Ƿ����Ҫ��
        {
            printf("%c",password);
            i++;
        } 
    }
    
    printf("\n");
    printf("\n");
}

void lowerchar(int length)    //��ӡ��ָ�����ȵ�Сд��ĸ���� 2
{
    
    
    srand(time(0));
    
    system("cls");    /* �����Ļ */
    printf("\n\t\t����%dλ������Ϊ��",length);
    for(i = 0;i < length;)
    {
        password=rand()%128;
        if ( password > 97 && password < 122 )   //�������������ַ��Ƿ����Ҫ��
        {
            printf("%c",password);
            i++;
        } 
    }
    
    printf("\n");
    printf("\n");
}

void upperchar(int length)     //��ӡ��ָ�����ȵĴ�д��ĸ���� 3
{
    
    
    srand(time(0));
    
    system("cls");    /* �����Ļ */
    printf("\n\t\t����%dλ������Ϊ��",length);
    for(i = 0;i < length;)
    {
        password=rand()%128;
        if ( password > 65 && password < 90 )   //�������������ַ��Ƿ����Ҫ��
        {
            printf("%c",password);
            i++;
        } 
    }
    
    printf("\n");
    printf("\n");
}

void lower_number(int length)    //��ӡ��ָ�����ȵ�Сд��ĸ���������� 4
{
    
    
    srand(time(0));
    
    system("cls");    /* �����Ļ */
    printf("\n\t\t����%dλ������Ϊ��",length);
    for(i=0;i<length;)
    {
        password=rand()%128;
        if ( ( password > 97 && password < 122 ) || ( password > 48 && password < 57 ) )   //�������������ַ��Ƿ����Ҫ��
        {
            printf("%c",password);
            i++;
        } 
    }
    
    printf("\n");
    printf("\n");
}

void upper_number(int length)    //��ӡ��ָ�����ȵĴ�д��ĸ���������� 5
{
    
    
    srand(time(0));
    
    system("cls");    /* �����Ļ */
    printf("\n\t\t����%dλ������Ϊ��",length);
    for(i=0;i<length;)
    {
        password=rand()%128;
        if ( ( password > 65 && password < 90 ) || ( password > 48 && password < 57 ) )   //�������������ַ��Ƿ����Ҫ��
        {
            printf("%c",password);
            i++;
        } 
    }
    
    printf("\n");
    printf("\n");
}

void lower_upper_number(int length)    //��ӡ��ָ�����ȵ�Сд��ĸ���������� 6
{
    
    
    srand(time(0));
    
    system("cls");    /* �����Ļ */
    printf("\n\t\t����%dλ������Ϊ��",length);
    for(i=0;i<length;)
    {
        password=rand()%128;
        if ( (( password > 97 && password < 122 ) || ( password > 48 && password < 57 )) || ( password > 65 && password < 90 ) )   //�������������ַ��Ƿ����Ҫ��
        {
            printf("%c",password);
            i++;
        } 
    }
    
    printf("\n");
    printf("\n");
}

void allchar(int length)    //��ӡ��ָ�����ȵ������ַ������� 7
{
    
    
    srand(time(0));
    
    system("cls");    /* �����Ļ */
    printf("\n\t\t����%dλ������Ϊ��",length);
    for(i=0;i<length;)
    {
        password=rand()%128;
        if ( password > 32 && password <126 )   //�������������ַ��Ƿ����Ҫ��
        {
            printf("%c",password);
            i++;
        } 
    }
    
    printf("\n");
    printf("\n");
    
    
}