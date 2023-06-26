#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000 // Increased number of subintervals
#define PERTURBATION_RANGE 0.1 // Range of random perturbation
#define NUM_ITERATIONS 100 // Number of iterations
#define DT 0.01 // Time step

#define INITIAL_X 1.2 // Initial value of x
#define INITIAL_Y 3.1 // Initial value of y

#define PARAM_A 1.0 // Brusselator parameter A
#define PARAM_B 3.0 // Brusselator parameter B
#define PARAM_C 1.0 // Brusselator parameter C
#define PARAM_D 1.0 // Brusselator parameter D

typedef struct {
    double A;
    double B;
    double C;
    double D;
} Parameters;

double f(double x, double y, Parameters params) {
    return params.A - (params.B + 1) * x + params.C * x * x * y;
}

double g(double x, double y, Parameters params) {
    return params.B * x - params.C * x * x * y;
}

double integrate(double a, double b, double y0, Parameters params) {
    double h = (b - a) / N;
    double sum = f(a, y0, params) + f(b, y0, params); // Endpoint values

    for (int i = 1; i < N; i += 2) {
        double x = a + i * h;
        sum += 4.0 * f(x, y0, params); // Coefficients for odd terms
    }

    for (int i = 2; i < N - 1; i += 2) {
        double x = a + i * h;
        sum += 2.0 * f(x, y0, params); // Coefficients for even terms
    }

    sum *= h / 3.0;

    return sum;
}

int main() {
    srand(time(NULL));

    double x0 = INITIAL_X;
    double y0 = INITIAL_Y;
    double t = 0.0;

    Parameters params = { PARAM_A, PARAM_B, PARAM_C, PARAM_D };

    for (int i = 0; i < NUM_ITERATIONS; i++) {
        double perturbationA = (2 * ((double)rand() / RAND_MAX) - 1) * PERTURBATION_RANGE;
        double perturbationB = (2 * ((double)rand() / RAND_MAX) - 1) * PERTURBATION_RANGE;
        double perturbationC = (2 * ((double)rand() / RAND_MAX) - 1) * PERTURBATION_RANGE;

        params.A += perturbationA;
        params.B += perturbationB;
        params.C += perturbationC;

        double perturbation = (2 * ((double)rand() / RAND_MAX) - 1) * PERTURBATION_RANGE;
        double x1 = x0 + DT * integrate(0, 1, y0, params) + perturbation;

        perturbation = (2 * ((double)rand() / RAND_MAX) - 1) * PERTURBATION_RANGE;
        double y1 = y0 + DT * integrate(0, 1, x1, params) + perturbation;

        x0 = x1;
        y0 = y1;
        t += DT;

        printf("t = %.2f, x = %.6f, y = %.6f\n", t, x0, y0);
    }

    return 0;
}
