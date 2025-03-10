#include <Arduino.h>
#include <NVQueue.h>

void setup()
{
    Serial.begin(115200);
    Serial.println("__________[ NVQueue Example ]__________");
}

void loop()
{
    // Create an NVQueue instance
    NVQueue<int> myQueue = NVQueue<int>();

    // Fill the queue
    myQueue.enqueue(100);
    myQueue.enqueue(5912);
    myQueue.enqueue(-73);

    // Dequeue!
    while (myQueue.length() > 0)
    {
        Serial.println(myQueue.dequeue());
    }

    // Halt!
    Serial.println("_________[ DONE! ]_________");
    while (1)
    {
    }
}