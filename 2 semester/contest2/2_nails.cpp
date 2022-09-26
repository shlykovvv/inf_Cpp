#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v;
    int n;
    while (std::cin >> n) {
        v.push_back(n);
    }
    std::sort (v.begin(), v.end());
    std::vector<int> a(v.size() + 1, 0);
    a[1] = 10000;
    for (int i = 2; i < v.size() + 1; i++){
        a[i] = std::min(a[i - 1], a[i - 2]) + v[i - 1] - v[i - 2];
    }
    std::cout << a[v.size()];
    return 0;
}
