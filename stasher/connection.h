#pragma once

/*
 * This is the entry point to the datastore.
 */

class BaseConnection {
public:
    virtual ~BaseConnection() {}

    EntityResultSet get(KeyList keys);

};

class Connection:
    public BaseConnection {

};

class TransactionalConnection:
    public BaseConnection {

};
