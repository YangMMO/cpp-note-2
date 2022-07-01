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

// ��ʾ��ϵ��
void showPerson(AddressBooks *abs)
{
    // �ж�ͨѶ¼�Ƿ�Ϊ��
    if (abs->m_Size == 0) {
        cout << "ͨѶ¼Ϊ�գ��޷���ʾ��ϵ��" << endl;
        return;
    } else {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "������" << abs->personArray[i].m_Name << "\t";
            cout << "�Ա�" << (abs->personArray[i].m_Gender == 1 ? "��" : "Ů") << "\t";
            cout << "���䣺" << abs->personArray[i].m_Age << "\t";
            cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
            cout << "��ַ��" << abs->personArray[i].m_Address << endl;
        }

        system("pause");
        system("cls");  //����
        
    }
    
}

// �����ϵ���Ƿ���ڣ����ڷ����±꣬�����ڷ���-1
// ����1 ͨѶ¼ �� ����2 �Ա�����
int isExist(AddressBooks *abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        // �ҵ�������ͬ����ϵ��
        if (abs->personArray[i].m_Name == name)
        {
            return i;   // �����±�
        }
    }
    return -1;   // �����ڷ���-1  
}

// ɾ����ϵ��
void deletePerson(AddressBooks *abs)
{
    cout << "������Ҫɾ������ϵ��������" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1) {    // ����
        // �ñ�ɾ�����ݵĺ���һλ��������ǰ��һλ
        for (int i = 0; i < abs->m_Size; i++)
        {
            // ����ǰ�Ʋ���
            abs->personArray[i] = abs->personArray[i + 1];
        }

        abs->m_Size--;  // ����ͨѶ¼����

        cout << "ɾ���ɹ�" << endl;
    } else {    // ������
        cout << "û���ҵ�����ϵ��" << endl;
    }

    system("pause");
    system("cls");  //����
    
}

// ������ϵ��
void findPseson(AddressBooks *abs)
{
    cout << "������Ҫ���ҵ���ϵ��������" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);

    if (ret != -1)
    {
        cout << "������" << abs->personArray[ret].m_Name << "\t";
        cout << "�Ա�" << (abs->personArray[ret].m_Gender == 1 ? "��" : "Ů") << "\t";
        cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
        cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
        cout << "��ַ��" << abs->personArray[ret].m_Address << endl;
    } else {
        cout << "û���ҵ�����ϵ��" << endl;
    }
    
    system("pause");
    system("cls");  //����

}

// �޸���ϵ��
void modifyPerson(AddressBooks *abs)
{
    cout << "������Ҫ�޸ĵ���ϵ��������" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1) {    // ����
        // ��������
        string name;
        cout << "������������" << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;

        // �����Ա�
        int gender = 0;
        cout << "��������ϵ���Ա�" << endl;
        cout << "1 --- ��" << endl;
        cout << "2 --- Ů" << endl;

        while (true) // �ж������Ƿ�1��2��ֱ����ȷbreak
        {
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                abs->personArray[ret].m_Gender = gender;
                break;
            }
            cout << "����������������" << endl;
        }

        // ��������
        int age = 0;
        cout << "��������ϵ�����䣺" << endl;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        // ����绰
        string phone;
        cout << "��������ϵ�˵绰��" << endl;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        // �����ַ
        string address;
        cout << "��������ϵ�˵�ַ��" << endl;
        cin >> address;
        abs->personArray[ret].m_Address = address;

        cout << "�޸ĳɹ�" << endl;

    } else {    // ������
        cout << "û���ҵ�����ϵ��" << endl;
    }

    system("pause");
    system("cls");  //����
}

// ���ͨѶ¼
void cleanPerson(AddressBooks *abs)
{
    int isClean = 0;
    cout << "�Ƿ�ȷ�����ͨѶ¼��" << endl;
    cout << "1 --- ȷ��" << endl;
    cout << "2 --- ȡ��" << endl;
    cin >> isClean;

    if (isClean == 1)
    {
        abs->m_Size = 0;
        cout << "��ճɹ�" << endl;
    } else {
        cout << "ȡ�����" << endl;
    }

    system("pause");
    system("cls");  //����
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
            showPerson(&abs);
            break;
        case 3:
            /* ɾ����ϵ�� */
            deletePerson(&abs);
            break;
        case 4:
            /* ��ѯ��ϵ�� */
            findPseson(&abs);
            break;
        case 5:
            /* �޸���ϵ�� */
            modifyPerson(&abs);
            break;
        case 6:
            /* �����ϵ�� */
            cleanPerson(&abs);
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