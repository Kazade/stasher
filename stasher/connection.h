#pragma once

/*
 * This is the entry point to the datastore.
 */

class BaseConnection {
public:
    virtual ~BaseConnection() {}

    EntityList get(const KeyList& keys);
    EntityList get_async(const KeyList& keys) {
        // FIXME: Implement async version
        return get(keys);
    }

    KeyList put(const EntityList& entities);
    KeyList put_async(const EntityList& entities) {
        // FIXME: Implement async version
        return put(entities);
    }

    int64_t erase(const EntityList& entities);
    int64_t erase_async(const EntityList& entities) {
        // FIXME: Implement async version
        return erase(entities);
    }
};

class Connection:
    public BaseConnection {

};

class TransactionalConnection:
    public BaseConnection {

};
