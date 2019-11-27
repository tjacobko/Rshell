#include "gtest/gtest.h"
#include "Commands_test.cpp"
#include "Test_unit.cpp"
#include "Connectors_test.cpp"
#include "Paren_test.cpp"
#include "Exit_test.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
