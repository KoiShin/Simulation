#include <stdio.h>

float f(float x, float y) {
    return (2 * y) / (1 + x);
}

void heun(float x0, float y0, float h) {
    int i;
    float x_now = x0;
    float y_now = y0;
    float k1, k2, k3, k4;
    float x_next, y_next;

    printf("h = %f\n", h);
    for (i = 0; i <= 1; i++) {
        printf("x%d = %f\n", i, x_now);
        printf("y%d = %f\n\n", i, y_now);

        x_next = x_now + h;
        k1 = h * f(x_now, y_now);
        k2 = h * f(x_now + h / 2, y_now + k1 / 2);
        k3 = h * f(x_now + h / 2, y_now + k2 / 2);
        k4 = h * f(x_now + h, y_now + k3);
        y_next = y_now + (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        x_now = x_next;
        y_now = y_next;
    }
}

int main(void) {
    heun(0, 0.5, 0.5);
    return 0;
}
