#include "employee.h"
    Employee:: Employee(int id,string name, int did,int salary){
        this->m_Id=id;
        this->m_name=name;
        this->m_DeptId=did;
        this->m_salary=salary;
    }
     void Employee::showInfo(){
        cout<<"职工编号： "<<this->m_Id;
        cout<<"   职工姓名： "<<this->m_name;
        cout<<"   岗位： "<<this->getDeptName();
        cout<<"   薪资： "<<this->m_salary;
        cout<<"   岗位职责： 完成经理交给的任务"<<endl;
     }
     string Employee:: getDeptName(){
        return string("员工");
     }