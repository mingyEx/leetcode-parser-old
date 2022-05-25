
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


int main()
{
  std::ifstream file("in.txt");
  std::string input1;
  std::getline(file, input1);
  auto t1 = Vec<int>(input1);
  cout << Solution().func_name() << endl;
}
