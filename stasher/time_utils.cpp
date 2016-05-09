#include <chrono>

uint64_t get_timestamp() {
    auto now = std::chrono::high_resolution_clock::now();
    return now.time_since_epoch().count();
}
