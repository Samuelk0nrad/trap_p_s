// https://cses.fi/problemset/task/1135
#include <bits/stdc++.h>
#include <vector>

using namespace std;
const int MAXP = 18;
int n;
vector<vector<int>> al;
vector<vector<int>> per;
vector<int> depth;

void dfs(int node, int perent) {
  per[0][node] = perent;
  depth[node] = depth[perent] + 1;
  for (auto anc : al[node]) {
    if (anc == perent)
      continue;
    dfs(anc, node);
  }
}

int lca(int a, int b) {
  if (depth[a] < depth[b]) {
    int tmp = a;
    a = b;
    b = tmp;
  }
  int k = depth[a] - depth[b];
  for (int i = MAXP; i >= 0; --i) {
    if (k >= (1 << i)) {
      a = per[i][a];
      k -= (1 << i);
    }
  }
  if (a == b) {
    return a;
  }
  for (int i = MAXP; i >= 0; --i) {
    if (per[i][a] != per[i][b]) {
      a = per[i][a];
      b = per[i][b];
    }
  }
  return per[0][a];
}

int main() {
  int q;
  cin >> n >> q;
  al.assign(n + 2, {});
  per.assign(MAXP + 1, vector<int>(n + 2));
  depth.assign(n + 2, 0);

  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    al[a].push_back(b);
    al[b].push_back(a);
  }

  dfs(1, 1);

  for (int p = 1; p <= MAXP; ++p) {
    for (int i = 1; i <= n; ++i) {
      per[p][i] = per[p - 1][per[p - 1][i]];
    }
  }

  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    int l = lca(a, b);
    int res = depth[a] + depth[b] - (depth[l] * 2);
    cout << res << "\n";
  }
}
