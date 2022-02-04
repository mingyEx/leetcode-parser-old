//问个问题还他妈的被永久性塞了，一帮傻逼连人话都听不懂。
//https://stackoverflow.com/questions/70972238/how-to-correctly-create-a-2d-vector-from-this-input
//先挂着。
#include <iostream>
#include <iterator>
#include <string>
#include <regex>
#include<fstream>
#include<sstream>
using namespace std;
const int32_t TREE_NODE_BOUNDNARY = INT_MIN + 1;
template<typename T>
std::vector<T> CreateVector(const std::string inputStr)
{
	std::vector<T> ret;
	const std::string pattern = R"(([+|-]?\w*\.?\w+),?)";
	std::smatch match;

	std::string log = inputStr;
	while (regex_search(log, match, (std::regex)pattern)) {
		std::stringstream ss;
		std::string treeNull = match.str(0) == "null" ? std::to_string(TREE_NODE_BOUNDNARY) : match.str(1);
		ss << treeNull;
		T temp;
		ss >> temp;
		ret.push_back(temp);
		log = match.suffix();
	}
	if (ret.empty()) {
		std::cout << "CreateVector failed." << std::endl;
	}
	return ret;
}
template<typename T>
std::vector<std::vector<T>> CreateMatrix(const std::string inputStr)
{
	std::vector<std::vector<T>> ret;
	const std::string pattern = R"((\[[^\[\]]*\]))";
	std::smatch match;

	std::string log = inputStr;
	while (regex_search(log, match, (std::regex)pattern)) {
		std::string vec = match.str(1);
		ret.push_back(CreateVector<T>(vec));	//这里错误，进去的数据为空。
		log = match.suffix();
	}

	if (ret.empty()) {
		std::cout << "CreateVector failed." << std::endl;
	}
	return ret;
}
template<typename T>
void pprint(vector<T> in)
{
	for (auto i : in)
	{
		std::cout << i << " ";
	}
}
template<typename T>
void pprint(vector<vector<T>> in)
{
	for (auto i : in)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
}
int main()
{
	//std::ifstream file("file.txt");
	std::string temp{"[[\"#\", \".\", \"#\"]]"};
	std::string temp2{ "[[\"carls\",\"Spice\",\"sasas\"],[\"carls\",\"Spice\",\"sasas\"]] "};
	//std::getline(file, temp);
	//std::getline(file, temp2);
	std::cout << temp << " " << temp2 << std::endl;
	auto t1 = CreateMatrix<std::string>(temp2);	//正常
	auto t2 = CreateVector<std::string>(temp);	//fail in vector create
	//auto t2 = CreateMatrix<std::string>(temp);	//fail
	pprint(t1);
	return 0;
}
