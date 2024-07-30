## Table of Contents
- [Table of Contents](#table-of-contents)
- [LeetCode 1: 两数之和](#leetcode-1-两数之和)
- [LeetCode 15: 三数之和，uhth](#leetcode-15-三数之和uhth)
- [LeetCode 49: 字母异位词分组](#leetcode-49-字母异位词分组)
- [LeetCode 138: 随机链表的复制](#leetcode-138-随机链表的复制)
- [LeetCode 295: 数据流的中位数](#leetcode-295-数据流的中位数)
- [iFlytec 1: 动态删除中位数](#iflytec-1-动态删除中位数)
- [LeetCode 940: 不同的子序列 II](#leetcode-940-不同的子序列-ii)
- [iFlytec 2: 不同的子序列](#iflytec-2-不同的子序列)
- [LeetCode 343: 整数拆分](#leetcode-343-整数拆分)
- [iFlytec 3: 整数拆分](#iflytec-3-整数拆分)
- [iFlytec 4: 理解 lambda 函数](#iflytec-4-理解-lambda-函数)
- [LeetCode 209: 长度最小的子数组，bddu](#leetcode-209-长度最小的子数组bddu)
- [LeetCode 300: 最长递增子序列，dewu gobk](#leetcode-300-最长递增子序列dewu-gobk)
- [LeetCode 402: 移掉 K 位数字，SAP](#leetcode-402-移掉-k-位数字sap)
- [LeetCode 767: 重构字符串](#leetcode-767-重构字符串)
- [LeetCode 1576: 替换所有的问号](#leetcode-1576-替换所有的问号)
- [dewu fhkr: 重构字符串，与，替换所有问号，的结合](#dewu-fhkr-重构字符串与替换所有问号的结合)
- [LeetCode 1423: 可获得的最大点数，hisi](#leetcode-1423-可获得的最大点数hisi)

---
## LeetCode 1: 两数之和
[两数之和](https://leetcode.cn/problems/two-sum/description/)

创建一个字典：我们创建一个空字典，用来存储每个数字及其在列表中的位置。

遍历列表：我们依次查看列表中的每个数字。

计算差值：对于每个数字，我们计算它与目标值之间的差值（我们希望找到另一个数字，它加上当前数字等于目标值）。

检查字典：我们查看这个差值是否已经在字典中：

如果在字典中：说明我们之前遇到过这个差值对应的数字，现在找到了两个数，它们的和等于目标值。我们返回这两个数在列表中的位置。
如果不在字典中：我们把当前的数字和它的位置存入字典中，方便后面查找。
返回结果：如果遍历完整个列表也没有找到这样的两个数，就返回一个空列表。

代码文件：[1-two-sum.py](./1-two-sum.py)

---

## LeetCode 15: 三数之和，uhth
[三数之和](https://leetcode.cn/problems/3sum/description/)

首先对数组进行排序，得到 [-4, -1, -1, 0, 1, 2]。

然后从头开始，固定一个数 nums[i]，使用双指针 left 和 right 来寻找另外两个数，使得三数之和为0。

在找到一个满足条件的三元组后，继续移动指针跳过相同的元素，确保结果不重复。

代码文件：[15-3sum.py](./15-3sum.py)

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

## LeetCode 138: 随机链表的复制
[随机链表的复制](https://leetcode.cn/problems/copy-list-with-random-pointer/description/)

复制一个带有随机指针的链表（LeetCode 138）需要我们创建一个深拷贝的链表，每个节点不仅有一个 `next` 指针，还有一个 `random` 指针指向链表中的任意节点或 `None`。实现这个方法可以分为三个步骤：

1. **复制每个节点并将复制节点插入到原节点后面**：通过遍历原链表，我们创建一个新的节点，并将其插入到原节点后面。这样每个原节点后面紧跟一个复制节点。
2. **复制随机指针**：通过再次遍历链表，更新复制节点的 `random` 指针。
3. **拆分链表**：将复制节点从混合链表中拆分出来，恢复原链表并获得复制链表。

代码文件：[138-copy-list-with-random-pointer.py](./138-copy-list-with-random-pointer.py)

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

## LeetCode 209: 长度最小的子数组，bddu
[长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum/description/)

初始化：设定左边界 left 为 0，当前窗口的和 sum 为 0，以及最小长度 min_length 为正无穷大。

扩展窗口：使用右边界 right 遍历数组，每次将当前元素加入窗口的和 sum 中。

收缩窗口：如果当前窗口的和 sum 大于等于目标值 target，则尝试收缩窗口，即不断移动左边界 left 并更新最小长度 min_length，直到窗口的和小于目标值。

返回结果：遍历结束后，如果 min_length 被更新，则返回其值，否则返回 0，表示没有满足条件的子数组。

代码文件：[209-minimum-size-subarray-sum.py](./209-minimum-size-subarray-sum.py)

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