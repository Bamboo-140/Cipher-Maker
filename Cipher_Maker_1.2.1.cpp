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
    int choice = 0,serialLen = 0;    //choice 选择项,serialLen 串长度
    system("color 3f");
while(1)
    {
        if(!(fp = fopen("password_record.txt","a")))
            exit(0);
        //cout <<(int)'a';
        cout <<"请输入长度(负数长度退出):";
        //serialLen = getNumber("序列长度(长度不能为0)");
        serialLen = getNumber("序列长度(长度不能为0)");
            //if(!serialLen)   //长度为0退出，由于无法传0
        if(serialLen < 0)    //上面问题的中和方案
            exit(0);
        choice = showMenu();
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
    //system("cls");
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
    //cout <<"\r\t\t-1.退出"<<endl;
    cout <<"\r**********************************************"<<endl;
    cout<<"\r请输入:";
    //cin>>input;
    //sele = getInput();
    //cin>>sele;
    sele = getNumber("序列类型(1-8)");

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
            //system("cls");
            putchar('\n');
            putchar('\n');
            showMenu();
            break;
    }
    return 1;
}
///获取输入并判断数据的合法性（用来判断输入是否合法的功能但不完善，不能返回0）
int getNumber(char * info)
{
    char ch;    //测试字符
    int input = 0;
    cin >>input;
    while(!input)
        {
            if(((ch = getchar()) != '\n')&&(ch >= 48 && ch <= 57))    //这段代码本可简写 if(((ch = getchar())>= 48) && ch <=57)
            {
                ungetc(ch,stdin);
            }
            //system("cls");
            //putchar('\n');
            //cout << "输入的有问题,请重输:";
            printf("\r输入的\"%s\"有问题,请重输:",info);
            scanf("%d",&input);
            //cin >>input;      //用cin 就不行只能用scanf才能正确定显示
        }
        //getchar();
/*    //尝试无效的代码
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
