#include"main.h"
int main()
{
	menu();
	int n;
	srand((unsigned int)time(NULL));
	do//ѭ��ʵ�ֲ˵�����
	{
		
		cout << "������ִ�еĲ�����" << endl;
		//int n = 0;
		cin >> n;
		switch (n)
		{
		case 1: cout << "������ʼ" << endl; start(); break;
		case 2:cout << "�����¼" << endl; loadrecord();  break;
		case 3:myclear(); cout << "���" << endl; break;
		case 0:exit(); cout << "����" << endl; break;
		default:cout << "ִ�д����������" << endl; break;
		}
	} while (n);
	return 0;
}