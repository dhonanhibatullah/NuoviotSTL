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

#endif