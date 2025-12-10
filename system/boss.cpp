#include "boss.h"
 Boss:: Boss(int id,string name, int did,int salary){
        this->m_Id=id;
        this->m_name=name;
        this->m_DeptId=did;
        this->m_salary=salary;
    }
     void Boss::showInfo(){
        cout<<"职工编号： "<<this->m_Id;
        cout<<"   职工姓名： "<<this->m_name;
        cout<<"   岗位： "<<this->getDeptName();
        cout<<"   薪资： "<<this->m_salary;
        cout<<"   岗位职责： 管理公司所有事务"<<endl;
     };
     string Boss:: getDeptName(){
        return string("老板");
     };