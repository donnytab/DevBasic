#include <vector>
using namespace std;

void shift(vector<int>& nums, int i, int len) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max = i;    // parent index
    if (left < len && nums[left] > nums[max]) max = left;
    if (right < len && nums[right] > nums[max]) max = right;
    if (max != i) {
        swap(nums[max], nums[i]);
        shift(nums, max, len);
    }
}

// build max heap
void heapify(vector<int>& nums, int len) {
    for (int i = len / 2 + 1; i >= 0; i--) {  // from heap bottom to top
        shift(nums, i, len);
    }
}

// result in ascending order
void heapsort(vector<int>& nums) {
    int len = nums.size();
    heapify(nums, len);
    for (int i = len - 1; i >= 1; i--) {
        swap(nums[0], nums[i]);  // move the max node to the end
        shift(nums, 0, i);       // build max heap from nums[0] to nums[i]
    }
}
