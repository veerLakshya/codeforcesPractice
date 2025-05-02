#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    auto bfs = [&](int i) -> int {
        vector<int> vis(n, 0), dis(n, 0);
        queue<pair<int, int>> q;
        q.push({ i, -1 });
        vis[i] = 1;

        while (!q.empty()) {
            auto x = q.front();
            int cur = x.first, parent = x.second;
            q.pop();

            for (int nbr = 0; nbr < n; nbr++) {
                if (a[cur][nbr] == 1) {
                    if (!vis[nbr]) {
                        vis[nbr] = 1;
                        dis[nbr] = dis[cur] + 1;
                        q.push({ nbr, cur });
                    }
                    else if (nbr != parent) return dis[cur] + 1;
                }
            }
        }
        return -1;
        };

    for (int i = 0; i < n; i++) {
        if (a[i][i] == 1) {
            cout << "1" << endl;
            continue;
        }
        else {
            int a = bfs(i);
            if (a != -1) cout << a << endl;
            else cout << "NO WAY\n";
        }
    }
}
