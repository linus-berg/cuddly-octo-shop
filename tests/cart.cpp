#include "gtest/gtest.h"
#include "database.h"
#include "cart.h"

class cartTest : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	cartTest() {
		// You can do set-up work for each test here.
	}

	virtual ~cartTest() {
		// You can do clean-up work that doesn't throw exceptions here.
  }

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).

	}

	// Objects declared here can be used by all tests in the test case for Project1.
  db::Database *database_ = new db::Database("./shop.db");
  model::Cart cart;
};

TEST_F(cartTest, UpdateCart) {
  EXPECT_TRUE(cart.UpdateCart(new db::ItemDTO("1", "1", "1", 10, 10), 10));
  EXPECT_FALSE(cart.UpdateCart(new db::ItemDTO("1", "1", "1", 10, 9), 10));
  EXPECT_FALSE(cart.UpdateCart(new db::ItemDTO("1", "1", "1", 10, 10), 10));
}

