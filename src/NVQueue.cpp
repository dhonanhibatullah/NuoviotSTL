#include "NVQueue.h"

template <typename T>
NVQueue<T>::NVQueue()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->len = 0;
}

template <typename T>
NVQueue<T>::~NVQueue()
{
    while (this->len > 0)
        this->dequeue();
}

template <typename T>
void NVQueue<T>::enqueue(const T item)
{
    NVQueue<T>::Node *newNode = new NVQueue<T>::Node;
    newNode->item = item;

    if (this->len == 0)
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        this->tail->next = newNode;
        this->tail = newNode;
    }

    this->len++;
}

template <typename T>
T NVQueue<T>::dequeue()
{
    if (this->len == 0)
        return 0;

    NVQueue<T>::Node *tempNode = this->head;
    T resVal = tempNode->item;
    this->head = tempNode->next;

    delete tempNode;
    this->len--;

    return resVal;
}

template <typename T>
uint16_t NVQueue<T>::length()
{
    return this->len;
}