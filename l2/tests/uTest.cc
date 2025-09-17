#include <gtest/gtest.h>

#include "../src/string.hh"

using namespace std;

TEST(Creation_Test, Subtest_1) { str::string str; }

TEST(Creation_Test, Subtest_2) {
    const char strPtr[] = "testing";
    str::string str{strPtr};
    ASSERT_EQ(str.getLen(), sizeof(strPtr));
    for (size_t i = 0; i < str.getLen(); i++) {
        ASSERT_EQ(str[i], strPtr[i]);
    }
}
TEST(Creation_Test, Subtest_3) {
    str::string str1{"___test__3"};
    str::string str2 = str1;
    ASSERT_EQ(str1.getLen(), str2.getLen());
    for (size_t i = 0; i < str1.getLen(); i++) {
        ASSERT_EQ(str1[i], str2[i]);
    }
}

TEST(Operator_Tests, Subtest_1) {
    str::string str1 {"___test__1"};
    str::string str2 = str1;
    ASSERT_EQ((str1 != str2), false);
}
TEST(Insetrion_Tests, Subtest_2) {
    str::string str1 {"testsss__2"};
    str::string str2 {"testsss__2wqeqw"};
    ASSERT_EQ((str1 > str2), false);
    ASSERT_EQ((str2 > str1), true);
}
TEST(Insetrion_Tests, Subtest_3) {
    str::string str1 {"tessstsss__266666"};
    str::string str2 {"31testsss__2wqe"};
    ASSERT_EQ((str1 >= str2), true);
    ASSERT_EQ((str2 >= str1), false);
}
TEST(Insetrion_Tests, Subtest_4) {
    str::string str1 {"tessstsss__2"};
    str::string str2 {"31testsss__2wqeqw"};
    cout << (str1 < str2);
    ASSERT_EQ((str1 < str2), true);
    ASSERT_EQ((str2 < str1), false);
}
TEST(Insetrion_Tests, Subtest_5) {
    str::string str1 {"tessstsss__266666"};
    str::string str2 {"31testsss__2wqeqw"};
    ASSERT_EQ((str1 <= str2), true);
    ASSERT_EQ((str2 <= str1), true);
}

TEST(Printing_Tests, Subtest_1) {
    str::string str1 {"Hello world"};

    testing::internal::CaptureStdout();
    std::cout << str1;
    string out = testing::internal::GetCapturedStdout();
    EXPECT_EQ(out, "Hello world");
}

TEST(Printing_Tests, Subtest_2) {
    str::string str1 {"Hello world"};

    testing::internal::CaptureStdout();
    str::printString(str1);
    string out = testing::internal::GetCapturedStdout();
    EXPECT_EQ(out, "Hello world");
}
TEST(Reading_Tests, Subtest_1) {
    const char str1[] = "Hello world";
    str::string str2;
    std::istringstream sin{str1};
    sin >> str2;
    for (size_t i = 0; i < str2.getLen(); i++) {
        ASSERT_EQ(str2[i], str1[i]);
    }
}

