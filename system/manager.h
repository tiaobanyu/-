#pragma once
using namespace std;
#include <iostream>
#include "worker.h"
//经理类
class Manager:public Worker{
    public:
    Manager(int id,string name,int dId,int salary);
    virtual void showInfo();
    virtual string getDeptName();
};