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
    NVList myList = NVList();

    // Append some entries
    myList.append(123U);
    myList.append(3.14159F);
    myList.append("Hello, World!");

    // Print the list
    Serial.println("[1] Initializing NVList");
    Serial.println(myList[0].asUInt32());
    Serial.println(myList[1].asFloat());
    Serial.println(myList[2].asString());
    Serial.println();

    // Insert entries
    myList.insert(2, "John Doe"); // 123, 3.14159, John Doe, Hello, World!
    myList.insert(0, 999U);       // 999, 123, 3.14159, John Doe, Hello, World!

    // Print the list
    Serial.println("[2] Inserting new entries");
    Serial.println(myList[0].asUInt32());
    Serial.println(myList[1].asInt32());
    Serial.println(myList[2].asFloat());
    Serial.println(myList[3].asString());
    Serial.println(myList[4].asString());
    Serial.println();

    // Change entries, can change type
    myList[0] = "My";
    myList[1] = "Name";
    myList[2] = "Is";

    // Print the list
    Serial.println("[3] Changiing entries");
    Serial.println(myList[0].asString());
    Serial.println(myList[1].asString());
    Serial.println(myList[2].asString());
    Serial.println(myList[3].asString());
    Serial.println(myList[4].asString());
    Serial.println();

    // Pop entries
    Serial.println("[4] Popping entries");
    while (myList.length() > 0)
    {
        Serial.println(myList.pop(0).asString());
    }
    Serial.println();

    // Halt!
    Serial.println("_________[ DONE! ]_________");
    while (1)
    {
    }
}