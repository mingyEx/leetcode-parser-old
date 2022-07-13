### intent 
  0.提供等同于leetcode会员的自动补全与调试器功能。  
  1.网速较差的情况下，本地debug比online快  
  2.利用IDE更全面的调试功能，如条件断点，调用栈(对于设计类问题)等。  
  3.对于模拟类问题，本工具只用于查找`运行时错误`，`逻辑错误`要靠观察输出来排错，比如[900. RLE 迭代器](https://leetcode.cn/submissions/detail/332739590/)的`deleted = cur;`位置太低，`if (it == cnt.end())return -1;`导致提前退出的话，状态deleted的值没有得到及时更新。


### todo
- [ ] 使用 [`__func__`](https://stackoverflow.com/a/4384825/13792395) 来查看模拟类问题的调用栈。
- [ ] 使用宏对任意函数打印所有parameters ，以便于在弹出的窗口中debug时不需要看input，但是[这个](https://stackoverflow.com/a/24956733/13792395)call似乎只能套在`Solution().call(func,t1,t2,3`里,不便于开关(虽然不影响提交)，~~难得找到的写`&&` `...`的机会~~

- [ ] 使用全局变量 `recur_depth`来查看递归深度。 
- [ ] 正确处理带标点符号的string，如 `["a==b","b!=c","c==a"]` 来自[这里](https://leetcode-cn.com/problems/satisfiability-of-equality-equations/)

- [ ] 正确处理带空格的string，如 `["Hello userTwooo","Hi userThree","Wonderful day Alice","Nice day userThree"]` 来自[这里](https://leetcode.cn/contest/biweekly-contest-79/problems/sender-with-largest-word-count/)

- [ ] 正确处理符号如 `[[">>v","v^<","<><"]]` ，来自[ 2. 信物传送 ](https://leetcode.cn/contest/season/2022-spring/problems/6UEx57/)

- [ ] 正确处理包含不同类型的二维数组如 `[[], ["leetcode"], [4], ["practice"], [3], [8], [10], [2], [6]]` ，来自 [ 6093. 设计一个文本编辑器 ](https://leetcode.cn/contest/weekly-contest-296/problems/design-a-text-editor/)

- [ ] 支持多叉树的打印调试，例子:[1](https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/) [2](https://leetcode-cn.com/problems/smallest-missing-genetic-value-in-each-subtree/) [3](https://leetcode-cn.com/problems/longest-path-with-different-adjacent-characters/)

- [ ] 实现类似 [caide](https://github.com/slycelote/caide)里 ______ 的功能。

- [x] 支持[模拟类问题](https://leetcode.com/problems/dinner-plate-stacks/)的调试。   
      参数为单值类型: [__1993. 树上的操作__](https://leetcode.cn/problems/operations-on-tree/)  
      参数可能为空: [__1172. 餐盘栈__](https://leetcode.cn/problems/dinner-plate-stacks/)  
  
  
- [ ] 整理常用算法和宏的接口说明。

- [ ] 从[dbg](https://github.com/sharkdp/dbg-macro )中添加彩色输出功能。(行号有用吗?)。

## appendix
`lintcode`用户需将数组的`{}`替换为`[]`,树的`#`替换为`null`  
gcc/clang用户暂时先使用pprint的[原始版本](https://github.com/louisdx/cxx-prettyprint/blob/master/prettyprint.hpp),以后吃饱了撑的再搞懂为啥我修改了的(区别于正常的那个)版本不能用。
### 待了解
[gdb调试](https://stackoverflow.com/a/42896336/13792395)  
[gccfilter](http://www.mixtion.org/gccfilter/) 解决蛋逼的报错。  
[quickfix](https://stackoverflow.com/questions/1747091/how-do-you-use-vims-quickfix-feature) 一个Error list 类似物，可以用在屎vim里,这样就能在买不起clion的情况下在linux下感受有IDE的幻觉。  

## Thanks
[pprint](https://louisdx.github.io/cxx-prettyprint/)

[leetcode-helper](https://github.com/luckystone60/leetcode-helper)

[caide](https://github.com/slycelote/caide/issues/50)

[boost.Describe](https://www.boost.org/doc/libs/develop/libs/describe/doc/html/describe.html#example_json_rpc)
