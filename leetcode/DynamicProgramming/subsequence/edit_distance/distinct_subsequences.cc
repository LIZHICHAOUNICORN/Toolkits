#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "third_party/gflags/include/gflags.h"
#include "third_party/glog/include/logging.h"

using std::vector;
using std::string;
using std::max;

class Solution {
 public:
  int numDistinct(string s, string t) {
    vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1));
    for (int i = 0; i < s.size(); i++) dp[i][0] = 1;
    for (int j = 1; j < t.size(); j++) dp[0][j] = 0;
    for (int i = 1; i <= s.size(); i++) {
      for (int j = 1; j <= t.size(); j++) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[s.size()][t.size()];
  }
};

int main(int argc, char* argv[]) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, false);
  Solution solu;
  auto ret = solu.numDistinct("abc", "ahbgdc");
  LOG(INFO) << ret;
  return 0;
}