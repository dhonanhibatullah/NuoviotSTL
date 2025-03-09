#include "NVByteify.h"

NVByteifyItem::NVByteifyItem()
{
}

NVByteifyItem::NVByteifyItem(const uint8_t *byteified)
{
    this->dataType = byteified[0];

    if (this->dataType == NVBTYPE_CHAR || this->dataType == NVBTYPE_INT8 || this->dataType == NVBTYPE_UINT8)
    {
        this->dataSize = 1;
        this->totalSize = 2;
    }

    else if (this->dataType == NVBTYPE_INT16 || this->dataType == NVBTYPE_UINT16)
    {
        this->dataSize = 2;
        this->totalSize = 3;
    }

    else if (this->dataType == NVBTYPE_INT32 || this->dataType == NVBTYPE_UINT32 || this->dataType == NVBTYPE_FLOAT)
    {
        this->dataSize = 4;
        this->totalSize = 5;
    }

    else if (this->dataType == NVBTYPE_INT64 || this->dataType == NVBTYPE_UINT64 || this->dataType == NVBTYPE_DOUBLE)
    {
        this->dataSize = 8;
        this->totalSize = 9;
    }

    else
    {
        size_t size = 0;
        memcpy(&size, byteified + 1, 4);
        this->dataSize = size;
        this->totalSize = 5 + size;
    }

    this->dataByte = new uint8_t[this->totalSize];
    memcpy(this->dataByte, byteified, this->totalSize);
}

NVByteifyItem::NVByteifyItem(const char val)
{
    this->dataType = NVBTYPE_CHAR;
    this->dataSize = sizeof(char);
    this->totalSize = sizeof(char) + 1;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const int8_t val)
{
    this->dataType = NVBTYPE_INT8;
    this->dataSize = sizeof(int8_t);
    this->totalSize = sizeof(int8_t) + 1;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const int16_t val)
{
    this->dataType = NVBTYPE_INT16;
    this->dataSize = sizeof(int16_t);
    this->totalSize = sizeof(int16_t) + 1;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const int32_t val)
{
    this->dataType = NVBTYPE_INT32;
    this->dataSize = sizeof(int32_t);
    this->totalSize = sizeof(int32_t) + 1;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const int64_t val)
{
    this->dataType = NVBTYPE_INT64;
    this->dataSize = sizeof(int64_t);
    this->totalSize = sizeof(int64_t) + 1;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const uint8_t val)
{
    this->dataType = NVBTYPE_UINT8;
    this->dataSize = sizeof(uint8_t);
    this->totalSize = sizeof(uint8_t) + 1;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const uint16_t val)
{
    this->dataType = NVBTYPE_UINT16;
    this->dataSize = sizeof(uint16_t);
    this->totalSize = sizeof(uint16_t) + 1;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const uint32_t val)
{
    this->dataType = NVBTYPE_UINT32;
    this->dataSize = sizeof(uint32_t);
    this->totalSize = sizeof(uint32_t) + 1;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const uint64_t val)
{
    this->dataType = NVBTYPE_UINT64;
    this->dataSize = sizeof(uint64_t);
    this->totalSize = sizeof(uint64_t) + 1;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const float val)
{
    this->dataType = NVBTYPE_FLOAT;
    this->dataSize = sizeof(float);
    this->totalSize = sizeof(float) + 1;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const double val)
{
    this->dataType = NVBTYPE_DOUBLE;
    this->dataSize = sizeof(double);
    this->totalSize = sizeof(double) + 1;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const char *val, size_t size)
{
    this->dataType = NVBTYPE_ARRAY_CHAR;
    this->dataSize = size;
    this->totalSize = size + 5;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &size, 4);
    memcpy(this->dataByte + 5, val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const int8_t *val, size_t size)
{
    this->dataType = NVBTYPE_ARRAY_INT8;
    this->dataSize = size;
    this->totalSize = size + 5;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &size, 4);
    memcpy(this->dataByte + 5, val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const int16_t *val, size_t size)
{
    this->dataType = NVBTYPE_ARRAY_INT16;
    this->dataSize = size;
    this->totalSize = size + 5;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &size, 4);
    memcpy(this->dataByte + 5, val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const int32_t *val, size_t size)
{
    this->dataType = NVBTYPE_ARRAY_INT32;
    this->dataSize = size;
    this->totalSize = size + 5;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &size, 4);
    memcpy(this->dataByte + 5, val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const int64_t *val, size_t size)
{
    this->dataType = NVBTYPE_ARRAY_INT64;
    this->dataSize = size;
    this->totalSize = size + 5;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &size, 4);
    memcpy(this->dataByte + 5, val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const uint8_t *val, size_t size)
{
    this->dataType = NVBTYPE_ARRAY_UINT8;
    this->dataSize = size;
    this->totalSize = size + 5;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &size, 4);
    memcpy(this->dataByte + 5, val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const uint16_t *val, size_t size)
{
    this->dataType = NVBTYPE_ARRAY_UINT16;
    this->dataSize = size;
    this->totalSize = size + 5;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &size, 4);
    memcpy(this->dataByte + 5, val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const uint32_t *val, size_t size)
{
    this->dataType = NVBTYPE_ARRAY_UINT32;
    this->dataSize = size;
    this->totalSize = size + 5;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &size, 4);
    memcpy(this->dataByte + 5, val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const uint64_t *val, size_t size)
{
    this->dataType = NVBTYPE_ARRAY_UINT64;
    this->dataSize = size;
    this->totalSize = size + 5;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &size, 4);
    memcpy(this->dataByte + 5, val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const float *val, size_t size)
{
    this->dataType = NVBTYPE_ARRAY_FLOAT;
    this->dataSize = size;
    this->totalSize = size + 5;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &size, 4);
    memcpy(this->dataByte + 5, val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const double *val, size_t size)
{
    this->dataType = NVBTYPE_ARRAY_DOUBLE;
    this->dataSize = size;
    this->totalSize = size + 5;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &size, 4);
    memcpy(this->dataByte + 5, val, this->dataSize);
}

NVByteifyItem::NVByteifyItem(const void *val, size_t size)
{
    this->dataType = NVBTYPE_CUSTOM;
    this->dataSize = size;
    this->totalSize = size + 5;

    this->dataByte = new uint8_t[this->totalSize];
    this->dataByte[0] = this->dataType;
    memcpy(this->dataByte + 1, &size, 4);
    memcpy(this->dataByte + 5, val, this->dataSize);
}

NVByteifyItem::~NVByteifyItem()
{
    delete[] this->dataByte;
}

uint8_t NVByteifyItem::getType()
{
    return this->dataType;
}

size_t NVByteifyItem::getSize()
{
    return this->dataSize;
}

size_t NVByteifyItem::getTotalSize()
{
    return this->totalSize;
}

void NVByteifyItem::getValue(void *buffer)
{
    if (this->dataType < NVBTYPE_ARRAY_CHAR)
        memcpy(buffer, this->dataByte + 1, this->dataSize);
    else
        memcpy(buffer, this->dataByte + 5, this->dataSize);
}

void NVByteifyItem::getBytes(uint8_t *buffer)
{
    memcpy(buffer, this->dataByte, this->totalSize);
}

NVByteify::NVByteify(const size_t n)
{
    this->items = new NVByteifyItem[n];
    this->itemNum = n;
}

NVByteify::NVByteify(const uint8_t *bytes, size_t size)
{
    uint32_t i = 0;
    size_t n = 0;
    while (i < size)
    {
        if (bytes[i] == NVBTYPE_CHAR || bytes[i] == NVBTYPE_INT8 || bytes[i] == NVBTYPE_UINT8)
            i += 2;

        else if (bytes[i] == NVBTYPE_INT16 || bytes[i] == NVBTYPE_UINT16)
            i += 3;

        else if (bytes[i] == NVBTYPE_INT32 || bytes[i] == NVBTYPE_UINT32 || bytes[i] == NVBTYPE_FLOAT)
            i += 5;

        else if (bytes[i] == NVBTYPE_INT64 || bytes[i] == NVBTYPE_UINT64 || bytes[i] == NVBTYPE_DOUBLE)
            i += 9;

        else
        {
            size_t size;
            memcpy(&size, (bytes + i) + 1, 4);
            i += 5 + size;
        }

        n++;
    }

    this->items = new NVByteifyItem[n];
    this->itemNum = n;
    size_t j = 0;
    i = 0;
    while (i < size)
    {
        this->setItem(j, NVByteifyItem(bytes + i));
        j++;

        if (bytes[i] == NVBTYPE_CHAR || bytes[i] == NVBTYPE_INT8 || bytes[i] == NVBTYPE_UINT8)
            i += 2;

        else if (bytes[i] == NVBTYPE_INT16 || bytes[i] == NVBTYPE_UINT16)
            i += 3;

        else if (bytes[i] == NVBTYPE_INT32 || bytes[i] == NVBTYPE_UINT32 || bytes[i] == NVBTYPE_FLOAT)
            i += 5;

        else if (bytes[i] == NVBTYPE_INT64 || bytes[i] == NVBTYPE_UINT64 || bytes[i] == NVBTYPE_DOUBLE)
            i += 9;

        else
        {
            size_t size;
            memcpy(&size, (bytes + i) + 1, 4);
            i += 5 + size;
        }
    }
}

NVByteify::~NVByteify()
{
}

void NVByteify::setItem(uint32_t index, const NVByteifyItem &item)
{
    uint32_t idx = (index >= this->itemNum) ? this->itemNum - 1 : index;
    this->items[idx].~NVByteifyItem();
    this->items[idx] = item;
}

void NVByteify::getItem(uint32_t index, void *buffer)
{
    uint32_t idx = (index >= this->itemNum) ? this->itemNum - 1 : index;
    this->items[idx].getValue(buffer);
}

size_t NVByteify::getItemNum()
{
    return this->itemNum;
}

size_t NVByteify::getSize()
{
    size_t size = 0;
    for (size_t i = 0; i < this->itemNum; ++i)
    {
        size += (this->items + i)->getTotalSize();
    }
    return size;
}

void NVByteify::byteify(uint8_t *buffer)
{
    size_t chunkSize = 0;
    for (size_t i = 0; i < this->itemNum; ++i)
    {
        this->items[i].getBytes(buffer + chunkSize);
        chunkSize += this->items[i].getTotalSize();
    }
}
