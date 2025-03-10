#ifndef __NVBYTEIFY_H__
#define __NVBYTEIFY_H__

#include <Arduino.h>

enum NVByteifyType : uint8_t
{
    NVBTYPE_NONE,
    NVBTYPE_CHAR,
    NVBTYPE_INT8,
    NVBTYPE_INT16,
    NVBTYPE_INT32,
    NVBTYPE_INT64,
    NVBTYPE_UINT8,
    NVBTYPE_UINT16,
    NVBTYPE_UINT32,
    NVBTYPE_UINT64,
    NVBTYPE_FLOAT,
    NVBTYPE_DOUBLE,
    NVBTYPE_ARRAY_CHAR,
    NVBTYPE_ARRAY_INT8,
    NVBTYPE_ARRAY_INT16,
    NVBTYPE_ARRAY_INT32,
    NVBTYPE_ARRAY_INT64,
    NVBTYPE_ARRAY_UINT8,
    NVBTYPE_ARRAY_UINT16,
    NVBTYPE_ARRAY_UINT32,
    NVBTYPE_ARRAY_UINT64,
    NVBTYPE_ARRAY_FLOAT,
    NVBTYPE_ARRAY_DOUBLE,
    NVBTYPE_CUSTOM
};

class NVByteifyItem
{
public:
    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem();

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const uint8_t *byteified);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const char val);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const int8_t val);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const int16_t val);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const int32_t val);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const int64_t val);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const uint8_t val);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const uint16_t val);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const uint32_t val);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const uint64_t val);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const float val);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const double val);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const char *val, size_t size);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const int8_t *val, size_t size);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const int16_t *val, size_t size);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const int32_t *val, size_t size);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const int64_t *val, size_t size);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const uint8_t *val, size_t size);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const uint16_t *val, size_t size);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const uint32_t *val, size_t size);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const uint64_t *val, size_t size);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const float *val, size_t size);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const double *val, size_t size);

    /*
     * @brief
     * Constructor for `NVByteifyItem` instance.
     */
    NVByteifyItem(const void *val, size_t size);

    /*
     * @brief
     * Destructor for `NVByteifyItem` instance.
     */
    ~NVByteifyItem();

    /*
     * @brief
     * Returns the data type of the item.
     *
     * @return
     * The return type in `NVByteifyType`.
     */
    uint8_t getType();

    /*
     * @brief
     * Returns the size of the item (excluding the header).
     *
     * @return
     * The item size.
     */
    size_t getSize();

    /*
     * @brief
     * Returns the total size of the item (including the header).
     *
     * @return
     * The total item size.
     */
    size_t getTotalSize();

    /*
     * @brief
     * Returns the value to the buffer.
     *
     * @params
     * buffer a buffer to holds the item.
     */
    void getValue(void *buffer);

    /*
     * @brief
     * Returns the resulting/bytefied data.
     *
     * @params
     * buffer a buffer to holds the bytes.
     */
    void getBytes(uint8_t *buffer);

    /*
     * @brief
     * Delete the dynamically allocated memory.
     *
     * @note
     * The destructor is not used to ease the logic and widen the usage.
     */
    void deleteMemory();

private:
    uint8_t dataType = NVBTYPE_NONE;
    uint8_t *dataByte = nullptr;
    size_t dataSize = 0;
    size_t totalSize = 0;
};

class NVByteify
{
public:
    /*
     * @brief
     * Constructor method for `NVByteify` instance from number of items.
     *
     * @params
     * n number of items desired
     */
    NVByteify(const size_t n);

    /*
     * @brief
     * Constructor method for `NVByteify` instance from byteified bytes.
     *
     * @param
     * bytes the byteified bytes to parse
     * @param
     * size the size of the bytes
     */
    NVByteify(const uint8_t *bytes, size_t size);

    /*
     * @brief
     * Destructor method for `NVByteify` instance.
     */
    ~NVByteify();

    /*
     * @brief
     * Set the item at an index.
     *
     * @param
     * index index to set the item with, up to `.getNumberOfItems() - 1`
     * @param
     * item the item
     */
    void setItem(uint32_t index, const NVByteifyItem &item);

    /*
     * @brief
     * Get the item value at an index.
     *
     * @param
     * index index to get the item value, up to `.getNumberOfItems() - 1`
     * @param
     * buffer buffer to hold the value
     */
    void getItemValue(uint32_t index, void *buffer);

    /*
     * @brief
     * Get the item type at an index.
     *
     * @param
     * index index to get the item type, up to `.getNumberOfItems() - 1`
     *
     * @return
     * The data type within `NVByteifyType` enums.
     */
    uint8_t getItemType(uint32_t index);

    /*
     * @brief
     * Get the item size at an index.
     *
     * @param
     * index index to get the item size, up to `.getNumberOfItems() - 1`
     *
     * @return
     * The item size.
     */
    size_t getItemSize(uint32_t index);

    /*
     * @brief
     * Get the item total size at an index.
     *
     * @param
     * index index to get the item total size, up to `.getNumberOfItems() - 1`
     *
     * @return
     * The item total size.
     */
    size_t getItemTotalSize(uint32_t index);

    /*
     * @brief
     * Returns the number of items available.
     *
     * @return
     * The number of items.
     */
    size_t getNumberOfItems();

    /*
     * @brief
     * Returns the size of the byteified bytes.
     *
     * @return
     * The size of the bytefied bytes.
     */
    size_t getSize();

    /*
     * @brief
     * Get the bytefied bytes.
     *
     * @param
     * buffer buffer to hold the yielded bytes
     */
    void byteify(uint8_t *buffer);

private:
    NVByteifyItem *items;
    size_t itemNum;
};

#endif