// ** ContainerMap v0.4
#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;


struct Vector3
{
	float x, y, z;

	Vector3() : x(0.0f), y(0.0f), z(0.0f) {};

	Vector3(const float& _x, const float& _y) : x(_x), y(_y), z(0.0f) {};

	Vector3(const float& _x, const float& _y, const float& _z)
		: x(_x), y(_y), z(_z) {};
};

struct Trasnform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
};





struct Object
{
	Trasnform Info;

	Object() {};

	Object(const Trasnform& _Info) : Info(_Info) {};
};

struct Player : public Object
{
	Player() {};

	Player(const Trasnform& _Info) : Object(_Info) {};
};


// ** 오브젝트 몃개 더 추가함.
struct Enemy : public Object
{
	Enemy() {};

	Enemy(const Trasnform& _Info) : Object(_Info) {};
};

struct Bullet : public Object
{
	Bullet() {};

	Bullet(const Trasnform& _Info) : Object(_Info) {};
};

struct Boss : public Object
{
	Boss() {};

	Boss(const Trasnform& _Info) : Object(_Info) {};
};




map<string, list<Object*>> Objects;


void Initialize();
void AddObject(string _Key, Object* _Object);


int main(void)
{
	Trasnform Info;

	Info.Position.x = 10;
	Info.Position.y = 20;
	Info.Position.z = 30;

	AddObject("Player", new Player(Info));
	AddObject("Player", new Player(Info));
	AddObject("Player", new Player(Info));

	Info.Position.x = 100;
	Info.Position.y = 200;
	Info.Position.z = 300;

	AddObject("Enemy", new Enemy(Info));
	AddObject("Enemy", new Enemy(Info));

	Info.Position.x = 1000;
	Info.Position.y = 2000;
	Info.Position.z = 3000;

	AddObject("Bullet", new Bullet(Info));
	AddObject("Bullet", new Bullet(Info));
	AddObject("Bullet", new Bullet(Info));

	Info.Position.x = 10000;
	Info.Position.y = 20000;
	Info.Position.z = 30000;

	AddObject("Boss", new Boss(Info));
	AddObject("Boss", new Boss(Info));
	AddObject("Boss", new Boss(Info));

	for (map<string, list<Object*>>::iterator iter = Objects.begin();
		iter != Objects.end(); ++iter)
	{
		cout << " [" << iter->first << "] " << endl;
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			cout << (*iter2)->Info.Position.x << ", " <<
				(*iter2)->Info.Position.y << ", " << (*iter2)->Info.Position.z << endl;
		}
		cout << endl;
	}

	return 0;
}

void Initialize()
{
	Trasnform Info;

	Info.Position.x = 10;
	Info.Position.y = 20;
	Info.Position.z = 30;

	//Objects["Player"] = new Player(Info);
}

void AddObject(string _Key, Object* _Object)
{
	map<string, list<Object*>>::iterator iter = Objects.find(_Key);

	if (iter == Objects.end())
	{
		list<Object*> Temp;
		Temp.push_back(_Object);
		Objects.insert(make_pair(_Key, Temp));
	}
	else
		iter->second.push_back(_Object);
}


#pragma region ** ContainerMap v0.1

/*
#include <iostream>
#include <string>
#include <map>

using namespace std;



int main(void)
{
	/*
	map<int, int> Numbers;

	// ** Key, Value
	//map<int, int>

	Numbers[0] = 1;
	Numbers[1] = 2;
	Numbers[2] = 3;
	Numbers[3] = 4;
	Numbers[4] = 5;
	*/





	/*
	map<string, int> Numbers;

	// ** Key, Value
	//map<int, int>

	Numbers["A"] = 1;
	Numbers["B"] = 2;
	Numbers["C"] = 3;
	Numbers["D"] = 4;
	Numbers["E"] = 5;

	//for (map<string, int>::iterator iter = Numbers.begin();
	//	iter != Numbers.end(); ++iter)
	//{
	//	cout << iter->first << endl;
	//	cout << iter->second << endl << endl;
	//}

	for (auto iter = Numbers.begin(); iter != Numbers.end(); ++iter)
	{
		cout << iter->first << endl;
		cout << iter->second << endl << endl;
	}
	*/





	/*
	enum Key { AAA, BBB, CCC, DDD, EEE };

	const int Max = 10;
	int max = 10;

	Key _State = AAA;
	int Array[EEE];

	cout << Array[_State] << endl;
	*/





/*
* enum Key
{
	Player,
	Enemy,
	Bullet,
	Max,
};

const int MaxObject = 128;

int Array[Max][MaxObject];

for (int i = 0; i < Max; ++i)
{
	for (int j = 0; j < MaxObject; ++j)
	{
		Array[i][j] = j;
	}
}

for (int i = 0; i < MaxObject; ++i)
	cout << Array[Enemy][i] << endl;




return 0;
}

*/



#pragma endregion

#pragma region ** ContainerMap v0.3
/*
// ** ContainerMap v0.3
#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

struct Vector3
{
	float x, y, z;

	Vector3() : x(0.0f), y(0.0f), z(0.0f) {};

	Vector3(const float& _x, const float& _y)
		: x(_x), y(_y), z(0.0f) {};

	Vector3(const float& _x, const float& _y, const float& _z)
		: x(_x), y(_y), z(_z) {};
};

struct Trasnform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
};

struct Object
{
	Trasnform Info;

	Object() {};

	Object(const Trasnform& _Info) : Info(_Info) {};
};

struct Player : public Object
{

	Player() {};

	Player(const Trasnform& _Info) : Object(_Info) {};
};

// ** <key 값, Value 값>
map<string, list<Object*>> Objects;



void Initialize();
void AddObject(string _Key, Object* _Object);


int main(void)
{
	//Initialize();
	Trasnform Info;

	Info.Position.x = 10;
	Info.Position.y = 20;
	Info.Position.z = 30;

	AddObject("Player", new Player(Info));



	//cout << Objects["Player"]->Info.Position.x << endl;
	//cout << Objects["Player"]->Info.Position.y << endl;
	//cout << Objects["Player"]->Info.Position.z << endl;


	return 0;
}

void Initialize()
{
	Trasnform Info;

	Info.Position.x = 10;
	Info.Position.y = 20;
	Info.Position.z = 30;

	//Objects["Player"] = new Player(Info);
}


void AddObject(string _Key, Object* _Object)
{
	// ** find: 키값 검색
	map<string, list<Object*>>::iterator iter = Objects.find(_Key);

	// ** insert: 입력, make_pair: 값 덮어쓰기(Key 값, Value 값)
	if (iter == Objects.end())
	{
		list<Object*> Temp;
		Temp.push_back(_Object);
		Objects.insert(make_pair(_Key, Temp));
	}

	else
		iter->second.push_back(_Object);
}


*/
#pragma endregion
