#ifndef SKETCHPAD_CONTROLLER_H
#define SKETCHPAD_CONTROLLER_H

#include <cstdint>
#include <ace/xcomponent/native_interface_xcomponent.h>
#include "tool.h"

class Controller {
private:
    Tool *currentTool;

    Controller();
    static Controller *controller;

public:
    static void Init(OH_NativeXComponent *);
    static const Controller *GetInstance() { return controller; }
    void Load(uint32_t) const;
};

#endif // SKETCHPAD_CONTROLLER_H
