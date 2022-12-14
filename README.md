### Description

Helps you debug `leetcode` problems

### Feature
1. creating data structures such as  `array`,`tree`, `list`.  
2. Output all commonly used containers.
3. Debug  [Design problems](https://leetcode.com/tag/design/).

### dependencies 
[boost-describe](https://www.boost.org/doc/libs/develop/libs/describe/) when debug [design problems](https://leetcode.com/tag/design/)

### Todo :   

#### 0. To improve the debugging experience for grid and tree problems，Add a [natvis](https://www.cnblogs.com/X-Jun/p/8040916.html) file to modify the display in the locals window    
  1. For linked lists, add a display similar to std::list  
  2. For tree, the value of the pointer itself should be hidden, and only the member data val should be displayed. If there are left and right sub-objects, if it is nullptr, only null should be displayed. If it has a value, only val should be displayed.  
  3. The two-dimensional grid displays its index in the form of [y,x].  
  
#### 1.Support for more complex input parameter types By modifying [the regular expression](https://github.com/KargathEx/LC-parser/blob/main/lc.h#L55)

- [x] string with punctuation，like `["a==b","b!=c","c==a"]`in [990](https://leetcode.com/problems/satisfiability-of-equality-equations/)
- [x] string with spaces，like `["Hello userTwooo","Hi userThree","Wonderful day Alice","Nice day userThree"]` in [2284](https://leetcode.com/problems/sender-with-largest-word-count/)
- [x] symbols such as `[[">>v","v^<","<><"]]` in [2. 信物传送 ](https://leetcode.cn/contest/season/2022-spring/problems/6UEx57/)
- [x] symbols such as `["...","L.L","RR.","L.R"]` in [光线反射](https://leetcode.cn/contest/tianchi2022/problems/8KXuKl/)  

- [ ] two-dimensional vector containing more than one types,for example `[[], ["leetcode"], [4], ["practice"], [3], [8], [10], [2], [6]]` in  [2296](https://leetcode.com/problems/design-a-text-editor/)
- [ ] Eliminate error reporting for `[[ ]]`  
- [ ] `[[ ]]` should construct a `{}` instead of `{{}}` [link](https://leetcode.cn/problems/maximum-star-sum-of-a-graph/)

I don't know how to modify the regex to correctly parse such strings, eager for your suggestions

#### 2.print more data structures
- [ ] n-ary-tree   
  [559. Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/)    
  [2003. Smallest Missing Genetic Value in Each Subtree](https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/)   
  [2246. Longest Path With Different Adjacent Characters](https://leetcode.com/problems/longest-path-with-different-adjacent-characters/)  
### note
`lintcode`/`codewars` users need to replace `{}` with `[]` and `#` with `null`  
<!-- fmt对map的打印很丑，不用它 -->
### Any feature improvement suggestions are welcome

### Thanks
[pprint](https://louisdx.github.io/cxx-prettyprint/)  
[leetcode-helper](https://github.com/luckystone60/leetcode-helper)  
[caide](https://github.com/slycelote/caide/issues/50)  
[boost.Describe](https://www.boost.org/doc/libs/develop/libs/describe/doc/html/describe.html#example_json_rpc)
