#ifndef __NVLIST_H__
#define __NVLIST_H__

#include <Arduino.h>

template <typename T>
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
     * item item to add
     */
    void append(const T item);

    /*
     * @brief
     * Adds new item at any position/index of the list.
     *
     * @param
     * index index to choose
     * @param
     * item item to add
     */
    void insert(const uint16_t index, const T item);

    /*
     * @brief
     * Gets the item at an index.
     *
     * @param
     * index index to choose
     *
     * @return
     * The item.
     */
    T get(const uint16_t index);

    /*
     * @brief
     * Sets a new value for an item at an index.
     *
     * @param
     * index index to choose
     * @param
     * item new item/value to set
     */
    void set(const uint16_t index, const T item);

    /*
     * @brief
     * Gets and removes an item at an index.
     *
     * @param
     * index index to choose
     *
     * @return
     * The item.
     */
    T pop(const uint16_t index);

    /*
     * @brief
     * Returns the length of the list.
     *
     * @return
     * The length of the list.
     */
    uint16_t length();

private:
    struct Node
    {
        T item;
        Node *next = nullptr;
    };

    Node *head;
    uint16_t len;
};

#endif