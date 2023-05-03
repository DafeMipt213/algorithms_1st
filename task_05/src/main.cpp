#include <cstdio>
#include <iostream>

#include "tree.hpp"
#include <stdio.h>

  

int main() {
  Tree tree;
  int key = 1;
  int value = 2;
  
  tree.PrintAll();

  
  tree.Insert(2, 5);
  tree.Insert(2, 3);
  tree.Insert(3, 7);
  tree.Insert(4, 5);
  tree.Insert(5, 9);
  tree.Insert(6, 6);

  printf("Это значение для ключа %d: %d\n",2, tree.Find(2));
  printf("Это значение для ключа %d: %d\n",3, tree.Find(3));
  printf("Это значение для ключа %d: %d\n",4, tree.Find(4));
  printf("Это значение для ключа %d: %d\n",5, tree.Find(5));
  printf("Это значение для ключа %d: %d\n",6, tree.Find(6));
  printf("Это значение для ключа %d: %d\n",7, tree.Find(7));
  printf("Это значение для ключа %d: %d\n",8, tree.Find(8));

  tree.PrintAll();
  return 0;
}
