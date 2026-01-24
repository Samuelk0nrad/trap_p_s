#include <bits/stdc++.h>
#define ll long long

using namespace std;

char board[8][8] = {{'.'}};

bool col[8] = {false};
bool rdia[16] = {false};
bool ldia[16] = {false};

ll solve(int num, int rlast, int clast) {
  if (num == 8) {
    return 1;
  }
  int i = rlast + 1;
  ll res = 0;
  for (int j = 0; j < 8; ++j) {
    if (i == rlast && j == 0) {
      j = clast;
    }
    if (board[i][j] == '*')
      continue;
    if (!(col[j] || rdia[j + i] || ldia[7 + i - j])) {
      col[j] = true;
      rdia[j + i] = true;
      ldia[7 + i - j] = true;
      res += solve(num + 1, i, j);
      col[j] = false;
      rdia[j + i] = false;
      ldia[7 + i - j] = false;
    }
  }
  return res;
}

int main() {
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      cin >> board[i][j];
    }
  }

  int res = solve(0, -1, 0);

  cout << res;
}
