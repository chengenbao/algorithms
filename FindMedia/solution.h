// Copyright @ 2019 chengenbao

#ifndef SOLUTION_H_
#define SOLUTION_H_

#include "repeatable_stream.h"

namespace algorithm {

class Solution {
 public:
  static int FindMedia(RepeatableStream<int>* stream);

  static int FindMediaBetter(RepeatableStream<int>* stream);

 private:
  static int FindMedia(RepeatableStream<int>* stream, int partition);
  static int FindMedia(RepeatableStream<int>* stream, int min, int max);
};

}  // namespace algorithm

#endif  // SOLUTION_H_
