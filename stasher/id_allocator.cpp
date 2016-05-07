
#include "id_allocator.h"

std::vector<int64_t> SequentialAllocator::allocate(
    const std::string &kind,
    const int64_t number,
    const std::string &ns) {

    std::vector<int64_t> ret;

    if(!counters_.count(kind)) {
        counters_.insert(std::make_pair(kind, 0));
    }

    for(auto i = 0; i < number; ++i) {
        ret.push_back(++counters[kind]);
    }

    return ret;
}

std::vector<int64_t> allocate(const Key& parent, const int64_t number) {
    return allocate(parent.kind(), number, parent.ns());
}

