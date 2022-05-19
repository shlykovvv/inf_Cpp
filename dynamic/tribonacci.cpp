#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int *v = new int[n];

    v[0] = 0;
    if (n > 0) v[1] = 1;
    if (n > 1) v[2] = 1;
    for (int i = 3; i <= n; i++){
        v[i] = v[i - 3] + v[i - 2] + v[i - 1];
    }
    std::cout << v[n];
    return 0;
}
