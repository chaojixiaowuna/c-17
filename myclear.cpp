#include"main.h"
void myclear()
{
	cout << "确认清空" << endl;
	cout << "是 1 否 0" << endl;
	int n;
	cin >> n;
	if (n == 1)
	{
		ofstream ofs;
		ofs.open("演讲比赛.csv", ios::trunc);
		cout << "清空成功" << endl;
	}
	

}