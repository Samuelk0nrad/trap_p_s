#include <bits/stdc++.h>
#include <ios>

using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < (1 << n); ++i) {
    int res = i ^ (i >> 1);
    bitset<16> bits(res);
    string bs = bits.to_string().substr(16 - n, n);
    cout << bs << "\n";
  }
}
