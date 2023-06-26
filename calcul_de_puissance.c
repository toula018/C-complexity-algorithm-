#include <stdio.h>
#include <time.h>

long long int expoPower1(long long int n, long long int p, int* count) {
    (*count)++;
    if (p == 0) {
        return 1;
    } else {
        if (p % 2 == 0) {
            return expoPower1(n*n, p/2, count);
        } else {
            return n*expoPower1(n*n, (p-1)/2, count);
        }
    }
}

long long int expoPower2(long long int n, long long int p, int* count) {
    (*count)++;
    if (p == 0) {
        return 1;
    } else {
        if (p % 2 == 0) {
            long long int r=expoPower2(n,p/2,count);
            return r*r;
        } else {
            long long int r=expoPower2(n,(p-1)/2,count);
            return n*r*r;
        }
    }
}

long long int classicPower(long long int n, long long int p, int* count) {
    long long int result = 1;
    for (int i = 0; i < p; i++) {
        (*count)++;
        result *= n;
    }
    return result;
}

int main() {
    long long int  n,p;
    printf("Entrez la valeur de n : ");
    scanf("%lld", &n);
    printf("Entrez la valeur de p : ");
    scanf("%lld", &p);

    int count = 0;
    clock_t start_time = clock();
    long long int result = expoPower1(n, p, &count);
    clock_t end_time = clock();
    double time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("%lld^%lld = %lld (exponentielle recursive) avec %d comparaisons en %f secondes\n", n, p, result, count, time_taken);

    count = 0;
    start_time = clock();
    result = expoPower2(n, p, &count);
    end_time = clock();
    time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("%lld^%lld = %lld (exponentielle recursive avec optimisation) avec %d comparaisons en %f secondes\n", n, p, result, count, time_taken);

    count = 0;
    start_time = clock();
    result = classicPower(n, p, &count);
    end_time = clock();
    time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("%lld^%lld = %lld (classique) avec %d comparaisons en %f secondes\n", n, p, result, count, time_taken);

    return 0;
}
