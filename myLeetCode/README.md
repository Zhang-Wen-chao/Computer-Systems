# After having chatgpt, why should I practice leetcode?
leetcode is still important though there is chatgpt.
期望达到的效果是，理解算法思想，代码风格统一，命名规范，便于记忆。用vscode g++编译，chatGPT帮助，输入输出与LeetCode一致。不追求奇技淫巧，变态的时间复杂度要求。
# 规范

using std::cout;
using std::endl;
then in the following code , it is no need to write std:: again.

Simple is Beautiful !
Short
Simple
Efficient

Some Tips on Optimization
•Choose an appropriate algorithm
•Clear and simple code for the compiler to optimize
•Optimize code for memory
•Do not copy large memory
•No printf()/cout in loops
•Table lookup (sin(), cos() ...)
•SIMD, OpenMP


Suggestions to your Project 3
•Use size_t for mat.cols and mat.rows
•Use memcpy() to copy data. Element assignment has a lower efficiency.
•Use 1D array (float*) nor 2D array (float**) for matrix data.
•Redundant computation in loops
•Do parameter checking in functions: null pointers, dimension matching in 
matrix operations, etc
•Do not bind the create matrix function with file I/O.
•File name: head.h, source1.c, source2.c, source3.c
•Good implementation VS good homework.



pay more attention to algorithms, concepts, technologies, rather than particular features, particular programming language. and do not try to use all those fancy features of the language that you just learned in your project, because those features just exist and you want to make your code look cool by using all those features, because this is a good change that a couple of months later, you won't be able to read your own code because it's too complex. And you need to develop proper style of using C++, not to shoot yourself on the foot. And try not to use manual memory allocation, using existing containers like std::vector, or if you use OpenCV, use cv::Mat, etc. Try to put some regression test before you do any refactoring or optimization. There should be some tests, of course. As I said, develop some methodology, a proper methodology how to create robust software that is easy to debug or doesn't need to be debbugged at all, it works out of the box. Instead of just using very complex language constructions that you may not fully understand. When people avoid using raw pointers in C++, but instead use containers like cv::Mat or cv::Vec or shared pointers, the number of memory leaks problems go almost to zero.


- use clang-format.
- 不能使用单个字母做变量名，没人能看懂。
- Solution sol;
- ans 代表 answer

- 使用局部变量 i
使用局部变量 i 是常见的习惯，表示迭代的索引。这种命名约定在编程中被广泛使用，并且很容易理解和阅读。使用 i 表示迭代索引是一种通用的做法，无论是在循环中还是在其他地方都适用。虽然 idx 也是一个有效的命名选项，但 i 是更为常见和被接受的方式，因此使用 i 是一种更好的选择。

- 使用n代表长度
避免在for循环中一直调用函数nums.size()
int n = nums.size();
n = len(nums)                                                                                                                           

- 不使用递归
这种递归的写法可以解决问题，但是在处理大规模的链表时可能会导致栈溢出，因为递归的深度会随着链表长度的增加而增加。

- 使用什么头文件，就引用什么头文件。不要使用万能头文件
#include <iostream>
#include <vector>
- 不使用using namespace std; 建议在代码中显式地使用 std:: 前缀，以提高代码的可读性和避免潜在的命名冲突。
- 文件命名上还是得加上数字，方便索引。
- 双指针使用left,right; fast,slow.
- 使用 nullptr，而不是NULL
- 统一treenode的数据结构
开头声明 LCA is the abbreviation of lowestCommonAncestor
The greatest common divisor (GCD) 
0669有正确的二叉树输出。
0701有正确的二叉树输入。
# rate of progress
我follow [代码随想录](https://github.com/youngyangyang04/leetcode-master)

hash table 349


代码关键的是：
1. 代码风格规范，符合google style接轨工业界// https://google.github.io/styleguide/
2. 代码编译后的复杂度低
3. 可读性好

Good code style is important for many reasons¹²³⁴, such as:

- It makes the code easier to read, understand and maintain¹²³.
- It makes the intent of the code obvious and clear²⁴.
- It improves the performance and efficiency of the code¹⁴.
- It ensures consistency and uniformity throughout the software¹².
- It facilitates knowledge transfer and collaboration among developers¹³.

Therefore, based on these benefits, some possible answers to your question are:

- Easier to maintain
- Makes the intent of the code obvious

The other options are not benefits of good code style. In fact, they may indicate poor code quality or bad practices. For example:

- Allows it to never have to be touched again: This implies that the code is rigid and inflexible, which is not desirable for software development. Code should be adaptable and extensible to changing requirements and needs.
- Makes sure the author will refactor it later: This implies that the code is messy and incomplete, which is not a good sign of quality. Code should be refactored as soon as possible to avoid technical debt and bugs.