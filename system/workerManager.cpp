#include "workerManager.h" 
#include <cstdlib>
WorkerManager::WorkerManager(){
    //1.文件不存在
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open()){
        cout << "文件不存在" << endl;
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
        cout << "文件为空！" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray=NULL;
        this->m_FileIsEmpty=true;
        ifs.close();
        return;
    }
    // 3.文件存在，并且记录数据
    int num=this->get_EmpNum();
    this->m_EmpNum=num;
    this->m_EmpArray=new Worker*[this->m_EmpNum];
    //将文件中的数据存到数组中
    this->init_Emp();
}
WorkerManager::~WorkerManager(){
    if(this->m_EmpArray!=NULL){
        for(int i=0;i<m_EmpNum;i++){
            if(this->m_EmpArray[i]!=NULL){
                delete this->m_EmpArray[i];
            }
        }
        delete[]this->m_EmpArray;
        this->m_EmpArray=NULL;
    }
}
void WorkerManager::showMenu(){;
    cout<<"**********欢迎使用职工管理系统！****"<<endl;
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
            cout<<"请输入第 "<<i+1<<"个新职工的薪资： "<<endl;
            cin>>salary;
            cout<<"请选择该职工的岗位： "<<endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
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
//保存文件
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
//初始化职工
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
//显示职工
void WorkerManager::Show_Emp(){
    if(this->m_FileIsEmpty){
        cout << "文件不存在" << endl;
        system("pause");
        system("cls");
    }
    else{
        for(int i=0;i<this->m_EmpNum;i++){
            //利用多态调用接口
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}
//删除职工
void WorkerManager::Del_Emp(){
    if(this->m_FileIsEmpty){
        cout << "文件不存在" << endl;
    }
    else{
        cout << "请输入想要删除的职工编号： " << endl;
        int id=0;
        cin>>id;
       int index=this->IsExist(id);
       if(index!=-1){
        //数据前移
        for(int j=index;j<this->m_EmpNum-1;j++){
            this->m_EmpArray[j]=this->m_EmpArray[j+1];
        }
        this->m_EmpNum--;
        //同步更新到文件中
        this->save();
        cout << "删除成功" << endl;
       }
       else{
           cout << "未找到该职工,删除失败" << endl;
       }
    }
    system("pause");
    system("cls");
}
//判断职工是否存在
int WorkerManager::IsExist(int id){
    int index=-1;
    for(int i=0;i<m_EmpNum;i++){
        if(this->m_EmpArray[i]->m_Id==id){
            //找到职工
            index=i;
            break;
        }
    }
    return index;
}
//修改职工
void WorkerManager::Mod_Emp(){
    if(this->m_FileIsEmpty){
        cout << "文件不存在" << endl;
    }
    else{
        cout << "请输入修改职工的编号" << endl;
        int id;
        cin>>id;
        int count=this->IsExist(id);
        if(count==-1){
            cout << "修改失败,查无此人" << endl;
        }
        else{
            delete this->m_EmpArray[count];
            int newId=0;
            string newName=" ";
            int newSalary=0;
            int dSelect=0;
            cout << "查到： " << id << "号职工,请输入新职工的工号" << endl;
            cin>>newId;
            cout << "请输入新姓名： " << endl;
            cin>>newName;
            cout << "请输入岗位： " << endl;
            cout << "1. 普通职工" << endl;
            cout << "2. 经理 " << endl;
            cout << "3. 老板" << endl;
            cin>>dSelect;
            cout << "请输入薪资： " << endl;
            cin>>newSalary;
            Worker *worker=NULL;
            switch(dSelect){
                case 1:
                worker=new Employee(newId,newName,dSelect,newSalary);
                break;
                case 2:
                worker=new Manager(newId,newName,dSelect,newSalary);
                break;
                case 3:
                worker=new Boss(newId,newName,dSelect,newSalary);
                break;
                default:
                break;
            }
            this->m_EmpArray[count]=worker;
            cout << "修改成功!" << endl;
            this->save();
        }
    }
    system("pause");
    system("cls");
}
//查找职工
void WorkerManager::Find_Emp(){
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在" << endl;
    }
    else{
        cout << "请输入查找的方式： " << endl;
        cout << "1.按职工编号查找" << endl;
        cout << "2.按职工姓名查找" << endl;
        int select=0;
        cin>>select;
        if(select==1){
            cout << "请输入要查找的编号： " << endl;
            int id=0;
            cin>>id;
            int count=this->IsExist(id);
            if (count == -1) {
                cout << "查无此人，查找失败" << endl;
            }
            else {
                cout << "查找成功，职工信息如下： " << endl;
                this->m_EmpArray[count]->showInfo();
            }
        }
        else if(select==2){
            cout << "请输入要查找的名字： " << endl;
            string name;
            cin>>name;
            bool flag=false;
            for(int i=0;i<m_EmpNum;i++){
                if(this->m_EmpArray[i]->m_name==name){
                    cout << "查找成功，职工编号为："
                        << m_EmpArray[i]->m_Id
                        << " 号的信息如下： " << endl;
                    flag=true;
                    this->m_EmpArray[i]->showInfo();
                }
            }
            if(flag==false){
                cout << "查找失败，查无此人" << endl;
            }
        }
        else{
            cout << "输入选项有误" << endl;
        }
    }
    system("pause");
    system("cls");
}
//排序职工
void WorkerManager::Sort_Emp(){
     if (this->m_FileIsEmpty)
    {
         cout << "文件不存在" << endl;
        system("pause");
        system("cls");
    }
    else{
        if(this->m_EmpNum==0){
            cout<<"无职工数据,无法排序!"<<endl;
            system("pause");
            system("cls");
            return;
        }
         cout << "请选择排序方式： " << endl;
         cout << "1.按职工号升序的方式排序" << endl;
         cout << "2.按职工号降序的方式排序" << endl;
        int select=0;
        cin>>select;
       for(int i=0;i<m_EmpNum;i++){
            int minOrMax=i;
            for(int j=i+1;j<m_EmpNum;j++){
                if(select==1){
                    if(this->m_EmpArray[minOrMax]->m_Id>this->m_EmpArray[j]->m_Id){
                        minOrMax=j;
                    }
                }
                else{
                    if(this->m_EmpArray[minOrMax]->m_Id<this->m_EmpArray[j]->m_Id){
                        minOrMax=j;
                    }
                }
            }
            if(i!=minOrMax){
                Worker * temp=this->m_EmpArray[i];
                this->m_EmpArray[i]=this->m_EmpArray[minOrMax];
                this->m_EmpArray[minOrMax]=temp;
            }
        }
       cout << "排序成功，排序后结果为： " << endl;
        this->Show_Emp(); 
        //保存文件
        this->save();
    
}
}
//清空文件
void WorkerManager::Clean_File(){
    cout << "确认清空？" << endl;
    cout << "1.确认" << endl;
    cout << "2.返回" << endl;
    int select=0;
    cin>>select;
    if(select==1){
        //打开模式ios::trunc 如果存在删除文件并重新创建
        ofstream ofs(FILENAME,ios::trunc);
        ofs.close();
        if(this->m_EmpArray!=NULL){
              for(int i=0;i<m_EmpNum;i++){
                delete this->m_EmpArray[i];
                this->m_EmpArray[i]=NULL;
              }
              //删除堆区数据指针
              delete []this->m_EmpArray;
              this->m_EmpArray=NULL;
              this->m_FileIsEmpty=true;
        }
        cout << "清空成功" << endl;
    }
        system("pause");
        system("cls");
    
}
//退出系统
void WorkerManager::exitsystem(){
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}
