#include"main.h"
void myclear()
{
	cout << "ȷ�����" << endl;
	cout << "�� 1 �� 0" << endl;
	int n;
	cin >> n;
	if (n == 1)
	{
		ofstream ofs;
		ofs.open("�ݽ�����.csv", ios::trunc);
		cout << "��ճɹ�" << endl;
	}
	

}