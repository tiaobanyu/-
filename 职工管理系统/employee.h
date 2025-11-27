#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
class Employee:public Worker{
    Employee(int id,string name, int did);
    virtual void showInfo();
    virtual string getDeptName();
};