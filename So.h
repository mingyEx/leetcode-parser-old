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
#include<cassert>
#include<functional>
#include<cctype>
#include<iomanip>
#include<tuple>
#include <random>
#include<stack>
using namespace std;
using namespace lc;
#define spice
#ifdef spice
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
#define all(c) c.begin(), c.end()
//#define mp make_pair
//#define bg(x) begin(x)
//#define rall(x) x.rbegin(), x.rend() 
//#define lb lower_bound
//#define ub upper_bound
//#define each(a,x) for (auto& a: x)
const int dx[4]{ 1,0,-1,0 }, dy[4]{ 0,1,0,-1 }; // for every grid problem!!
#define sz(a) int((a).size())
#define pb push_back
template<typename T> void un(T& n) { sort(all(n)); n.erase(std::unique(n.begin(), n.end()), n.end()); }
template<typename T>set<typename T::value_type> to_set(T t) { return set(t.begin(), t.end()); }
template<typename T>vector<typename T::value_type> set_to(T input) { vector<typename T::value_type> output; std::copy(input.begin(), input.end(), std::back_inserter(output)); return output; }
vector<int> get_insect(vector<int>n1, vector<int> n2) { vector<int> res; set_intersection(all(n1), all(n2), inserter(res, res.end())); return res; }
#define dbg(x) cout << #x << " is " << x << endl;
//#define rt  return res;
#define ed cout << endl;
//#define  sw cout<<res<<endl<<l<<" "<<r<<endl<<endl; //滑动窗口debug用。
//#define dbg(x);
//位运算，整理专题再说 https://github.com/bqi343/USACO/blob/master/Implementations/content/contest/TemplateLong.cpp#L67
template<typename T>auto clear(queue<T>& q) { std::queue<T>empty; std::swap(q, empty); }
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#endif
class Solution {
public:
  
};
