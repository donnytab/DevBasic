/* 
 * Advantage: time complexity up to O(n)
 * Disadvantage: range limit, positive number, extra space
 *
 * 8 people, score 0 ~ 5, range:6
 * {2, 5, 3, 0, 2, 3, 0, 3}
 * 
 *        0 1 2 3 4 5
 * C[6] : 2 0 2 3 0 1
 * C[6] : 2 2 4 7 7 8 (sum)
 */

void countsort(int* a, int n) {
    int max = a[0];
    for (int i = 1; i < n, ++i) {
        max = std::max(max, a[i]);
    }
    int C[]
}
