#define spice
#ifdef spice
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
#define all(c) c.begin(), c.end()
const int dx[4]{ 1,0,-1,0 }, dy[4]{ 0,1,0,-1 };
#define sz(a) int((a).size())
#define pb push_back
template<typename T> void un(T& n) { sort(all(n)); n.erase(std::unique(n.begin(), n.end()), n.end()); }
template<typename T>set<typename T::value_type> to_set(T t) { return set(t.begin(), t.end()); }
template<typename T>vector<typename T::value_type> set_to(T input) { vector<typename T::value_type> output; std::copy(input.begin(), input.end(), std::back_inserter(output)); return output; }
vector<int> get_insect(vector<int>n1, vector<int> n2) { vector<int> res; set_intersection(all(n1), all(n2), inserter(res, res.end())); return res; }
template<typename T>auto clear(queue<T>& q) { std::queue<T>empty; std::swap(q, empty); }
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#define dbg(x) cout << #x << " is " << x << endl;
#define ed cout << endl;
//#define  sw cout<<res<<endl<<l<<" "<<r<<endl<<endl; //滑动窗口debug用。
//#define rt  return res;
template<class C1, class C2, class R, class... A, std::size_t... I>
boost::json::value
call_impl_(C1& c1, R(C2::* pmf)(A...), boost::json::array const& args,
  std::index_sequence<I...>)
{
  return boost::json::value_from(
    (c1.*pmf)(
      boost::json::value_to< boost::remove_cv_ref_t<A> >(args[I])...));
}

template<class C1, class C2, class R, class... A>
boost::json::value
call_impl(C1& c1, R(C2::* pmf)(A...), boost::json::array const& args)
{
  if (args.size() != sizeof...(A))
  {
    throw std::invalid_argument("Invalid number of arguments");
  }

  return call_impl_(c1, pmf, args, std::index_sequence_for<A...>());
}
template<class C>
boost::json::value
call(C& c, boost::string_view method, boost::json::value const& args)
{
  using Fd = boost::describe::describe_members<C,
    boost::describe::mod_public | boost::describe::mod_function>;
  bool found = false;
  boost::json::value result;  //怎么把它转换成bool int string等？
  boost::mp11::mp_for_each<Fd>([&](auto D) {
    if (!found && method == D.name)
    {
      result = call_impl(c, D.pointer, args.as_array());
      found = true;
    }
    });
  if (!found)
  {
    throw std::invalid_argument("Invalid method name");
  }
  return result;
}
#endif


class Solution
{
  //...
    BOOST_DESCRIBE_CLASS(Solution, (), (member_func1, member_func2, member_func3), (), ());//Comment this line when submitting code
    //参数依次为:类名，(基类1，基类2..基类n),(public成员函数与成员变量，以书写顺序)，(同前，Protected),(同前,private))
