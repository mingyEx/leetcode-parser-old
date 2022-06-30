#ifndef H_PRETTY_PRINT
#define H_PRETTY_PRINT
#include<iostream>
#include<vector>
#include<string>
#include<tuple>
#include<unordered_set>
#include<set>
#include<valarray>

namespace pretty_print
{
	namespace detail
	{
		template <typename T>
		struct has_const_iterator
		{
		private:
			template <typename U>
			static constexpr decltype(std::declval<U::const_iterator>(), bool()) test(int) { return true; }
			template <typename U>
			static constexpr bool test(...) { return false; }
		public:
			static const bool value = test<T>(1);
			using type = T;
		};
		template <typename T>
		struct has_begin_end
		{
		private:
			template <typename U>
			static constexpr decltype(std::declval<U>().begin(), bool()) f(int) { return true; }
			template <typename U>
			static constexpr bool f(...) { return false; }
			template <typename U>
			static constexpr decltype(std::declval<U>().end(), bool()) g(int) { return true; }
			template <typename U>
			static constexpr bool g(...) { return false; }

		public:
			static bool const beg_value = f<T>(2);
			static bool const end_value = g<T>(2);
		};
	}


	//觉得这些注释应该在其他地方
	//分隔定界符始终为“ , ”（逗号，空格）。
	//对和元组用圆括号（括号）括起来：(1, foo)。
	//集用大括号括起来{1, 5, 11}。
	//所有其他容器都放在方括号中：[1.4, -1.2, Inf, 88.6]。

	// 保存特定字符类型定界符的定界符值,在这里就是char,实际上也不会有其他的吧..
	template <typename TChar>
	struct delimiters_values
	{
		using char_type = TChar;
		const char_type* prefix;
		const char_type* delimiter;
		const char_type* postfix;
	};

	//对特定的容器和字符类型，定义其分隔符的值.		这个value里面有三个指针.
	template <typename T, typename TChar>
	struct delimiters
	{
		using type = delimiters_values<TChar>;
		static const type values;
	};

	//用来打印容器的仿函数，如果想要指定非默认的分隔符类型，可以在这里写. 
	//可以通过特化嵌套模板来自定义打印逻辑.
	template <typename T,
		typename TChar = char,
		typename TCharTraits = ::std::char_traits<TChar>,
		typename TDelimiters = delimiters<T, TChar>>

		struct print_container_helper	//打印的是print_container_helper本身，所以要看oeprator<<()
	{
		using delimiters_type = TDelimiters;
		using ostream_type = std::basic_ostream<TChar, TCharTraits>;

		template <typename U>
		struct printer
		{
			//这个负责打印容器里的东西，通过迭代器，至于分隔符待会单独看。
			static void print_body(const U& c, ostream_type& stream)
			{
				using std::begin;
				using std::end;

				auto it = begin(c);
				const auto the_end = end(c);	//why const? 因为end()是尾后迭代器?

				if (it != the_end)
				{
					while (true)
					{
						stream << *it;
						if (++it == the_end) break;
						if (delimiters_type::values.delimiter != nullptr)
							stream << delimiters_type::values.delimiter;
					}
				}
			}
		};

		print_container_helper(const T& container)
			: container_(container) {}

		inline void operator()(ostream_type& stream) const
		{
			if (delimiters_type::values.prefix != nullptr)
				stream << delimiters_type::values.prefix;
			printer<T>::print_body(container_, stream);

			if (delimiters_type::values.postfix != nullptr)
				stream << delimiters_type::values.postfix;
		}

	private:
		const T& container_;
	};


	//为pair的特化？
	template <
		typename T,
		typename TChar,
		typename TCharTraits,
		typename TDelimiters>
		template <typename T1, typename T2>

	//这里之所以写了两行template是因为这是一个特化的版本？哪有这么特化的啊
	//哦，下面指定了函数printer,有什么区别吗？我都不会写特化了...去看primer和cppref.
	//哦，这里是因为printer是print_container_helper struct 里面的 struct,所以外面那个要原封不动的把模板写出来，而里面则是
	//我们自己定义的，指定了部分参数pair的特化版本？	在哪里见过这种嵌套而写两层template的东西，想不起，找一找.
	//我已经想不起哪里这么说过了，也没法把它拆成自己认知中的基础语法，先挂起来吧
	//https://en.cppreference.com/w/cpp/language/member_template 继续吧！
	struct print_container_helper<T, TChar, TCharTraits, TDelimiters>::printer<std::pair<T1, T2>>	//默认值用上了. 这里是针对其中嵌套子模板printer 的特化.
	{
		using ostream_type = typename print_container_helper<T, TChar, TCharTraits, TDelimiters>::ostream_type;	//如果没有这个会如何呢? 会需要下面的都写很长？大概吧.

		static void print_body(const std::pair<T1, T2>& c, ostream_type& stream)	//相比于原来的，这个只打印元素和分隔符，外面的怎么办?
		{
			stream << c.first;
			if (print_container_helper<T, TChar, TCharTraits, TDelimiters>::delimiters_type::values.delimiter != nullptr)
				stream << print_container_helper<T, TChar, TCharTraits, TDelimiters>::delimiters_type::values.delimiter;
			stream << c.second;
		}
	};

	//为tuples的特化
	template <
		typename T,
		typename TChar,
		typename TCharTraits,
		typename TDelimiters>
		template <typename ...Args>

	struct print_container_helper<T, TChar, TCharTraits, TDelimiters>::printer<std::tuple<Args...>>
	{
		using ostream_type = typename print_container_helper<T, TChar, TCharTraits, TDelimiters>::ostream_type;
		using element_type = std::tuple<Args...>;

		template <std::size_t I> struct Int { };

		static void print_body(const element_type& c, ostream_type& stream)		//是重载
		{
			tuple_print(c, stream, Int<0>());
		}
		//3 or void
		static void tuple_print(const element_type&, ostream_type&, Int<sizeof...(Args)>) {}
		//1
		static void tuple_print(const element_type& c, ostream_type& stream,
			typename std::conditional<sizeof...(Args) != 0, Int<0>, std::nullptr_t>::type)
		{
			stream << std::get<0>(c);
			tuple_print(c, stream, Int<1>());
		}
		//2
		template <std::size_t N>
		static void tuple_print(const element_type& c, ostream_type& stream, Int<N>)
		{
			if (print_container_helper<T, TChar, TCharTraits, TDelimiters>::delimiters_type::values.delimiter != nullptr)
				stream << print_container_helper<T, TChar, TCharTraits, TDelimiters>::delimiters_type::values.delimiter;
			stream << std::get<N>(c);
			tuple_print(c, stream, Int<N + 1>());
		}
	};

	//把 print_container_helper 打印到确定的流, 调用了print_container_helper的operator()来把东西塞到stream里.
	template<typename T, typename TChar, typename TCharTraits, typename TDelimiters>
	inline std::basic_ostream<TChar, TCharTraits>& operator<<(
		std::basic_ostream<TChar, TCharTraits>& stream,
		const print_container_helper<T, TChar, TCharTraits, TDelimiters>& helper)
	{
		helper(stream);
		return stream;
	}

	//integral_constant: base class for the C++ type traits.如果第二个参数是true,则is_container包含value==true.
	// Basic is_container template;specialize to derive from std::true_type for all desired container types
	template <typename T>
	struct is_container : public std::integral_constant<bool,
		detail::has_const_iterator<T>::value&&
		detail::has_begin_end<T>::beg_value&&
		detail::has_begin_end<T>::end_value> { };

	template <typename T, std::size_t N>
	struct is_container<T[N]> : std::true_type { };	//原生数组

	//因为涉及到编码问题.所以把它设定为false. 但是注释之后就正常了，为什么
	/*template <std::size_t N>
	struct is_container<char[N]> : std::false_type { };
	*/


	/*	template <std::size_t N>
		struct is_container<wchar_t[N]> : std::false_type { };*/

	template <typename T>
	struct is_container<std::valarray<T>> : std::true_type { };		//https://stackoverflow.com/a/1602594/13792395 看起来没人用.

	template <typename T1, typename T2>
	struct is_container<std::pair<T1, T2>> : std::true_type { };
	template <typename ...Args>
	struct is_container<std::tuple<Args...>> : std::true_type { };

	// Default delimiters	一些特化,设定了关于char, wchar_t 的默认值。
	template <typename T> struct delimiters<T, char> { static const delimiters_values<char> values; };
	template <typename T> const delimiters_values<char> delimiters<T, char>::values = { "[", ", ", "]" };
	template <typename T> struct delimiters<T, wchar_t> { static const delimiters_values<wchar_t> values; };
	template <typename T> const delimiters_values<wchar_t> delimiters<T, wchar_t>::values = { L"[", L", ", L"]" };

	// Delimiters for (multi)set and unordered_(multi)set	
	//可以写成一个吗? 对char wchar_t和set都？定义一个泛型，is_set,没有这样的东西.
	template <typename T, typename TComp, typename TAllocator>
	struct delimiters< ::std::set<T, TComp, TAllocator>, char> { static const delimiters_values<char> values; };

	template <typename T, typename TComp, typename TAllocator>
	const delimiters_values<char> delimiters< ::std::set<T, TComp, TAllocator>, char>::values = { "{", ", ", "}" };

	template <typename T, typename TComp, typename TAllocator>
	struct delimiters< ::std::set<T, TComp, TAllocator>, wchar_t> { static const delimiters_values<wchar_t> values; };

	template <typename T, typename TComp, typename TAllocator>
	const delimiters_values<wchar_t> delimiters< ::std::set<T, TComp, TAllocator>, wchar_t>::values = { L"{", L", ", L"}" };

	template <typename T, typename TComp, typename TAllocator>
	struct delimiters< ::std::multiset<T, TComp, TAllocator>, char> { static const delimiters_values<char> values; };

	template <typename T, typename TComp, typename TAllocator>
	const delimiters_values<char> delimiters< ::std::multiset<T, TComp, TAllocator>, char>::values = { "{", ", ", "}" };

	template <typename T, typename TComp, typename TAllocator>
	struct delimiters< ::std::multiset<T, TComp, TAllocator>, wchar_t> { static const delimiters_values<wchar_t> values; };

	template <typename T, typename TComp, typename TAllocator>
	const delimiters_values<wchar_t> delimiters< ::std::multiset<T, TComp, TAllocator>, wchar_t>::values = { L"{", L", ", L"}" };

	template <typename T, typename THash, typename TEqual, typename TAllocator>
	struct delimiters< ::std::unordered_set<T, THash, TEqual, TAllocator>, char> { static const delimiters_values<char> values; };

	template <typename T, typename THash, typename TEqual, typename TAllocator>
	const delimiters_values<char> delimiters< ::std::unordered_set<T, THash, TEqual, TAllocator>, char>::values = { "{", ", ", "}" };

	template <typename T, typename THash, typename TEqual, typename TAllocator>
	struct delimiters< ::std::unordered_set<T, THash, TEqual, TAllocator>, wchar_t> { static const delimiters_values<wchar_t> values; };

	template <typename T, typename THash, typename TEqual, typename TAllocator>
	const delimiters_values<wchar_t> delimiters< ::std::unordered_set<T, THash, TEqual, TAllocator>, wchar_t>::values = { L"{", L", ", L"}" };

	template <typename T, typename THash, typename TEqual, typename TAllocator>
	struct delimiters< ::std::unordered_multiset<T, THash, TEqual, TAllocator>, char> { static const delimiters_values<char> values; };

	template <typename T, typename THash, typename TEqual, typename TAllocator>
	const delimiters_values<char> delimiters< ::std::unordered_multiset<T, THash, TEqual, TAllocator>, char>::values = { "{", ", ", "}" };

	template <typename T, typename THash, typename TEqual, typename TAllocator>
	struct delimiters< ::std::unordered_multiset<T, THash, TEqual, TAllocator>, wchar_t> { static const delimiters_values<wchar_t> values; };

	template <typename T, typename THash, typename TEqual, typename TAllocator>
	const delimiters_values<wchar_t> delimiters< ::std::unordered_multiset<T, THash, TEqual, TAllocator>, wchar_t>::values = { L"{", L", ", L"}" };


	// Delimiters for pair and tuple
	template <typename T1, typename T2> struct delimiters<std::pair<T1, T2>, char> { static const delimiters_values<char> values; };
	template <typename T1, typename T2> const delimiters_values<char> delimiters<std::pair<T1, T2>, char>::values = { "(", ", ", ")" };
	template <typename T1, typename T2> struct delimiters< ::std::pair<T1, T2>, wchar_t> { static const delimiters_values<wchar_t> values; };
	template <typename T1, typename T2> const delimiters_values<wchar_t> delimiters< ::std::pair<T1, T2>, wchar_t>::values = { L"(", L", ", L")" };

	template <typename ...Args> struct delimiters<std::tuple<Args...>, char> { static const delimiters_values<char> values; };
	template <typename ...Args> const delimiters_values<char> delimiters<std::tuple<Args...>, char>::values = { "(", ", ", ")" };
	template <typename ...Args> struct delimiters< ::std::tuple<Args...>, wchar_t> { static const delimiters_values<wchar_t> values; };
	template <typename ...Args> const delimiters_values<wchar_t> delimiters< ::std::tuple<Args...>, wchar_t>::values = { L"(", L", ", L")" };

	// Type-erasing helper class for easy use of custom delimiters.
	// Requires TCharTraits = std::char_traits<TChar> and TChar = char or wchar_t, and MyDelims needs to be defined for TChar.
	// Usage: "cout << pretty_print::custom_delims<MyDelims>(x)".

	struct custom_delims_base
	{
		virtual ~custom_delims_base() { }
		virtual std::ostream& stream(::std::ostream&) = 0;
		virtual std::wostream& stream(::std::wostream&) = 0;
	};

	template <typename T, typename Delims>
	struct custom_delims_wrapper : custom_delims_base
	{
		custom_delims_wrapper(const T& t_) : t(t_) { }

		std::ostream& stream(std::ostream& s)
		{
			return s << print_container_helper<T, char, std::char_traits<char>, Delims>(t);
		}

		std::wostream& stream(std::wostream& s)
		{
			return s << print_container_helper<T, wchar_t, std::char_traits<wchar_t>, Delims>(t);
		}

	private:
		const T& t;
	};

	template <typename Delims>
	struct custom_delims
	{
		template <typename Container>
		custom_delims(const Container& c) : base(new custom_delims_wrapper<Container, Delims>(c)) { }

		std::unique_ptr<custom_delims_base> base;
	};

	template <typename TChar, typename TCharTraits, typename Delims>
	inline std::basic_ostream<TChar, TCharTraits>& operator<<(std::basic_ostream<TChar, TCharTraits>& s, const custom_delims<Delims>& p)
	{
		return p.base->stream(s);
	}


	// A wrapper for a C-style array given as pointer-plus-size.
	// Usage: std::cout << pretty_print_array(arr, n) << std::endl;
	template<typename T>
	struct array_wrapper_n
	{
		typedef const T* const_iterator;
		typedef T value_type;

		array_wrapper_n(const T* const a, size_t n) : _array(a), _n(n) { }
		inline const_iterator begin() const { return _array; }
		inline const_iterator end() const { return _array + _n; }

	private:
		const T* const _array;
		size_t _n;
	};


	// A wrapper for hash-table based containers that offer local iterators to each bucket.
	// Usage: std::cout << bucket_print(m, 4) << std::endl;  (Prints bucket 5 of container m.)
	template <typename T>
	struct bucket_print_wrapper
	{
		typedef typename T::const_local_iterator const_iterator;
		typedef typename T::size_type size_type;

		const_iterator begin() const
		{
			return m_map.cbegin(n);
		}

		const_iterator end() const
		{
			return m_map.cend(n);
		}

		bucket_print_wrapper(const T& m, size_type bucket) : m_map(m), n(bucket) { }

	private:
		const T& m_map;
		const size_type n;
	};
}   // namespace pretty_print


// Global accessor functions for the convenience wrappers

template<typename T>
inline pretty_print::array_wrapper_n<T> pretty_print_array(const T* const a, size_t n)
{
	return pretty_print::array_wrapper_n<T>(a, n);
}

template <typename T> pretty_print::bucket_print_wrapper<T>
	bucket_print(const T& m, typename T::size_type n)
	{
		return pretty_print::bucket_print_wrapper<T>(m, n);
	}

	// Main magic entry point: An overload snuck into namespace std.
	// Can we do better?
	namespace std
	{
		// Prints a container to the stream using default delimiters
		template<typename T, typename TChar, typename TCharTraits>
		inline typename std::enable_if_t< ::pretty_print::is_container<T>::value, basic_ostream<TChar, TCharTraits>&>
			//enable_if_t 提供第二个参数作为类型，只有一个则为void,否则无此函数
			operator<<(basic_ostream<TChar, TCharTraits>& stream, const T& container)
		{
			return stream << ::pretty_print::print_container_helper<T, TChar, TCharTraits>(container);
		}
	}
#endif  // H_PRETTY_PRINT
