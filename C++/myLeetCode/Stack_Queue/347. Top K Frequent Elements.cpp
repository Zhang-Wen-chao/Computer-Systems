// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    // 使用哈希表跟踪每个元素的频率
    std::unordered_map<int, int> frequency;
    for (int num : nums) {
        frequency[num]++;
    }

    // 使用优先队列找到前k个高频元素
    // 优先队列中的元素是一个pair，其中第一个元素是元素的频率，第二个元素是元素本身
    std::priority_queue<std::pair<int, int>> pq;
    for (const auto& [num, freq] : frequency) {
        pq.push({freq, num});
    }
    // clang++ 347.\ Top\ K\ Frequent\ Elements.cpp -std=c++17
    
    // 从优先队列中提取前k个元素
    std::vector<int> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(pq.top().second);
        pq.pop();
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