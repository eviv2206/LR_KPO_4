#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const int n = 3;
    int a[n][n];
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = rand() % 9 + 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
    int arrSum[n];
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += a[j][i];
        }
        arrSum[i] = sum;
        if (i > 0) {
            int k = i - 1;
            int curr = i;
            while (k >= 0 && arrSum[curr] < arrSum[k]) {
                for (int j = 0; j < n; ++j) {
                    int temp = a[j][curr];
                    a[j][curr] = a[j][k];
                    a[j][k] = temp;
                }
                int temp = arrSum[curr];
                arrSum[curr] = arrSum[k];
                arrSum[k] = temp;
                curr = k;
                k--;
            }
        }
    }

    printf("\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", arrSum[i]);
    }
}

