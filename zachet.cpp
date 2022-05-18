#include <iostream>

int det(int a11, int a12, int a21, int a22){
    return (a11 * a22) - (a12 * a21);
}

int main() {
    int i, n;
    std::cin >> n;
    int* coords = new int[6 * n];
    for (i = 0; i < 6 * n; i++){
        std::cin >> coords[i];
    }
    int x1 = coords[0], y1 = coords[1], z1 = coords[2];
    int x2, y2, z2;
    int x3, y3, z3;
    int A, B, C, D;
    bool collinear = true; //нет 3х различных точек не на одной прямой
    bool res = true;
    int j = 2 * n;
    for (i = 1; i < 2 * n; i++){
        if (x1 != coords[3*i] || y1 != coords[3*i+1] || z1 != coords[3*i+2]){
            x2 = coords[3*i];
            y2 = coords[3*i+1];
            z2 = coords[3*i+2];
            j = i + 1;
            break;
        }
    }
    for (i = j; i < 2 * n; i++){
        if ((x1 != coords[3*i] || y1 != coords[3*i+1] || z1 != coords[3*i+2])){
            if ((x2 != coords[3*i] || y2 != coords[3*i+1] || z2 != coords[3*i+2])){
                x3 = coords[3*i];
                y3 = coords[3*i+1];
                z3 = coords[3*i+2];
                A = det(y2-y1, z2-z1, y3-y1, z3-z1);
                B = det(x2-x1, z2-z1, x3-x1, z3-z1);
                C = det(x2-x1, y2-y1, x3-x1, y3-y1);
                D = y1*B - x1*A - z1*C;
                std::cout << i << '-';
                std::cout << A << B << C << D << std::endl;
                if (A*A + B*B + C*C != 0){
                    collinear = false;
                    j = i + 1;
                    break;
                }
            }
        }
    }

    if (!collinear){
        res = true;
        for (i = j; i < 2 * n; i++){
            if (A*coords[3*i] + B*coords[3*i+1] + C*coords[3*i+2] != D){
                res = false;
                break;
            }
        }
    }

    if (res){
        std::cout << "YES";
    } else{
        std::cout << "NO";
    }
    return 0;
}

