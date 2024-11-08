#ifndef SKETCHPAD_STORE_H
#define SKETCHPAD_STORE_H

#include "database/rdb/relational_store.h"

class RdbStore {
private:
    OH_Rdb_Store *store;

    RdbStore();
    static RdbStore *rdbStore;

public:
    static void Init(char *buf);
    static const RdbStore *GetInstance() { return rdbStore; }
};

#endif // SKETCHPAD_STORE_H
