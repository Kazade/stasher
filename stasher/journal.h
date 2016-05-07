#pragma once

#include <map>
#include <atomic>
#include "constants.h"
#include "entity.h"

/**
 * @brief Current and recent entity data store.
 *
 * The Journal is the store of an entity's data, it records all writes
 * to an entity's key, and a committed timestamp. The current version of an entity
 * is the one with the committed time, any older than that are stale version (that must
 * remain around for 60 seconds for transactions) and any newer than that are uncommitted
 * versions created by transactions.
 */
class Journal {
public:
    Entity get(Timestamp=0); // Returns the most recent entity, or the one given by the timestamp if specified

    Timestamp write(Entity new_entity);
    void commit(Timestamp time);
    void clean(); // Cleans up entries older than 60 seconds (max transaction period)

private:
    std::map<Timestamp, Entity> entries_;
    std::atomic<Timestamp> committed_;
};

/**
 * @brief The definitive store of entities
 *
 * This is the definitive store of entities by key. Think of this
 * like the "Entities" table in BigTable. Each Key is associated with a Journal
 * which is like a transaction log of a particular entity for the last 60 seconds.
 */
class EntityStore {
public:
    Entity get(const Key& key) const;

private:
    std::map<Key, Journal> entities_;
};
