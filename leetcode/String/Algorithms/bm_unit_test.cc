#include "leetcode/String/Algorithms/boyer_moore.h"

#include "third_party/gflags/include/gflags.h"
#include "third_party/glog/include/logging.h"

DEFINE_string(src, "asdfadsfasdfabcabd", "src string");
DEFINE_string(pattern, "abcabd", "pattern string");

int main(int argc, char* argv[]) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, false);

  base::BM bm;
  int ret = bm.Search(FLAGS_src, FLAGS_pattern);
  LOG(INFO) << "pos: " << ret;
  return 0;
}