#pragma once
using namespace std;
#include <iostream>
#include "worker.h"
//老板类
class Boss:public Worker{
    public:
    Boss(int id,string name,int dId);
    virtual void showInfo();
    virtual string getDeptName();
}
;