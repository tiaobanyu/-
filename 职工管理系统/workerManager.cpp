#include "workerManager.h" 
WorkerManager::WorkerManager(){
    //1.文件不存在
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open()){
        cout<<"文件不存在"<<endl;
    //初始化属性
    this->m_EmpNum=0;
    this->m_EmpArray=NULL;
    this->m_FileIsEmpty=true;
    ifs.close();
    return;
}
    //2.文件存在，并且没有记录
    char ch;
    ifs>>ch;
    if(ifs.eof()){
        cout<<"文件为空！"<<endl;
        this->m_EmpNum=0;
        this->m_EmpArray=NULL;
        this->m_FileIsEmpty=true;
        ifs.close();
        return;
    }
    // 3.文件存在，并且记录数据
    this->m_EmpArray=new Worker*[this->m_EmpNum];
    //将文件中的数据存到数组中
    this->init_Emp();
}
WorkerManager::~WorkerManager(){
    if(this->m_EmpArray!=NULL){
        delete[]this->m_EmpArray;
        this->m_EmpArray=NULL;
    }
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
   //添加职工
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
            int salary;
            cout<<"请输入第 "<<i+1<<"个新职工的编号： "<<endl;
            cin>>id;
            cout<<"请输入第 "<<i+1<<"个新职工的姓名： "<<endl;
            cin>>name;
            cout<<"请输入第 "<<i+1<<"个新职工的薪资: "<<endl;
            cin>>salary;
            cout<<"请选择该职工的岗位: "<<endl;
            cout<<"1.普通职工"<<endl;
            cout<<"2.经理"<<endl;
            cout<<"3.老板"<<endl;
            cin>>dSelect;
            Worker *worker=NULL;
            switch(dSelect){
                case 1:
                worker= new Employee(id,name ,1,salary);
                break;
                case 2:
                worker=new Manager(id,name,2,salary);
                break;
                case 3:
                worker=new Boss(id,name,3,salary);
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
        //更新职工不为空标志
        this->m_FileIsEmpty=false;
        cout<< "成功添加"<<addNum<<"名新职工"<<endl;
        //保存数据到文件中
        this->save();
    }
    else{
        cout<<"输入数据有误"<<endl;
    }
    system("pause");
    system("cls");
};
void WorkerManager::save(){
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    for(int i=0;i<this->m_EmpNum;i++){
        ofs<<this->m_EmpArray[i]->m_Id<<" "
           <<this->m_EmpArray[i]->m_name<<" "
           <<this->m_EmpArray[i]->m_salary<<" "
           <<this->m_EmpArray[i]->m_DeptId<<endl;
    }
    ofs.close();
}
int WorkerManager::get_EmpNum(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int did;
    int salary;
    int num=0 ;
    while (ifs>>id&&ifs>>name&&ifs>>salary&&ifs>>did)
    {   //统计人数变量
        num++;
    }
    return num;
}
void WorkerManager::init_Emp(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int did;
    int salary;
    int index=0;
    while(ifs>>id&&ifs>>name&&ifs>>salary&&ifs>>did){
        Worker *worker=NULL;
        //根据不同的部门ID创建不同对象
        if(did==1){
            worker=new Employee(id,name,did,salary);
        }
        else if(did==2){
            worker=new Manager(id,name,did,salary);
        }
        else if(did==3){
            worker=new Boss(id,name,did,salary);
        }
        this->m_EmpArray[index]=worker;
        index++;
    }
}
//退出系统
void WorkerManager::exitsystem(){
    cout<<"欢迎下次使用"<<endl;
    system("pause");
    exit(0);
}
