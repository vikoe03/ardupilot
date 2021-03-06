#include "BetterStream.h"

#include "print_vprintf.h"

void AP_HAL::BetterStream::printf(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
}

void AP_HAL::BetterStream::vprintf(const char *fmt, va_list ap)
{
    print_vprintf(this, fmt, ap);
}

size_t AP_HAL::BetterStream::write(const uint8_t *buffer, size_t size)
{
    for (size_t i=0; i<size;i++) {
        if (write(buffer[i] == 0)) {
            return i;
        }
    };
    return size;
}

size_t AP_HAL::BetterStream::write(const char *str)
{
    return write((const uint8_t *)str, strlen(str));
}
