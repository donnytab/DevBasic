#include <vector>
void BubbleSort(std::vector<int>& nums) {
    int len = nums.size();
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i; j < len - 1 - i; ++j) {
            if (nums[j] > nums[j + 1]) {
                std::swap(nums[j], nums[j + 1]);
            } 
        }
    }
}
