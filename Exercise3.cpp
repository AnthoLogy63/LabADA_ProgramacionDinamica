#include <cstring>
#include <cstdio>
using namespace std;

int dp[255][305], length[255];

void maxTilingMEMO(int n) {
    if (length[n] > 0) return;
    maxTilingMEMO(n - 1);
    maxTilingMEMO(n - 2);
    for (int j = 1; j <= 300; j++) {
        dp[n][j] += dp[n - 1][j] + dp[n - 2][j] * 2;
        if (dp[n][j] >= 10) {
            dp[n][j + 1] += dp[n][j] / 10;
            dp[n][j] %= 10;
        }
    }
    for (int k = 300; k >= 1; k--) {
        if (dp[n][k] > 0) {
            length[n] = k;
            break;
        }
    }
}

int main() {
    memset(dp, 0, sizeof(dp));
    memset(length, -1, sizeof(length));
    dp[0][1] = 1;
    dp[1][1] = 1;
    length[0] = 1;
    length[1] = 1;
    
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n > 1) {
            maxTilingMEMO(n);
            for (int i = length[n]; i >= 1; i--) {
                printf("%d", dp[n][i]);
            }
            printf("\n");
        } else 
            printf("1\n");
        
    }
    return 0;
}
