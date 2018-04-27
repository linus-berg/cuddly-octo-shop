#include "gtest/gtest.h"
#include "database.h"

class dbTest : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	dbTest() {
		// You can do set-up work for each test here.
	}

	virtual ~dbTest() {
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
};

TEST_F(dbTest, GetItem) {
  EXPECT_EQ(database_->GetItem("0000000001")->ean_, "0000000001");
}

TEST_F(dbTest, GetCustomer) {
  EXPECT_EQ(database_->GetCustomer("1234567890")->discount_, 60);
}

TEST_F(dbTest, SetStock) {
  EXPECT_EQ(database_->SetStock(new db::ItemDTO("0000000001", "", "", 1, 20), 1), 101);
}

TEST_F(dbTest, LogSale) {
  EXPECT_EQ(database_->LogSale(new db::SaleDTO(1, "2", 1, 1, "1", "1")), 101);
}
