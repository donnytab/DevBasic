#include <vector>

void selection_sort(std::vector<int>& nums) {
    int len = nums.size();
    for (int i = 0; i < len - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < len; ++j) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        std::swap(nums[min], nums[i]);
    }
}
