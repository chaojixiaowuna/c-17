#include"main.h"
#define groupA 0;
#define groupB 1;
class Player//定义选手类
{
public:
	Player(string name,int id)
	{
		this->name = name;
		this->id = id;
		this->grade = 0;
	}
	string name;
	int grade;
	int id;
};
class myprint
{
public:
	void operator()(Player &p)
	{
		 cout << "姓名:" << p.name << "编号:" << p.id << "成绩:" <<p.grade << endl;
	}
};
//class mycase    不知道为啥出问题了
//{
//public:
//	Player* operator()(pair<const int,Player> &m)
//	{
//		if (m.first)
//		{ 
//			return &(m.second) ;
//		}
//			
//	}
//};
void createplayer(vector<Player>&v,multimap<int,Player>&m)
{
	int count0 = 0;
	int count1 = 0;
	string playerseed = "abcdefghijkl";
	for (int i = 0; i < 12; i++)
	{
		string name = "选手";
		name += playerseed[i];
		int id;
		id = 1000 + i;
		Player p(name, id);
		//随机分组
		int div = 0;
		div = rand() % 2;
		if (count0 <6&&count1<6)
		{
			if (div == 0)
			{
				count0++;
			}
			else if (div == 1)
			{
				count1++;
			}
		}
		else {
			if (count0 == 6)
			{
				div = 1;
			}
			else if (count1==6)
			{
				div = 0;
			}
		}
		
		m.insert(make_pair(div, p));
		v.push_back(p);
	}
}
void showPlayer(vector<Player>&v)
{
	for_each(v.begin(), v.end(), myprint());
	cout << endl;
}

class divprint
{
public:
	void operator()(pair<const int, Player>& p)
	{
		if (p.first == 0)
		{
			cout << "第一组" <<p.second.name << endl;
		}
		if(p.first==1)
		{
			cout << "第二组" << p.second.name << endl;
		}
	}
};
void divshow(multimap<int, Player >& m)
{
	for_each(m.begin(), m.end(), divprint());
	cout << endl;
}
void speechcontest(Player &p1)
{
	deque<int> d;
	for (int i = 0; i < 10; i++)
	{
		int n = rand() % 50+50;
		//d.insert(d.begin (),n);
		d.push_back(n);
	}
	sort(d.begin(), d.end());
	d.pop_back();
	d.pop_front();
	int grade = accumulate(d.begin(), d.end(), 0) / d.size();
	p1.grade = grade;
}
class com
{
public:
	bool operator()(Player& p1,Player p2)
	{
		return p1.grade  > p2.grade ;
	}
};
void start()
{
	//创建比赛选手
	vector<Player> v;
	multimap<int, Player> m;
	createplayer(v,m);
	//showPlayer(v);//显示全部选手信息

	//分组显示选手信息
	//divshow(m);

	//将两组选手放到两个容器中
	vector<Player> v0;
	vector<Player>v1;
	//transform(m.begin(), m.end(), v1.begin(), mycase());  不知道为啥出问题了
	for (multimap<int, Player>::iterator it = m.begin(); it != m.end(); it++)
	{
		if ((*it).first == 0)
		{
			v0.push_back((*it).second);
		}
		else if ((*it).first == 1)
		{
			v1.push_back((*it).second);
		}
	}
	//showPlayer(v0);
	//showPlayer(v1);

	//抽签
	random_shuffle(v0.begin(), v0.end());
	//showPlayer(v0);
	random_shuffle(v1.begin(), v1.end());

	//第一轮比赛打分 十个评委打分 去掉最高和最低 取平均分
	for (vector<Player>::iterator vit = v0.begin(); vit != v0.end(); vit++)
	{
		speechcontest(*vit);
	}
	//showPlayer(v0);
	for (vector<Player>::iterator vvit = v1.begin(); vvit != v1.end(); vvit++)
	{
		speechcontest(*vvit);
	}
	//showPlayer(v1);

	//展示排名 按任意键结束
	vector<Player> v3;//存放两组前三名
	cout << "第一轮的第一组前三名为：" << endl;
	sort(v0.begin(), v0.end(),com());
	for (int i = 0; i < 3; i++)
	{
		cout << v0[i].name << v0[i].grade << endl;
		v3.push_back(v0[i]);//存取前三名
	}
	cout << "第一轮的第二组前三名为：" << endl;
	sort(v1.begin(), v1.end(),com());
	for (int i = 0; i < 3; i++)
	{
		cout << v1[i].name << v1[i].grade << endl;
		v3.push_back(v1[i]);//存取前三名
	}
	system("pause");

	//第二轮比赛
	for (vector<Player>::iterator vit = v3.begin(); vit != v3.end(); vit++)
	{
		speechcontest(*vit);
	}
	sort(v3.begin(), v3.end(), com());
	ofstream ofs;
	ofs.open("演讲比赛.csv", ios::out|ios::app);
	for (int i = 0; i < 3; i++)
	{
		cout << "第" << i+1 <<"名" << endl;
		cout << v3[i].name << v3[i].grade << endl;
		ofs << "第" << i + 1 << "名"  << v3[i].name <<"   " 
			<< "id:" << v3[i].id <<"   grade:" << v3[i].grade << endl;//写文件
	}
	
	cout << "比赛结束 " << endl << "保存成功" << endl;
}