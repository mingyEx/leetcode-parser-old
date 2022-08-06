
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
#include<iomanip>
#include<variant>
#include<cassert>
#include<memory>
#include<typeinfo>
#include <gtest/gtest.h>
#include "pprint.h"
#include "lc.h"
#include"So.h"
using namespace std;
using namespace lc;


auto strToChar(vector<vector<string>> t1)
{
  vector<vector<char>> t;
  for (auto i : t1)
  {
    t.push_back(vector<char>());
    for (auto j : i)
      t.back().push_back(j[0]);
  }
  return t;
}

int main()
{
  std::ifstream file("in.txt");
  std::string input1;
  std::getline(file, input1);
  auto t1 = Vec<int>(input1);
  cout << Solution().func_name() << endl;
  
  //对于模拟类问题
  vector<int> init{ -1,0,0,1,1,2,2 };
  Solution obj(init);
  for (int i = 0; i < t1.size(); ++i)
  {
    std::string sa = t1[i];
    std::vector<int> sb = t2[i];
    boost::json::value sc = boost::json::value_from(sb);
    std::cout << call(obj, sa, sc) << std::endl;
  }
}
