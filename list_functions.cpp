///////////////////////////////
// File: list_functions.cpp
// Author: 杜佳杰
// Function: ItemList类的成员函数
///////////////////////////////

#include "itemlist.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// 显示表头
void showHeader()
{
    cout << setw(5) << "\n编号";
    cout << setw(20) << "物品名称";
    cout << setw(10) << "物品数量";
    cout << setw(15) << "物品持有人";
    cout << setw(15) << "联系电话";
    cout << endl;
}

// Item的输入输出重载
istream &operator>>(istream &is, Item &i)
{
    cout << "请输入物品名称：";
    getline(is, i.m_name);
    cout << "请输入物品数量：";
    int n = 0;
    is >> n;
    while (n <= 0)
    {
        cout << "输入有误，请重新输入：";
        is >> n;
    }
    i.m_num = n;
    is.get(); // 吸收换行符
    cout << "请输入物品持有人姓名：";
    getline(is, i.m_owner);
    cout << "请输入物品持有人电话：";
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

void ItemList::getList()
{
    Item get_item;
    ifstream fin("listdata.csv");
    if (fin)
    {
        while (!fin.eof())
        {
            getline(fin, get_item.m_name, ',');
            string s_num; // 临时以字符串形式保存数字
            if (get_item.m_name == "") break; // 检测是否为空行
            getline(fin, s_num, ',');
            get_item.m_num = stoi(s_num);
            getline(fin, get_item.m_owner, ',');
            getline(fin, get_item.m_tel, ',');
            getline(fin, s_num); // 文件读取位置换行

            Node *temp = new Node(get_item);
            temp->prev = tail->prev;
            temp->next = tail;
            tail->prev->next = temp;
            tail->prev = temp;
            ++num_item;
        }
        fin.close();
    }
}

void ItemList::saveList()
{
    Node *temp = head->next;
    ofstream fout("listdata.csv");
    if (!fout)
    {
        cout << "保存物品列表失败！" << endl;
        return;
    }
    while (temp != tail)
    {
        //将链表中的Item类以二进制形式存入外部文件
        fout << temp->m_item.m_name << ",";
        fout << temp->m_item.m_num << ",";
        fout << temp->m_item.m_owner << ",";
        fout << temp->m_item.m_tel << ",";
        fout << endl;
        temp = temp->next;
    }
    fout.close();
}

// ItemList构造函数
ItemList::ItemList()
{
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
    num_item = 0;
    getList();
}

// ItemList的析构函数
ItemList::~ItemList()
{
    Node *temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// 向物品列表中添加物品
void ItemList::add()
{
    Item add_item;
    cin >> add_item;
    // 创建新的结点插入双链表尾部
    Node *temp = new Node(add_item);
    temp->prev = tail->prev;
    temp->next = tail;
    tail->prev->next = temp;
    tail->prev = temp;
    cout << "物品" << add_item.m_name << "添加成功！" << endl;
    ++num_item;
    saveList(); // 保存当前的列表到csv文件
}

// 显示物品列表
void ItemList::showList()
{
    int index = 1; // 物品的编号
    showHeader();
    Node *temp = head->next;
    while (temp != tail) {
        cout << setw(5) << index;
        cout << temp->m_item << endl;
        temp = temp->next;
        ++index;
    }
    cout << "\n共找到" << num_item << "条数据\n\n";
}

// 根据物品的序号移除物品
void ItemList::remove(int index)
{
    // 判断是否存在该编号的物品
    if (index <= 0 || index > num_item)
    {
        cout << "编号为" << index << "的物品不存在！" << endl;
        return;
    }
    Node *temp = head;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    string temp_name = temp->m_item.m_name; // 被删除物品的名字
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
    cout << "成功删除编号为" << index << "的物品" << temp_name << "！" << endl;
    --num_item;
    saveList();
}

// 搜索物品
void ItemList::search(string name)
{
    Node *temp = head->next;
    int cnt = 0, index = 1;
    bool header = false; // 是否显示标头
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
        cout << "未搜索到相关物品" << endl;
    }
    else
    {
        cout << "\n\n共搜索到" << cnt << "条结果" << endl;
    }
}