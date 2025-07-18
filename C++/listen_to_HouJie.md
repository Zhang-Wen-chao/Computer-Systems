# 规范
# C++ 面向对象高级编程





构造函数可以有多个，overloading.

const member functions，const 不会变。
pass by value 是整包传过去；pass by reference,传引用，就是传指针。参数传递，尽量都用传引用，不希望对方改，再加const。
返回值传递，也都尽量return by reference。可以的情况下，都reference。
friend，友元。朋友函数可以自由取得private成员。
相同class的各个objects互为friends。
谁调用函数，this就指向谁。

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

## 代码关键的是：
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