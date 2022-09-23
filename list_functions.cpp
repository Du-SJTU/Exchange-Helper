///////////////////////////////
// File: list_functions.cpp
// Author: �żѽ�
// Function: ItemList��ĳ�Ա����
///////////////////////////////

#include "itemlist.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// ��ʾ��ͷ
void showHeader()
{
    cout << setw(5) << "���";
    cout << setw(20) << "��Ʒ����";
    cout << setw(10) << "��Ʒ����";
    cout << setw(15) << "��Ʒ������";
    cout << setw(15) << "��ϵ�绰";
    cout << endl;
}

// Item�������������
istream &operator>>(istream &is, Item &i)
{
    cout << "��������Ʒ���ƣ�";
    getline(is, i.m_name);
    cout << "��������Ʒ������";
    int n = 0;
    is >> n;
    while (n <= 0)
    {
        cout << "�����������������룺";
        is >> n;
    }
    i.m_num = n;
    is.get(); // ���ջ��з�
    cout << "��������Ʒ������������";
    getline(is, i.m_owner);
    cout << "��������Ʒ�����˵绰��";
    getline(is, i.m_tel);
    return is;
}

ostream &operator<<(ostream &os, Item &i)
{
    cout << setw(20) << i.m_name;
    cout << setw(10) << i.m_num;
    cout << setw(15) << i.m_owner;
    cout << setw(15) << i.m_tel;
    return os;
}

// ItemList���캯��
ItemList::ItemList()
{
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
    num_item = 0;
    //getList();
}

// ItemList����������
ItemList::~ItemList()
{
    Node *temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// ����Ʒ�б���������Ʒ
void ItemList::add()
{
    Item add_item;
    cin >> add_item;
    // �����µĽ�����˫����β��
    Node *temp = new Node(add_item);
    temp->prev = tail->prev;
    temp->next = tail;
    tail->prev->next = temp;
    tail->prev = temp;
    cout << "��Ʒ" << add_item.m_name << "���ӳɹ���" << endl;
    ++num_item;
}

// ��ʾ��Ʒ�б�
void ItemList::showList()
{
    int index = 1; // ��Ʒ�ı��
    showHeader();
    Node *temp = head->next;
    while (temp != tail) {
        cout << setw(5) << index;
        cout << temp->m_item << endl;
        temp = temp->next;
        ++index;
    }
    cout << "\n���ҵ�" << num_item << "������\n\n";
}

// ������Ʒ������Ƴ���Ʒ
void ItemList::remove(int index)
{
    // �ж��Ƿ���ڸñ�ŵ���Ʒ
    if (index <= 0 || index > num_item)
    {
        cout << "���Ϊ" << index << "����Ʒ�����ڣ�" << endl;
        return;
    }
    Node *temp = head;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    string temp_name = temp->m_item.m_name; // ��ɾ����Ʒ������
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
    cout << "�ɹ�ɾ�����Ϊ" << index << "����Ʒ" << temp_name << "��" << endl;
}

// ������Ʒ
void ItemList::search(string name)
{
    Node *temp = head->next;
    int cnt = 0, index = 1;
    bool header = false; // �Ƿ���ʾ��ͷ
    while (temp) {
        if (temp->m_item.m_name == name)
        {
            if (!header)
            {
                header = true;
                showHeader();
            }
            cout << setw(5) << index;
            cout << temp->m_item << endl;
            ++cnt;
        }
        temp = temp->next;
        ++index;
    }
    if (cnt == 0)
    {
        cout << "δ�����������Ʒ" << endl;
    }
    else
    {
        cout << "\n\n��������" << cnt << "�����" << endl;
    }
}