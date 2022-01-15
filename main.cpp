//#define _CRT_SECURE_NO_WARNINGS
//#define _USE_MATH_DEFINES
//#define CATCH_CONFIG_MAIN  //so we don't need main
//#define PR(x) cout<<#x "="<<x<<"\n";

#include "pprint.h"
#include "lc.h"
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include <unordered_map>
#include<iostream>
#include<bitset>
#include<algorithm>
#include<fstream>
#include<numeric>
#include<queue>
#include<functional>
using namespace std;
using namespace lc;

#define biu
#define dout MyDebug(std::cout)
class MyDebug
{
	std::ostream& stream;
public:
	MyDebug(std::ostream& s) : stream(s) {}

#ifdef biu
	template<typename T>
	MyDebug& operator<<(T& item)
	{
		stream << item;
		return *this;
	}
#else
	template<typename T>
	MyDebug& operator<<(T&)	//卧槽，那个玩意是不是要往这里放一份的?
	{
		return *this;
	}
#endif
	MyDebug& operator<<(std::ostream& (*pf)(std::ostream&))
	{
		stream << pf;
		return *this;
	}
	template<typename R, typename P>
	MyDebug& operator<<(R& (*pf)(P&))	//<== 他是干嘛的
	{
		std::cout << "never called!";
		stream << pf;
		return *this;
	}
};

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair < int, int > ii;
#define all(c) c.begin(), c.end()

int main()
{
	std::ifstream file("file.txt");
	std::string temp;
	std::string temp2;
	std::getline(file, temp);
	//std::getline(file, temp2);
	auto t1 = CreateVector<int>(temp);
	//auto t2 = CreateMatrix<int>(temp2);
	cout << Solution().some_func(t1, 8);

	return 0;
}
