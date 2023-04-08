#include <iostream>

#include "tree.hpp"
int main() {
  Tree t1;
  t1.Insert(10, 112123123);  // NOLINT
  ShowTree(&t1);
  t1.Insert(12, 12312312);  // NOLINT
  ShowTree(&t1);
  t1.Insert(11, 1222212);  // NOLINT
  ShowTree(&t1);
  t1.Insert(17, 1223132312);  // NOLINT
  ShowTree(&t1);
  t1.Insert(16, 12222323);  // NOLINT
  ShowTree(&t1);
  t1.Insert(15, 124421234);  // NOLINT
  ShowTree(&t1);
  t1.Insert(14, 1256676);  // NOLINT
  ShowTree(&t1);
  t1.Insert(18, 199982);  // NOLINT
  ShowTree(&t1);
  t1.Insert(20, 19992);  // NOLINT
  ShowTree(&t1);
  t1.Insert(19, 919992);  // NOLINT
  ShowTree(&t1);
  t1.InsertOrUpdate(10, 1944);  // NOLINT
  ShowTree(&t1);
  t1.InsertOrUpdate(14, 1494);  // NOLINT
  ShowTree(&t1);
  t1.InsertOrUpdate(13, 1494);  // NOLINT
  ShowTree(&t1);
  t1.Find(14);  // NOLINT
  ShowTree(&t1);
  t1.Find(16);  // NOLINT
  ShowTree(&t1);
  t1.RemoveSplay(11);  // NOLINT
  ShowTree(&t1);
}
