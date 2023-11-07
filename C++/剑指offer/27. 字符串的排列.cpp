#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 函数声明
void PermutationHelper(string str, int start, vector<string>& result);
vector<string> Permutation(string str);

int main() {
    string str = "abc";
    vector<string> result = Permutation(str);

    // 输出所有排列
    for (const string& s : result) {
        cout << s << endl;
    }

    return 0;
}

// 函数定义
void PermutationHelper(string str, int start, vector<string>& result) {
    if (start == str.size() - 1) {
        result.push_back(str);
    } else {
        for (int i = start; i < str.size(); ++i) {
            if (i != start && str[i] == str[start]) continue; // 有重复字符时，跳过
            swap(str[start], str[i]);
            PermutationHelper(str, start + 1, result);
            //swap(str[start], str[i]); // 可以不用swap回来，因为每次递归都是传值调用
        }
    }
}

vector<string> Permutation(string str) {
    vector<string> result;
    if (str.empty()) return result;
    PermutationHelper(str, 0, result);
    sort(result.begin(), result.end()); // 按字典序输出
    return result;
}
