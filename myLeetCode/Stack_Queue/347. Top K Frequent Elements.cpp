// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <queue>
// #include <algorithm>

// std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
//     // 统计每个元素的频率
//     std::unordered_map<int, int> freq;
//     for (int num : nums) {
//         freq[num]++;
//     }
    
//     // 定义一个最小堆，按照频率从小到大排序
//     std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    
//     // 遍历频率表，维护堆的大小为 k
//     for (auto& pair : freq) {
//         pq.push({pair.second, pair.first});
//         if (pq.size() > k) {
//             pq.pop();
//         }
//     }
    
//     // 从堆中取出前 k 个频率最高的元素
//     std::vector<int> result;
//     while (!pq.empty()) {
//         result.push_back(pq.top().second);
//         pq.pop();
//     }
    
//     // 结果按照频率高低进行排序
//     std::reverse(result.begin(), result.end());
    
//     return result;
// }

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    
    std::vector<std::pair<int, int>> freqVec(freq.begin(), freq.end());
    std::partial_sort(freqVec.begin(), freqVec.begin() + k, freqVec.end(),
                      [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
                          return p1.second > p2.second;
                      });
    
    std::vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(freqVec[i].first);
    }
    
    return result;
}

int main() {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    
    std::vector<int> result = topKFrequent(nums, k);
    
    std::cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}