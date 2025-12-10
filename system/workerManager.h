#pragma once//防止头文件包含
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"
#include <fstream>
#define FILENAME "empFile.text"
using namespace std;
class WorkerManager{
    public:
    WorkerManager(); 
    //展示菜单
    void showMenu();
    //退出系统
    void exitsystem();
    ~WorkerManager();
    //添加职工
    void Add_Emp();
    //记录职工人数
    int m_EmpNum;
    //保存文件
    void save();
    //标志文件是否为空
    bool m_FileIsEmpty;
    //统计人数
    int get_EmpNum();
    //初始化职工
    void init_Emp();
    //显示职工
    void Show_Emp();
    //删除职工
    void Del_Emp();
    //判断职工是否存在
    int IsExist(int id);
    //修改职工
    void Mod_Emp();
    //查找职工
    void Find_Emp();
    //排序职工
    void Sort_Emp();
    //清空数据
    void Clean_File();
    //职工数组指针
    Worker **m_EmpArray;    
};