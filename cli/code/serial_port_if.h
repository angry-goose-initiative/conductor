#pragma once

#include <cstddef>
#include <vector>
#include <string_view>

using ByteBuf = std::vector<std::byte>;

// Abstracts details about interfacing with the serial port file
class SerialPortIf {
public:
    SerialPortIf() = default;
    ~SerialPortIf();

    // Disable copying and moving
    SerialPortIf(SerialPortIf const &) = delete;
    void operator=(SerialPortIf const &) = delete;
    SerialPortIf(SerialPortIf &&) = delete;
    void operator=(SerialPortIf &&) = delete;

    void open(std::string_view);
    void close();
    ByteBuf read();
    void write(ByteBuf);
private:
    bool file_is_open_{false};
    int port_fd_{-1}; // Initialize to invalid FD
};
