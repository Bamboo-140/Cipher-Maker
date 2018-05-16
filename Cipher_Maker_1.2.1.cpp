#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int showMenu();
int getNumber(char *info);
void createSerial(int typeSerial,int serialLength,FILE *fp);
int outputFile(int ch,FILE *fp);
int main()
{
    FILE *fp;
    int choice = 0,serialLen = 0;    //choice ѡ����,serialLen ������
    system("color 3f");
while(1)
    {
        if(!(fp = fopen("password_record.txt","a")))
            exit(0);
        //cout <<(int)'a';
        cout <<"�����볤��(���������˳�):";
        //serialLen = getNumber("���г���(���Ȳ���Ϊ0)");
        serialLen = getNumber("���г���(���Ȳ���Ϊ0)");
            //if(!serialLen)   //����Ϊ0�˳��������޷���0
        if(serialLen < 0)    //����������кͷ���
            exit(0);
        choice = showMenu();
        createSerial(choice,serialLen,fp);
        fclose(fp);
    }
    return 0;
}

///��ʾ�˵�
int showMenu()
{
    int sele;
    char *input;
    //system("cls");
    cout <<"\r��ѡ�����ͣ�"<<endl;
    cout <<"\r**********************************************"<<endl;
    cout <<"\r\t\t1.ȫ����"<<endl;
    cout <<"\r\t\t2.ȫСд"<<endl;
    cout <<"\r\t\t3.ȫ��д"<<endl;
    cout <<"\r\t\t4.��Сд"<<endl;
    cout <<"\r\t\t5.Сд+����"<<endl;
    cout <<"\r\t\t6.��д+����"<<endl;
    cout <<"\r\t\t7.��Сд+����"<<endl;
    cout <<"\r\t\t8.��Сд+����+����"<<endl;
    //cout <<"\r\t\t-1.�˳�"<<endl;
    cout <<"\r**********************************************"<<endl;
    cout<<"\r������:";
    //cin>>input;
    //sele = getInput();
    //cin>>sele;
    sele = getNumber("��������(1-8)");

    switch(sele)
    {
        case 0:
            exit(0);break;
        case 1:
            return sele;break;
        case 2:
            return sele;break;
        case 3:
            return sele;break;
        case 4:
            return sele;break;
        case 5:
            return sele;break;
        case 6:
            return sele;break;
        case 7:
            return sele;break;
        case 8:
            return sele;break;
        default:
            //cout<<"��������!!"<<endl;
            //system("cls");
            putchar('\n');
            putchar('\n');
            showMenu();
            break;
    }
    return 1;
}
///��ȡ���벢�ж����ݵĺϷ��ԣ������ж������Ƿ�Ϸ��Ĺ��ܵ������ƣ����ܷ���0��
int getNumber(char * info)
{
    char ch;    //�����ַ�
    int input = 0;
    cin >>input;
    while(!input)
        {
            if(((ch = getchar()) != '\n')&&(ch >= 48 && ch <= 57))    //��δ��뱾�ɼ�д if(((ch = getchar())>= 48) && ch <=57)
            {
                ungetc(ch,stdin);
            }
            //system("cls");
            //putchar('\n');
            //cout << "�����������,������:";
            printf("\r�����\"%s\"������,������:",info);
            scanf("%d",&input);
            //cin >>input;      //��cin �Ͳ���ֻ����scanf������ȷ����ʾ
        }
        //getchar();
/*    //������Ч�Ĵ���
    scanf("%d",&input);
    if(getchar() == '\n')
        putchar(' ');
    while(!input)
    {
        scanf("%d",&input);
    }
*/
        if(input < 0)
            exit(0);
    return input;
}

///��������Ĳ��֣� typeSerial : �������ͣ�serialLength:���볤�ȣ�fpָ������ļ���ָ��
void createSerial(int typeSerial,int serialLength,FILE *fp)
{
    char ch;

    srand((unsigned)time(NULL));
    for(int i = 0;i < serialLength;i++)
    {
        ch = rand()%128;
        if (ch < 128 && ch > 31 && typeSerial == 8 )
            outputFile(ch,fp);
        else if(ch >= 48 && ch <= 57  && typeSerial == 1)
            outputFile(ch,fp);
        else if(ch >=97 && ch <=122 && typeSerial == 2)    //С
            outputFile(ch,fp);
        else if( ch >= 65 && ch <= 90 && typeSerial == 3)    //��
            outputFile(ch,fp);
        else if((ch >= 65 && ch <= 90 || ch >=97 && ch <=122) && typeSerial == 4)    //��С
            outputFile(ch,fp);
        else if((ch >= 48 && ch <= 57 || ch >= 97 && ch <= 122) && typeSerial == 5)
            outputFile(ch,fp);
        else if((ch >= 48 && ch <= 57 || ch >= 65 && ch <= 90) && typeSerial == 6)
            outputFile(ch,fp);
        else if((ch >= 65 && ch <= 90 || ch >=97 && ch <=122 || ch >= 48 && ch <= 57) && typeSerial == 7)    //��С��
            outputFile(ch,fp);
        else
            i--;
    }
    outputFile('\n',fp);
    outputFile('\n',fp);
}

///����ļ�����ӡ����Ļ��;ch ��Ӧ�ַ���ASCII ;fp ָ������ļ���ָ��;
int outputFile(int ch,FILE *fp)
{
    int res;
    //putchar(ch);
    printf("%c",ch);
    //res = fprintf(fp,"%c",ch);
    res = putc(ch,fp);
    return res;
}
