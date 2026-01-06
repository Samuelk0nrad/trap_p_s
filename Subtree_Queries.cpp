// https://cses.fi/problemset/task/1137
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ll long long

vector<vector<int>> edges;
vector<int> w;
vector<int> tin;
vector<int> tout;
vector<int> flat;
vector<long long> st;

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

void build(int p, int L, int R) {
  if (L == R - 1) {
    st[p] = flat[L];
    return;
  }
  build(2 * p + 1, L, (L + R) / 2);
  build(2 * p + 2, (L + R) / 2, R);
  st[p] = st[2 * p + 1] + st[2 * p + 2];
}

void update(int p, int L, int R, int node, int x) {
  if (L > node || R <= node) {
    return;
  }
  if (L == R - 1) {
    st[p] = x;
    return;
  }
  update(2 * p + 1, L, (L + R) / 2, node, x);
  update(2 * p + 2, (L + R) / 2, R, node, x);
  st[p] = st[2 * p + 1] + st[2 * p + 2];
}

ll query(int p, int L, int R, int i, int j) {
  if (L >= i && R <= j) {
    return st[p];
  }
  if (L >= j || R <= i) {
    return 0;
  }
  return query(2 * p + 1, L, (L + R) / 2, i, j) +
         query(2 * p + 2, (L + R) / 2, R, i, j);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  edges.assign(n + 1, {});
  w.assign(n + 1, 0);
  tin.assign(n + 1, 0);
  tout.assign(n + 1, 0);
  flat.assign(n + 1, 0);
  st.assign(4 * n + 2, 0);

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

  build(0, 1, n + 1);

  for (int i = 0; i < q; ++i) {
    int v, s;
    cin >> v >> s;
    if (v == 2) {
      ll res = query(0, 1, n + 1, tin[s], tout[s] + 1);
      cout << res << "\n";
    } else {
      int x;
      cin >> x;
      update(0, 1, n + 1, tin[s], x);
    }
  }
}
