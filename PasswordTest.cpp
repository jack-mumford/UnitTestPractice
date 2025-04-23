/**
 * Unit Tests for Password class
 **/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
protected:
	PasswordTest() {}		   // constructor runs before each test
	virtual ~PasswordTest() {} // destructor cleans up after tests
	virtual void SetUp() {}	   // sets up before each test (after constructor)
	virtual void TearDown() {} // clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

// Test for mixed case password
TEST(PasswordTest, mixed_case_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Aa");
	ASSERT_TRUE(actual);
}

// Test for all upper case password
TEST(PasswordTest, all_upper_case_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AA");
	ASSERT_FALSE(actual);
}

// Test for all lower case password
TEST(PasswordTest, all_lower_case_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aa");
	ASSERT_FALSE(actual);
}