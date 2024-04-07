#include <gtest/gtest.h>
#include "utility.h"


TEST(extractNumbersFromStringTest, BasicAssertions) {

  EXPECT_EQ(extractNumbersFromString("7-623"), "7623");

  EXPECT_EQ(extractNumbersFromString("..2965a"), "2965");

  // Handles zero and disregards negative numbers.
  EXPECT_EQ(extractNumbersFromString("-0"), "0");

  EXPECT_EQ(extractNumbersFromString("-11-11"), "1111");

  // If no numbers are present, return empty string
  EXPECT_EQ(extractNumbersFromString("ORNL"), "");

  // If all characters are numbers, return the same string
  EXPECT_EQ(extractNumbersFromString("156"), "156");
}

TEST(removeDuplicatesTest, BasicAssertions) {
  //
  std::vector<std::string> inputVecStr{"a", "b", "c", "a", "b", "d"};
  std::vector<std::string> resultVecStr{"a", "b", "c", "d"};
  
  std::vector<int> inputVecInt{4, 4, 3, 2, 3, 1};
  std::vector<int> resultVecInt{4, 3, 2, 1};

  EXPECT_EQ(removeDuplicates(inputVecStr), resultVecStr);

  EXPECT_EQ(removeDuplicates(inputVecInt), resultVecInt);

}

TEST(getSpecialtyNamesTest, BasicAssertions) {
  std::vector<std::string> IDs{"7-623", "8235", "8-235"};
  std::vector<Specialty> specialties{{1381, "Front-end web development"}, {8235, "data engineering"}, {3434, "API Design"}, {7623, "security"}, {9153, "UX"}};

  std::vector<std::string> result{"security", "data engineering"};

  EXPECT_EQ(getSpecialtyNames(IDs, specialties), result);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}