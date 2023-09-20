#include <vector>
using namespace std;

void merge(vector<int>& nums, int low, int mid, int high) {
    int len1 = mid - low + 1;
    int len2 = high - mid;
    vector<int> l_v = vector<int>(nums.cbegin(), nums.cbegin() + len1);
    vector<int> r_v = vector<int>(nums.cbegin() + len1 + 1, nums.cend());

    int i = 0, j = 0, m = 0;
    while (i < len1 && j < len2) {
        nums[m] = l_v[i] <= r_v[j] ? l_v[i++] : r_v[j++];
    }

    while (i < len1) nums[m++] = l_v[i++]; 
    while (j < len2) nums[m++] = r_v[j++]; 
}

void mergesort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int mid = low + (high - low)/2;
        mergesort(nums, low, mid);
        mergesort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
}
