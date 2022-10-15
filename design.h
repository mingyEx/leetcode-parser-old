//for https://leetcode.com/tag/design/ questions
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include <boost/describe.hpp>
#include <boost/mp11.hpp>
#include <boost/json.hpp>
#include <boost/type_traits.hpp>
#include <boost/utility/string_view.hpp>
using namespace std;
using namespace boost::json;

#define design

#ifdef design
// C1:class name
// C2:pointer to member function
// R:return type of member function
// A: member function parameter pack
// I: Parameter pack expansion
template<class C1, class C2, class R, class... A, std::size_t... I>
boost::json::value
call_impl_(
  C1& c1, R(C2::* pmf)(A...), boost::json::array const& args,
  std::index_sequence<I...>)
{
  if constexpr (std::is_same_v<R, void>)
  {
    (c1.*pmf)(boost::json::value_to<boost::remove_cv_ref_t<A>>(args[I])...);  //void func call
    return boost::json::value{};
  }
  else
    return boost::json::value_from((c1.*pmf)(boost::json::value_to< boost::remove_cv_ref_t<A> >(args[I])...));
}
// C1: class name
// C2: pointer to member function
// R : return type of member function
// A : member function parameter pack
// args: member function args
template<class C1, class C2, class R, class... A>
boost::json::value
call_impl(
  C1& c1, R(C2::* pmf)(A...), boost::json::array const& args)
{
  if (args.size() != sizeof...(A))
    throw std::invalid_argument("Invalid number of arguments");
  return call_impl_(c1, pmf, args, std::index_sequence_for<A...>());
}
// c:class name
// method: member function name
// args: member function args
template<class C>
boost::json::value call(C& c, boost::string_view method,
  boost::json::value const& args = boost::json::array{})
{
  using Fd = boost::describe::describe_members<C,
    boost::describe::mod_public | boost::describe::mod_function>;
  bool found = false;
  boost::json::value result;
  boost::mp11::mp_for_each<Fd>([&](auto D) {
    if (!found && method == D.name)
    {
      result = call_impl(c, D.pointer, args.as_array());
      found = true;
    }
    });
  return found ? result
    : throw std::invalid_argument("Invalid method name");
}
//usage:    BOOST_DESCRIBE_CLASS(class name, (Inherited class name), (member_func1, member_func2, member_func3), (), ());
#endif 

class StackOfPlates {
  using Stack = std::stack<int>;
  std::vector<Stack> store;
  size_t             capacity;

public:
  StackOfPlates(size_t cap) { capacity = cap; }

  void push(int val) {
    if (capacity == 0)
      return;
    if (store.empty() || store.back().size() == capacity)
      store.emplace_back();
    store.back().push(val);
    return ;
  }

  int pop() {
    if (capacity == 0 || store.empty())
      return -1;
    int res = store.back().top();
    store.back().pop();
    if (store.back().empty())
      store.pop_back();
    return res;
  }

  int popAtStack(size_t index) {
    if (capacity == 0 || index >= store.size() || store.at(index).empty())
      return -1;
    int res = store.at(index).top();
    store.at(index).pop();
    if (store.at(index).empty()) {
      store.erase(store.begin() + index);
    }
    return res;
  }
  BOOST_DESCRIBE_CLASS(StackOfPlates, (), (push, pop, popAtStack), (), ())
};

//int main()
//{
//  vector<std::string> t1{ "push", "push", "popAtStack", "pop", "pop" };
//  vector<vector<int>> t2{ { 1},{2},{1},{},{} };
//  StackOfPlates obj(1);
//  for (int i = 0; i < t1.size(); ++i)
//  {
//    std::string method = t1[i];
//    std::vector<int> args = t2[i];
//    boost::json::value sc = boost::json::value_from(args);
//    std::cout << call(obj, method, sc) << std::endl;
//  }
//  return 0;
//}
