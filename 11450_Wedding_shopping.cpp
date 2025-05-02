/* UVa 11450 - Wedding Shopping - Bottom Up */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, j, k, TC, M, C;
    int price[25][25]; 
    bool reachable[25][210];
    cin >> TC;
    while (TC--) {
        cin >> M >> C;
        for (i = 0; i < C; i++) {
            cin >> price[i][0];
            for (j = 1; j <= price[i][0]; j++) 
                cin >> price[i][j];
        }

        memset(reachable, false, sizeof reachable);         // clear everything
        
        for (i = 1; i <= price[0][0]; i++)       // initial values (base cases)
            if (M - price[0][i] >= 0)      // to prevent array index out of bound
                reachable[0][M - price[0][i]] = true;  // using first garment g = 0

        for (i = 1; i < C; i++)                   // for each remaining garment
            for (j = 0; j < M; j++) if (reachable[i - 1][j]) // a reachable state
                for (k = 1; k <= price[i][0]; k++) if (j - price[i][k] >= 0)
                    reachable[i][j - price[i][k]] = true;   // also a reachable state

        for (j = 0; j <= M && !reachable[C - 1][j]; j++); // the answer in here

        if (j == M + 1) cout << "no solution\n";         // last row has on bit
        else cout << (M-j) << endl;
    }
} 