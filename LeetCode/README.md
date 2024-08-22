## Table of Contents
- [Table of Contents](#table-of-contents)
- [LeetCode 1: 两数之和](#leetcode-1-两数之和)
- [LeetCode 15: 三数之和，uhth](#leetcode-15-三数之和uhth)
- [ailab 1: 幻方](#ailab-1-幻方)
- [LeetCode 840: 矩阵中的幻方](#leetcode-840-矩阵中的幻方)
- [LeetCode 1895: 最大的幻方](#leetcode-1895-最大的幻方)
- [LeetCode 20: 有效的括号，xbds](#leetcode-20-有效的括号xbds)
- [xiyu 1: 打印竖式乘法](#xiyu-1-打印竖式乘法)
- [LeetCode 49: 字母异位词分组](#leetcode-49-字母异位词分组)
- [LeetCode 69: x 的平方根 ，xbds](#leetcode-69-x-的平方根-xbds)
- [LeetCode 191: 位1的个数，amd](#leetcode-191-位1的个数amd)
- [LeetCode 338: 比特位计数](#leetcode-338-比特位计数)
- [LeetCode 2166: 设计位集, zijp](#leetcode-2166-设计位集-zijp)
- [LeetCode 73: 矩阵置零 ，xbds](#leetcode-73-矩阵置零-xbds)
- [LeetCode 112: 路径总和 ，xbds](#leetcode-112-路径总和-xbds)
- [LeetCode LCR 155: 将二叉搜索树转化为排序的双向链表 ，mayi](#leetcode-lcr-155-将二叉搜索树转化为排序的双向链表-mayi)
- [LeetCode 19: 删除链表的倒数第 N 个结点 ，soul](#leetcode-19-删除链表的倒数第-n-个结点-soul)
- [LeetCode 138: 随机链表的复制，bddu](#leetcode-138-随机链表的复制bddu)
- [LeetCode 283: 移动零，xbds](#leetcode-283-移动零xbds)
- [LeetCode 295: 数据流的中位数](#leetcode-295-数据流的中位数)
- [iFlytec 1: 动态删除中位数](#iflytec-1-动态删除中位数)
- [LeetCode 940: 不同的子序列 II](#leetcode-940-不同的子序列-ii)
- [iFlytec 2: 不同的子序列](#iflytec-2-不同的子序列)
- [LeetCode 343: 整数拆分](#leetcode-343-整数拆分)
- [iFlytec 3: 整数拆分](#iflytec-3-整数拆分)
- [iFlytec 4: 理解 lambda 函数](#iflytec-4-理解-lambda-函数)
- [LeetCode 64: 最小路径和](#leetcode-64-最小路径和)
- [xiyu 2: 最大路径和](#xiyu-2-最大路径和)
- [xiyu 3: 手搓神经网络](#xiyu-3-手搓神经网络)
- [uhth 1: 利用梯度下降法求解函数最小值](#uhth-1-利用梯度下降法求解函数最小值)
- [LeetCode 300: 最长递增子序列，dewu gobk](#leetcode-300-最长递增子序列dewu-gobk)
- [LeetCode 402: 移掉 K 位数字，SAP](#leetcode-402-移掉-k-位数字sap)
- [LeetCode 767: 重构字符串](#leetcode-767-重构字符串)
- [LeetCode 1576: 替换所有的问号](#leetcode-1576-替换所有的问号)
- [dewu fhkr: 重构字符串，与，替换所有问号，的结合](#dewu-fhkr-重构字符串与替换所有问号的结合)
- [LeetCode 209: 长度最小的子数组，bddu](#leetcode-209-长度最小的子数组bddu)
- [LeetCode 239: 滑动窗口最大值，uhth](#leetcode-239-滑动窗口最大值uhth)
- [LeetCode 1423: 可获得的最大点数，hisi](#leetcode-1423-可获得的最大点数hisi)
- [wwld-1 : 自余数，jkds](#wwld-1--自余数jkds)
- [LeetCode 912: 排序数组 ，muxi](#leetcode-912-排序数组-muxi)
- [LeetCode 1188: 设计有限阻塞队列 ，zijp](#leetcode-1188-设计有限阻塞队列-zijp)
- [LeetCode 3244: 新增道路查询后的最短距离 II，zijp](#leetcode-3244-新增道路查询后的最短距离-iizijp)
- [LeetCode 207: 课程表，qualcom](#leetcode-207-课程表qualcom)
- [LeetCode 210: 课程表 II，qualcom](#leetcode-210-课程表-iiqualcom)

---
## LeetCode 1: 两数之和
[两数之和](https://leetcode.cn/problems/two-sum/description/)

代码文件：[1. Two Sum.py](../C++/代码随想录/Hashtable/1.%20Two%20Sum.py)

---

## LeetCode 15: 三数之和，uhth
[三数之和](https://leetcode.cn/problems/3sum/description/)

首先对数组进行排序，得到 [-4, -1, -1, 0, 1, 2]。

然后从头开始，固定一个数 nums[i]，使用双指针 left 和 right 来寻找另外两个数，使得三数之和为0。

在找到一个满足条件的三元组后，继续移动指针跳过相同的元素，确保结果不重复。

代码文件：[15. 3Sum.py](../C++/代码随想录/Hashtable/15.%203Sum.py)

---

## ailab 1: 幻方

代码文件：[ailab-is_magic_square.py](./ailab-is_magic_square.py)

---

## LeetCode 840: 矩阵中的幻方
[矩阵中的幻方](https://leetcode.cn/problems/magic-squares-in-grid/description/)

代码文件：[840-magic-squares-in-grid.py](./840-magic-squares-in-grid.py)

---

## LeetCode 1895: 最大的幻方
[最大的幻方](https://leetcode.cn/problems/largest-magic-square/description/)

代码文件：[1895-largest-magic-square.py](./1895-largest-magic-square.py)

---

## LeetCode 20: 有效的括号，xbds
[有效的括号](https://leetcode.cn/problems/valid-parentheses/description/)

代码文件：[20-valid-parentheses.py](../C++/代码随想录/Stack_Queue/20.%20Valid%20Parentheses.py)

---

## xiyu 1: 打印竖式乘法
[打印竖式乘法](https://www.acgo.cn/problemset/info/7221)

代码文件：[xiyu-1-print-vertical-multiplication.py](./xiyu/xiyu-1-print-vertical-multiplication.py)

---

## LeetCode 49: 字母异位词分组
[字母异位词分组](https://leetcode.cn/problems/group-anagrams/description/)

这个代码的主要思路是通过将每个单词排序后的结果作为键，将同一组字母的单词（即变位词）归类到一起。以下是具体步骤：

1. **创建一个默认字典**：`anagrams` 是一个默认字典（`defaultdict`），其默认值是一个空列表。这个字典用于存储排序后的单词作为键，原始单词列表作为值。
2. **遍历输入的单词列表**：
   - 对于每个单词，先对其字母进行排序。
   - 将排序后的单词作为键，原始单词作为值，添加到默认字典 `anagrams` 中。
3. **返回结果**：最终返回默认字典 `anagrams` 的所有值（即每个键对应的单词列表），它们是一个包含变位词的列表。

具体步骤如下：
1. 初始化一个默认字典 `anagrams`。
2. 遍历 `strs` 列表中的每个单词：
3. 将单词按字母顺序排序，得到一个新的排序后的字符串 `sorted_word`。
4. 使用 `sorted_word` 作为键，将原始单词添加到 `anagrams` 字典中相应的列表中。
5. 最后，将 `anagrams` 字典的所有值转换为一个列表返回。

通过这个过程，相同字母组成的单词（变位词）被归类到同一个列表中。

代码文件：[49-group-anagrams.py](./49-group-anagrams.py)

---

## LeetCode 69: x 的平方根 ，xbds
[x 的平方根](https://leetcode.cn/problems/sqrtx/description/)


代码文件：[69-sqrtx.py](./69-sqrtx.py)

---
## LeetCode 191: 位1的个数，amd
[x 的平方根](https://leetcode.cn/problems/number-of-1-bits/description/)


代码文件：[191-number-of-1-bits.py](./191-number-of-1-bits.py)

---
## LeetCode 338: 比特位计数
[比特位计数](https://leetcode.cn/problems/counting-bits/description/)


代码文件：[338-counting-bits.py](./338-counting-bits.py)

---
## LeetCode 2166: 设计位集, zijp
[设计位集](https://leetcode.cn/problems/design-bitset/description/)
zijp 改题，cpp设计并实现一个能存储n位数的位图。32位，有set，Reset，find查看状态。

代码文件：[2166-design-bitset.cpp](./2166-design-bitset.cpp)

---
## LeetCode 73: 矩阵置零 ，xbds
[矩阵置零](https://leetcode.cn/problems/set-matrix-zeroes/description/)

这个代码的核心思想是通过两次扫描矩阵来设置零值。具体过程如下：

标记零值的位置：首先遍历矩阵，记录所有为零的元素所在的行和列。使用两个辅助数组 row 和 col 来分别记录哪些行和哪些列需要被置零。

设置零值：再次遍历矩阵，根据第一步记录的 row 和 col 数组，将对应行和列的元素全部置零。

具体步骤：

初始化：获取矩阵的行数 m 和列数 n，并创建两个长度分别为 m 和 n 的布尔数组 row 和 col，初始值为 False。

第一次遍历矩阵：双重循环遍历矩阵，如果遇到元素为零的情况，将对应的 row[i] 和 col[j] 设为 True，表示第 i 行和第 j 列需要被置零。

第二次遍历矩阵：再次双重循环遍历矩阵，如果当前元素所在行 i 或列 j 需要被置零（即 row[i] 或 col[j] 为 True），则将当前元素 matrix[i][j] 置为零。

这种方法的优点是只需要两次遍历矩阵，并且使用额外的空间记录需要置零的行和列，相比于直接修改矩阵元素，能更高效地完成任务。

代码文件：[73-set-matrix-zeroes.py](./73-set-matrix-zeroes.py)

---

## LeetCode 112: 路径总和 ，xbds
[路径总和](https://leetcode.cn/problems/path-sum/description/)


代码文件：[112. Path Sum.py](../C++/代码随想录/Binary_Tree/Find%20the%20attributes%20of%20Binary%20tree/112.%20Path%20Sum.py)

---

## LeetCode LCR 155: 将二叉搜索树转化为排序的双向链表 ，mayi
[将二叉搜索树转化为排序的双向链表](https://leetcode.cn/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/description/)

代码文件：[LCR-155-er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof.py](./LCR-155-er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof.py)

---

## LeetCode 19: 删除链表的倒数第 N 个结点 ，soul
[删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/)

代码文件：[19-remove-nth-node-from-end-of-list.py](./19-remove-nth-node-from-end-of-list.py)

---

## LeetCode 138: 随机链表的复制，bddu
[随机链表的复制](https://leetcode.cn/problems/copy-list-with-random-pointer/description/)

复制一个带有随机指针的链表（LeetCode 138）需要我们创建一个深拷贝的链表，每个节点不仅有一个 `next` 指针，还有一个 `random` 指针指向链表中的任意节点或 `None`。实现这个方法可以分为三个步骤：

1. **复制每个节点并将复制节点插入到原节点后面**：通过遍历原链表，我们创建一个新的节点，并将其插入到原节点后面。这样每个原节点后面紧跟一个复制节点。
2. **复制随机指针**：通过再次遍历链表，更新复制节点的 `random` 指针。
3. **拆分链表**：将复制节点从混合链表中拆分出来，恢复原链表并获得复制链表。

python中切片用的是深拷贝还是浅拷贝？在 Python 中，切片操作通常产生一个浅拷贝（shallow copy）。
浅拷贝将当成是信用卡副卡，共享额度。

代码文件：[138-copy-list-with-random-pointer.py](./138-copy-list-with-random-pointer.py)

---

## LeetCode 283: 移动零，xbds
[移动零](https://leetcode.cn/problems/move-zeroes/description/)

这里参考了快速排序的思想，快速排序首先要确定一个待分割的元素做中间点 x，然后把所有小于等于 x 的元素放到 x 的左边，大于 x 的元素放到其右边。

这里我们可以用 0 当做这个中间点，把不等于 0(注意题目没说不能有负数)的放到中间点的左边，等于 0 的放到其右边。

这的中间点就是 0 本身，所以实现起来比快速排序简单很多，我们使用两个指针 i 和 j，只要 nums[i]!=0，我们就交换 nums[i] 和 nums[j]

代码文件：[283-move-zeroes.py](./283-move-zeroes.py)

---

## LeetCode 295: 数据流的中位数
[数据流的中位数](https://leetcode.cn/problems/find-median-from-data-stream/description/)

`__init__` 方法中，我们初始化两个堆：`self.small` 和 `self.large`。`self.small` 为最大堆，`self.large` 为最小堆。

`addNum` 方法中，我们首先将新的数字插入到最大堆中，为了模拟最大堆的行为，我们插入负值。
- 然后我们将最大堆的堆顶（最大值）插入最小堆。
- 如果最小堆的长度超过最大堆，我们将最小堆的堆顶（最小值）重新插入最大堆。

`findMedian` 方法中，我们根据两个堆的长度关系来决定中位数的计算方式：
- 如果两个堆的长度相等，中位数为两个堆顶的平均值。
- 否则，中位数为最大堆的堆顶（注意我们存储的是负值，所以要取反）。

这个方法保证了插入和查找中位数操作的时间复杂度都是 `O(logn)`。

代码文件：[295-find-median-from-data-stream.py](./295-find-median-from-data-stream.py)

---

## iFlytec 1: 动态删除中位数
要使代码运行得更快，可以减少重复排序的次数。每次移除中位数后，我们可以通过二分查找来找到并移除中位数，这样可以避免重复排序，从而提高效率。

1. **初始排序**：对输入数组进行一次排序。
2. **找到并移除中位数**：每次找到中位数后，用 `pop` 方法直接移除该元素，而不再进行排序。这通过利用列表的有序特性，使得查找和移除操作变得高效。
3. **时间复杂度**：这种方法的主要耗时操作是初始排序，时间复杂度为 \(O(n \log n)\)。每次移除中位数的操作由于列表是有序的，因此时间复杂度为 \(O(n)\)。总体时间复杂度相比之前的方法更低。

输入：
```
4
1 9 8 5
```
输出：
```
5 8 1 9
```

输入：
```
6
6 6 6 6 6 6
```
输出：
```
6 6 6 6 6 6
```

代码文件：[dynamic_delete_median.py](./iFlytec-1-dynamic_delete_median.py)

---

## LeetCode 940: 不同的子序列 II
1. **初始化变量**：
    - `MOD` 用于取模运算，避免结果过大。
    - `dp` 数组用于动态规划，其中 `dp[i]` 表示前 `i` 个字符的不同非空子序列的个数。
    - `last` 字典记录每个字符最后一次出现的位置。

2. **遍历字符串**：
    - 每个位置 `i` 的子序列数 `dp[i]` 初始为前一个位置的子序列数的两倍（因为每个子序列可以选择包含当前字符或不包含当前字符）。
    - 如果当前字符之前已经出现过，减去上一次出现该字符时可能形成的重复子序列数。

3. **返回结果**：
    - 最后返回 `dp[n] - 1`，因为 `dp[n]` 包含了空子序列，需要减去。

对于字符串 `"abc"`：
- 子序列有：`"a"`, `"b"`, `"c"`, `"ab"`, `"ac"`, `"bc"`, `"abc"` 共 7 个，所以结果是 7。


代码文件：[940-distinct-subsequences-ii.py](./940-distinct-subsequences-ii.py)

---

## iFlytec 2: 不同的子序列
但是我没看懂这个题目。

给定一个仅由小写字母组成，长度为n的字符串s，则字符串有2^n-1个非空子序列。请你求出所有子序列中不同字符的个数总和，由于答案较大，输出对10^9+7取模后的结果。 例如 输入 aaaa 输出 15 说明：2^6-1 =15 输入 abcde 输出 80

---

## LeetCode 343: 整数拆分

1. **初始化**：创建一个长度为 \( n+1 \) 的数组 `dp`，其中 `dp[i]` 表示将整数 \( i \) 拆分后得到的最大乘积。
2. **边界条件**：由于 \( dp[1] = 1 \)（尽管实际问题中 \( n >= 2 \)，这里定义为1以简化代码逻辑）。
3. **动态规划递推**：
   - 外层循环从 2 到  n ，表示当前计算的整数。
   - 内层循环从 1 到  i-1 ，表示尝试将当前整数  i  拆分成两部分：\( j \) 和 \( i-j \)。
   - 更新 `dp[i]` 的值为 `max(dp[i], j * (i - j), j * dp[i - j])`，分别对应不进一步拆分 \( i - j \) 和进一步拆分 \( i - j \) 的情况。

这样，最终的 `dp[n]` 就是将整数 \( n \) 拆分后得到的最大乘积。

代码文件：[343-integer-break.py](./343-integer-break.py)

---
## iFlytec 3: 整数拆分
这个能看懂，但不会写，它的示例我没记录完全。明明我的答案也合理，但是就是判错了。

众所周知，任何一个数，都可以拆成若干项不同的，由2的次幂，3的次幂相乘的和。比如10等于2的三次方乘3的0次方加上2的一次方乘3的0次方。 请你写个Python代码 输入，第一行是一个整数t，代表了t组数据。 输出，对于每一组数据，第一行输出一个整数m代表序列的项数，第二行输出m个不同的整数代表拆出的序列。并由大到小输出。 比如 输入 1 10 输出 2 8 2

---

## iFlytec 4: 理解 lambda 函数
理解这句代码时，关键在于理解 `fun()` 返回的是一个包含多个函数的列表。我们先回顾一下 `fun()` 函数的定义：

```python
def fun():
    lis = []
    i = 0
    while i < 3:
        lis.append(lambda x: print(i*x, end= ","))
        i += 1
    return lis
```

1. `fun()` 函数初始化了一个空列表 `lis`。
2. 然后，使用 `while` 循环向 `lis` 中添加三个 `lambda` 函数。
3. 最后，`fun()` 返回这个包含三个 `lambda` 函数的列表。

因此，当你调用 `fun()` 时，返回的实际上是一个包含三个 `lambda` 函数的列表：

```python
[
    lambda x: print(i*x, end=","),
    lambda x: print(i*x, end=","),
    lambda x: print(i*x, end=",")
]
```

虽然这些 `lambda` 函数看起来是相同的，但由于闭包的特性，它们都会引用相同的变量 `i`，而 `i` 的最终值是 3。

现在来看这一行代码：

```python
for f in fun():
    f(2)
```

这行代码可以分解为以下步骤：

1. 调用 `fun()` 函数，得到一个包含三个 `lambda` 函数的列表。
2. 使用 `for` 循环迭代这个列表，将列表中的每个函数依次赋值给 `f`。
3. 对每个 `f`（即列表中的每个 `lambda` 函数）调用 `f(2)`，传入参数 `2`。

在具体执行时：

- 第一次迭代时，`f` 是 `lambda x: print(i*x, end=",")`，此时 `i` 的值是 3，所以执行 `f(2)` 会打印 `6`。
- 第二次迭代时，`f` 还是 `lambda x: print(i*x, end=",")`，`i` 依然是 3，执行 `f(2)` 还是打印 `6`。
- 第三次迭代时，`f` 依然是 `lambda x: print(i*x, end=",")`，`i` 还是 3，执行 `f(2)` 还是打印 `6`。

因此输出是 `6,6,6`。

解释 `fun` 里面有很多函数

在这个例子中，`fun()` 返回的是一个列表，这个列表包含了多个 `lambda` 函数。这些 `lambda` 函数在定义时都捕获了相同的外部变量 `i`。因此，这个列表中的每个元素都是一个函数（具体来说是 `lambda` 函数）。

通过 `for f in fun():` 进行迭代时，你实际上是在对包含的每个函数进行迭代并调用它们。这样就可以对每个函数传递参数并执行它们的功能。

代码文件：[understand-lambda.py](./iFlytec-4-understand-lambda.py)

---

## LeetCode 64: 最小路径和
[最小路径和](https://leetcode.cn/problems/minimum-path-sum/description/)

代码文件：[64-minimum-path-sum.py](./64-minimum-path-sum.py)

---

## xiyu 2: 最大路径和
[最大路径和](https://cloud.tencent.com/developer/article/1856834)

代码文件：[xiyu-2-maximum-path-sum.py](./xiyu/xiyu-2-maximum-path-sum.py)

---
## xiyu 3: 手搓神经网络
据说，不用torch，不用numpy。下面的代码，cnn_python.py 是运行不了的。

代码文件：[cnn_torch.py](./xiyu/cnn_torch.py)
代码文件：[cnn_numpy.py](./xiyu/cnn_numpy.py)
代码文件：[cnn_python.py](./xiyu/cnn_python.py)

代码文件：[transformer.py](./xiyu/transformer.py)
代码文件：[bert.py](./xiyu/bert.py)

---

## uhth 1: 利用梯度下降法求解函数最小值

代码文件：[uhth-1-gradient_descent.py](./uhth-1-gradient_descent.py)

---


## LeetCode 300: 最长递增子序列，dewu gobk
[最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/description/)

初始化 dp 数组，每个位置的值为1，因为每个元素都可以看作是一个长度为1的递增子序列。

遍历数组的每个元素，对于每个元素，向前检查所有之前的元素。如果前面的元素小于当前元素，那么我们可以更新 dp 数组的当前值，即 dp[i] = max(dp[i], dp[j] + 1)，其中 j 是当前元素之前的元素的索引。

最终，最长递增子序列的长度就是 dp 数组中的最大值。

代码文件：[402-remove-k-digits.py](./402-remove-k-digits.py)

---

## LeetCode 402: 移掉 K 位数字，SAP
[移掉 K 位数字](https://leetcode.cn/problems/remove-k-digits/description/)

对于输入 num = "1432219" 和 k = 3：

初始栈为空。

依次处理每个数字，移除3个比当前数字大的数字。

最后栈中剩下的数字为 ['1', '2', '1', '9']。

拼接成字符串得到 "1219"。

代码文件：[402-remove-k-digits.py](./402-remove-k-digits.py)

---

## LeetCode 767: 重构字符串

[重构字符串](https://leetcode.cn/problems/reorganize-string-/description/)

统计每个字符的出现频率：使用 collections.Counter 统计每个字符在字符串中的出现频率。

用最大堆存储字符和它们的频率：由于 Python 的 heapq 模块默认是最小堆，因此我们存储负数的频率以实现最大堆的效果。

构建结果字符串：每次从堆中取出频率最高的字符，并将其添加到结果字符串中。将上一次取出的字符（如果还有剩余）重新放回堆中。

检查结果字符串的有效性：最后检查生成的结果字符串长度是否与原字符串相等。如果不相等，说明无法重新排列字符使得相邻字符不同，返回空字符串。

代码文件：[767-reorganize-string.py](./767-reorganize-string.py)

---
## LeetCode 1576: 替换所有的问号

[替换所有的问号](https://leetcode.cn/problems/replace-all-s-to-avoid-consecutive-repeating-characters/description/)

转换为列表：首先将字符串转换为列表，以方便对字符进行修改。

遍历字符串：遍历字符串中的每一个字符，如果是 '?'，则选择一个合适的字母进行替换。

选择合适的字母：为了确保替换后的字符不与前后字符相同，我们从 'abcdefghijklmnopqrstuvwxyz' 中选择一个字母，并检查是否与前后字符冲突。

替换并返回：将 '?' 替换为合适的字母后，将列表转换回字符串并返回。

代码文件：[1576-replace-all-s-to-avoid-consecutive-repeating-characters.py](./1576-replace-all-s-to-avoid-consecutive-repeating-characters.py)

---
## dewu fhkr: 重构字符串，与，替换所有问号，的结合
一个字符串由0，1，2，？等字符组成，请将所有的？字符转为0，1，2里面的一个，需要保证替换后相邻字符不同，有多少替换方式？

定义函数 count_replaces(s)，该函数用于计算可能的组合数。

在 count_replaces(s) 中定义了一个嵌套的回溯函数 backtrack(index)，它会从字符串的指定索引位置开始递归地进行字符替换和检查。

backtrack(index) 函数：

如果当前索引等于字符串的长度，表示已经处理完所有字符，增加计数器 count 并返回。

如果当前字符是 '?'，则尝试将其替换为 '0'、'1' 或 '2'，并确保替换后的字符与前一个字符不同，然后继续处理下一个字符。

如果当前字符不是 '?'，则检查它是否与前一个字符不同，如果不同则继续处理下一个字符。

count_replaces(s) 函数初始化计数器 count 为 0，并将字符串转换为列表（以便修改），然后调用 backtrack(0) 开始递归。

count_replaces(s) 最后返回计数器 count 的值，表示符合条件的字符串组合数。

在 main() 函数中，测试不同的字符串并打印结果。

代码文件：[dewu-1-replace-wenhao.py](./dewu-1-replace-wenhao.py)

---
## LeetCode 209: 长度最小的子数组，bddu
[长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum/description/)

初始化：设定左边界 left 为 0，当前窗口的和 sum 为 0，以及最小长度 min_length 为正无穷大。

扩展窗口：使用右边界 right 遍历数组，每次将当前元素加入窗口的和 sum 中。

收缩窗口：如果当前窗口的和 sum 大于等于目标值 target，则尝试收缩窗口，即不断移动左边界 left 并更新最小长度 min_length，直到窗口的和小于目标值。

返回结果：遍历结束后，如果 min_length 被更新，则返回其值，否则返回 0，表示没有满足条件的子数组。

代码文件：[209-minimum-size-subarray-sum.py](./209-minimum-size-subarray-sum.py)

---

## LeetCode 239: 滑动窗口最大值，uhth
[滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/description/)

双端队列 deq：用于存储当前滑动窗口中元素的索引，并且保证这些元素的顺序是从大到小的。因此，deq[0]始终是当前窗口中的最大值的索引。

移除过期元素：如果deq中的第一个元素已经超出当前滑动窗口的范围，就将其从deq中移除。

保持deq的顺序：从deq的尾部开始，如果当前元素nums[i]大于等于deq尾部的元素，我们就将这些较小的元素移除，因为它们不可能成为窗口的最大值。

加入新元素：将当前元素的索引添加到deq中。

记录最大值：一旦我们遍历过一个完整的窗口（i >= k - 1），将deq[0]对应的元素添加到结果列表result中。

代码文件：[239-sliding-window-maximum.py](./239-sliding-window-maximum.py)

---

## LeetCode 1423: 可获得的最大点数，hisi
[可获得的最大点数](https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/description/)

计算总和：
首先计算所有卡牌点数的总和 total。

确定需要留下的卡牌数量：
计算需要留下的卡牌数量 leave_count = n - k，其中 n 是卡牌总数。这是因为你要从两端拿走 k 张卡牌。

特殊情况处理：
如果需要拿走的卡牌数量 k 等于卡牌总数 n，那么直接返回总和 total，因为你会拿走所有的卡牌。

滑动窗口计算最小的子数组和：
为了最大化总和，实际上需要最小化中间未被拿走的子数组和。这可以通过滑动窗口技术来实现：

初始化最小子数组和 min_subarray_sum 为无穷大。
计算第一个长度为 leave_count 的子数组的和，并更新 min_subarray_sum。
使用滑动窗口，从数组的 leave_count 位置开始，一直到数组末尾，每次滑动窗口向右移动一位，更新当前窗口的和，并更新 min_subarray_sum。
计算最大得分：
最后，最大得分就是总和 total 减去最小子数组和 min_subarray_sum。

代码文件：[1423-maximum-points-you-can-obtain-from-cards.py](./1423-maximum-points-you-can-obtain-from-cards.py)

---

## wwld-1 : 自余数，jkds
[自余数](https://www.cnblogs.com/wined/p/16045778.html)


这个代码通过预处理和查表的方法有效地计算了多个查询中给定范围内满足特定条件的数的数量。它使用了一个大数组 table 来存储中间结果，从而使查询变得非常高效。

代码文件：[wwld-1-ziyushu.cpp](./wwld-1-ziyushu.cpp)

---

## LeetCode 912: 排序数组 ，muxi
[排序数组](https://leetcode.cn/problems/sort-an-array/description/)
改为快排任意长度数组，数组内容也用随机数填充。

代码文件：[912-sort-an-array.cpp](./912-sort-an-array.cpp)

---

## LeetCode 1188: 设计有限阻塞队列 ，zijp
[设计有限阻塞队列](https://leetcode.cn/problems/design-bounded-blocking-queue/description/)

https://blog.csdn.net/HeavenDan/article/details/117925822

代码文件：[1188-design-bounded-blocking-queue.py](./1188-design-bounded-blocking-queue.py)
代码文件：[1188-design-bounded-blocking-queue.cpp](./1188-design-bounded-blocking-queue.cpp)

---


## LeetCode 3244: 新增道路查询后的最短距离 II，zijp
[新增道路查询后的最短距离 II](https://leetcode.cn/problems/shortest-distance-after-road-addition-queries-ii/)

代码文件：[3244-shortest-distance-after-road-addition-queries-ii.py](./3244-shortest-distance-after-road-addition-queries-ii.py)

---

## LeetCode 207: 课程表，qualcom
[课程表](https://leetcode.cn/problems/course-schedule/description/)

这是一道经典的图论题目，要求判断一个课程安排是否可能，即判断一个有向图中是否有环。可以使用拓扑排序（Kahn's Algorithm）或深度优先搜索（DFS）来解决。

下面是使用拓扑排序（BFS）来解决此问题的Python代码。

代码文件：[207-course-schedule.py](./207-course-schedule.py)

---

## LeetCode 210: 课程表 II，qualcom
[课程表](https://leetcode.cn/problems/course-schedule-ii/description/)


要求你找到一种学习所有课程的顺序。如果有多个正确的顺序，只需要返回其中一个，如果无法完成所有课程，则返回空列表。这本质上是求一个有向无环图（DAG）的拓扑排序。

代码文件：[210-course-schedule-ii.py](./210-course-schedule-ii.py)

---