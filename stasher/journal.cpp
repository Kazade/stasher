
#include "journal.h"
#include "time_utils.h"
#include "exceptions.h"

Entity Journal::get_by_timestamp(Timestamp timestamp) {
    read_lock<shared_mutex> lock(entries_mutex_);
    return entries_.at(timestamp);
}

Entity Journal::get() {
    if(committed_ == 0) {
        throw EntityNotFoundError("No entity has been committed yet");
    }

    read_lock<shared_mutex> lock(entries_mutex_);
    if(!entries_.count(committed_)) {
        throw EntityNotFoundError("No such committed entity");
    } else {
        return entries_.at(committed_);
    }
}

Timestamp Journal::write(Entity new_entity) {
    write_lock<shared_mutex> lock(entries_mutex_);
    auto timestamp = get_timestamp(); // Get the time now
    entries_.insert(std::make_pair(timestamp, new_entity));
    return timestamp;
}

void Journal::commit(Timestamp time, Timestamp expected) {
    /* First, check that this is a valid entry. This will throw
     * EntityNotFoundError if this isn't the case */
    get_by_timestamp(time);

    //FIXME: We must check that time < 60 seconds ago, otherwise
    // clean might clean up the journal entry here even though we just
    // checked it. We *could* read lock the whole function but that
    // seems unnecessary.

    // If no expected value was passed in then just blindly commit
    if(expected == 0) {
        // Atomic, so avoid locking unnecessarily
        committed_.store(time);
    } else {
        assert(0 && "Not implemented");
    }
}

void Journal::clean() {

}

