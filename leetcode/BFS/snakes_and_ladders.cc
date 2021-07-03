// Author: Zhichao Li
// Time:   2021-06-27

#include <cassert>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <queue>

#include "glog/logging.h"
#include "gflags/gflags.h"

using std::map;
using std::set;
using std::vector;
using std::queue;
using std::string;
using std::pair;
using std::unordered_set;
using std::find;

// Timeout

class Solution {
    pair<int, int> id2rc(int id, int n) {
        int r = (id - 1) / n, c = (id - 1) % n;
        if (r % 2 == 1) {
            c = n - 1 - c;
        }
        return {n - 1 - r, c};
    }

public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        vector<int> vis(n * n + 1);
        queue<pair<int, int>> q;
        q.emplace(1, 0);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (int i = 1; i <= 6; ++i) {
                int nxt = p.first + i;
                if (nxt > n * n) { // 超出边界
                    break;
                }
                auto rc = id2rc(nxt, n); // 得到下一步的行列
                if (board[rc.first][rc.second] > 0) { // 存在蛇或梯子
                    nxt = board[rc.first][rc.second];
                }
                if (nxt == n * n) { // 到达终点
                    return p.second + 1;
                }
                if (!vis[nxt]) {
                    vis[nxt] = true;
                    q.emplace(nxt, p.second + 1); // 扩展新状态
                }
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[]) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, false);
  Solution solu;
  return 0;
}