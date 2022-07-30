### Description

Provides autocompletion and debugger features for leetcode beginners 

### Feature
todo...

### Examples
todo...

### Todo

grid类问题，通过自定义数据结构的配置文件，用IDE自带的子窗口来显示一个二维网格(如果做不到就搞一个插件)，跟着调试器显示每一步值的变化.  
一些可能用得上的链接:  
[x-jun](https://www.cnblogs.com/X-Jun/p/8040916.html) [vczh](http://www.cppblog.com/vczh/archive/2013/03/21/198665.html)

#### Support for more complex input parameter types

- [ ] string with punctuation，like `["a==b","b!=c","c==a"]`   
from [990. Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations/)
- [ ] string with spaces，like `["Hello userTwooo","Hi userThree","Wonderful day Alice","Nice day userThree"]`   
from [2284. Sender With Largest Word Count](https://leetcode.com/problems/sender-with-largest-word-count/)
- [ ] symbols such as `[[">>v","v^<","<><"]]`   
from [2. 信物传送 ](https://leetcode.cn/contest/season/2022-spring/problems/6UEx57/)
- [ ] 2D arrays containing different types such as `[[], ["leetcode"], [4], ["practice"], [3], [8], [10], [2], [6]]`   
from  [2296. Design a Text Editor](https://leetcode.com/problems/design-a-text-editor/)

#### print more data structures
- [ ] n-ary-tree  
example:  
[559. Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/)    
[2003. Smallest Missing Genetic Value in Each Subtree](https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/)   
[2246. Longest Path With Different Adjacent Characters](https://leetcode.com/problems/longest-path-with-different-adjacent-characters/)  
  
## appendix
`lintcode` users need to replace `{}` with `[]` and `#` with `null`
gcc/clang users should use pprint's [original version](https://github.com/louisdx/cxx-prettyprint/blob/master/prettyprint.hpp)

## Thanks
[pprint](https://louisdx.github.io/cxx-prettyprint/)  
[leetcode-helper](https://github.com/luckystone60/leetcode-helper)  
[caide](https://github.com/slycelote/caide/issues/50)  
[boost.Describe](https://www.boost.org/doc/libs/develop/libs/describe/doc/html/describe.html#example_json_rpc)
