#include <vector>
using namespace std;

void bucketsort(vector<int>& nums) {
    if (nums.empty()) return;
    int low = *std::min_element(nums.begin(), nums.end());
    int high = *std::max_element(nums.begin(), nums.end());
    int range = high - low + 1;
    vector<int> buckets(range);

    for (auto n : nums) {
        ++buckets[n - low];
    }
    for (int i = 0; i < range; ++i) {     // bucket indexes ASC
        for (int j = 0; j < buckets[i]; ++j) {    // bucket[]: number of elements
            nums.push_back(i + low);
        }
    }
}
