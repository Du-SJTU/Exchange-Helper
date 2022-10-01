///////////////////////////////
// File: item.h
// Author: Du
// Function: ItemList���ԭ��
///////////////////////////////

#ifndef ITEM_H_
#define ITEM_H_

#include <string>
using namespace std;
// Item�ṹ�����ڱ�����Ʒ�������Ϣ
struct Item {
    int m_num; // ��Ʒ����
    string m_name; // ��Ʒ����
    string m_owner; // ��Ʒ����
    string m_tel; // ��ϵ�绰

    Item() {}
    Item(int num, string name, string owner, string tel) :
        m_num(num), m_name(name), m_owner(owner), m_tel(tel){}
    ~Item() {}
};
// �����������������Ի�û������Ʒ��Ϣ
istream &operator>>(istream &is, Item &i);
ostream &operator<<(ostream &os, Item &i);
// ItemListΪ��Ʒ�б�����˫����ʵ��
class ItemList {
public:
    ItemList();
    ~ItemList();
    
    void add(); // �����Ʒ 
    void remove(int index); // ������Ʒ������Ƴ���Ʒ
    void showList(); // ��ʾ������Ʒ
    void search(string name); // ������Ʒ
    void reset();

private:
    // ˫������
    struct Node 
    {
        Item m_item;
        Node *prev, *next;

        Node() : next(nullptr) {}
        Node(Item &i, Node *p = nullptr, Node *n = nullptr) :
            m_item(i), prev(p), next(n) {}
        ~Node() {}
    };

    int num_item; // �б�����Ʒ����
    Node *head, *tail; // ��ʼ����β���

    void getList(); // ���ⲿ�ļ���ȡ�б�
    void saveList(); // �����б��ⲿ�ļ�
};

#endif