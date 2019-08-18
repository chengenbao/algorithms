// Copyright @ 2019 chengenbao

#include "repeatable_stream.h"

#include "gtest/gtest.h"

#include "generator.h"


namespace algorithm {

TEST(RepeatableStreamTest, All) {
  RepeatableStream<int> stream;
  Generator generator(0, 1<<20);

  for (int i = 0; i < 20; ++i) {
    auto data = generator.Generate();
    stream.Feed(data.begin(), data.end());

    for (int j = 0; j < 3; ++j) {
      stream.Rewind();
      int v2 = 0;
      for (auto v1 : data) {
        ASSERT_TRUE(stream.Read(&v2));
        ASSERT_EQ(v1, v2);
      }
      ASSERT_FALSE(stream.Read(&v2));
    }
  }
}

}  // namespace algorithm
