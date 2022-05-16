#include <iostream>
#include <string>

int main()
{
    int n = 0;
    std::cin >> n;
    std::string temp;
    int x_white, y_white;
    int x[n], y[n];
    for (int i = 0; i < n; i++){
        std::cin >> temp;
        x[i] = (int)(temp[0]) - 97;
        y[i] = (int)(temp[1]) - 49;
    }
    std::cin >> temp;
    x_white = (int)(temp[0]) - 97;
    y_white = (int)(temp[1]) - 49;

    int ways[8][8];
    for (int i = 0; i < 8; i++){
        ways[i][7] = 1;
    }
    for (int i = 7; i > y_white; i--){
        for (int j = 0; j < 8; j++){
            ways[j][i - 1] = ways[j][i];
        }
        for (int k = 0; k < n; k++){
            if (y[k] == i){
                ways[x[k]][i - 1] -= ways[x[k]][i];
                if ((x[k] - 1 >= 0) & (x[k] - 1 <= 7)){
                    ways[x[k] - 1][i - 1] += ways[x[k]][i];
                }
                if ((x[k] + 1 >= 0) & (x[k] + 1 <= 7)){
                    ways[x[k] + 1][i - 1] += ways[x[k]][i];
                }
            }
        }
    }
    std::cout << ways[x_white][y_white];
    return 0;
}
