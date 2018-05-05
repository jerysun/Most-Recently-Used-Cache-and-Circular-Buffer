#include "mru_cache.h"
#include "circularBuffer.h"

int main() {
  std::cout << "Most Recently Used Cache:\n";
  jsun::MRU_Cache<int, std::string> mrucache(3);
  mrucache.put(1, "John");
  mrucache.put(2, "Kohn");
  mrucache.put(3, "Lohn");
  mrucache.print();
  mrucache.put(4, "Mohn");
  mrucache.put(5, "Nohn");
  mrucache.print();

  jsun::CircularBuffer<int> cb(3);
  cb.put(1);
  cb.put(2);
  cb.put(3);

  std::cout << "\nThe full circular buffer is:\n";
  for (size_t i = 0; i < cb.size(); ++i) {
    std::cout << cb.get() << (i < cb.size() - 1 ? ", " : "\n");
  }

  std::cout << "\nAfter adding 4, 5 to the circular buffer:\n";
  cb.put(4);
  cb.put(5);
  for (size_t i = 0; i < cb.size(); ++i) {
    std::cout << cb.get() << (i < cb.size() - 1 ? ", " : "\n");
  }
}
