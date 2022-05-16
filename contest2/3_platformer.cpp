#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> v(n, 0);
    for (int i = 0; i < n; i++){
        std::cin >> v[i];
    }

    std::vector<int> a(v.size(), 0);
    a[1] = abs(v[1] - v[0]);
    for (int i = 2; i < v.size(); i++){
        a[i] = std::min(a[i - 1] + abs(v[i] - v[i - 1]), a[i - 2] + 3 * abs(v[i] - v[i - 2]));
    }
    std::cout << a[v.size() - 1];
    return 0;
}

