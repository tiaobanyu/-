#pragma once//防止头文件包含
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"
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
    //职工数组指针
    Worker **m_EmpArray;
};