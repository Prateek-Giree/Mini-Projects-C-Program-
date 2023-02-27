// bisection method for cosx-3x+1
#include <math.h>
#include <stdio.h>

double f(double x)
{
    return cos(x) - 3 * x + 1;
}

int main()
{
    double a = 0.0;
    double b = 1.0;
    double epsilon = 1e-6;
    int max_iterations = 100;
    int iteration = 0;
    double c;

    while (fabs(b - a) > epsilon && iteration < max_iterations)
    {
        c = (a + b) / 2;

        printf("Iteration %d: a = %.6f, b = %.6f, c = %.6f, f(c) = %.6f\n", iteration, a, b, c, f(c));

        if (f(c) == 0)
        {
            break;
        }
        else if (f(c) * f(a) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }

        iteration++;
    }

    if (fabs(b - a) < epsilon)
    {
        printf("The solution is: %.6f\n", c);
    }
    else
    {
        printf("The solution could not be found within the maximum number of iterations.\n");
    }

    return 0;
}