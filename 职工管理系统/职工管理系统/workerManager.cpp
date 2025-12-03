#include "workerManager.h" 
WorkerManager::WorkerManager(){
    this->m_EmpNum=0;
    this->m_EmpArray=NULL;
}

WorkerManager::~WorkerManager(){


}
void WorkerManager::showMenu(){;
    cout<<"**********欢迎使用职工管理系统！*********"<<endl;
    cout<<"************0.退出管理系统**********"<<endl;
    cout<<"************1.增加职工信息**********"<<endl;
    cout<<"************2.显示职工信息**********"<<endl;
    cout<<"************3.删除离职职工**********"<<endl;
    cout<<"************4.修改职工信息**********"<<endl;
    cout<<"************5.查找职工信息**********"<<endl;
    cout<<"************6.按照编号排序**********"<<endl;
    cout<<"************7.清空所有文档**********"<<endl;
   cout<<endl;}
void WorkerManager::Add_Emp(){
    cout<<"请输入添加职工数量： "<<endl;
    int addNum=0;
    cin>>addNum;
    if(addNum>0){
        int newSize=addNum+this->m_EmpNum;
        Worker ** newSpace =new Worker *[newSize];
        //将原来的空间下的数据拷贝到新空间下
        if(this->m_EmpArray!=NULL){
            for(int i=0;i<this->m_EmpNum;i++){
                newSpace[i]=this->m_EmpArray[i];
            }
        }
        //添加新数据
        for(int i=0;i<addNum;i++){
            int id;
            string name;
            int dSelect;
            cout<<"请输入第 "<<i+1<<"个新职工的编号： "<<endl;
            cin>>id;
            cout<<"请输入第 "<<i+1<<"个新职工的姓名： "<<endl;
            cin>>name;
            cout<<"请选择该职工的岗位: "<<endl;
            cout<<"1.普通职工"<<endl;
            cout<<"2.经理"<<endl;
            cout<<"3.老板"<<endl;
            cin>>dSelect;
            Worker *worker=NULL;
            switch(dSelect){
                case 1:
                worker= new Employee(id,name ,1);
                break;
                case 2:
                worker=new Manager(id,name,2);
                break;
                case 3:
                worker=new Boss(id,name,3);
                break;
                default:
                break;
            }
            newSpace[this->m_EmpNum+i]=worker;
        }
        delete[]this->m_EmpArray;
        //更改新空间指向
        this->m_EmpArray=newSpace;
        //更新新的职工人数
        this->m_EmpNum=newSize;
        cout<< "成功添加"<<addNum<<"名新职工"<<endl;
    }
    else{
        cout<<"输入数据有误"<<endl;
    }
    system("pause");
    system("cls");
};
void WorkerManager::exitsystem(){
    cout<<"欢迎下次使用"<<endl;
    system("pause");
    exit(0);
}
