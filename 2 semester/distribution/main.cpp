#include <iostream>
#include <cmath>


float sum_recursive(float const psi[], float const pdf[], unsigned size) {
    float sum = 0.f;
    int size_1 = 0;
    if (size == 1) {
        sum = psi[0] * pdf[0];
        return sum;
    }
    if (size % 2 == 0) {
        size_1 = size / 2;
    }
    else {
        size_1 = size / 2 + 1;
    }
    float* psi_1 = new float[size / 2];
    float* pdf_1 = new float[size / 2];
    float* psi_2 = new float[size_1];
    float* pdf_2 = new float[size_1];
    for (int idx = 0; idx < size_1; idx++) {
        psi_2[idx] = psi[idx + size / 2];
        pdf_2[idx] = pdf[idx + size / 2];
    }
    for (int idx = 0; idx < size / 2; idx++) {
        psi_1[idx] = psi[idx];
        pdf_1[idx] = pdf[idx];
    }
    sum = sum_recursive(psi_1, pdf_1, size / 2) + sum_recursive(psi_2, pdf_2, size_1);
    delete[] psi_1;
    delete[] pdf_1;
    delete[] psi_2;
    delete[] pdf_2;
    return sum;
}


float mean_rec(float const psi[], float const pdf[], float const dv, unsigned size) {
    float sum = 0.f;
    return sum_recursive(psi, pdf, size) * dv;
}

float sum_neigh(float const psi[], float const pdf[], unsigned size) {
    float* psipdf = new float[size];
    for (int idx = 0; idx < size; idx++) {
        psipdf[idx] = psi[idx] * pdf[idx];
    }
    for (int step = 1; step < size; step = step * 2) {
        for (int idx = 0; idx < size; idx += 2 * step) {
            if (idx + step > size - 1) {
                continue;
            }
            psipdf[idx] = psipdf[idx] + psipdf[idx + step];
        }
    }
    float a = psipdf[0];
    delete[] psipdf;
    return a;
}

float mean_of_neigh(float const psi[], float const pdf[], float const dv, unsigned size) {
    return sum_neigh(psi, pdf, size) * dv;
}

float sum_kahan(float const psi[], float const pdf[], unsigned size) {
    float* psipdf = new float[size];
    float sum = 0.f;
    float t = 0.f;
    for (int idx = 0; idx < size; idx++) {
        psipdf[idx] = psi[idx] * pdf[idx];
    }
    for (int idx = 0; idx < size; idx++) {
        float y = psipdf[idx] - t;
        float z = sum + y;
        t = (z - sum) - y;
        sum = z;
    }
    delete[] psipdf;
    return sum;
}

float kahan_mean(float const psi[], float const pdf[], float const dv, unsigned size) {
    return sum_kahan(psi, pdf, size) * dv;
}

void split(float const x, float& x_l, float& x_h) {
    auto c = static_cast<float>((1ul << 11) + 1ul);
    x_h = (c * x) + (x - (c * x));
    x_l = x - x_h;
}

void two_mult(float const a, float const b, float& s, float& t) {
    float a_high = 0, a_low = 0, b_high = 0, b_low = 0;
    split(a, a_high, a_low);
    split(b, b_high, b_low);
    s = a * b;
    t = -s + a_high * a_low;
    t += a_high * b_low;
    t += a_low * b_high;
    t += a_low * b_low;
}

void two_sum(float const a, float const b, float& s, float& t) {
    s = a + b;
    auto z = s - a;
    t = (a - (s - z)) + (b - z);
}

float mean_fma(float const psi[], float const pdf[], float const dv, unsigned size) {
    float sum = 0.f;
    float t = 0.f;
    float s = 0.f;
    for (int idx = 0; idx < size; idx++) {
        two_mult(psi[idx], pdf[idx], s, t);
        two_sum(sum, s, sum, t);
    }
    return sum * dv;
}

float mean_double(float const psi[], float const pdf[], float const dv, unsigned size) {
    double sum = 0.f;
    for (int idx = 0; idx < size; idx++) {
        sum += (double)psi[idx] * (double)pdf[idx];
    }
    return (float)(sum * (double)dv);
}

void func_defenition(float psi[], float pdf[], float T, const int size) {
    float const f_pi = 3.14159265359f;
    for (int i = 0; i < size; i++) {
        psi[i] = abs((float)i/25.f - (float)size/50.f);
        pdf[i] = 1 / (sqrt(f_pi * T)) * exp(-((float)i/25.f - (float)size / 50.f) * (i/25.0 - (float)size / 50.f) / T);
    }
}

int main(){
    const int size = 10000;
    float dv = 0.04;
    float* psi = new float[size];
    float* pdf = new float[size];
    std::cout.precision(15);
    for (int T = 2; T < 400; T += 4) {
        func_defenition(psi, pdf, (float)T, size);
        std::cout << mean_of_neigh(psi, pdf, dv, size) << " ";
        std::cout << kahan_mean(psi, pdf, dv, size) << " ";
        std::cout << mean_rec(psi, pdf, dv, size) << " ";
        std::cout << mean_fma(psi, pdf, dv, size) << " ";
        std::cout << mean_double(psi, pdf, dv, size) << '\n';
    }
    delete[] psi;
    delete[] pdf;
    return 0;
}

