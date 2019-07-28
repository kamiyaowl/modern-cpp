#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;

template<typename InputIterator,typename AccumulateType,typename BinaryOperation,typename Predicate>
const AccumulateType accumulate_if(
  InputIterator first,
  const InputIterator last,
  AccumulateType init,
  BinaryOperation&& binary_op,
  Predicate&& predicate) {
  for (; first != last; ++first)
    if (predicate(*first)) init = binary_op(init, *first);
  return init;
}

template<typename T>
double calc_rating(const vector<T>& src) noexcept {
    const auto sum = std::accumulate(src.begin(), src.end(), 0);
    const double average = static_cast<double>(sum) / src.size();
    const double lower = average * 0.05;
    const double upper = average * 0.95;

    const double sum2 = accumulate_if(src.begin(), src.end(), 0, std::plus<T>(), [&](const auto& x){ return (lower < x) && (x < upper); });
    const double average2 = static_cast<double>(sum) / src.size();
    return average2;
}

int main(void) {
    vector<int> rates = { 1,2,2,3,4,5,6,7,7,7,8,9,10,10,};
    std::cout << std::fixed << std::setprecision(1) << calc_rating(rates) << std::endl;
    return 0;
}