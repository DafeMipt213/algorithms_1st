#include <iostream>

#include "tree.hpp"
int main() {
  Tree t1;
  t1.Insert(10, 112123123);
  ShowTree(&t1);
  t1.Insert(12, 12312312);
  ShowTree(&t1);
  t1.Insert(11, 1222212);
  ShowTree(&t1);
  t1.Insert(17, 1223132312);
  ShowTree(&t1);
  t1.Insert(16, 12222323);
  ShowTree(&t1);
  t1.Insert(15, 124421234);
  ShowTree(&t1);
  t1.Insert(14, 1256676);
  ShowTree(&t1);
  t1.Insert(18, 199982);
  ShowTree(&t1);
  t1.Insert(20, 19992);
  ShowTree(&t1);
  t1.Insert(19, 919992);
  ShowTree(&t1);
  t1.InsertOrUpdate(10, 1944);
  ShowTree(&t1);
  t1.InsertOrUpdate(14, 1494);
  ShowTree(&t1);
  t1.InsertOrUpdate(13, 1494);
  ShowTree(&t1);
  t1.Find(14);
  ShowTree(&t1);
  t1.Find(16);
  ShowTree(&t1);
}
