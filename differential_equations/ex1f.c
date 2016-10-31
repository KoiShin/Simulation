#include <stdio.h>
#include <math.h>

float f(float t, float q) {
    float r = 2000;
    float c = pow(10, -6);
    float v = 10;

    return (v - q / c) / r;
}

void euler(float x0, float y0, float h) {
    int i;
    float x_now = x0;
    float y_now = y0;
    float x_next, y_next;

    printf("h  = %f\n", h);
    for (i = 0; i <= 2; i++) {
        printf("x%d = %f\n",   i, x_now);
        printf("y%d = %f\n\n", i, y_now);

        x_next = x_now + h;
        y_next = y_now + h * f(x_now, y_now);

        x_now = x_next;
        y_now = y_next;
    }
}

int main(void) {
    euler(0, 0, 0.1);
    return 0;
}
