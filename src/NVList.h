#ifndef __NVLIST_H__
#define __NVLIST_H__

#include <Arduino.h>

class NVListItem
{
public:
    enum NVType : uint8_t
    {
        TYPE_UNDEFINED,
        TYPE_CHAR,
        TYPE_INT8,
        TYPE_INT16,
        TYPE_INT32,
        TYPE_INT64,
        TYPE_UINT8,
        TYPE_UINT16,
        TYPE_UINT32,
        TYPE_UINT64,
        TYPE_FLOAT,
        TYPE_DOUBLE,
        TYPE_STRING
    };

    /*
     * @brief
     * Constructor method for creating `NVListItem` instance.
     */
    NVListItem();

    /*
     * @brief
     * Destructor method for gracefully erasing `NVListItem` instance.
     */
    ~NVListItem();

    /*
     * @brief
     * Clears all the preallocated memory.
     */
    void clear();

    /*
     * @brief
     * Assigns a value to the item.
     *
     * @param
     * val value to assign
     */
    void operator=(const char val);

    /*
     * @brief
     * Assigns a value to the item.
     *
     * @param
     * val value to assign
     */
    void operator=(const int8_t val);

    /*
     * @brief
     * Assigns a value to the item.
     *
     * @param
     * val value to assign
     */
    void operator=(const int16_t val);

    /*
     * @brief
     * Assigns a value to the item.
     *
     * @param
     * val value to assign
     */
    void operator=(const int32_t val);

    /*
     * @brief
     * Assigns a value to the item.
     *
     * @param
     * val value to assign
     */
    void operator=(const int64_t val);

    /*
     * @brief
     * Assigns a value to the item.
     *
     * @param
     * val value to assign
     */
    void operator=(const uint8_t val);

    /*
     * @brief
     * Assigns a value to the item.
     *
     * @param
     * val value to assign
     */
    void operator=(const uint16_t val);

    /*
     * @brief
     * Assigns a value to the item.
     *
     * @param
     * val value to assign
     */
    void operator=(const uint32_t val);

    /*
     * @brief
     * Assigns a value to the item.
     *
     * @param
     * val value to assign
     */
    void operator=(const uint64_t val);

    /*
     * @brief
     * Assigns a value to the item.
     *
     * @param
     * val value to assign
     */
    void operator=(const float val);

    /*
     * @brief
     * Assigns a value to the item.
     *
     * @param
     * val value to assign
     */
    void operator=(const double val);

    /*
     * @brief
     * Assigns a value to the item.
     *
     * @param
     * val value to assign
     */
    void operator=(const String val);

    /*
     * @brief
     * Returns the value in `char` type.
     *
     * @return
     * Value in `char` type.
     */
    char asChar();

    /*
     * @brief
     * Returns the value in `int8_t` type.
     *
     * @return
     * Value in `int8_t` type.
     */
    int8_t asInt8();

    /*
     * @brief
     * Returns the value in `int16_t` type.
     *
     * @return
     * Value in `int16_t` type.
     */
    int16_t asInt16();

    /*
     * @brief
     * Returns the value in `int32_t` type.
     *
     * @return
     * Value in `int32_t` type.
     */
    int32_t asInt32();

    /*
     * @brief
     * Returns the value in `int64_t` type.
     *
     * @return
     * Value in `inte64_t` type.
     */
    int64_t asInt64();

    /*
     * @brief
     * Returns the value in `uint8_t` type.
     *
     * @return
     * Value in `uint8_t` type.
     */
    uint8_t asUInt8();

    /*
     * @brief
     * Returns the value in `uint16_t` type.
     *
     * @return
     * Value in `uint16_t` type.
     */
    uint16_t asUInt16();

    /*
     * @brief
     * Returns the value in `uint32_t` type.
     *
     * @return
     * Value in `uint32_t` type.
     */
    uint32_t asUInt32();

    /*
     * @brief
     * Returns the value in `uint64_t` type.
     *
     * @return
     * Value in `uint64_t` type.
     */
    uint64_t asUInt64();

    /*
     * @brief
     * Returns the value in `float` type.
     *
     * @return
     * Value in `float` type.
     */
    float asFloat();

    /*
     * @brief
     * Returns the value in `double` type.
     *
     * @return
     * Value in `double` type.
     */
    double asDouble();

    /*
     * @brief
     * Returns the value in Arduino's `String()` type.
     *
     * @return
     * Value in `String()` type.
     */
    String asString();

    NVListItem *next;
    void *value;
    uint8_t type;
};

class NVList
{
public:
    /*
     * @brief
     * Constructor method for creating `NVList` instance.
     */
    NVList();

    /*
     * @brief
     * Destructor method for gracefully erasing `NVList` instance.
     */
    ~NVList();

    /*
     * @brief
     * Adds new item at the end of the list.
     *
     * @param
     * val value to add
     */
    void append(const char val);

    /*
     * @brief
     * Adds new item at the end of the list.
     *
     * @param
     * val value to add
     */
    void append(const int8_t val);

    /*
     * @brief
     * Adds new item at the end of the list.
     *
     * @param
     * val value to add
     */
    void append(const int16_t val);

    /*
     * @brief
     * Adds new item at the end of the list.
     *
     * @param
     * val value to add
     */
    void append(const int32_t val);

    /*
     * @brief
     * Adds new item at the end of the list.
     *
     * @param
     * val value to add
     */
    void append(const int64_t val);

    /*
     * @brief
     * Adds new item at the end of the list.
     *
     * @param
     * val value to add
     */
    void append(const uint8_t val);

    /*
     * @brief
     * Adds new item at the end of the list.
     *
     * @param
     * val value to add
     */
    void append(const uint16_t val);

    /*
     * @brief
     * Adds new item at the end of the list.
     *
     * @param
     * val value to add
     */
    void append(const uint32_t val);

    /*
     * @brief
     * Adds new item at the end of the list.
     *
     * @param
     * val value to add
     */
    void append(const uint64_t val);

    /*
     * @brief
     * Adds new item at the end of the list.
     *
     * @param
     * val value to add
     */
    void append(const float val);

    /*
     * @brief
     * Adds new item at the end of the list.
     *
     * @param
     * val value to add
     */
    void append(const double val);

    /*
     * @brief
     * Adds new item at the end of the list.
     *
     * @param
     * val value to add
     */
    void append(const String val);

    /*
     * @brief
     * Adds new value at any position/index of the list.
     *
     * @param
     * index index to choose
     * @param
     * val value to add
     */
    void insert(const uint16_t index, const char val);

    /*
     * @brief
     * Adds new value at any position/index of the list.
     *
     * @param
     * index index to choose
     * @param
     * val value to add
     */
    void insert(const uint16_t index, const int8_t val);

    /*
     * @brief
     * Adds new value at any position/index of the list.
     *
     * @param
     * index index to choose
     * @param
     * val value to add
     */
    void insert(const uint16_t index, const int16_t val);

    /*
     * @brief
     * Adds new value at any position/index of the list.
     *
     * @param
     * index index to choose
     * @param
     * val value to add
     */
    void insert(const uint16_t index, const int32_t val);

    /*
     * @brief
     * Adds new value at any position/index of the list.
     *
     * @param
     * index index to choose
     * @param
     * val value to add
     */
    void insert(const uint16_t index, const int64_t val);

    /*
     * @brief
     * Adds new value at any position/index of the list.
     *
     * @param
     * index index to choose
     * @param
     * val value to add
     */
    void insert(const uint16_t index, const uint8_t val);

    /*
     * @brief
     * Adds new value at any position/index of the list.
     *
     * @param
     * index index to choose
     * @param
     * val value to add
     */
    void insert(const uint16_t index, const uint16_t val);

    /*
     * @brief
     * Adds new value at any position/index of the list.
     *
     * @param
     * index index to choose
     * @param
     * val value to add
     */
    void insert(const uint16_t index, const uint32_t val);

    /*
     * @brief
     * Adds new value at any position/index of the list.
     *
     * @param
     * index index to choose
     * @param
     * val value to add
     */
    void insert(const uint16_t index, const uint64_t val);

    /*
     * @brief
     * Adds new value at any position/index of the list.
     *
     * @param
     * index index to choose
     * @param
     * val value to add
     */
    void insert(const uint16_t index, const float val);

    /*
     * @brief
     * Adds new value at any position/index of the list.
     *
     * @param
     * index index to choose
     * @param
     * val value to add
     */
    void insert(const uint16_t index, const double val);

    /*
     * @brief
     * Adds new value at any position/index of the list.
     *
     * @param
     * index index to choose
     * @param
     * val value to add
     */
    void insert(const uint16_t index, const String val);

    /*
     * @brief
     * Gets and removes a value at an index.
     *
     * @param
     * index index to choose
     *
     * @return
     * The value in `NVListItem` instance.
     */
    NVListItem pop(const uint16_t index);

    /*
     * @brief
     * Gets a value at an index.
     *
     * @param
     * index index to choose
     *
     * @return
     * The value in `NVListItem` instance.
     */
    NVListItem &operator[](const uint16_t index);

    /*
     * @brief
     * Returns the length of the list.
     *
     * @return
     * The length of the list.
     */
    uint16_t length();

private:
    NVListItem *head;
    uint16_t len;
};

#endif