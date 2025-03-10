#include <Arduino.h>
#include <NVByteify.h>

void setup()
{
    Serial.begin(115200);
    Serial.println("__________[ NVByteify Byteifying Example ]__________");
}

void loop()
{
    // Create data to bytefied
    int age = 22;
    char text[13] = "Hello world!";
    float sensors[3] = {3.14, 2.712, 9.8};

    // Create a NVByteify instance with 8 items
    NVByteify nvb(5);

    // Set the NVByteify items
    nvb.setItem(0, NVByteifyItem(age));
    nvb.setItem(1, NVByteifyItem(text, sizeof(text)));
    nvb.setItem(2, NVByteifyItem(sensors, sizeof(sensors)));

    // We could also define the item directly
    nvb.setItem(3, NVByteifyItem((double)42.19238));
    nvb.setItem(4, NVByteifyItem((uint8_t)0xAB));

    // Byteify!
    // 1. Get the size first
    size_t byteSize = nvb.getSize();

    // 2. Create a buffer with the same size
    uint8_t buf[byteSize];

    // 3. Byteifies the data
    nvb.byteify(buf);

    // Here is the result:
    Serial.printf("SIZE   : %u\n", byteSize);
    Serial.printf("RESULT : ");
    for (size_t i = 0; i < byteSize; ++i)
        Serial.printf("0x%02X, ", buf[i]);

    // It should display:
    // 04 16 00 00 00 0C 0D 00 00 00 48 65 6C 6C 6F 20 77
    // 6F 72 6C 64 21 00 15 0C 00 00 00 C3 F5 48 40 68 91
    // 2D 40 CD CC 1C 41 0B C6 33 68 E8 9F 18 45 40 06 AB
    // on the serial monitor

    // We will see how to parse the bytes in 'Parsing' example

    // Halt!
    Serial.println("_________[ DONE! ]_________");
    while (1)
    {
    }
}