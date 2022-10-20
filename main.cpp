///////////////////////////////
// File: main.cpp
// Author: Du
// Function: ������
///////////////////////////////

#include "itemlist.h"
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

void showWelcome(); // ��ʾ��ӭ���
void showTips(); // ��ʾʹ��˵��

int main()
{
    ItemList list;
    string query_name;
    char op; // ����
    showWelcome();
    while (true)
    {
        showTips();
        op = cin.get();
        cin.get(); // ���ջ��з�
        switch (op)
        {
        case '1':
            list.add();
            break;
        case '2':
            int index;
            cout << "����ɾ������Ʒ�ı�ţ�";
            cin >> index;
            cin.get(); // ���ջ��з�
            list.remove(index);
            break;
        case '3':
            list.showList();
            break;
        case '4':
            cout << "��������Ҫ��ѯ����Ʒ�����֣�";
            getline(cin, query_name);
            list.search(query_name);
            break;
        case 'r':
            while (true)
            {
                cout << "��ȷ��Ҫ�����б���y/n����";
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
            cout << "û�д�ָ�����������!";
        }
        cout << "\n************��������һ������ָ��************\n";
    }
    return 0;
}

void showWelcome()
{
    cout << setw(20) << "##########################################" << endl;
    cout << setw(20) << "####  ��ӭʹ�á������������Ʒ����ϵͳ  ####" << endl;
    cout << setw(20) << "##########################################" << endl;
}

void showTips()
{
    cout << "\n��ѡ����Ҫʹ�õĹ��ܲ�������Ӧ�����ֻ���ĸ" << endl;
    cout << "1.�����Ʒ" << endl;
    cout << "2.ɾ����Ʒ" << endl;
    cout << "3.�鿴�б�" << endl;
    cout << "4.�����б�" << endl;
    cout << "r.�����б�" << endl;
    cout << "q.�˳�����" << endl;
}
