#include <vector>

int partition(std::vector<int>& nums, int l, int r) {
    int pivot = nums[l];
    while (l < r) {
        while (nums[r] > pivot && l < r) { --r; }
        if (l < r) { std::swap(nums[l++], nums[r]); }
        while (nums[l] < pivot && l < r) { ++l; }
        if (l < r) { std::swap(nums[l], nums[r--]); }
    }
    return l;
}

void quicksort(std::vector<int>& nums, int l, int r) {
    if (l < r) {
        int pivot = partition(nums, l, r);
        quicksort(nums, l, pivot - 1);
        quicksort(nums, pivot + 1, r);
    }
}
