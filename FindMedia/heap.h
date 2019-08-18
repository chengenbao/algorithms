// Copyright @ 2019 chengenbao

#ifndef HEAP_H_
#define HEAP_H_

#include <functional>
#include <vector>

namespace algorithm {

// A min-heap implementation, change Comparae function C
// for max-heap
template<typename T, typename C = std::less<T> >
class Heap {
 public:
  void Add(const T& item) {
    data_.push_back(item);
  }

  void Build() {
    for (int i = data_.size() / 2; i > 0; --i) {
      Adjust(i - 1);
    }
  }

  // Justify node i to be min/max heap, 0 based
  void Adjust(int i) {
    T temp = data_[i];
    int n = data_.size();
    while (2 * i + 1 < n) {
      int p = 2 * i + 1;
      if (p + 1 < n && compare_(data_[p + 1], data_[p])) {
        ++p;
      }

      if (compare_(temp, data_[p])) {
        break;
      }

      data_[i] = data_[p];
      i = p;
    }
    data_[i] = temp;
  }

  // pop the min/max elemnt, you must make sure
  // the heap is not empty
  T Pop() {
    T ret = data_[0];
    data_[0] = data_.back();
    data_.pop_back();
    Adjust(0);
    return ret;
  }

  T& Top() {
    return data_[0];
  }

  size_t size() {return data_.size(); }

 private:
  std::vector<T> data_;
  C compare_;
};

}  // namespace algorithm

#endif  // HEAP_H_
