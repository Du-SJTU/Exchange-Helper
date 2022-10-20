///////////////////////////////
// File: main.cpp
// Author: Du
// Function: 主程序
///////////////////////////////

#include "itemlist.h"
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

void showWelcome(); // 显示欢迎语句
void showTips(); // 显示使用说明

int main()
{
    ItemList list;
    string query_name;
    char op; // 操作
    showWelcome();
    while (true)
    {
        showTips();
        op = cin.get();
        cin.get(); // 吸收换行符
        switch (op)
        {
        case '1':
            list.add();
            break;
        case '2':
            int index;
            cout << "输入删除的物品的编号：";
            cin >> index;
            cin.get(); // 吸收换行符
            list.remove(index);
            break;
        case '3':
            list.showList();
            break;
        case '4':
            cout << "请输入你要查询的物品的名字：";
            getline(cin, query_name);
            list.search(query_name);
            break;
        case 'r':
            while (true)
            {
                cout << "你确定要重置列表吗（y/n）：";
                cin >> op;
                cin.get();
                if (tolower(op) == 'y')
                {
                    list.reset();
                    break;
                }
                else if (tolower(op) == 'n')
                {
                    break;
                }
            }
            break;
        case 'q':
            exit(0);
        default:
            cout << "没有此指令，请重新输入!";
        }
        cout << "\n************请输入下一个操作指令************\n";
    }
    return 0;
}

void showWelcome()
{
    cout << setw(20) << "##########################################" << endl;
    cout << setw(20) << "####  欢迎使用”你帮我助“物品交换系统  ####" << endl;
    cout << setw(20) << "##########################################" << endl;
}

void showTips()
{
    cout << "\n请选择你要使用的功能并输入相应的数字或字母" << endl;
    cout << "1.添加物品" << endl;
    cout << "2.删除物品" << endl;
    cout << "3.查看列表" << endl;
    cout << "4.搜索列表" << endl;
    cout << "r.重置列表" << endl;
    cout << "q.退出程序" << endl;
}
