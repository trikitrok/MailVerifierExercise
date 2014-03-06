#pragma once;

#include <vector>
#include <iterator>
#include <algorithm>
#include <set>

namespace VectorUtils
{
  template<typename T, class UnaryPredicate>
  std::vector<T> filter(const std::vector<T> & original, UnaryPredicate pred) {

    std::vector<T> filtered;

    std::copy_if(
      original.begin(), original.end(),
      std::back_inserter(filtered),
      pred);

    return filtered;
  }

  template<typename T2, typename T1, typename Function>
  std::vector<T2> map(const std::vector<T1> & original, Function f) {

    std::vector<T2> mapped;

    std::transform(original.begin(), original.end(),
      std::back_inserter(mapped),
      f);

    return mapped;
  }

  template<typename T>
  void append(std::vector<T> & appendedTo, const std::vector<T> & appended) {
    appendedTo.insert(appendedTo.end(), appended.begin(), appended.end());
  }

  template<typename T>
  std::vector<T> removeDuplicate(const std::vector<T> & elements) {
    std::vector<T> nonDuplicateElements;
    std::set<T> setOfElements;
    std::pair<std::set<T>::iterator, bool> res;

    for (auto i = 0; i < elements.size(); ++i) {
      res = setOfElements.insert(elements[i]);
      if (res.second) {
        nonDuplicateElements.push_back(elements[i]);
      }
    }
    return nonDuplicateElements;
  }
}