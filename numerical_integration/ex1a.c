#include <stdio.h>
#include <math.h>

float f(float x) {
    return 4.0 / (1 + x * x);
}

float g(float x) {
    return 1.0 / cos(x);
}

float integrate(float start, float end, float n) {
    float sum = 0;
    float h = (end - start) / n;
    float j = start + h;

    sum += g(start);
    for (; j <= end - h; j += h) {
        sum += 2 * g(j);
    }
    sum += g(end);

    return h / 2.0 * sum;
}

int main(void) {
    // printf("%f\n", integrate(0.0, 1.0, 32));
    printf("%f\n", integrate(0.0, M_PI / 6.0, 32));
    return 0;
}
