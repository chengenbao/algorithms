// Copyright @ 2019 chengenbao

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

namespace algorithm {

class Generator {
 public:
  Generator(size_t min, size_t max)
      : min_(min), max_(max >= min ? max : min) {
  }

  // Generate a list of data, the first one is the media,
  // The remaining is the sample data
  std::vector<int> Generate() {
    std::vector<int> data;
    if (max_ > min_) {
      std::srand(time(NULL));

      int len = min_ + std::rand() % (max_ - min_);
      if (len == 0) {
        return data;
      }

      data.resize(len + 1);

      // generate media number
      int media = std::rand();
      data[0] = media;

      int i = 1;
      int m = len / 2 - 1;
      if (len % 2 == 1) {
        ++m;
      }

      for (; i <= m; ++i) {
        data[i] = std::rand() % (media + 1);
      }

      data[i++] = media;

      for (; i <= len; ++i) {
        data[i] = media + std::rand();
        if (data[i] < media) {
          data[i] = media;
        }
      }

      // shuffle the data
      for (i = 1; i <= len - 1; ++i) {
        // choose j from [i, len] and swap (i, j)
        int j = i + std::rand() % (len - i + 1);
        std::swap(data[i], data[j]);
      }
    }

    return data;
  }

 private:
  size_t min_;
  size_t max_;
};

};  // namespace algorithm

#endif  // GENERATOR_H_
