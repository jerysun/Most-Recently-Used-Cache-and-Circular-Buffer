/* filename: mru_cache.h
 * describe: A generic implementation of the Most Recently Used Cache
 *           using C++ 14
 * author:   Jerry Sun <jerysun0818@gmail.com>
 * date:     May 5, 2018
 * remark:   The algorithm policy is FIFO using hash map as auxiliary
 *           data structure. Time complexity: O(1)
 * web:      http://nl.linkedin.com/in/jerysun
 * blog:     https://sites.google.com/site/geekssmallworld
 */

#ifndef MRU_CACHE_H
#define MRU_CACHE_H

#include <iostream>
#include <list>
#include <unordered_map>

namespace jsun {
//Most Recently Used Cache
template<typename K, typename V>
class MRU_Cache {
public:
  explicit MRU_Cache(size_t size = 128) noexcept : m_size{size} {}
  void put(const K &k, const V &v);
  std::pair<bool,V> get(const K &k);
  void print();

private:
  void clean(void);

private:
  size_t m_size;
  std::list<std::pair<K,V>> m_cache;
  std::unordered_map<K, decltype(m_cache.begin())> m_records;
};

template<typename K, typename V>
void MRU_Cache<K,V>::put(const K &k, const V &v) {
  auto it = m_records.find(k);

  if (it != m_records.end()) {
    m_cache.erase(it->second);
    m_records.erase(it);
  }

  m_cache.emplace_front(k, v);
  m_records.emplace(k, m_cache.begin());
  clean();
}

template<typename K, typename V>
std::pair<bool,V> MRU_Cache<K,V>::get(const K &k) {
  auto it = m_records.find(k);
  if (it == m_records.end()) {
    return std::make_pair(false, V());
  } else {
    // The being accessed one becomes the MOST recently visited!
    m_cache.splice(m_cache.begin(), m_cache, it->second);
    return std::make_pair(true, it->second->second);
  }
}

template<typename K, typename V>
void MRU_Cache<K,V>::print() {
  for (auto e : m_cache) {
    std::cout << e.first << ": " << e.second << std::endl;
  }
}

template<typename K, typename V>
void MRU_Cache<K,V>::clean() {
  while (m_records.size() > m_size) {
    auto it = m_cache.end();
    --it;
    m_records.erase(it->first);
    m_cache.pop_back();
  }
}
}

#endif //MRU_CACHE_H
