// Copyright @ 2019 chengenbao

#include <vector>

#include "gtest/gtest.h"

#include "solution.h"
#include "generator.h"
#include "repeatable_stream.h"

namespace algorithm {

TEST(SolutionTest, FindMedia) {
  RepeatableStream<int> stream;
  ASSERT_EQ(-1, Solution::FindMedia(&stream));
  ASSERT_EQ(-1, Solution::FindMediaBetter(&stream));

  std::vector<int> all_same(1021, 5);
  stream.Feed(all_same.begin(), all_same.end());

  ASSERT_EQ(5, Solution::FindMedia(&stream));
  ASSERT_EQ(5, Solution::FindMediaBetter(&stream));

  Generator generator(0, 1 << 20);
  for (int i = 0; i < 200; ++i) {
    auto data = generator.Generate();
    if (!data.empty()) {
      stream.Feed(data.begin() + 1, data.end());
      ASSERT_EQ(data[0], Solution::FindMedia(&stream));
      ASSERT_EQ(data[0], Solution::FindMediaBetter(&stream));
    }
  }
}

}  // namespace algorithm
