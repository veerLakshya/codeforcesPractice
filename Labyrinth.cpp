#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m, sx = -1, sy = -1, dx = -1, dy = -1;
    cin >> n >> m;

    vector<vector<char> > v(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            v[i][j] = s[j];
            if (v[i][j] == 'A') {
                sx = i;
                sy = j;
            }
            if (v[i][j] == 'B') {
                dx = i;
                dy = j;
            }
        }
    }

    queue <pair<int, int>> q;
    q.push({ sx,sy });
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> prev(n, vector<int>(m));

    vis[sx][sy] = 1;
    int dirx[] = { 0,0,-1,1 };
    int diry[] = { -1,1,0,0 };
    string dir = "LRUD";
    while (q.size()) {
        auto node = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int x = node.first + dirx[k];
            int y = node.second + diry[k];
            if (x >= 0 && x < n && y >= 0 && y < m && v[x][y] != '#' && !vis[x][y]) {
                vis[x][y] = 1;
                q.push({ x, y });
                prev[x][y] = k;
            }
        }
    }
    if (vis[dx][dy] == 1) {
        cout << "YES" << endl;
        string ans;
        while (dx != sx || dy != sy) {
            int p = prev[dx][dy];
            ans += dir[p];
            dx -= dirx[p];
            dy -= diry[p];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        cout << ans << endl;
    }
    else cout << "NO";
}

