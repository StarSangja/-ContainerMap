// ** ContainerMap v0.2
#include <iostream>
#include <string>
#include <map>

using namespace std;

// ** <key 값, Value 값>
map<int, int> Number;

void AddData(int _Key, int _Value);


int main(void)
{

	Number[0] = 0;
	Number[1] = 10;
	Number[2] = 20;
	Number.insert(make_pair(3, 30));
	//Number[3] = 30;

	Number[1] = 100;

	Number.insert(make_pair(4, 40));
	

	AddData(2, 200);

	/*
	* for (int i = 0; i < 5; ++i)
	{
		cout << Number[i] << endl;
	}

	*/
	

	for (map<int, int>::iterator iter = Number.begin();
	iter != Number.end(); ++iter)
	cout << iter->second << endl;

	return 0;
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

void AddData(int _Key, int _Value)
{
	// ** find: 키값 검색
	map<int, int>::iterator iter = Number.find(_Key);

	// ** insert: 입력, make_pair: 값 덮어쓰기(Key 값, Value 값)
	if (iter == Number.end())
		Number.insert(make_pair(_Key, _Value));

	else
		iter->second = _Value;
}
