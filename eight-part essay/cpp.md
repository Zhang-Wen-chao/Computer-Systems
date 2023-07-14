# 基础定义
把c++的东西都背下来。能讲出来就行了。

struct vs class ?
当使用 struct 定义一个类时，类的成员默认为公共的（public），而使用 class 定义一个类时，类的成员默认为私有的（private）。

当我们提及类型、多态、接口继承与实现继承的关系时，你应该对这些概念了然于胸，而不是迫不及待地翻阅手头的字典。


C++ 中 printf 和 cout 什么区别？ - Lawgh的回答 - 知乎
https://www.zhihu.com/question/357208801/answer/905489671


在C++中，int const和const int
https://blog.csdn.net/tengqi200/article/details/115441616#

## 具体对象、和临时对象的生命周期
    Solution<int> solution;
    std::vector<std::string> paths = solution.binaryTreePaths(root);
和下面的写法是不是等价？两者有什么不一样？
    std::vector<std::string> paths = Solution<int>().binaryTreePaths(root);

主要区别在于对象的生命周期和代码的结构。在第一种写法中，我们显式地创建了一个Solution<int>对象，并将其赋值给solution变量。这个对象会一直存在，直到它超出了其作用域（在这个例子中是main函数的结束）。然后我们使用这个对象调用binaryTreePaths函数。

而在第二种写法中，我们使用临时对象Solution<int>()来直接调用binaryTreePaths函数，而没有将对象赋值给一个变量。这个临时对象会在语句执行完毕后被销毁，它的生命周期更短暂。

从功能上来说，两种写法是等价的，都可以正确地获取二叉树的路径。选择使用哪种写法取决于具体的编程需求和个人偏好。如果在后续的代码中需要多次使用Solution<int>对象，那么第一种写法可以更好地复用该对象。如果只是一次性地使用binaryTreePaths函数，那么第二种写法可以更简洁。
## -> 的含义
在 `node->val` 中，`->` 是 C++ 中的成员访问运算符，用于通过指针访问其所指向对象的成员。在这种情况下，`node` 是一个指向节点对象的指针，而 `val` 是节点对象的一个成员。

使用 `node->val` 表达式，可以访问指针 `node` 所指向节点对象的 `val` 成员。

如果你不想使用箭头运算符 `->`，还有另一种等效的写法，即使用星号运算符 `*` 配合点号运算符 `.`。例如，`(*node).val` 等效于 `node->val`。

这是因为 `node->val` 是对 `(*node)` 执行点号运算符的简写。也就是说，先对指针 `node` 解引用（使用 `*` 运算符），然后使用点号运算符访问解引用后的对象的成员 `val`。

所以，`node->val` 是比较常见和简洁的写法，用于通过指针访问节点对象的成员。
## 不能将一个非常量的左值引用绑定到一个右值上
39. Combination Sum.cpp:32:41: error: cannot bind non-const lvalue reference of type ‘std::vector<int>&’ to an rvalue of type ‘std::vector<int>’
这是什么错误，应该怎么避免？

这是一个编译错误，意思是你不能将一个非常量的左值引用绑定到一个右值上。左值是指可以取地址的对象，右值是指临时的、不可取地址的对象。在你的代码中，你的函数参数是一个非常量的左值引用，但是你传递给它的是一个右值，即std::vector<int>类型的临时对象。这样做是不合法的，因为你可能会修改这个临时对象，而这是没有意义的。要避免这个错误，你有两种方法：

将你的函数参数改为一个常量的左值引用，即const std::vector<int>&。这样可以绑定到右值，并且延长它的生命周期，但是不能修改它。
将你的函数参数改为一个右值引用，即std::vector<int>&&。这样可以绑定到右值，并且可以修改它，但是要注意它的生命周期和有效性。
# Solution solution;和Solution();的区别
Solution solution;使用了类的默认构造函数来创建对象。如果您没有提供任何自定义的构造函数，编译器将提供一个默认构造函数，该构造函数没有任何参数。当您使用Solution solution;语法创建对象时，编译器将自动调用默认构造函数来初始化对象。

Solution();语法是显式地调用类的默认构造函数。这是通过在类名后面添加括号，即Solution()，来实现的。这种方式在实际中很少使用，因为通常我们更倾向于使用Solution solution;这种隐式调用默认构造函数的方式。

总的来说，Solution solution;和Solution();在功能上是相同的，都可以用于创建类的对象。但是在实际使用中，Solution solution;更常见和更易读。