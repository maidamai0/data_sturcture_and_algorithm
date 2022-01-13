#include <vcruntime.h>

#include <utility>
#include <vector>

namespace dsa {
template <typename T>
class queue {
  using value_type = T;

 public:
  void push(value_type&& value) {
    data_.push_back(std::forward<value_type&&>(value));
  }

  value_type pop() {
    value_type value = data_.front();
    data_.erase(data_.begin());
    return value;
  }

  bool empty() { return data_.empty(); }
  size_t size() const { return data_.size(); }

 private:
  std::vector<value_type> data_;
};
}  // namespace dsa