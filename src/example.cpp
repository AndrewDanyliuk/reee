#include "reee/example.h"

namespace reee {

Example::Example(int value) : value_(value) {}

int Example::getValue() const
{
    return value_;
}

void Example::setValue(int value)
{
    value_ = value;
}

int Example::add(int amount)
{
    value_ += amount;
    return value_;
}

}  // namespace reee
