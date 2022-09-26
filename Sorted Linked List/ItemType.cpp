#include "ItemType.h"

/**
 * Creates a new ItemType object
 */
ItemType::ItemType() {
    value = 0;
} //ItemType

/**
 * Compares the input itemType to this itemType.
 *
 * @param item the item to compare to this one.
 * @returns GREATER if this item is creater.
 * @returns LESS if this item is less.
 * @returns EQUAL if they're equal.
 */
Comparison ItemType::compareTo(ItemType item) {
    if (item.getValue() < value) {
        return GREATER;
    } else if (item.getValue() > value) {
        return LESS;
    }
    return EQUAL;
} //compareTo

/**
 * Returns this itemType's value.
 *
 * @returns value
 */
int ItemType::getValue() const {
    return value;
} //getValue

/**
 * Initializes this ItemType.
 *
 * @param num the number to set value to.
 */
void ItemType::initialize(int num) {
    value = num;
} //initialize
