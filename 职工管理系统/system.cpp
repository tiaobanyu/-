#include <iostream>
using namespace std;
#include "workerManager.h"
#include "workerManager.cpp"
#include <windows.h>
 int main(){
 SetConsoleOutputCP(936);  // 设置控制台编码为GBK
    // 后续代码
    WorkerManager wm;
    wm.showMenu();
    cout<<"请输入您的选择"<<endl;
    int choice;
    cin>>choice;
    switch(choice){
      case 0 ://退出系统
        wm.exitsystem();
      case 1 ://增加职工
      wm.Add_Emp();
        break;
      case 2 ://显示职工
      wm.Show_Emp();
        break;
      case 3 ://删除职工
      wm.Del_Emp();
        break;
      case 4 ://修改职工
      wm.Mod_Emp();
        break;
      case 5 ://查找职工
      wm.Find_Emp();
        break;
      case 6 ://排序
      wm.Sort_Emp();
        break;
      case 7 ://清空文档
      wm.Clean_File();
        break;
      default :
      system("cls");
      break;
    }
    system("pause");
    return 0;
 }
