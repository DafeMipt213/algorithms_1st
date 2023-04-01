int MinStack::GetMin() {
  Stack finder;
  Stack reverse;
  reverse.Push(stack.Pop());
  finder.Push(reverse.Peak());
  while (not stack.Is_empty()) {
    reverse.Push(stack.Pop());
    if (reverse.Peak() <= finder.Peak()) {
      finder.Push(reverse.Peak());
    }
  }
  while (not reverse.Is_empty()) {
    stack.Push(reverse.Pop());
  }
  return finder.Peak();
}