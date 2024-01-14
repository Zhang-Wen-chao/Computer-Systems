// 108. Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// clang++ 108.\ Convert\ Sorted\ Array\ to\ Binary\ Search\ Tree.cpp -std=c++17
#include "../../printUtils.hpp"

template<typename T>
class Solution {
public:
    // Convert a sorted array to a balanced BST
    TreeNode<T>* sortedArrayToBST(std::vector<T>& nums) {
        // Call the helper function with the whole array as the range
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    
    // Helper function to convert a subarray to a balanced BST
    TreeNode<T>* sortedArrayToBST(std::vector<T>& nums, int start, int end) {
        // Base case: empty subarray
        if (start > end) return nullptr;
        
        // Find the middle element of the subarray
        int mid = start + (end - start) / 2;
        
        // Create a new node with the middle element as the value
        TreeNode<T>* root = new TreeNode(nums[mid]);
        
        // Recursively build the left and right subtrees using the left and right halves of the subarray
        root->left = sortedArrayToBST(nums, start, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, end);
        
        // Return the root of the subtree
        return root;
    }
};

int main() {
    std::vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode<int>* result = Solution<int>().sortedArrayToBST(nums);
    std::cout << "The result is: " << std::endl;
    printArray(levelOrder(result));

    std::vector<int> nums2 = {1, 3};
    TreeNode<int>* result2 = Solution<int>().sortedArrayToBST(nums2);
    std::cout << "The result is: " << std::endl;
    printArray(levelOrder(result2));

    return 0;
}
