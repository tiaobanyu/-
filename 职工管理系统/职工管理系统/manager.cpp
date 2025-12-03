#include "manager.h"
Manager:: Manager(int id,string name, int did){
        this->m_Id=id;
        this->m_name=name;
        this->m_DeptId=did;
    }
     void Manager::showInfo(){
        cout<<"职工编号： "<<this->m_Id<<endl;
        cout<<"职工姓名： "<<this->m_name<<endl;
        cout<<"岗位： "<<this->getDeptName()<<endl;
        cout<<"岗位职责： 完成老板交给的任务，并下发任务给员工"<<endl;
     };
     string Manager:: getDeptName(){
        return string("经理");
     };