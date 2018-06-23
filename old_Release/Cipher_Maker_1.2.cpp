#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int showMenu();
int getNumber();
void createSerial(int typeSerial,int serialLength,FILE *fp);
int outputFile(int ch,FILE *fp);
int main()
{
    FILE *fp;
    int choice = 0,serialLen = 0;    //choice 选择项,serialLen 串长度
    system("color 3f");
while(1)
    {
        if(!(fp = fopen("password_record.txt","a")))
            exit(0);
        //cout <<(int)'a';
        cout <<"请输入长度(0长度退出):";
        serialLen = getNumber();
        if(!serialLen)
            exit(0);
        choice = showMenu();
        //cout << choice<<serialLen<<endl;
        createSerial(choice,serialLen,fp);
        fclose(fp);
    }
    return 0;
}

///显示菜单
int showMenu()
{
    int sele;
    char *input;
    cout <<"\r请选择类型："<<endl;
    cout <<"\r**********************************************"<<endl;
    cout <<"\r\t\t1.全数字"<<endl;
    cout <<"\r\t\t2.全小写"<<endl;
    cout <<"\r\t\t3.全大写"<<endl;
    cout <<"\r\t\t4.大小写"<<endl;
    cout <<"\r\t\t5.小写+数字"<<endl;
    cout <<"\r\t\t6.大写+数字"<<endl;
    cout <<"\r\t\t7.大小写+数字"<<endl;
    cout <<"\r\t\t8.大小写+数字+符号"<<endl;
    cout <<"\r\t\t0.退出"<<endl;
    cout <<"\r**********************************************"<<endl;
    cout<<"\r请输入:";
    //cin>>input;
    //sele = getInput();
    //cin>>sele;
    sele = getNumber();
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
            //cout<<"输入有误!!"<<endl;
            system("cls");
            showMenu();
            break;
    }
}
///获取输入并判断数据的合法性（用来判断输入是否合法的）
int getNumber()
{
    int input = 0;
    cin >>input;
    /*
    while(!input)
        {
            getchar();
            system("cls");
            cout << "输入有问题,请重输:";
            scanf("%d",&input);
        }
        getchar();
/*
    scanf("%d",&input);
    if(getchar() == '\n')
        putchar(' ');
    while(!input)
    {
        scanf("%d",&input);
    }
*/
    return input;
}

///生成密码的部分； typeSerial : 密码类型；serialLength:密码长度；fp指向输出文件的指针
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
        else if(ch >=97 && ch <=122 && typeSerial == 2)    //小
            outputFile(ch,fp);
        else if( ch >= 65 && ch <= 90 && typeSerial == 3)    //大
            outputFile(ch,fp);
        else if((ch >= 65 && ch <= 90 || ch >=97 && ch <=122) && typeSerial == 4)    //大小
            outputFile(ch,fp);
        else if((ch >= 48 && ch <= 57 || ch >= 97 && ch <= 122) && typeSerial == 5)
            outputFile(ch,fp);
        else if((ch >= 48 && ch <= 57 || ch >= 65 && ch <= 90) && typeSerial == 6)
            outputFile(ch,fp);
        else if((ch >= 65 && ch <= 90 || ch >=97 && ch <=122 || ch >= 48 && ch <= 57) && typeSerial == 7)    //大小数
            outputFile(ch,fp);
        else
            i--;
    }
    outputFile('\n',fp);
}

///输出文件并打印在屏幕上;ch 对应字符的ASCII ;fp 指向输出文件的指针;
int outputFile(int ch,FILE *fp)
{
    int res;
    //putchar(ch);
    printf("%c",ch);
    //res = fprintf(fp,"%c",ch);
    res = putc(ch,fp);
    return res;
}
