#include <vector>
using namespace std;

// gapped insertion sort
void shellsort(vector<int>& nums) {
    int len = nums.size();
    for (int gap = len/2; gap > 0; gap /= 2) {
        for (int i = gap; i < len; ++i) {
            for (int j = i; j - gap >= 0 && nums[j - gap] > nums[j]; j-= gap) {
                swap(nums[j - gap], nums[j]);
            }
        }
    }
}
