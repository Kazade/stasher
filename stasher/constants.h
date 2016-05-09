#pragma once

const uint32_t MAX_STRING_BYTES = 1500;
const uint32_t MAX_TRANSACTION_LIFETIME_IN_SECONDS = 60;
const uint32_t MAX_IDLE_TRANSACTION_TIME_IN_SECONDS = 30; // Not sure this is correct

const std::string KEY_PROPERTY = "__key__";

typedef uint64_t Timestamp;

enum PropertyType {
    PROPERTY_TYPE_NONE,
    PROPERTY_TYPE_KEY,
    PROPERTY_TYPE_INT64,
    PROPERTY_TYPE_FLOAT,
    PROPERTY_TYPE_UNICODE,
    PROPERTY_TYPE_BOOLEAN,
    PROPERTY_TYPE_TEXT,
    PROPRETY_TYPE_BLOB,
    PROPERTY_TYPE_DATETIME
};

enum ConsistencyPolicy {
    STRONGLY_CONSISTENT, // Wait for apply()
    EVENTUALLY_CONSISTENT, // Don't wait for apply()
    FIXED_TIME_CONSISTENT // Apply after time-delay
};


