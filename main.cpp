#define _CRT_SECURE_NO_WARNINGS
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
std::ifstream file("in.txt");
using namespace std;
using namespace lc;

//multiple test cases
auto get(ifstream& file)
{
  std::string input1;
  std::getline(file, input1);
  Tree* t1=new Tree(input1); //change it by need
  return t1;
}
//按需复制多次
TEST(TmpAddTest, c1)
{
  auto t1 = get(file);
  t1->print();
  ASSERT_EQ(1, 2 - 1);
  EXPECT_TRUE(true);
}
//按需复制多次
TEST(TmpAddTest, c2)
{
  auto t1 = get(file);
  t1->print();
  ASSERT_EQ(1, 2 - 1);
  EXPECT_TRUE(true);
}
//按需复制多次
TEST(TmpAddTest, c3)
{
  auto t1 = get(file);
  t1->print();
  ASSERT_EQ(1, 2 - 1);
  EXPECT_TRUE(true);
}
int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

//single testcase
//int main()
//{
//  std::ifstream file("in.txt");
//  std::string input1;
//  std::getline(file, input1);
//  auto t1 =Vec<int>(input1);
//  cout << Solution().func_name() << endl;
//}
