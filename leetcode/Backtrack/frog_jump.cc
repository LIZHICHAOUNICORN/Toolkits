#include <algorithm>
#include <climits>
#include <functional>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include <gflags/gflags.h>
#include <glog/logging.h>

using std::vector;
using std::stack;
using std::string;
using std::function;
using namespace std;

// Problem: https://leetcode-cn.com/problems/frog-jump/

class Solution {
 public:
  vector<unordered_map<int, int>> rec;

  bool dfs(vector<int>& stones, int i, int lastDis) {
    if (i == stones.size() - 1) {
      return true;
    }
    if (rec[i].count(lastDis)) {
      return rec[i][lastDis];
    }
    for (int curDis = lastDis - 1; curDis <= lastDis + 1; curDis++) {
      if (curDis > 0) {
        int j = lower_bound(stones.begin(), stones.end(), curDis + stones[i]) -
                stones.begin();
        if (j != stones.size() && stones[j] == curDis + stones[i] &&
            dfs(stones, j, curDis)) {
          return rec[i][lastDis] = true;
        }
      }
    }
    return rec[i][lastDis] = false;
  }

  bool canCross(vector<int>& stones) {
    int n = stones.size();
    rec.resize(n);
    return dfs(stones, 0, 0);
  }
};

int main(int argc, char* argv[]) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, false);

  vector<int> envelopes({0, 1, 3, 5, 6, 8, 12, 17});

  Solution solu;
  auto ret = solu.canCross(envelopes);
  LOG(INFO) << ret;
  return 0;
}
