#include"main.h"
int main()
{
	menu();
	int n;
	srand((unsigned int)time(NULL));
	do//循环实现菜单功能
	{
		
		cout << "请输入执行的操作：" << endl;
		//int n = 0;
		cin >> n;
		switch (n)
		{
		case 1: cout << "比赛开始" << endl; start(); break;
		case 2:cout << "往届记录" << endl; loadrecord();  break;
		case 3:myclear(); cout << "清空" << endl; break;
		case 0:exit(); cout << "结束" << endl; break;
		default:cout << "执行代码输入错误" << endl; break;
		}
	} while (n);
	return 0;
}