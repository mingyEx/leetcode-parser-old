# lc_debug

### todo: 

- [x] 测试框架集成(debug print不方便，暂时放弃)

- [ ] 理清常用板子的接口

- [ ] 给pprint添加matrix打印时自动分行的功能。

- [ ] 实现类似 [caide](https://github.com/slycelote/caide)的功能。

- [ ] 支持[模拟类问题](https://leetcode.com/problems/dinner-plate-stacks/)的调试

- [ ] CreateTree()是以输入字符串作为层序遍历结果来构建Tree的，[652. 寻找重复的子树](https://leetcode-cn.com/classic/problems/find-duplicate-subtrees/description/)的例1显示 `不同的树其层序遍历结果可能相同` 所以根据lc的字符串来本地构建Tree有待改进，比如生成所有可能的tree给玩家自行挑选。

- [ ]哪天需要支持17的东西(variant等)了就看看[这个] (https://github.com/tcbrindle/pretty_print.hpp#optionals)
- [ ] 常用数据结构，板子，宏的收集和接口说明。
- [ ] 查看这个[dbg宏](https://github.com/sharkdp/dbg-macro )与pprint的重合度，以及它额外提供的功能是否必须 .

## Thanks
[pprint](https://louisdx.github.io/cxx-prettyprint/)

[leetcode-helper](https://github.com/luckystone60/leetcode-helper)

[caide](https://github.com/slycelote/caide/issues/50)
