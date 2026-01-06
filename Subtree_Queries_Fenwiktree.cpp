// https://cses.fi/problemset/task/1137
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> edges;
vector<int> w;
vector<int> tin;
vector<int> tout;
vector<int> flat;
vector<ll> ft;

int n;

int step = 0;
void dfs(int node, int parent) {
  step++;
  tin[node] = step;
  flat[step] = w[node];
  for (auto e : edges[node]) {
    if (e != parent) {
      dfs(e, node);
    }
  }
  tout[node] = step;
}

void update(int node, int x) {
  for (int i = node; i < n; i += (i & -i)) {
    ft[i] += x;
  }
}

ll query(int node) {
  ll sum = 0;
  for (int i = node; i >= 1; i -= (i & -i)) {
    sum += ft[i];
  }
  return sum;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int q;
  cin >> n >> q;

  edges.assign(n + 1, {});
  w.assign(n + 1, 0);
  tin.assign(n + 1, 0);
  tout.assign(n + 1, 0);
  flat.assign(n + 1, 0);
  ft.assign(n + 10, 0);

  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
  }

  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  dfs(1, 1);

  for (int i = 1; i <= n; ++i) {
    update(i, flat[i]);
  }

  for (int i = 0; i < q; ++i) {
    int v, s;
    cin >> v >> s;
    if (v == 2) {
      ll res = query(tout[s]) - query(tin[s] - 1);
      cout << res << "\n";
    } else {
      int x;
      cin >> x;
      update(tin[s], x - flat[tin[s]]);
      flat[tin[s]] = x;
    }
  }
}
