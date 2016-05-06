#pragma once

#include "connection.h"
#include "journal.h"

class Datastore {
public:
    Connection new_connection();

private:
    EntityStore entities_;
};
