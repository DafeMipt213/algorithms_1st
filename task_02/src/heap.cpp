#include <algorithm>
#include <vector>

class Heap {
 public:
  void push(int value) {
    heap.push_back(value);  // добавляем элемент в конец вектора
    std::push_heap(heap.begin(), heap.end());  // перестраиваем кучу
  }

  int pop() {
    std::pop_heap(
        heap.begin(),
        heap.end());  // перемещаем максимальный элемент в конец вектора
    int max_value = heap.back();  // сохраняем максимальный элемент
    heap.pop_back();  // удаляем его из вектора
    return max_value;  // возвращаем максимальный элемент
  }

  bool empty() const {
    return heap.empty();  // проверяем, пуста ли куча
  }

 private:
  std::vector<int> heap;  // вектор, хранящий элементы кучи
};
