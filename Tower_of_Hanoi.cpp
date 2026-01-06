#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  int m[17] = {0};

  cout << (1 << n) - 1 << "\n";
  for (int i = 1; i < (1 << n); ++i) {
    int k = i & -i;
    int s = __builtin_ctz(k) + 1;
    if (n % 2 != s % 2) {
      int p = (m[s] % 3) + 1;

      m[s]++;
      cout << p << " " << (m[s] % 3) + 1 << "\n";
    } else {
      int p = 0;
      int cm = m[s] % 3;
      if (cm == 0)
        p = 1;
      else if (cm == 1)
        p = 3;
      else if (cm == 2)
        p = 2;

      int np = 0;
      if (cm == 0)
        np = 3;
      else if (cm == 1)
        np = 2;
      else if (cm == 2)
        np = 1;

      m[s]++;
      cout << p << " " << np << "\n";
    }
  }
  cout << " ";
}
