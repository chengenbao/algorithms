// Copyright @ 2019 chengenbao

#include <cstdlib>
#include <algorithm>

#include "gtest/gtest.h"

#include "heap.h"

namespace algorithm {

TEST(HeapTest, Add) {
  Heap<int> heap;
  heap.Add(14);
  heap.Add(3);
  heap.Add(5);

  ASSERT_EQ(3u, heap.size());
}

TEST(HeapTest, Build) {
  Heap<int> heap;

  heap.Add(11);
  heap.Add(3);
  heap.Add(5);
  heap.Add(16);
  heap.Add(9);
  heap.Add(8);
  heap.Add(7);
  heap.Add(1);

  heap.Build();

  ASSERT_EQ(1, heap.Pop());
  ASSERT_EQ(3, heap.Pop());
  ASSERT_EQ(5, heap.Pop());
  ASSERT_EQ(7, heap.Pop());
  ASSERT_EQ(8, heap.Pop());
  ASSERT_EQ(9, heap.Pop());
  ASSERT_EQ(11, heap.Pop());
  ASSERT_EQ(16, heap.Pop());

  ASSERT_EQ(0u, heap.size());
}

TEST(HeapTest, Pop) {
  std::vector<int> vec;
  Heap<int> heap;

  for (int i = 0; i < 100; ++i) {
    vec.push_back(std::rand());
    heap.Add(vec.back());
  }

  std::sort(vec.begin(), vec.end());
  heap.Build();

  for (auto v : vec) {
    ASSERT_EQ(v, heap.Pop());
  }

  ASSERT_EQ(0u, heap.size());
}

TEST(HeapTest, Max) {
  std::vector<int> vec;
  Heap<int, std::greater<int> > heap;

  for (int i = 0; i < 100; ++i) {
    vec.push_back(std::rand());
    heap.Add(vec.back());
  }

  std::sort(vec.begin(), vec.end(), [] (int a, int b) { return a > b; });
  heap.Build();

  for (auto v : vec) {
    ASSERT_EQ(v, heap.Pop());
  }

  ASSERT_EQ(0u, heap.size());
}

}  // namespace algorithm
