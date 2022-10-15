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
#include<xutility>
#include<queue>
#include<cassert>
#include<functional>
#include<cctype>
#include<iomanip>
#include<bit>
#include<tuple>
#include <random>
#include <algorithm>
#include<stack>
#include<array>
#include "pprint.h"
#include "lc.h"
#ifdef design
#include <boost/describe.hpp>
#include <boost/mp11.hpp>
#include <boost/json.hpp>
#include <boost/type_traits.hpp>
#include <boost/utility/string_view.hpp>
#endif
using namespace std;
using namespace lc;

#ifdef design
template<class C1, class C2, class R, class... A, std::size_t... I>
boost::json::value
call_impl_(C1& c1, R(C2::* pmf)(A...), boost::json::array const& args,
  std::index_sequence<I...>)
{
  return boost::json::value_from((c1.*pmf)(boost::json::value_to< boost::remove_cv_ref_t<A> >(args[I])...));
}

template<class C1, class C2, class R, class... A>
boost::json::value
call_impl(C1& c1, R(C2::* pmf)(A...), boost::json::array const& args)
{
  if (args.size() != sizeof...(A))
#ifdef func

template<typename T>set<typename T::value_type> to_set(T t) { return set(t.begin(), t.end()); }
template<typename T>vector<typename T::value_type> set_to(T input) { vector<typename T::value_type> output; std::copy(input.begin(), input.end(), std::back_inserter(output)); return output; }
vector<int> get_insect(vector<int>n1, vector<int> n2)
{
  vector<int> res; set_intersection(all(n1), all(n2), inserter(res, res.end())); return res;
}
template<typename T>auto clear(queue<T>& q) { std::queue<T>empty; std::swap(q, empty); }
vector<string> split(string s, string delimiter = " ") {
  std::stringstream stringStream(s);
  std::string line;
  vector<string> wordVector;
  while (std::getline(stringStream, line))
  {
    std::size_t prev = 0, pos;
    while ((pos = line.find_first_of(delimiter, prev)) != std::string::npos)
    {
      if (pos > prev)
        wordVector.push_back(line.substr(prev, pos - prev));
      prev = pos + 1;
    }
    if (prev < line.length())
      wordVector.push_back(line.substr(prev, std::string::npos));
  }
  return wordVector;
}
#endif

#define ice
#ifdef ice
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<vs> vss;
typedef pair<int, int > ipair;
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define sz(a) int((a).size())
#define tr(c, i) for (typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define pb push_back
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define loop(i,a,b) for (int i = a; i <= b; i++)
#define loop2(x, n,step) for(int x = 0; x < n; x+=step)
const int dx[4]{ 1,0,-1,0 }, dy[4]{ 0,1,0,-1 };
const double pi = acos(-1.0);//NOTES:pi 
const double eps = 1e-11;//NOTES:eps
template<class T> inline T lowbit(T n) { return (n ^ (n - 1)) & n; }  // 6(110)->2(10)
template<class T> inline int countbit(T n) { return (n == 0) ? 0 : (1 + countbit(n & (n - 1))); }//1 in binary represent

template<typename T> void UN(T& n) { sort(all(n)); n.erase(std::unique(n.begin(), n.end()), n.end()); }
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>; //小根堆.

//数学函数
template<class T> inline vector<pair<T, int>> factorize(T n)
{
  vector<pair<T, int> > R;
  for (T i = 2; n > 1;)
  {
    if (n % i == 0)
    {
      int C = 0;
      for (; n % i == 0; C++, n /= i);
      R.push_back(make_pair(i, C));
    }
    i++;
    if (i > n / i) i = n;
  }
  if (n > 1)
    R.push_back(make_pair(n, 1));
  return R;
}
template<class T> inline bool isPrimeNumber(T n)
{
  if (n <= 1)return false;
  for (T i = 2; i * i <= n; i++)if (n % i == 0) return false; return true;
}
//几何
template<class T> inline T sqr(T x) { return x * x; }//NOTES:sqr
double dist(double x1, double y1, double x2, double y2) { return sqrt(sqr(x1 - x2) + sqr(y1 - y2)); }//两点距离
template<class T> T cross(T x0, T y0, T x1, T y1, T x2, T y2)//x1y2-x2y1 叉积
{
  return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
}

//在左则1,否则-1.
int crossOper(double x0, double y0, double x1, double y1, double x2, double y2)
{
  double t = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
  if (fabs(t) <= eps) return 0;
  return (t < 0) ? -1 : 1;
}
//线段相交
bool isIntersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
  return crossOper(x1, y1, x2, y2, x3, y3) * crossOper(x1, y1, x2, y2, x4, y4) < 0 && crossOper(x3, y3, x4, y4, x1, y1) * crossOper(x3, y3, x4, y4, x2, y2) < 0;
}

//自定
#define D(x) cout << #x << " : " << x << endl;
#define ed cout << endl;
//#define  sw cout<<res<<endl<<l<<" "<<r<<endl<<endl; //滑动窗口debug用。
//#define rt  return res;
#endif

//\
#define D(x);
