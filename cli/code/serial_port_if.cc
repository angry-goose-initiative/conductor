#include "serial_port_if.h"

#include <cstddef>
#include <string_view>

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

namespace {

void configure_serial_port(int const fd) {
    termios term{};
    tcgetattr(fd, &term);
    cfsetispeed(&term, B115200); // Set baud rate
    term.c_cflag &= ~PARENB; // Disable parity
    term.c_cflag &= ~CSTOPB; // Use one stop bit
    term.c_cflag &= ~CSIZE; // Clear data size bits
    term.c_cflag |= CS8; // Use 8 data bits
    tcsetattr(fd, TCSANOW, &term);
}

} // namespace

SerialPortIf::~SerialPortIf() {
    if (this->file_is_open_) {
        ::close(this->port_fd_);
    }
}

void SerialPortIf::open(std::string_view const port) {
    if (this->file_is_open_) {
        return; // TODO - Error handling
    }

    this->port_fd_ = ::open(port.data(), O_RDWR | O_NOCTTY);

    if (this->port_fd_ < 0) {
        // TODO - Error handling
    }

    ::configure_serial_port(this->port_fd_);
}

void SerialPortIf::close() {
    if (!this->file_is_open_) {
        return; // TODO - Error handling
    }

    ::close(this->port_fd_);
}

ByteBuf SerialPortIf::read() {
    if (!this->file_is_open_) {
        return {}; // TODO - Error handling
    }

    ByteBuf data{};
    std::byte byte_read{};
    while (::read(this->port_fd_, &byte_read, 1U) > 0) {
        data.push_back(byte_read);
    }
    return data;
}

void SerialPortIf::write(ByteBuf data) {
    if (!this->file_is_open_) {
        return; // TODO - Error handling
    }

    if (::write(this->port_fd_, data.data(), data.size()) != data.size()) {
        // TODO - Error handling
    }
}
