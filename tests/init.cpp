#include <gtest/gtest.h>
import logging;
class LogCleanupEnvironment : public ::testing::Environment {
public:
    void SetUp() override {
        logger.clearLogDirectory();
    }
};

// This static variable initializes before main() runs, 
// registering the cleanup environment into GTest's core engine.
static const ::testing::Environment* const g_log_env = 
    ::testing::AddGlobalTestEnvironment(new LogCleanupEnvironment);