#include "NVList.h"

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