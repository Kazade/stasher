#include <functional>
#include "kaztest/kaztest.h"

#include "../stasher/journal.h"
#include "../stasher/id_allocator.h"
#include "../stasher/entity.h"
#include "../stasher/exceptions.h"

class JournalTests : public TestCase {
public:
    void test_write() {
        Journal journal;
        Entity new_entity("test_kind", 1);
        new_entity.set("field1", Property("test_string"));
        new_entity.set("field2", Property(9999));

        auto timestamp = journal.write(new_entity);

        // Nothing committed yet!
        assert_raises(EntityNotFoundError, std::bind(&Journal::get, &journal));

        // Timestamp specified so we hit the uncommitted journal
        assert_equal(new_entity, journal.get_by_timestamp(timestamp));

        // Commit the entity we wrote
        journal.commit(timestamp);

        // Now should return committed version
        assert_equal(new_entity, journal.get());

        new_entity.set("field1", Property(555));

        journal.write(new_entity);

        // Should return uncommitted value
        assert_equal(journal.get().get("field1").value<std::string>(), "test_string");
    }
};
