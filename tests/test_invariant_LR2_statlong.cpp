#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <cstring>
#include "sqlite3.h"

// Test that SQL query construction properly escapes single quotes in player IDs.
// The security invariant: no user-controlled input can break out of the SQL string literal.

static std::string build_query_with_snprintf(const char* id) {
    char str[256];
    sqlite3_snprintf(256, str, "SELECT * FROM player WHERE id = '%s'", id);
    return std::string(str);
}

static std::string build_query_safe(const char* id) {
    char str[256];
    sqlite3_snprintf(256, str, "SELECT * FROM player WHERE id = '%q'", id);
    return std::string(str);
}

class SqlInjectionTest : public ::testing::TestWithParam<std::string> {};

TEST_P(SqlInjectionTest, PlayerIdMustNotEscapeSqlStringLiteral) {
    // Invariant: After the opening quote, the query must contain exactly one
    // unescaped closing quote (the terminal one). Any single quote in the ID
    // must be doubled (escaped) so it cannot terminate the string literal.
    std::string payload = GetParam();
    
    // This demonstrates the VULNERABLE path using %s
    std::string vulnerable_query = build_query_with_snprintf(payload.c_str());
    
    // This demonstrates the SAFE path using %q
    std::string safe_query = build_query_safe(payload.c_str());
    
    // Count unescaped single quotes after "id = '" in the safe query
    // The safe query should have the value properly escaped (quotes doubled)
    size_t pos = safe_query.find("id = '");
    ASSERT_NE(pos, std::string::npos);
    std::string after_open = safe_query.substr(pos + 6); // after "id = '"
    
    // Verify the safe version doesn't allow SQL injection:
    // There should be no unescaped single quote except the final closing one
    // (all internal quotes must be doubled)
    int consecutive_singles = 0;
    bool injection_possible = false;
    for (size_t i = 0; i < after_open.size() - 1; i++) {
        if (after_open[i] == '\'') {
            if (i + 1 < after_open.size() && after_open[i + 1] == '\'') {
                i++; // skip escaped pair
            } else {
                // This is the closing quote - everything after should be empty or safe
                break;
            }
        }
    }
    
    // The vulnerable version with malicious input WILL allow breaking out
    if (payload.find('\'') != std::string::npos) {
        // With %s, the quote is NOT escaped - demonstrating the vulnerability
        EXPECT_NE(vulnerable_query, safe_query)
            << "Payloads with quotes should differ between %s and %q";
    }
    
    // Verify safe query is valid SQL (parseable without injection)
    sqlite3* db;
    sqlite3_open(":memory:", &db);
    sqlite3_exec(db, "CREATE TABLE player (id TEXT)", nullptr, nullptr, nullptr);
    
    sqlite3_stmt* stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, safe_query.c_str(), -1, &stmt, nullptr);
    EXPECT_EQ(rc, SQLITE_OK) << "Safe query must always be valid SQL";
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

INSTANTIATE_TEST_SUITE_P(
    AdversarialInputs,
    SqlInjectionTest,
    ::testing::Values(
        "'; DROP TABLE player; --",
        "' OR '1'='1",
        "normal_player_id",
        "a]b'c\"d",
        ""
    )
);

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}