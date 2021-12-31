一键开关穿插在代码里的打印符

```cpp

//#define NDEBUG
//https://stackoverflow.com/a/1389600/13792395
#ifdef NDEBUG
#define out std::cout
#else
#define out NullStream()
#endif
class NullStream {
public:
	NullStream() { }
	template<typename T> NullStream& operator<<(T const&) { return *this; }
};

int main()
{

	vector<int> sa{ 1,2,3,45 };
	out << sa<<"\n";
}
```

这里有一个更优化版本，暂时不知道他的template<<是干嘛的。
https://stackoverflow.com/a/1389813/13792395


更传统的做法是这样，好处是编译时候这些代码绝对不会出现。

```cpp
#ifdef DEBUG
#  define IFDBG(x) x
#else
#  define IFDBG(x)
#endif
```
IFDBG(cout << result << endl);
