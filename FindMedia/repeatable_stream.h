// Copyright @ 2019 chengenbao

#ifndef REPEATABLE_STREAM_H_
#define REPEATABLE_STREAM_H_

#include <vector>

namespace algorithm {

template <typename T>
class RepeatableStream {
 public:
  RepeatableStream(): pos_(0) {}

  typedef typename std::vector<T>::const_iterator Iterator;
  void Feed(Iterator begin, Iterator end) {
    pos_ = 0;
    data_.assign(begin, end);
  }

  void Feed(const T& item) {
    data_.push_back(item);
  }

  bool Read(T* value) {
    if (pos_ >= data_.size()) {
      return false;
    }

    *value = data_[pos_++];
    return true;
  }

  void Rewind() {
    pos_ = 0;
  }

 private:
  size_t pos_;
  std::vector<T> data_;
};

}  // namespace algorithm

#endif  // REPEATABLE_STREAM_H_
