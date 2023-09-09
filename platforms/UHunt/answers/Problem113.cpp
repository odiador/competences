#include<cstdio>
#include<cmath>


int main() {
    double n, p;
    while (scanf("%lf %lf", &n, &p) != -1)
        printf("%.0lf\n", pow(p, 1 / n));
    return 0;
}