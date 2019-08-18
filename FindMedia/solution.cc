// Copyright @ 2019 chengenbao

#include "solution.h"

#include <iostream>
#include <functional>

#include "heap.h"

namespace algorithm {

const size_t kHeapSize = 512;

int Solution::FindMedia(RepeatableStream<int>* stream) {
  stream->Rewind();

  int partition = 0;
  if (!stream->Read(&partition)) {
    return -1;
  }

  return FindMedia(stream, partition);
}

int Solution::FindMediaBetter(RepeatableStream<int> *stream) {
  stream->Rewind();

  int min = 0;
  int max = 0;
  if (!stream->Read(&min)) {
    return -1;
  }
  max = min;

  int value = 0;
  while (stream->Read(&value)) {
    if (value < min) {
      min = value;
    } else if (value > max) {
      max = value;
    }
  }

  return FindMedia(stream, min, max);
}

int Solution::FindMedia(RepeatableStream<int>* stream, int min, int max) {
  if (min > max) {
    return -1;
  }

  if (min == max) {
    return min;
  }

  int partition = min / 2 + max / 2;
  size_t stream_size = 0;
  size_t partition_num = 0;
  size_t position = 0;  // number lower than partition

  stream->Rewind();
  int value = 0;
  while (stream->Read(&value)) {
    ++stream_size;
    if (value < partition) {
      ++position;
    } else if (value == partition) {
      ++partition_num;
    }
  }

  size_t m = stream_size / 2;
  if (stream_size % 2 == 1) {
    ++m;
  }

  if (m > position && m <= position + partition_num) {
    return partition;
  }

  if (m <= position) {
    return FindMedia(stream, min, partition - 1);
  }

  return FindMedia(stream, partition + 1, max);
}

int Solution::FindMedia(RepeatableStream<int>* stream, int partition) {
  stream->Rewind();

  size_t stream_size = 0;
  size_t partition_num = 0;
  size_t position = 0;  // number lower than partition

  Heap<int> low_heap;
  Heap<int, std::greater<int> > up_heap;

  int value = 0;
  while (stream->Read(&value)) {
    ++stream_size;
    if (value < partition) {
      if (low_heap.size() < kHeapSize) {
        low_heap.Add(value);
        if (low_heap.size() == kHeapSize) {
          low_heap.Build();
        }
      } else if (low_heap.Top() < value) {
        low_heap.Top() = value;
        low_heap.Adjust(0);
      }
      ++position;
    } else if (value > partition) {
      if (up_heap.size() < kHeapSize) {
        up_heap.Add(value);
        if (up_heap.size() == kHeapSize) {
          up_heap.Build();
        }
      } else if (up_heap.Top() > value) {
        up_heap.Top() = value;
        up_heap.Adjust(0);
      }
    } else {
      ++partition_num;
    }
  }

  size_t m = stream_size / 2;
  if (stream_size % 2 == 1) {
    ++m;
  }

  if (m > position && m <= position + partition_num) {
    return partition;
  }

  if (m <= position - low_heap.size()) {
    return FindMedia(stream, low_heap.Top());
  }

  if (m > position + partition_num + up_heap.size()) {
    return FindMedia(stream, up_heap.Top());
  }

  // In low heap range
  if (m <= position && m > position - low_heap.size()) {
    size_t gap = low_heap.size() - position + m - 1;
    while (gap--) {
      low_heap.Pop();
    }

    return low_heap.Top();
  }

  // In up heap range
  size_t gap = up_heap.size() + position + partition_num - m;
  while (gap--) {
    up_heap.Pop();
  }
  return up_heap.Top();
}

}  // namespace algorithm
