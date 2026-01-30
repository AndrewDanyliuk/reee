#ifndef REEE_EXAMPLE_H
#define REEE_EXAMPLE_H

namespace reee {

/**
 * @brief A simple example class demonstrating basic functionality
 */
class Example
{
public:
    /**
     * @brief Constructor
     * @param value Initial value
     */
    explicit Example(int value);

    /**
     * @brief Get the current value
     * @return Current value
     */
    int getValue() const;

    /**
     * @brief Set a new value
     * @param value New value to set
     */
    void setValue(int value);

    /**
     * @brief Add to the current value
     * @param amount Amount to add
     * @return New value after addition
     */
    int add(int amount);

private:
    int value_;
};

}  // namespace reee

#endif  // REEE_EXAMPLE_H
