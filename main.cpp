#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

constexpr auto kMod = ll{1000000};
vl dp;
string s;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> s;
  if (s[0] == '0') {
    cout << 0;
    return 0;
  }

  dp = vl(s.length() + 1, 0);
  dp[0] = 1;
  dp[1] = 1;

  for (auto i = 2; i <= s.length(); ++i) {
    if (s[i - 1] != '0') dp[i] = dp[i - 1] % kMod;

    const auto& two = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
    if (10 <= two && two <= 26) {
      dp[i] += dp[i - 2];
      dp[i] %= kMod;
    }
  }

  cout << dp[s.length()];

  return 0;
}