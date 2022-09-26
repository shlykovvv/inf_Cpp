#include <iostream>
#include <cmath>

int check(int k) {
    int x = 1, f = 1, n = ceil(log10(k));
    for (int i = 1; i < n; i++) {
        x *= 10;
    }
    for (int i = 10; i <= k; i*=10) {
        if (k%i/(i/10) != k/(x/i*10)%10) {
            f = 0;
            break;
        }
//        std::cout << "zh" << std::endl;
    }
    return f;
}


int main() {
//    int n;
//    std::cin >> n;
//    int v[n];
//    for (int i = 0; i < n; i++) {
//        std::cin >> v[i];
//        std::cout << check(v[i]) << " ";
//    }
    int n;
    std::cin >> n;
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            std::cout << static_cast<char>(static_cast<int>('A')+j);
        }
        for (int j = 0; j < n-i; j++) {
            std::cout << ' ';
            std::cout << ' ';
        }
        for (int j = 1; j <= i; j++) {
            std::cout << static_cast<char>(static_cast<int>('A')+i-j);
        }
        std::cout << std::endl;
    }
    return 0;
}

int NOD(int a , int b)
{
    while(a!=0 and b!=0)
    {
        if(a>b)
        {
            a=a%b;
        }
        else
        {
            b=b%a;
        }

    }
    return (a+b);
}


//int main()
//{
//    int a, b;
//    std::cin >> a >> b;
//    std::cout<<NOD(a ,b)<<std::endl<<a*b/NOD(a ,b)<<std::endl;
//
//
//    return 0;
//}
