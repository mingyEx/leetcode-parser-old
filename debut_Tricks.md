https://stackoverflow.com/a/29326784/13792395
这样也可以输出
```cpp
template<typename ...Args>
void log(Args && ...args)
{
	(std::cout << ... << args);
}
	
int main()
{
	log("Hello", "brave","new","world!\n");
	log("1", 2,std::string("3"),4.0,'\n');
}
```
但是我有了pprint,谁tm还想加括号。


以下内容来自此帖子
https://codeforces.com/blog/entry/79446
```cpp
using Str = string;
template <class T> using Vec = vector<T>;
template <class K, class V> using UM = unordered_map<K, V>;
```

可以把输入塞进单文件里，用ifstream读取，这样就不用自己一直复制字符串了，也不用想什么test框架的宏怎么写。

这次整理好，加好大标题，整理的意义是为了以后累的时候也能快速找到。

```cpp
#define LOG(...)  cerr << "[ "#__VA_ARGS__" ] = "; log(__VA_ARGS__) << '\n'
```

能输出container名字吗? 我觉得不能。。


https://codeforces.com/contest/1367/submission/85413433

```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
template <class ...As> auto &read(As &...as) { return (cin >> ... >> as); }
template <class T> auto &operator>>(istream &is, vector<T> &xs) {
    for (auto &x : xs) is >> x;
    return is;
}
 
#define READ(...)             __VA_ARGS__; read(__VA_ARGS__)
#define READ_CTOR(name, ...)  name(__VA_ARGS__); cin >> name
 
auto main() -> int {
    int READ(t);
    while (t--) {
        int READ(n);
        vector<int> READ_CTOR(xs, n);
 
        cerr << "[ n ] = " << n << '\n';
 
        int odd = 0, even = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == xs[i] % 2) continue;
            (i % 2 ? odd : even) += 1;
        }
 
        cout << (odd == even ? odd : -1) << '\n';
    }
}
```

我们lc玩家不需要这个。

### 仅在调试模式下运行调试代码

```cpp
#ifdef DEBUG
  cerr << "a = " << a << " b = " << b << '\n'
#endif // DEBUG
```
太傻逼了，我才不用。

### 打印所有变量

```cpp
#define LOG(...)  cout << "[ "#__VA_ARGS__" ] = "; log(__VA_ARGS__) << '\n'
```

我有pprint,不需要这玩意。

```cpp

template <class ...Args>
auto& log(const Args &...args) {
	return ((cerr << " " << args), ...) << '\n';
}

#define LOG(...)  cerr << "[ "#__VA_ARGS__" ] = "; log(__VA_ARGS__) << '\n'

int main() {
	int a = 10;
	int b=10;
	LOG(a, b, a + b);
	// prints: [ a, b, a + b ] = 2 2 4

	cout << a + b << '\n';
}
```
同理，不需要，虽然这个变量名挺好的，nameof做不到。

### auto

```cpp
for (auto &row : table) 
	```
可能会有临时对象(的拷贝？) 为了避免这个，要用通用引用

```cpp
// works just fine: no copies, 
//   reference if regular object
//   value if temporary one
for (auto &&row : table)
```
自己写简单的例子测试，结果&和&&是一样的。

这里提到了用法：
```cpp
vector<pair<int, int>> some_events = ...;
sort(some_events.begin(), some_events.end(), [&](auto &&lhs, auto &&rhs) {
  // compare two pair<int, int> here
});

#define BY_FUNC(func) [&](auto &&lhs, auto &&rhs) { \
  return func(lhs) < func(rhs);                     \
}
```
上述很垃圾，正是用法
```cpp
#define ALL(xs) begin(xs), end(xs)

#define BY(...) [&](auto &&lhs, auto &&rhs) { \
  auto predicate = [&](auto &&x) {            \
    return __VA_ARGS__;                       \
  };                                          \
  return predicate(lhs) < predicate(rhs);     \
}

sort(ALL(pairs), BY(x.second));

// expands to:

sort(pairs.begin(), pairs.end(), [&](auto &&lhs, auto &&rhs) {
  auto predicate = [&](auto &&x) {
    return x.second;
  };
  return predicate(lhs) < predicate(rhs);
});
```

### dbg 宏

太麻烦了，放弃。
