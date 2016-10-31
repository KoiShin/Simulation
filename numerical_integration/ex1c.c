#include <stdio.h>
#include <math.h>

float f(float x) {
    return 4.0 / (1 + x * x);
}

float g(float x) {
    return 1.0 - cos(x);
}

float s_n(float start, float end, float n) {
    int i;
    float result = 0;
    float a, h;

    if (n == 0) return 1;
    h = (end - start) / n;
    a = start;

    result += s_n(start, end, n / 2) / 2;
    for (i = 1; i < n; i += 2) {
        result += h * f(a + i * h);
    }

    return result;
}

int main(void) {
    printf("%f\n", s_n(0.0, 1.0, 1024));
    // printf("%f\n", s_n(0.0, M_PI / 2.0, 1024));
    return 0;
}
