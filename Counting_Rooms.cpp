#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        arr[i] = s;
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    auto bfs = [&](int i, int j, auto self) -> void {
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && y >= 0 && x < n && y < m && arr[x][y] == '.' && !vis[x][y]) self(x, y, self);
        }
        };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '.' && !vis[i][j]) ans++, (bfs(i, j, bfs));
        }
    }
    cout << ans;

}