#include<iostream>  //数据流输入／输出
#include<stdlib.h>  //standard library标准库
#include<string.h>  //关于字符数组的函数定义
#include <cstring>  //字符串类
#include<fstream>  //C++ STL中对文件操作
#include <sstream>  //字符串流，用于格式转换
#include <algorithm> // std::find，用于模糊查找
//以上是引入的库
using namespace std;
#ifndef function_H
#define function_H

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




void main_menu(){
    
}































#endif