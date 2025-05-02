#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int diameter = 0;
    function <int(int, int)> dfs = [&](int cur, int par)->int {
        int maxi = -1, smaxi = -1;
        for (auto nbr : adj[cur]) {
            if (nbr == par) continue;
            int val = dfs(nbr, cur);
            if (val > maxi) {
                smaxi = maxi;
                maxi = val;
            }
            else if (val > smaxi) smaxi = val;
        }
        diameter = max(diameter, 2 + maxi + smaxi);
        return maxi == -1 ? 0 : maxi + 1;
        };
    dfs(1, 0);
    ll circumfrence = diameter * 3;
    cout << circumfrence;
}