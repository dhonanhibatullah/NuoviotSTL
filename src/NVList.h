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

template <typename T>
NVList<T>::NVList()
{
    this->head = nullptr;
    this->len = 0;
}

template <typename T>
NVList<T>::~NVList()
{
    while (this->len > 0)
    {
        this->pop(0);
    }
}

template <typename T>
void NVList<T>::append(const T item)
{
    NVList<T>::Node *newNode = new NVList<T>::Node;
    newNode->item = item;

    if (this->len == 0)
    {
        this->head = newNode;
    }
    else
    {
        NVList<T>::Node *tempNode = this->head;
        for (uint16_t i = 0; i < (this->len - 1); ++i)
        {
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
    }

    this->len++;
}

template <typename T>
void NVList<T>::insert(const uint16_t index, const T item)
{
    uint16_t idx = (index > this->len) ? this->len : index;

    if (this->len == 0 || idx == this->len)
    {
        this->append(item);
    }
    else
    {
        NVList<T>::Node *tempNode = this->head;
        NVList<T>::Node *prevNode = nullptr;

        for (uint16_t i = 0; i < idx; ++i)
        {
            prevNode = tempNode;
            tempNode = tempNode->next;
        }

        NVList<T>::Node *newNode = new NVList<T>::Node;
        newNode->item = item;

        if (idx == 0)
        {
            newNode->next = this->head;
            this->head = newNode;
        }
        else
        {
            prevNode->next = newNode;
            newNode->next = tempNode;
        }

        this->len++;
    }
}

template <typename T>
T NVList<T>::get(const uint16_t index)
{
    uint16_t idx = (index > (this->len - 1)) ? (this->len - 1) : index;
    NVList<T>::Node *tempNode = this->head;

    for (uint16_t i = 0; (i < idx) && (i < this->len); ++i)
    {
        tempNode = tempNode->next;
    }
    return tempNode->item;
}

template <typename T>
void NVList<T>::set(const uint16_t index, const T item)
{
    uint16_t idx = (index > (this->len - 1)) ? (this->len - 1) : index;
    NVList<T>::Node *tempNode = this->head;

    for (uint16_t i = 0; (i < idx) && (i < this->len); ++i)
    {
        tempNode = tempNode->next;
    }
    tempNode->item = item;
}

template <typename T>
T NVList<T>::pop(const uint16_t index)
{
    if (this->len == 0)
        return 0;
    uint16_t idx = (index > (this->len - 1)) ? (this->len - 1) : index;

    T resVal;
    NVList<T>::Node *tempNode = this->head;
    NVList<T>::Node *prevNode = nullptr;

    for (uint16_t i = 0; i < idx; ++i)
    {
        prevNode = tempNode;
        tempNode = tempNode->next;
    }
    resVal = tempNode->item;

    if (idx == 0)
    {
        this->head = tempNode->next;
        delete tempNode;
    }
    else if (idx == (this->len - 1))
    {
        prevNode->next = nullptr;
        delete tempNode;
    }
    else
    {
        prevNode->next = tempNode->next;
        delete tempNode;
    }

    this->len--;
    return resVal;
}

template <typename T>
uint16_t NVList<T>::length()
{
    return this->len;
}

#endif