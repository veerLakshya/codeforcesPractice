#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        long long n;
        cin >> n;
        vector <vector<pair<long long, long long>>> edj(n);
        for (long long i = 0; i < n - 1; i++) {
            long long x, y, w;
            cin >> x >> y >> w;
            x--, y--;
            edj[x].push_back({ y,w });
            edj[y].push_back({ x,w });
        }
        long long ans = 0;
        auto dfs = [&](long long node, long long par, auto self)->long long {
            long long cur = 1;
            for (auto i : edj[node]) {
                if (i.first != par) {
                    long long x = self(i.first, node, self);
                    cur += x;
                    ans += (2 * min(x, n - x) * i.second);
                }
            }
            return cur;
            };

        dfs(0, -1, dfs);
        cout << "Case #" << test << ": " << ans << endl;
    }
}