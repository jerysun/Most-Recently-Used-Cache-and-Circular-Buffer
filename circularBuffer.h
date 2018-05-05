/* filename: circularBuffer.h
 * describe: A generic implementation of the circular buffer using C++ 14
 *           1. The exact starting location does not matter in a circular
 *              buffer.
 *           2. If you write to a FULL CicularBuffer, then it starts over-
 *              writing the OLDEST data.
 *           3. When an element is overwritten, the start pointer is incre-
 *              mented to the next element.
 * author:   Jerry Sun <jerysun0818@gmail.com>
 * date:     May 5, 2018
 * remark:   The underline data structure is a raw array, very efficient.
 *           It's thread-safe and exception-safe. Time complexity: O(1)
 * web:      http://nl.linkedin.com/in/jerysun
 * blog:     https://sites.google.com/site/geekssmallworld
 */

#ifndef CIRCULAR_BUFFER_
#define CIRCULAR_BUFFER_

#include <memory>
#include <mutex>

namespace jsun {
template<typename T>
class CircularBuffer {
public:
  CircularBuffer(size_t size = 64) : m_size{size},
    m_head{0}, m_tail{0},
    buf{std::make_unique<T[]>(size)} {}
  
  void put(T item) {
    std::lock_guard<std::mutex> lock(m_mutex);
    buf[m_head] = item;
    m_head = (m_head + 1) % m_size;

    if (m_head == m_tail) {
      //m_tail = (m_tail + 1) % m_size;
    }
  }

  T get() {
    std::lock_guard<std::mutex> lock(m_mutex);

    T val = buf[m_tail];
    m_tail = (m_tail + 1) % m_size;
    return val;
  }

  void reset() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_head = m_tail;
  }

  bool empty() {
    return m_head == m_tail;
  }

  bool full() {
    return (m_head + 1) % m_size == m_tail;
  }

  size_t size() {
    return m_size;
  }

private:
  size_t m_size;
  size_t m_head;
  size_t m_tail;
  std::unique_ptr<T[]> buf;
  std::mutex m_mutex;
};
}

#endif //CIRCULAR_BUFFER_
