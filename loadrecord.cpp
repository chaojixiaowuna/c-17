#include"main.h"
void loadrecord()
{
	ifstream ifs;
	ifs.open("演讲比赛.csv", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
	}
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}
	ifs.close();
}