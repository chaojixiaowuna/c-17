#include"main.h"
void loadrecord()
{
	ifstream ifs;
	ifs.open("�ݽ�����.csv", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}
	ifs.close();
}