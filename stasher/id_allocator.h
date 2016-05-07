#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include <cstdint>

#include "key.h"

class IDAllocator {
public:
    virtual ~IDAllocator() {}

    virtual std::vector<int64_t> allocate(
        const std::string& kind,
        const int64_t number=1,
        const std::string& ns=""
    ) = 0;

    virtual std::vector<int64_t> allocate(
        const Key& parent,
        const int64_t number=1
    ) = 0;
};

class SequentialAllocator:
    public IDAllocator {
public:
    std::vector<int64_t> allocate(const std::string &kind, const int64_t number=1, const std::string &ns="") override;
    std::vector<int64_t> allocate(const Key& parent, const int64_t number=1) override;

private:
    std::unordered_map<std::string, int64_t> counters_;
};
