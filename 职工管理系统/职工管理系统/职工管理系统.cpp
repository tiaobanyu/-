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
      case 0 :
        wm.exitsystem();
      case 1 :
      wm.Add_Emp;
        break;
      case 2 :
        break;
      case 3 :
        break;
      case 4 :
        break;
      case 5 :
        break;
      case 6 :
        break;
      case 7 :
        break;
      default :
      system("cls");
      break;
    }
    system("pause");
    return 0;
 }
