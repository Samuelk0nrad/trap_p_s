// https://judge.yosupo.jp/problem/staticrmq
// sparce table
#include <bits/stdc++.h>
#include <climits>
#include <vector>

using namespace std;
const int MAXP = 20;

int main() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> st(MAXP + 2, vector<int>(n + 2, INT_MAX));

  for (int i = 0; i < n; ++i) {
    cin >> st[0][i];
  }

  for (int p = 1; p < MAXP; ++p) {
    for (int i = 0; i + (1 << (p - 1)) < n; ++i) {
      int f = st[p - 1][i];
      int s = st[p - 1][i + (1 << (p - 1))];
      st[p][i] = min(f, s);
    }
  }

  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    uint k = r - l;
    int p = 31 - __builtin_clz(k);
    int first = st[p][l];
    int ttttt = l + (k - (1 << p));
    int second = st[p][ttttt];
    int res = min(first, second);
    cout << res << "\n";
  }
}
