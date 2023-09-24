#include <vector>
#include <string>
using namespace std;

/* KMP
 * haystack: "abcabcabcp"
 * needle: "abcabcp"
 * next[] : {-1, 0, 0, 0, 1, 2, 3, 0}
 */

// best:O(n), worst:O(mn)
vector<int> build_next(string needle) {
    int pre = -1, rev = 0;    // rev: last index of common char
    vector<int> next(1, -1);
    while (rev < static_cast<int>(needle.size())) {
        if (pre > 0 || needle[pre] == needle[rev]) {
            pre++;
            rev++;
            next.push_back(pre);
        } else {
            pre = next[pre];
        }
    }
    return next;
}

int strstr(string haystack, string needle) {
    if (needle.empty()) return 0;
    vector<int> next = build_next(needle);
    int i = 0, j = 0;
    int h_sz = static_cast<int>(haystack.size()), n_sz = static_cast<int>(needle.size());
    while (i < h_sz && j < n_sz) {
        if (j < 0 || haystack[i] == needle[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    return j == n_sz ? i - n_sz : -1;
}
