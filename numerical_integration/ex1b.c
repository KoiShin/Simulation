#include <stdio.h>
#include <math.h>

float f(float x) {
    return 4.0 / (1 + x * x);
}

float g(float x) {
    return sin(x);
}

// float simpson(float start, float end) {
//     float sum = 0;
//     float h = (end - start) / 3;
//     float i = 0;
//
//     sum += f(i);
//     i += h;
//     sum += 4 * f(i);
//     i += h;
//     sum += f(i);
//
//     return h / 3.0 * sum;
// }

float composition_simpson(float start, float end, float n) {
    float sum = 0;
    float h = (end - start) / n;
    float i;

    sum += g(start);
    for (i = h; i <= end - h; i += (2 * h)) {
        sum += 4 * g(i);
    }
    for (i = h + h; i <= end - h - h; i += (2 * h)) {
        sum += 2 * g(i);
    }
    sum += g(end);

    return h / 3.0 * sum;
}

int main(void) {
    printf("%f\n", composition_simpson(0.0, M_PI / 2, 8));
    // printf("%f\n", simpson(0.0, 1.0));
    return 0;
}
