#include <vector>
using namespace std;

// gapped insertion sort
void shellsort(vector<int>& nums) {
    int len = nums.size();
    for (int gap = len/2; gap > 0; gap /= 2) {
        for (int i = gap; i < len; ++i) {
            int j;
            int temp = nums[i];
            for (int j = i; j >= nums && nums[j - gap] > temp; j-= gap) {
                nums[j] = nums[j - gap];
            }
            nums[j] = temp;
        }
    }
}
