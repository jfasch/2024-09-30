#pragma once

#include "stdint.h"

struct Frame{
    uint8_t id{};
    uint8_t dlc{};
    uint8_t data[8]{};
};
