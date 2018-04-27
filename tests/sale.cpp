#include "gtest/gtest.h"
#include "sale.h"
#include "database.h"

class saleTest : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	saleTest() {
		// You can do set-up work for each test here.
	}

	virtual ~saleTest() {
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
	model::Sale p;
  db::Database *database_ = new db::Database("./shop.db");
};

TEST_F(saleTest, AddItem) {
  EXPECT_TRUE(p.AddItem(new db::ItemDTO("Sale Test", "Descr", "mmh", 10, 10)));
}

TEST_F(saleTest, SetDiscount) {
  EXPECT_TRUE(p.SetDiscount("12345", 1));
  EXPECT_FALSE(p.SetDiscount("1234567891", 0));
}

