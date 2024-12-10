#ifndef MockState_H
#define MockState_H

#include "PosSystem.h"

class MockState {
public:
    void initAppState(PosSystem& posSystem);
private:
    void loadMenu(PosSystem& posSystem);
    void loadOrders(PosSystem& posSystem);
};

#endif