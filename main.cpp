#include<iostream>  //数据流输入／输出
#include<stdlib.h>  //standard library标准库
#include<string.h>  //关于字符数组的函数定义
#include <cstring>  //字符串类
#include<fstream>  //C++ STL中对文件操作
#include <sstream>  //字符串流，用于格式转换
#include <algorithm> // std::find，用于模糊查找
//以上是引入的库
using namespace std;

//如果要对该系统设计一个登录系统，定义如下数据结构；
struct user
{
    int username;
    int userkeyword;
}user[2]={
    {178668333,1815267310},
    {100,100}
};//定义了两个管理员的登陆信息；

struct student
{
    char name[20];  //姓名
    char num[20];  //学号
    char sex[10];  //性别
    int age;  //年龄
    char hometown[20];//籍贯
    char major[20];//专业
};//学生基本信息；

student stu[10];//定义学生列表
int g=0;
int student_number=0;//定义学生人数

void login();    //登入函数
void main_menu();    //主界面函数
void input_record();    //输入学生成绩处理  1
void show_record();    //显示学生成绩处理   2   
void search_record();    //查询学生成绩处理 3
void change_record();    //更新学生成绩处理 4
void delete_record();    //删除学生信息  5
void save_record();    //保存处理   
void exit_record();    //退出   6
//查询子函数声明
void search_by_num();    //学号查询
void search_by_num1();    //按学号精准查找
void search_by_num2();    //按学号模糊查找
void search_by_name();   //姓名查询
void search_by_name1();  //按姓名精准查找
void search_by_name2();  //按姓名模糊查找
void search_by_sex();    //性别查询
void search_by_mult();   //多条件查询
void search_by_exit();   //返回上一级
//自定义函数
void print_table();   //表头
void read();        //将文件中的数据读入到结构体数组中


void login(){
    int i;
    int usen;//用户名
    int keyw;//密码
    cout << "****登录界面****" << endl;
    cout << "请输入账号名：";
    cin >>usen;
    cout << "请输入密码：";
    cin >> keyw;
    for(i=0;i<2;i++){
        if (usen==user[i].username&& keyw==user[i].userkeyword)
        {
            cout << "登录成功!" << endl;
            system("cls");  //清屏函数
            main_menu();   //登录成功，打印主界面
            break;
        }
    }
    if(i==2){
        system("cls");
        cout << "登录失败！" << endl ;
        g++; //第11行定义了全局变量g，有三次登录机会，每次登录都遍历一次user结构体
        if (g >= 3)  //若三次机会都用完，则退出系统
        {
            cout << "你已经输错三次，将自动退出系统" << endl;
            exit(1);
        }
        else login(); //否则，登陆成功，进入主界面
    }

}//登录界面


void main_menu(){
    /*read();    //将文件中的学生信息读取到链表中
    save_record();*/
    system("cls");  //清屏函数
    int x;
    //主菜单
    cout << "*************************************************" << endl;
    cout << "*\t欢迎使用高校学生信息管理系统\t*" << endl;
    cout << "*************************************************" << endl;
    cout << "*\t\t1.输入学生信息\t\t\t*" << endl;
    cout << "*\t\t2.显示学生信息\t\t\t*" << endl;
    cout << "*\t\t3.查询学生信息\t\t\t*" << endl;
    cout << "*\t\t4.更新学生信息\t\t\t*" << endl;
    cout << "*\t\t5.删除学生信息\t\t\t*" << endl;
    cout << "*\t\t6.退出系统\t\t\t*" << endl;
    cout << "*************************************************" << endl;
    cout << "请输入你要执行的操作：";
    cin >> x;
    if (x == 1)input_record();      //输入学生信息
    if (x == 2)show_record();       //显示学生信息 
    if (x == 3)search_record();     //查询学生信息   
    if (x == 4)exit_record();       //退出系统
    else{
        cout << "输入错误，即将重新进入主界面" << endl;
        main_menu();//重新打印主界面
    }
}//主菜单界面



void exit_record()   //退出系统函数    8
{
    cout << "感谢您的使用，已退出！";
    exit(0);
}

void read(){
    FILE* fp;  //定义一个文件指针
    int i;
    //若文件打开失败
    if ((fp = fopen("student-list", "rb")) == NULL)  {//以二进制方式读取文件
        cout << "cannot open file" << endl;
        return;
    }
    fread(&student_number, 4, 1, fp);     //读取学生人数
    for (i = 0; i < student_number; i++)  {
        if (fread(&stu[i], sizeof(struct student), 1, fp) != 1)cout << "file read error" << endl; //出错处理
        else cout << "file read sucess" << endl; //文件读取成功
    }
    fclose(fp);  //关闭文件指针
}//读取文件

void save_record(){
     //文本文件方式存储（txt）  
    int q = 0;
    ofstream file("C:\\C++code\\student-list.txt", ios::out);
    for (q = 0; q < student_number; q++)  //将学生信息写入文件
    {
        file << stu[q].name << " " << stu[q].num << " " << stu[q].sex << " " << stu[q].age << " " << stu[q].hometown << " " << stu[q].major << endl; //按“ ”隔开字符串写入文件
    }
    file.close();//关闭文件

    //二进制方式对文件进行写
    FILE* fp;  //定义一个文件指针
    int i;
    //若文件打开失败
    if ((fp = fopen("student-list", "wb")) == NULL)
    {
        cout << "cannot open file" << endl;
        return;
    }
    fwrite(&student_number, 4, 1, fp);     //将学生人数写入文件
    for (i = 0; i < student_number; i++) {//以二进制写入
    if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)cout << "file write error" << endl; //出错处理
    else cout << "file write sucess" << endl; //文件写入成功
    }
    fclose(fp);  //关闭文件指针
}

void input_record(){
    aa:{
            system("cls");
            cout<<"请输入学生姓名：";
            cin>>stu[student_number].name;

        bb:
            while(1){
                cout<<"请输入学号(十位)";
                cin>>stu[student_number].num;
                if (strlen(stu[student_number].num) == 10) break;
                else cout << "您的学号输入有误，请重新输入！" << endl;
            }

            while(1){
                cout<<"请输入性别(男/女):";
                cin>>stu[student_number].sex;
                char *c=stu[student_number].sex;
                if(strcmp(c,"男")==0||strcmp(c,"女")==0)break;
                else cout<<"输入有误请重新输入"<<endl;
            }

            while(1){
                cout<<"请输入年龄：";
                cin>>stu[student_number].age;
                if(stu[student_number].age>0&&stu[student_number].age<100)break;
                else cout<<"输入有误请重新输入"<<endl;
            }

            cout<<"请输入籍贯:";
            cin>>stu[student_number].hometown;

            cout<<"请输入学生专业:";
            cin>>stu[student_number].major;

            cout << "请选择是否保存(y或n):";
            getchar();

            if(getchar()=='y'){
                student_number++;
                save_record();
            }

             cout << "是否继续添加，请选择(y或n)(否会回到主界面):" << endl;//询问是否继续添加
             getchar();
 
            if (getchar() == 'y') goto aa;//继续添加
            if (getchar() == 'n') main_menu();//返回主界面
    }
}

void search_record(){
    system("cls");
    int z;
    cout << "1 按学号查询" << endl;
    cout << "2 按姓名查询" << endl;
    cout << "3 返回上一级" << endl;
    cout << "请输入:";
    cin>>z;
    if (z == 1)
        search_by_num(); //按学号查询函数 
    if (z == 2)
        search_by_name(); //按姓名查询函数 
    if (z == 3)
        main_menu(); //返回主界面
    else
    {
        cout << ("输入错误\n");
        search_record();  //重新查询
    }
}//查询方式

void print_table()     
{
    cout << "+----------+----------------+------+------+----------------+------------+" << endl;
    cout << "|   姓名   |      学号      | 性别 | 年龄 |      籍贯      |    专业    |" << endl;
    cout << "+----------+----------------+------+------+----------------+------------+" << endl;
}//打印学生信息表格的表头函数 
void search_by_num(){
    int i;
    int v;//代指学生数量
    char num[20];//用于储存学号
    system("cls");
    cin>>num;
    for(i=0;i<student_number;i++){
        if(strcmp(num,stu[i].num)==0){
            print_table();
            cout<<"|  " << stu[i].name << "  |  " << stu[i].num << "  |  " << stu[i].sex << "  |  " << stu[i].age << "  |  " << stu[i].hometown << "  |  " << stu[i].major << "  |" << endl;
            v++;
            break;
        }
    }
    cout << endl << "满足条件的学生人数为:" << v << "人" << endl;
    if (i == student_number)  cout << "不存在这个学号！" << endl;
    cout << endl << "1.返回主界面" << endl << "2.继续查询";//询问返回哪里
    cout << "请输入：";
    getchar();//获取用户回答
    if (getchar() == 1) main_menu();
    else search_record();
}

void search_by_name() {   //按名字查找——精准查找
    //定义两个int型变量来获取用户的输入
    int i;
    int v = 0;
    char name[20]; 
    system("cls");  
    cout << "请输入查找的姓名：";
    cin >> name;
    for (i = 0; i < student_number; i++)  
    {
        if (strcmp(name, stu[i].name) == 0)
        {
            print_table();
            cout << "|  " << stu[i].name << "  |  " << stu[i].num << "  |  " << stu[i].sex << "  |  " << stu[i].age << "  |  " << stu[i].hometown << "  |  " << stu[i].major << "  |" << endl;
            v++;
            break;
        }
    }
    cout << endl << "满足条件的学生人数为:" << v << "人" << endl;
    if (i == student_number) cout << "不存在这个姓名" << endl;
    cout << endl << "1.返回主界面" << endl << "2.继续查询";
    cout << "请输入：";
    getchar();//获取用户回答
    if (getchar() == 1) main_menu();
    else search_record();
}
void show_record()  //显示学生信息函数    2   
{
    system("cls");  //清屏函数
    print_table();  //打印表头 
    for (int i = 0; i < student_number; i++) //打印表格数据 
    {
        cout << "|  " << stu[i].name << "  |  " << stu[i].num << "  |  " << stu[i].sex << "  |  " << stu[i].age << "  |  " << stu[i].hometown << "  |  " << stu[i].major << "  |" << endl;
    }
    cout << endl << "1.返回主界面" << endl;
    cout << "请输入：";
    getchar();
    if (getchar() == 1)main_menu();
}
 
int main()
{
    login();  //首先进行管理员登录
    main_menu();  //显示主界面
    return 0;
}