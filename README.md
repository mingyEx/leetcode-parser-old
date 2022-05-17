
### todo: 

- [x] 测试框架集成，保证在为新的`testcase`修改代码时不会影响旧的`testcase`,就像`codewars`那样

- [ ] 正确处理 `["a==b","b!=c","c==a"]` 来自[这里](https://leetcode-cn.com/problems/satisfiability-of-equality-equations/submissions/)

- [ ] 支持多叉树的打印调试，例子:[1](https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/) [2](https://leetcode-cn.com/problems/smallest-missing-genetic-value-in-each-subtree/) [3](https://leetcode-cn.com/problems/longest-path-with-different-adjacent-characters/)

- [ ] 实现类似 [caide](https://github.com/slycelote/caide)里 ______ 的功能。

- [ ] 支持[模拟类问题](https://leetcode.com/problems/dinner-plate-stacks/)的[调试](https://github.com/slycelote/caide/issues/50)

- [ ] 整理常用算法和宏的接口说明。

- [ ] 从[dbg](https://github.com/sharkdp/dbg-macro )中添加彩色输出功能。  

所提供的`在表达式位置包裹dbg`功能无法在提交代码时快速注释，故略去。  

其他功能如行号和类型名字无用，过长的容器只会显示前几个，不符合debug需要。

## appendix
lintcode用户需将数组的{}替换为[],树的`#`替换为`null`

## Thanks
[pprint](https://louisdx.github.io/cxx-prettyprint/)

[leetcode-helper](https://github.com/luckystone60/leetcode-helper)

[caide](https://github.com/slycelote/caide/issues/50)
