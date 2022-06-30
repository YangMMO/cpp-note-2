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

// 显示联系人
void showPerson(AddressBooks *abs)
{
    // 判断通讯录是否为空
    if (abs->m_Size == 0) {
        cout << "通讯录为空，无法显示联系人" << endl;
        return;
    } else {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "姓名：" << abs->personArray[i].m_Name << "\t";
            cout << "性别：" << (abs->personArray[i].m_Gender == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personArray[i].m_Age << "\t";
            cout << "电话：" << abs->personArray[i].m_Phone << "\t";
            cout << "地址：" << abs->personArray[i].m_Address << endl;
        }

        system("pause");
        system("cls");  //清屏
        
    }
    
}

// 检测联系人是否存在，存在返回下标，不存在返回-1
// 参数1 通讯录 ， 参数2 对比名称
int isExist(AddressBooks *abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        // 找到姓名相同的联系人
        if (abs->personArray[i].m_Name == name)
        {
            return i;   // 返回下标
        }
    }
    return -1;   // 不存在返回-1  
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
            showPerson(&abs);
            break;
        case 3:
        {   // 如果 switch 内代码过程可能会报错，此时可以使用{}把代码括起来
            /* 删除联系人 */
            cout << "请输入要删除的联系人姓名：" << endl;
            string name;
            cin >> name;
            // 判断联系人是否存在
            if (isExist(&abs, name) == -1)
            {
                cout << "联系人不存在，无法删除" << endl;
            }
            else
            {
                // 删除联系人
                // deletePerson(&abs, name);

                cout << "删除成功" << endl;
            }
        }
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