#include <gtest/gtest.h>
#include "demo-connection.cpp"  // Include your project source file.

// Define a test fixture for connection tests
class ConnectionTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        // Add any setup code here if needed.
    }

    virtual void TearDown() {
        // Add any teardown code here if needed.
    }
};

// Test that a connection can be established to the MySQL database.
TEST_F(ConnectionTest, CanEstablishConnection) {
    // Call your connection function
    bool connected = YourConnectionFunction();

    // Check if the connection was successful
    ASSERT_TRUE(connected);
}

// Test that the connection can be closed successfully.
TEST_F(ConnectionTest, CanCloseConnection) {
    // Add code to close the connection if needed
    // You may not have a separate close function, but if you do, test it here.
    
    // Check if the connection is closed (assuming a successful connection was made before)
    bool closed = YourCloseConnectionFunction(); // Replace with your close function
    ASSERT_TRUE(closed);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
