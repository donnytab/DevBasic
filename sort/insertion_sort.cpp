#include <vector>

void insertion_sort(std::vector<int> nums) {
    int len = nums.size();
    for (int i = 1; i < len; ++i) {
        for (int j = i - 1; j >= 0 && nums[j] > nums[j + 1]; --j) {
            std::swap(nums[j], nums[j + 1]);
        }
    }

}

/*
 *           5 | 3 6 1 2
 *           3 5 | 6 1 2
 *           3 5 6 | 1 2
 *           1 3 5 6 | 2
 *           1 2 3 5 6 |
 *
 * */
