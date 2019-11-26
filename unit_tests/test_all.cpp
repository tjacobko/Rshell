#include "gtest/gtest.h"
//#include "Commands_test.cpp"
//#include "Exit_test.cpp"
#include "Test_unit.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
