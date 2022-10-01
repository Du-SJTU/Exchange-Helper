///////////////////////////////
// File: item.h
// Author: Du
// Function: ItemList类的原型
///////////////////////////////

#ifndef ITEM_H_
#define ITEM_H_

#include <string>
using namespace std;
// Item结构体用于保存物品的相关信息
struct Item {
    int m_num; // 物品数量
    string m_name; // 物品名字
    string m_owner; // 物品主人
    string m_tel; // 联系电话

    Item() {}
    Item(int num, string name, string owner, string tel) :
        m_num(num), m_name(name), m_owner(owner), m_tel(tel){}
    ~Item() {}
};
// 重载输入输出运算符以获得或输出物品信息
istream &operator>>(istream &is, Item &i);
ostream &operator<<(ostream &os, Item &i);
// ItemList为物品列表，采用双链表实现
class ItemList {
public:
    ItemList();
    ~ItemList();
    
    void add(); // 添加物品 
    void remove(int index); // 根据物品的序号移除物品
    void showList(); // 显示所有物品
    void search(string name); // 搜索物品
    void reset();

private:
    // 双链表结点
    struct Node 
    {
        Item m_item;
        Node *prev, *next;

        Node() : next(nullptr) {}
        Node(Item &i, Node *p = nullptr, Node *n = nullptr) :
            m_item(i), prev(p), next(n) {}
        ~Node() {}
    };

    int num_item; // 列表内物品数量
    Node *head, *tail; // 起始结点和尾结点

    void getList(); // 从外部文件获取列表
    void saveList(); // 保存列表到外部文件
};

#endif