
#include <gtest/gtest.h>

#include <vector>

#include "hashtable.hpp"

TEST(HashTable, Simple) {
  HashTable a;
  a.Insert("SUSA", 1);
  a.Insert("Drip", 2);
  a.Insert("KraccBacc", 4);
  a.Insert("YYYYY", 12);
  a.Insert("Moy", 11);
  a.Insert("PSIH", 43);
  a.Insert("Dyadya", 9);
  a.Insert("Zaper", 3);
  a.Insert("Menya", 5);
  a.Insert("V", 6);
  a.Insert("PoDVaLe", 23);
  a.Insert("SHA?!", 71);
  a.Insert("On", 14);
  a.Insert("zastavlyaet", 7);
  a.InsertOrUpdate("menya", 5);
  a.Insert("smotret'", 8);
  a.Insert("Video", 10);
  a.Insert("Krispy", 15);
  a.Insert("I", 50);
  a.Insert("Kongarta", 51);
  a.Insert("AAAAAAAAAA", 52);
  a.Insert("Moyego", 53);
  a.Insert("dryga", 54);
  a.Insert(", ", 55);
  a.Insert("WIINA", 56);
  a.Insert("Deilus", 57);
  a.Insert("Barnakl", 58);
  a.Insert("Johnsa", 59);
  a.Insert("Mladshego", 60);
  a.Insert("Zhestko", 61);
  a.Insert("UDARIL", 62);
  a.Insert("V Golovy", 63);
  a.Insert("Nosorog", 64);
  a.Insert("Potomu", 65);
  a.Insert("CHTO", 66);
  a.Insert("ON", 67);
  a.Insert("HE", 68);
  a.Insert("slyshal", 69);
  a.Insert("zhenshchin", 70);
  a.Insert("*spank*", 71);
  a.Insert("STOOP", 72);
  a.Insert("MOY", 73);
  a.Insert("ded", 74);
  a.Insert("vrezal", 75);
  a.Insert("mne", 76);
  a.Insert("po", 77);
  a.Insert("bashke", 78);
  a.Insert("so", 79);
  a.Insert("skorost'y", 80);
  a.Insert("90m/ph", 81);
  a.Insert("eheehehehehehhe", 82);
  a.Insert("MenYa", 83);
  a.Insert("paralizovalo", 84);
  a.Insert("OT", 85);
  a.Insert("talii", 86);
  a.Insert("vverh", 87);
  a.Insert("UHUHEHEHE", 88);
  a.Insert("BRAAAH", 89);
  a.Insert("YAY", 90);
  a.Insert("Quane", 91);
  a.Insert("Drain", 92);
  a.Insert("Dingle", 93);
  a.Insert("zdes'", 94);
  a.Insert("auyyua", 95);
  a.Insert("yA", 96);
  a.Insert("sbezhal", 97);
  a.Insert("iz", 98);
  a.Insert("tur'mi", 99);
  a.Insert("uuu", 100);
  ASSERT_EQ(a.Find(51), "Kongarta");
  ASSERT_EQ(a.Find(100), "uuu");
  ASSERT_EQ(a.Insert("NO_WAY!", 100), false);
  ASSERT_EQ(a.Size(), 20);
  ASSERT_EQ(a.Insert("YES_WAY!", 101), true);
}
TEST(HashTable, Complicated) {
  HashTable a;
  a.Insert("pepe", 1);
  a.Insert("beware", 2);
  a.Insert("nobody", 3);
  a.Insert("inside", 4);
  a.Insert("treehouse",5);
  a.Remove(4);
  ASSERT_ANY_THROW(a.Find(4));
}
