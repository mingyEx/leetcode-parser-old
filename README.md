### Description

Provides `autocompletion` and `debugger` for leetcode beginners 

### Feature
1. Supported data types: `int`, `double`, `char`, `string` in the form of `array` or `two-dimensional array`  
2. Support for creating data structures: `array` or `two-dimensional array`,`tree`, `list`,  (you won't need graph)  
3. Support for printing custom data structures (like `list` and `tree` )and common containers to help you debug,like `vector`,`unordered_map`,`map`,`set`,etc.

### dependencies 
Does not require any third-party library

### Support for more complex input parameter types
###### [By modifying the regular expression](https://github.com/KargathEx/LC-parser/blob/main/lc.h#L55)

- [ ] string with punctuation，like `["a==b","b!=c","c==a"]`   
from [990. Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations/)
- [ ] string with spaces，like `["Hello userTwooo","Hi userThree","Wonderful day Alice","Nice day userThree"]`   
from [2284. Sender With Largest Word Count](https://leetcode.com/problems/sender-with-largest-word-count/)
- [ ] symbols such as `[[">>v","v^<","<><"]]`   
from [2. 信物传送 ](https://leetcode.cn/contest/season/2022-spring/problems/6UEx57/)
- [ ] two-dimensional vector containing more than one types,for example `[[], ["leetcode"], [4], ["practice"], [3], [8], [10], [2], [6]]`   
from  [2296. Design a Text Editor](https://leetcode.com/problems/design-a-text-editor/)

#### print more data structures
- [ ] n-ary-tree   
  [559. Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/)    
  [2003. Smallest Missing Genetic Value in Each Subtree](https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/)   
  [2246. Longest Path With Different Adjacent Characters](https://leetcode.com/problems/longest-path-with-different-adjacent-characters/)  
  
### note
`lintcode`/`codewars` users need to replace `{}` with `[]` and `#` with `null`  
please use pprint's [original version](https://github.com/louisdx/cxx-prettyprint/blob/master/prettyprint.hpp)

### Any feature improvement suggestions are welcome

### Thanks
[pprint](https://louisdx.github.io/cxx-prettyprint/)  
[leetcode-helper](https://github.com/luckystone60/leetcode-helper)  
[caide](https://github.com/slycelote/caide/issues/50)  
[boost.Describe](https://www.boost.org/doc/libs/develop/libs/describe/doc/html/describe.html#example_json_rpc)
