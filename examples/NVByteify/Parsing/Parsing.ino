#include <Arduino.h>
#include <NVByteify.h>

void setup()
{
    Serial.begin(115200);
    Serial.println("__________[ NVByteify Parsing Example ]__________");
}

void loop()
{
    // Here is the data yields from the Byteifying example
    uint8_t data[51] = {0x04, 0x16, 0x00, 0x00, 0x00, 0x0C, 0x0D, 0x00, 0x00, 0x00, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x77, 0x6F, 0x72, 0x6C, 0x64, 0x21, 0x00, 0x15, 0x0C, 0x00, 0x00, 0x00, 0xC3, 0xF5, 0x48, 0x40, 0x68, 0x91, 0x2D, 0x40, 0xCD, 0xCC, 0x1C, 0x41, 0x0B, 0xC6, 0x33, 0x68, 0xE8, 0x9F, 0x18, 0x45, 0x40, 0x06, 0xAB};

    // Create the NVByteify instance in the following manner
    NVByteify nvb(data, sizeof(data));
    // NVByteify nvb(data, 51); also works

    // Get the number of items received
    size_t n = nvb.getNumberOfItems();
    Serial.printf("NUMBER OF ITEMS: %u\n\n", n);

    // Get the types, here are the types:
    Serial.printf("__________[ List of Types ]__________\n");
    Serial.printf("char       : %02X\n", NVBTYPE_CHAR);
    Serial.printf("int8_t     : %02X\n", NVBTYPE_INT8);
    Serial.printf("int16_t    : %02X\n", NVBTYPE_INT16);
    Serial.printf("int32_t    : %02X\n", NVBTYPE_INT32);
    Serial.printf("int64_t    : %02X\n", NVBTYPE_INT64);
    Serial.printf("uint8_t    : %02X\n", NVBTYPE_UINT8);
    Serial.printf("uint16_t   : %02X\n", NVBTYPE_UINT16);
    Serial.printf("uint32_t   : %02X\n", NVBTYPE_UINT32);
    Serial.printf("uint64_t   : %02X\n", NVBTYPE_UINT64);
    Serial.printf("float      : %02X\n", NVBTYPE_FLOAT);
    Serial.printf("double     : %02X\n", NVBTYPE_DOUBLE);
    Serial.printf("char[]     : %02X\n", NVBTYPE_ARRAY_CHAR);
    Serial.printf("int8_t[]   : %02X\n", NVBTYPE_ARRAY_INT8);
    Serial.printf("int16_t[]  : %02X\n", NVBTYPE_ARRAY_INT16);
    Serial.printf("int32_t[]  : %02X\n", NVBTYPE_ARRAY_INT32);
    Serial.printf("int64_t[]  : %02X\n", NVBTYPE_ARRAY_INT64);
    Serial.printf("uint8_t[]  : %02X\n", NVBTYPE_ARRAY_UINT8);
    Serial.printf("uint16_t[] : %02X\n", NVBTYPE_ARRAY_UINT16);
    Serial.printf("uint32_t[] : %02X\n", NVBTYPE_ARRAY_UINT32);
    Serial.printf("uint64_t[] : %02X\n", NVBTYPE_ARRAY_UINT64);
    Serial.printf("float[]    : %02X\n", NVBTYPE_ARRAY_FLOAT);
    Serial.printf("double[]   : %02X\n", NVBTYPE_ARRAY_DOUBLE);
    Serial.printf("custom     : %02X (for user-defined struct)\n\n", NVBTYPE_CUSTOM);

    // Let us list all the data types, you may implement the type-based logic on your case
    Serial.printf("DATA TYPES:\n");
    for (size_t i = 0; i < n; ++i)
    {
        uint8_t itemType = nvb.getItemType(i);
        Serial.printf("[%u] type: %02X\n", i, itemType);
    }
    Serial.println();

    // Allocate the memory for retrieving the data
    int dataInt;
    char dataString[nvb.getItemSize(1) / sizeof(char)];
    float dataFloats[nvb.getItemSize(2) / sizeof(float)];
    double dataDouble;
    uint8_t dataByte;

    // Retrieve the data
    nvb.getItemValue(0, &dataInt);
    nvb.getItemValue(1, dataString);
    nvb.getItemValue(2, dataFloats);
    nvb.getItemValue(3, &dataDouble);
    nvb.getItemValue(4, &dataByte);

    Serial.printf("THE DATA RETRIEVED:\n");
    Serial.println(dataInt);
    Serial.println(dataString);
    Serial.println(String(dataFloats[0]) + ", " + String(dataFloats[1]) + ", " + String(dataFloats[2])); // let's just say we know there are 3 floats LMAO
    Serial.println(dataDouble);
    Serial.println(String(dataByte, HEX));

    // Halt!
    Serial.println("_________[ DONE! ]_________");
    while (1)
    {
    }
}
