#include "gtest/gtest.h"
#include "ListDirectory_test.cpp"
#include "Git_test.cpp"
#include "Echo_test.cpp"
//#include "MakeDirectory_test.cpp"
#include "Exit_test.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
