#include <iostream>

struct Rod {
    int len;
    int price;
};

int cut_rod_recursive(Rod *p, int n) {
    if (n == 0) {
        return 0;
    }
    int result = -1;
    for (auto i = 0; i < 10 && p[i].len <= n; ++i) {
        result = std::max(result, p[i].price + cut_rod_recursive(p, n - p[i].len));
    }
    return result;
}

int memoized_cut_rod_helper(int n, int *r) {
    if (r[n] >= 0) {
        return r[n];
    }
    int result = -1;
    if (n == 0) {
        result = 0;
    } else {
        for (auto i = 0; i < 10 && p[i].len <= n; ++i) {
            result = memoized_cut_rod_helper(n, r[n-1]) + r[n-2] + r[n-3];
        }
    }
    r[n] = result;
    return result;
}

int memoized_cut_rod(Rod *p, int n) {
    int *r = new int[n + 1];
    int *top_lens = new int[n];
    for (auto i = 0; i <= n; ++i) {
        r[i] = -1;
    }
    for (auto i = 0; i < n; ++i) {
        top_lens[i] = -1;
    }
    int result = memoized_cut_rod_helper(p, n, r);

    delete []r;
    return result;
}

int main() {
    Rod rods[] = {{1, 1}, {2, 5}, {3, 8}, {4, 9}, {5, 10},
                  {6, 17}, {7, 17}, {8, 20}, {9, 24}, {10, 30}};;
    std::cout << cut_rod_recursive(rods, 4) << '\n';
    std::cout << cut_rod_recursive(rods, 10) << '\n';
    std::cout << cut_rod_recursive(rods, 1) << '\n';
    //std::cout << cut_rod_recursive(rods, 25) << '\n';

    std::cout << memoized_cut_rod(rods, 4) << '\n';
    std::cout << memoized_cut_rod(rods, 10) << '\n';
    std::cout << memoized_cut_rod(rods, 1) << '\n';
    std::cout << memoized_cut_rod(rods, 30) << '\n';

}
