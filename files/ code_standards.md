# After having chatgpt, why should I practice leetcode?
leetcode is still important though there is chatgpt.
期望达到的效果是，理解算法思想，代码风格统一，命名规范，便于记忆。用vscode g++编译，chatGPT帮助，输入输出与LeetCode一致。不追求奇技淫巧，变态的时间复杂度要求。
# 规范
候捷：大气正规的编程习惯。
数据一定私有。构造函数尽量使用：进行初始化。
尽量不要pass byu value。参数传递与返回值都by reference.
谁调用函数，this就指向谁。
return by reference 语法分析傅通者需知道接收者是以 reference 形式接收

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
- 字符串string s；
- 使用局部变量 i
- Solution sol;
- ans 代表 answer
- stk 代表 stack
- str 代表 string
- 使用n代表长度,避免在for循环中一直调用函数nums.size()
- 其他变量尽量容易懂，不要用什么abcd
- 不使用递归
- 不使用using namespace std; 
- 双指针使用left,right; fast,slow.
- 使用 nullptr，而不是NULL
- 不用或少用auto
- 输入放在main的代码上，不要在控制台一个一个输入。
- 统一treenode的数据结构


这个问题，你可以给我一个cpp的回答吗？不要用using namespace std; 不要用using std::vector;就在代码中使用std::vector
# rate of progress
该进行的是：greedy 455

我follow [代码随想录](https://github.com/youngyangyang04/leetcode-master)
- 双指针法这部分没有单独建立文件夹，还是在各个数据结构中散落。
- 我把二叉树的公共祖先问题放在了二叉搜索树属性的文件夹中。

代码关键的是：
1. 代码风格规范，符合google style接轨工业界 You can read Google C++ Style Guide (http://google.github.io/styleguide/cppguide.html ) or some other guide for code style.
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