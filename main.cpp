///////////////////////////////
// File: main.cpp
// Author: �żѽ�
// Function: ������
///////////////////////////////

#include "itemlist.h"
#include <iostream>
#include <iomanip>
using namespace std;

void showWelcome();
void showTips();

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
            cin >> query_name;
            cin.get(); // ���ջ��з�
            list.search(query_name);
            break;
        case 'q':
            exit(0);
        default:
            cout << "û�д�ָ�����������!";
        }
        cout << "************��������һ������ָ��************\n";
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
    cout << "q.�˳�����" << endl;
}