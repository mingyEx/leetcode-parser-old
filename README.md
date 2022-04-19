# lc_debug

### todo: 

- [x] 测试框架集成(debug print不方便，暂时放弃)

- [ ] 理清常用板子的接口

- [ ] 给pprint添加matrix打印时自动分行的功能。

- [ ] 正确处理 `["a==b","b!=c","c==a"]` 来自[这里](https://leetcode-cn.com/problems/satisfiability-of-equality-equations/submissions/)

- [ ] 支持多叉树的打印调试，例子:[1](https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/) [2](https://leetcode-cn.com/problems/smallest-missing-genetic-value-in-each-subtree/) [3](https://leetcode-cn.com/problems/longest-path-with-different-adjacent-characters/)
- [ ] 实现类似 [caide](https://github.com/slycelote/caide)的功能。

- [ ] 支持[模拟类问题](https://leetcode.com/problems/dinner-plate-stacks/)的调试

- [ ] 哪天需要支持17的东西(variant等)了就看看[这个] (https://github.com/tcbrindle/pretty_print.hpp#optionals)

- [ ] 常用数据结构，板子，宏的收集和接口说明。

- [x] 查看这个[dbg宏](https://github.com/sharkdp/dbg-macro )与pprint的重合度，以及它额外提供的功能是否必须 .

额外功能不需要，行号和类型名字无用，过长的容器会被省略后面的，也是废物，抄一下色彩的部分就好。

## Thanks
[pprint](https://louisdx.github.io/cxx-prettyprint/)

[leetcode-helper](https://github.com/luckystone60/leetcode-helper)

[caide](https://github.com/slycelote/caide/issues/50)
