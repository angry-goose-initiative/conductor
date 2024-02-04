#pragma once

#include "serial_port_if.h"

class Conductor {
public:
    Conductor() = default;
    ~Conductor() = default;

    // Disable copying and moving
    Conductor(Conductor const &) = delete;
    void operator=(Conductor const &) = delete;
    Conductor(Conductor &&) = delete;
    void operator=(Conductor &&) = delete;

private:
    SerialPortIf serial_port_if_;
};
