// Copyright @ 2019 chengenbao

#include "generator.h"

#include <algorithm>

#include "gtest/gtest.h"

namespace algorithm {

TEST(GeneratorTest, Generate) {
  size_t max = 1 << 20;
  Generator generator(0, max);

  for (int i = 0; i < 20; ++i) {
    auto data = generator.Generate();
    ASSERT_GE(data.size(), 0);
    ASSERT_LE(data.size(), max + 1);

    if (!data.empty()) {
      size_t sz = data.size();
      ASSERT_GE(sz, 2);

      int m = (sz - 1) / 2;
      if (sz % 2 == 0) {
        ++m;
      }

      std::sort(data.begin() + 1, data.end());
      ASSERT_EQ(data[0], data[m]);
    }
  }
}

}  // namespace algorithm
