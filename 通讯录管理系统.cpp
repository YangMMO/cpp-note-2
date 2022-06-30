#include <iostream>
#include <string>
using namespace std;

#define MAX 1000   // ����곣��

// �����ϵ�˽ṹ��
struct Person {
    string m_Name;      // ����
    int m_Gender;       // �Ա�
    int m_Age;          // ����
    string m_Phone;     // �绰
    string m_Address;   // ��ַ
};


// ���ͨѶ¼�ṹ��
struct AddressBooks
{
    struct Person personArray[MAX]; //ͨѶ¼�����������
    int m_Size; //��ǰ��¼����
};

// �����ϵ��
void AddPerson(AddressBooks *abs)
{
    if (abs->m_Size == MAX) {
        cout << "ͨѶ¼�������޷������ϵ��" << endl;
        return;
    } else {
        // ��������
        string name;
        cout << "��������ϵ��������" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        // �����Ա�
        int gender = 0;
        cout << "��������ϵ���Ա�" << endl;
        cout << "1 --- ��" << endl;
        cout << "2 --- Ů" << endl;

        while (true)    // �ж������Ƿ�1��2��ֱ����ȷbreak
        {
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                abs->personArray[abs->m_Size].m_Gender = gender;
                break;
            }
            cout << "����������������" << endl;
        }

        // ��������
        int age = 0;
        cout << "��������ϵ�����䣺" << endl;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        // ����绰
        string phone;
        cout << "��������ϵ�˵绰��" << endl;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone= phone;

        // �����ַ
        string address;
        cout << "��������ϵ�˵�ַ��" << endl;
        cin >> address;
        abs->personArray[abs->m_Size].m_Address = address;

        // ����ͨѶ¼����
        abs->m_Size++;

        // ��ӳɹ�
        cout << "��ӳɹ�" << endl;

        // ����
        system("pause");
        system("cls");  //����
    }
    
}


// �˵�����
void showMenu()
{
    cout << "**********************" << endl;
    cout << "* 1.�����ϵ��       *" << endl;
    cout << "* 2.��ʾ��ϵ��       *" << endl;
    cout << "* 3.ɾ����ϵ��       *" << endl;
    cout << "* 4.��ѯ��ϵ��       *" << endl;
    cout << "* 5.�޸���ϵ��       *" << endl;
    cout << "* 6.�����ϵ��       *" << endl;
    cout << "* 0.�˳�ϵͳ         *" << endl;
    cout << "**********************" << endl;
}


int main()
{

    // �����ṹ�����
    AddressBooks abs;
    abs.m_Size = 0; // ��ʼ��ͨѶ¼��ǰ��Ա����

    // �û��������
    int select = 0;

    // ͨ��ѭ�������cin�����˳�ϵͳ��ֻ��case��0���˳�
    while (true)
    {
        showMenu();

        cin >> select;

        switch (select)
        {
        case 1:
            /* �����ϵ�� */
            // ���õ�ַ��������ʵ��
            AddPerson(&abs);
            break;
        case 2:
            /* ��ʾ��ϵ�� */
            break;
        case 3:
            /* ɾ����ϵ�� */
            break;
        case 4:
            /* ��ѯ��ϵ�� */
            break;
        case 5:
            /* �޸���ϵ�� */
            break;
        case 6:
            /* �����ϵ�� */
            break;
        case 0:
            /* �˳�ϵͳ */
            cout << "�˳�ϵͳ" << endl;
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