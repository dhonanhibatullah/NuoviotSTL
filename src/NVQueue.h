#ifndef __NVQUEUE_H__
#define __NVQUEUE_H__

#include <Arduino.h>

template <typename T>
class NVQueue
{
public:
    /*
     * @brief
     * Constructor method for creating NVQueue instance.
     */
    NVQueue();

    /*
     * @brief
     * Destructor method for gracefully erasing NVQueue instance.
     */
    ~NVQueue();

    /*
     * @brief
     * Enqueues new item.
     *
     * @param
     * item item to add/enqueue
     */
    void enqueue(const T item);

    /*
     * @brief
     * Dequeues the head of the queue.
     *
     * @return
     * The item.
     */
    T dequeue();

    /*
     * @brief
     * Returns the length of the queue.
     *
     * @return
     * The length.
     */
    uint16_t length();

private:
    struct Node
    {
        T item;
        Node *next = nullptr;
    };

    Node *head;
    Node *tail;
    uint16_t len;
};

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

#endif