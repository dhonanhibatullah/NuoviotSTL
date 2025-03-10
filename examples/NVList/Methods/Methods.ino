#include <Arduino.h>
#include <NVList.h>

void setup()
{
    Serial.begin(115200);
    Serial.println("__________[ NVList Example ]__________");
}

void loop()
{
    // Create an NVList instance
    NVList<int> myList = NVList<int>();

    // Append some entries
    myList.append(1);
    myList.append(2);
    myList.append(3);

    Serial.println("1st action:");
    for (uint16_t i = 0; i < myList.length(); ++i)
    {
        Serial.printf("%d ", myList.get(i));
    }
    Serial.println('\n');

    // Insert entries
    myList.insert(2, 39); // 1, 2, 39, 3
    myList.insert(1, 56); // 1, 56, 2, 39, 3

    Serial.println("2nd action:");
    for (uint16_t i = 0; i < myList.length(); ++i)
    {
        Serial.printf("%d ", myList.get(i));
    }
    Serial.println('\n');

    // Change entries
    myList.set(1, 100); // 1, 100, 2, 39, 3
    myList.set(2, 999); // 1, 100, 999, 39, 3

    Serial.println("3rd action:");
    for (uint16_t i = 0; i < myList.length(); ++i)
    {
        Serial.printf("%d ", myList.get(i));
    }
    Serial.println('\n');

    // Pop entries
    int a = myList.pop(0); // 100, 999, 39, 3
    int b = myList.pop(3); // 100, 999, 39

    Serial.println("4th action:");
    Serial.printf("POPPED: %d %d\nREMAIN: ", a, b);
    for (uint16_t i = 0; i < myList.length(); ++i)
    {
        Serial.printf("%d ", myList.get(i));
    }
    Serial.println('\n');

    // Halt!
    Serial.println("_________[ DONE! ]_________");
    while (1)
    {
    }
}