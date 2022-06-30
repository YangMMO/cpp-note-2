#include <iostream>
#include <string>
using namespace std;

#define MAX 1000   // 定义宏常量

// 设计联系人结构体
struct Person {
    string m_Name;      // 名称
    int m_Gender;       // 性别
    int m_Age;          // 年龄
    string m_Phone;     // 电话
    string m_Address;   // 地址
};


// 设计通讯录结构体
struct AddressBooks
{
    struct Person personArray[MAX]; //通讯录数组最大人数
    int m_Size; //当前记录人数
};

// 添加联系人
void AddPerson(AddressBooks *abs)
{
    if (abs->m_Size == MAX) {
        cout << "通讯录已满，无法添加联系人" << endl;
        return;
    } else {
        // 输入姓名
        string name;
        cout << "请输入联系人姓名：" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        // 输入性别
        int gender = 0;
        cout << "请输入联系人性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;

        while (true)    // 判断输入是否1或2，直至正确break
        {
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                abs->personArray[abs->m_Size].m_Gender = gender;
                break;
            }
            cout << "请输入有误请重试" << endl;
        }

        // 输入年龄
        int age = 0;
        cout << "请输入联系人年龄：" << endl;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        // 输入电话
        string phone;
        cout << "请输入联系人电话：" << endl;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone= phone;

        // 输入地址
        string address;
        cout << "请输入联系人地址：" << endl;
        cin >> address;
        abs->personArray[abs->m_Size].m_Address = address;

        // 更新通讯录人数
        abs->m_Size++;

        // 添加成功
        cout << "添加成功" << endl;

        // 清屏
        system("pause");
        system("cls");  //清屏
    }
    
}


// 菜单界面
void showMenu()
{
    cout << "**********************" << endl;
    cout << "* 1.添加联系人       *" << endl;
    cout << "* 2.显示联系人       *" << endl;
    cout << "* 3.删除联系人       *" << endl;
    cout << "* 4.查询联系人       *" << endl;
    cout << "* 5.修改联系人       *" << endl;
    cout << "* 6.清空联系人       *" << endl;
    cout << "* 0.退出系统         *" << endl;
    cout << "**********************" << endl;
}


int main()
{

    // 创建结构体变量
    AddressBooks abs;
    abs.m_Size = 0; // 初始化通讯录当前人员个数

    // 用户输入变量
    int select = 0;

    // 通过循环，解决cin提早退出系统，只有case到0才退出
    while (true)
    {
        showMenu();

        cin >> select;

        switch (select)
        {
        case 1:
            /* 添加联系人 */
            // 利用地址传递修饰实参
            AddPerson(&abs);
            break;
        case 2:
            /* 显示联系人 */
            break;
        case 3:
            /* 删除联系人 */
            break;
        case 4:
            /* 查询联系人 */
            break;
        case 5:
            /* 修改联系人 */
            break;
        case 6:
            /* 清空联系人 */
            break;
        case 0:
            /* 退出系统 */
            cout << "退出系统" << endl;
            system("pause");
            return 0;
            break;
        default:
            break;
        }
    }
    
	system("pause");
    return 0;
}