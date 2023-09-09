#include <algorithm>
#include <array>
#include <locale>
#include <string>

#include <gflags/gflags.h>
#include <glog/logging.h>

using namespace std;

// Problem: https://leetcode-cn.com/problems/implement-strstr/

// 暴力
class Solution {
 public:
  int strStr(string haystack, string needle) {
    int n = haystack.size(), m = needle.size();
    for (int i = 0; i + m <= n; i++) {
      bool flag = true;
      for (int j = 0; j < m; j++) {
        if (haystack[i + j] != needle[j]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        return i;
      }
    }
    return -1;
  }
};

// KMP
class Solution1 {
 public:
  int strStr(string haystack, string needle) {
    int n = haystack.size(), m = needle.size();
    if (m == 0) {
      return 0;
    }
    vector<int> pi(m);
    for (int i = 1, j = 0; i < m; i++) {
      while (j > 0 && needle[i] != needle[j]) {
        j = pi[j - 1];
      }
      if (needle[i] == needle[j]) {
        j++;
      }
      pi[i] = j;
    }
    for (int i = 0, j = 0; i < n; i++) {
      while (j > 0 && haystack[i] != needle[j]) {
        j = pi[j - 1];
      }
      if (haystack[i] == needle[j]) {
        j++;
      }
      if (j == m) {
        return i - m + 1;
      }
    }
    return -1;
  }
};

int main(int argc, char* argv[]) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, false);

  Solution solu;
  auto ret = solu.strStr("hello", "ll");
  LOG(INFO) << ret;
  return 0;
}
