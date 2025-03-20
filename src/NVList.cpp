#include "NVList.h"

NVListItem::NVListItem()
{
    this->next = nullptr;
    this->value = nullptr;
    this->type = 0;
}

NVListItem::~NVListItem()
{
    this->clear();
}

void NVListItem::clear()
{
    if (this->type == NVListItem::TYPE_UNDEFINED || this->value == nullptr)
        return;

    switch (this->type)
    {
    case NVListItem::TYPE_CHAR:
        delete (char *)this->value;
        break;
    case NVListItem::TYPE_INT8:
        delete (int8_t *)this->value;
        break;
    case NVListItem::TYPE_INT16:
        delete (int16_t *)this->value;
        break;
    case NVListItem::TYPE_INT32:
        delete (int32_t *)this->value;
        break;
    case NVListItem::TYPE_INT64:
        delete (int64_t *)this->value;
        break;
    case NVListItem::TYPE_UINT8:
        delete (uint8_t *)this->value;
        break;
    case NVListItem::TYPE_UINT16:
        delete (uint16_t *)this->value;
        break;
    case NVListItem::TYPE_UINT32:
        delete (uint32_t *)this->value;
        break;
    case NVListItem::TYPE_UINT64:
        delete (uint64_t *)this->value;
        break;
    case NVListItem::TYPE_FLOAT:
        delete (float *)this->value;
        break;
    case NVListItem::TYPE_DOUBLE:
        delete (double *)this->value;
        break;
    case NVListItem::TYPE_STRING:
        delete (String *)this->value;
        break;
    }

    this->value = nullptr;
    this->type = NVListItem::TYPE_UNDEFINED;
}

void NVListItem::operator=(const char val)
{
    this->clear();
    char *newVal = new char;
    *newVal = val;
    this->value = (void *)newVal;
}

void NVListItem::operator=(const int8_t val)
{
    this->clear();
    int8_t *newVal = new int8_t;
    *newVal = val;
    this->value = (void *)newVal;
}

void NVListItem::operator=(const int16_t val)
{
    this->clear();
    int16_t *newVal = new int16_t;
    *newVal = val;
    this->value = (void *)newVal;
}

void NVListItem::operator=(const int32_t val)
{
    this->clear();
    int32_t *newVal = new int32_t;
    *newVal = val;
    this->value = (void *)newVal;
}

void NVListItem::operator=(const int64_t val)
{
    this->clear();
    int64_t *newVal = new int64_t;
    *newVal = val;
    this->value = (void *)newVal;
}

void NVListItem::operator=(const uint8_t val)
{
    this->clear();
    uint8_t *newVal = new uint8_t;
    *newVal = val;
    this->value = (void *)newVal;
}

void NVListItem::operator=(const uint16_t val)
{
    this->clear();
    uint16_t *newVal = new uint16_t;
    *newVal = val;
    this->value = (void *)newVal;
}

void NVListItem::operator=(const uint32_t val)
{
    this->clear();
    uint32_t *newVal = new uint32_t;
    *newVal = val;
    this->value = (void *)newVal;
}

void NVListItem::operator=(const uint64_t val)
{
    this->clear();
    uint64_t *newVal = new uint64_t;
    *newVal = val;
    this->value = (void *)newVal;
}

void NVListItem::operator=(const float val)
{
    this->clear();
    float *newVal = new float;
    *newVal = val;
    this->value = (void *)newVal;
}

void NVListItem::operator=(const double val)
{
    this->clear();
    double *newVal = new double;
    *newVal = val;
    this->value = (void *)newVal;
}

void NVListItem::operator=(const String val)
{
    this->clear();
    String *newVal = new String;
    *newVal = val;
    this->value = (void *)newVal;
}

char NVListItem::asChar()
{
    return *(char *)this->value;
}

int8_t NVListItem::asInt8()
{
    return *(int8_t *)this->value;
}

int16_t NVListItem::asInt16()
{
    return *(int16_t *)this->value;
}

int32_t NVListItem::asInt32()
{
    return *(int32_t *)this->value;
}

int64_t NVListItem::asInt64()
{
    return *(int64_t *)this->value;
}

uint8_t NVListItem::asUInt8()
{
    return *(uint8_t *)this->value;
}

uint16_t NVListItem::asUInt16()
{
    return *(uint16_t *)this->value;
}

uint32_t NVListItem::asUInt32()
{
    return *(uint32_t *)this->value;
}

uint64_t NVListItem::asUInt64()
{
    return *(uint64_t *)this->value;
}

float NVListItem::asFloat()
{
    return *(float *)this->value;
}

double NVListItem::asDouble()
{
    return *(double *)this->value;
}

String NVListItem::asString()
{
    return *(String *)this->value;
}

NVList::NVList()
{
    this->head = nullptr;
    this->len = 0;
}

NVList::~NVList()
{
    while (this->len > 0)
    {
        this->pop(0);
    }
}

void NVList::append(const char val)
{
    NVListItem *newItem = new NVListItem;
    *newItem = val;

    if (this->len == 0)
    {
        this->head = newItem;
    }
    else
    {
        NVListItem *tempItem = this->head;
        while (tempItem->next != nullptr)
        {
            tempItem = tempItem->next;
        }
        tempItem->next = newItem;
    }

    this->len++;
}

void NVList::append(const int8_t val)
{
    NVListItem *newItem = new NVListItem;
    *newItem = val;

    if (this->len == 0)
    {
        this->head = newItem;
    }
    else
    {
        NVListItem *tempItem = this->head;
        while (tempItem->next != nullptr)
        {
            tempItem = tempItem->next;
        }
        tempItem->next = newItem;
    }

    this->len++;
}

void NVList::append(const int16_t val)
{
    NVListItem *newItem = new NVListItem;
    *newItem = val;

    if (this->len == 0)
    {
        this->head = newItem;
    }
    else
    {
        NVListItem *tempItem = this->head;
        while (tempItem->next != nullptr)
        {
            tempItem = tempItem->next;
        }
        tempItem->next = newItem;
    }

    this->len++;
}

void NVList::append(const int32_t val)
{
    NVListItem *newItem = new NVListItem;
    *newItem = val;

    if (this->len == 0)
    {
        this->head = newItem;
    }
    else
    {
        NVListItem *tempItem = this->head;
        while (tempItem->next != nullptr)
        {
            tempItem = tempItem->next;
        }
        tempItem->next = newItem;
    }

    this->len++;
}

void NVList::append(const int64_t val)
{
    NVListItem *newItem = new NVListItem;
    *newItem = val;

    if (this->len == 0)
    {
        this->head = newItem;
    }
    else
    {
        NVListItem *tempItem = this->head;
        while (tempItem->next != nullptr)
        {
            tempItem = tempItem->next;
        }
        tempItem->next = newItem;
    }

    this->len++;
}

void NVList::append(const uint8_t val)
{
    NVListItem *newItem = new NVListItem;
    *newItem = val;

    if (this->len == 0)
    {
        this->head = newItem;
    }
    else
    {
        NVListItem *tempItem = this->head;
        while (tempItem->next != nullptr)
        {
            tempItem = tempItem->next;
        }
        tempItem->next = newItem;
    }

    this->len++;
}

void NVList::append(const uint16_t val)
{
    NVListItem *newItem = new NVListItem;
    *newItem = val;

    if (this->len == 0)
    {
        this->head = newItem;
    }
    else
    {
        NVListItem *tempItem = this->head;
        while (tempItem->next != nullptr)
        {
            tempItem = tempItem->next;
        }
        tempItem->next = newItem;
    }

    this->len++;
}

void NVList::append(const uint32_t val)
{
    NVListItem *newItem = new NVListItem;
    *newItem = val;

    if (this->len == 0)
    {
        this->head = newItem;
    }
    else
    {
        NVListItem *tempItem = this->head;
        while (tempItem->next != nullptr)
        {
            tempItem = tempItem->next;
        }
        tempItem->next = newItem;
    }

    this->len++;
}

void NVList::append(const uint64_t val)
{
    NVListItem *newItem = new NVListItem;
    *newItem = val;

    if (this->len == 0)
    {
        this->head = newItem;
    }
    else
    {
        NVListItem *tempItem = this->head;
        while (tempItem->next != nullptr)
        {
            tempItem = tempItem->next;
        }
        tempItem->next = newItem;
    }

    this->len++;
}

void NVList::append(const float val)
{
    NVListItem *newItem = new NVListItem;
    *newItem = val;

    if (this->len == 0)
    {
        this->head = newItem;
    }
    else
    {
        NVListItem *tempItem = this->head;
        while (tempItem->next != nullptr)
        {
            tempItem = tempItem->next;
        }
        tempItem->next = newItem;
    }

    this->len++;
}

void NVList::append(const double val)
{
    NVListItem *newItem = new NVListItem;
    *newItem = val;

    if (this->len == 0)
    {
        this->head = newItem;
    }
    else
    {
        NVListItem *tempItem = this->head;
        while (tempItem->next != nullptr)
        {
            tempItem = tempItem->next;
        }
        tempItem->next = newItem;
    }

    this->len++;
}

void NVList::append(const String val)
{
    NVListItem *newItem = new NVListItem;
    *newItem = val;

    if (this->len == 0)
    {
        this->head = newItem;
    }
    else
    {
        NVListItem *tempItem = this->head;
        while (tempItem->next != nullptr)
        {
            tempItem = tempItem->next;
        }
        tempItem->next = newItem;
    }

    this->len++;
}

void NVList::insert(const uint16_t index, const char val)
{

    uint16_t idx = (index > this->len) ? this->len : index;

    if (this->len == 0 || idx == this->len)
        this->append(val);
    else
    {
        NVListItem *tempItem = this->head;
        NVListItem *prevItem = nullptr;
        NVListItem *newItem = new NVListItem;
        *newItem = val;

        for (uint16_t i = 0; i < idx; ++i)
        {
            prevItem = tempItem;
            tempItem = tempItem->next;
        }

        if (idx == 0)
        {
            newItem->next = this->head;
            this->head = newItem;
        }
        else
        {
            prevItem->next = newItem;
            newItem->next = tempItem;
        }

        this->len++;
    }
}

void NVList::insert(const uint16_t index, const int8_t val)
{

    uint16_t idx = (index > this->len) ? this->len : index;

    if (this->len == 0 || idx == this->len)
        this->append(val);
    else
    {
        NVListItem *tempItem = this->head;
        NVListItem *prevItem = nullptr;
        NVListItem *newItem = new NVListItem;
        *newItem = val;

        for (uint16_t i = 0; i < idx; ++i)
        {
            prevItem = tempItem;
            tempItem = tempItem->next;
        }

        if (idx == 0)
        {
            newItem->next = this->head;
            this->head = newItem;
        }
        else
        {
            prevItem->next = newItem;
            newItem->next = tempItem;
        }

        this->len++;
    }
}

void NVList::insert(const uint16_t index, const int16_t val)
{

    uint16_t idx = (index > this->len) ? this->len : index;

    if (this->len == 0 || idx == this->len)
        this->append(val);
    else
    {
        NVListItem *tempItem = this->head;
        NVListItem *prevItem = nullptr;
        NVListItem *newItem = new NVListItem;
        *newItem = val;

        for (uint16_t i = 0; i < idx; ++i)
        {
            prevItem = tempItem;
            tempItem = tempItem->next;
        }

        if (idx == 0)
        {
            newItem->next = this->head;
            this->head = newItem;
        }
        else
        {
            prevItem->next = newItem;
            newItem->next = tempItem;
        }

        this->len++;
    }
}

void NVList::insert(const uint16_t index, const int32_t val)
{

    uint16_t idx = (index > this->len) ? this->len : index;

    if (this->len == 0 || idx == this->len)
        this->append(val);
    else
    {
        NVListItem *tempItem = this->head;
        NVListItem *prevItem = nullptr;
        NVListItem *newItem = new NVListItem;
        *newItem = val;

        for (uint16_t i = 0; i < idx; ++i)
        {
            prevItem = tempItem;
            tempItem = tempItem->next;
        }

        if (idx == 0)
        {
            newItem->next = this->head;
            this->head = newItem;
        }
        else
        {
            prevItem->next = newItem;
            newItem->next = tempItem;
        }

        this->len++;
    }
}

void NVList::insert(const uint16_t index, const int64_t val)
{

    uint16_t idx = (index > this->len) ? this->len : index;

    if (this->len == 0 || idx == this->len)
        this->append(val);
    else
    {
        NVListItem *tempItem = this->head;
        NVListItem *prevItem = nullptr;
        NVListItem *newItem = new NVListItem;
        *newItem = val;

        for (uint16_t i = 0; i < idx; ++i)
        {
            prevItem = tempItem;
            tempItem = tempItem->next;
        }

        if (idx == 0)
        {
            newItem->next = this->head;
            this->head = newItem;
        }
        else
        {
            prevItem->next = newItem;
            newItem->next = tempItem;
        }

        this->len++;
    }
}

void NVList::insert(const uint16_t index, const uint8_t val)
{

    uint16_t idx = (index > this->len) ? this->len : index;

    if (this->len == 0 || idx == this->len)
        this->append(val);
    else
    {
        NVListItem *tempItem = this->head;
        NVListItem *prevItem = nullptr;
        NVListItem *newItem = new NVListItem;
        *newItem = val;

        for (uint16_t i = 0; i < idx; ++i)
        {
            prevItem = tempItem;
            tempItem = tempItem->next;
        }

        if (idx == 0)
        {
            newItem->next = this->head;
            this->head = newItem;
        }
        else
        {
            prevItem->next = newItem;
            newItem->next = tempItem;
        }

        this->len++;
    }
}

void NVList::insert(const uint16_t index, const uint16_t val)
{

    uint16_t idx = (index > this->len) ? this->len : index;

    if (this->len == 0 || idx == this->len)
        this->append(val);
    else
    {
        NVListItem *tempItem = this->head;
        NVListItem *prevItem = nullptr;
        NVListItem *newItem = new NVListItem;
        *newItem = val;

        for (uint16_t i = 0; i < idx; ++i)
        {
            prevItem = tempItem;
            tempItem = tempItem->next;
        }

        if (idx == 0)
        {
            newItem->next = this->head;
            this->head = newItem;
        }
        else
        {
            prevItem->next = newItem;
            newItem->next = tempItem;
        }

        this->len++;
    }
}

void NVList::insert(const uint16_t index, const uint32_t val)
{

    uint16_t idx = (index > this->len) ? this->len : index;

    if (this->len == 0 || idx == this->len)
        this->append(val);
    else
    {
        NVListItem *tempItem = this->head;
        NVListItem *prevItem = nullptr;
        NVListItem *newItem = new NVListItem;
        *newItem = val;

        for (uint16_t i = 0; i < idx; ++i)
        {
            prevItem = tempItem;
            tempItem = tempItem->next;
        }

        if (idx == 0)
        {
            newItem->next = this->head;
            this->head = newItem;
        }
        else
        {
            prevItem->next = newItem;
            newItem->next = tempItem;
        }

        this->len++;
    }
}

void NVList::insert(const uint16_t index, const uint64_t val)
{

    uint16_t idx = (index > this->len) ? this->len : index;

    if (this->len == 0 || idx == this->len)
        this->append(val);
    else
    {
        NVListItem *tempItem = this->head;
        NVListItem *prevItem = nullptr;
        NVListItem *newItem = new NVListItem;
        *newItem = val;

        for (uint16_t i = 0; i < idx; ++i)
        {
            prevItem = tempItem;
            tempItem = tempItem->next;
        }

        if (idx == 0)
        {
            newItem->next = this->head;
            this->head = newItem;
        }
        else
        {
            prevItem->next = newItem;
            newItem->next = tempItem;
        }

        this->len++;
    }
}

void NVList::insert(const uint16_t index, const float val)
{

    uint16_t idx = (index > this->len) ? this->len : index;

    if (this->len == 0 || idx == this->len)
        this->append(val);
    else
    {
        NVListItem *tempItem = this->head;
        NVListItem *prevItem = nullptr;
        NVListItem *newItem = new NVListItem;
        *newItem = val;

        for (uint16_t i = 0; i < idx; ++i)
        {
            prevItem = tempItem;
            tempItem = tempItem->next;
        }

        if (idx == 0)
        {
            newItem->next = this->head;
            this->head = newItem;
        }
        else
        {
            prevItem->next = newItem;
            newItem->next = tempItem;
        }

        this->len++;
    }
}

void NVList::insert(const uint16_t index, const double val)
{

    uint16_t idx = (index > this->len) ? this->len : index;

    if (this->len == 0 || idx == this->len)
        this->append(val);
    else
    {
        NVListItem *tempItem = this->head;
        NVListItem *prevItem = nullptr;
        NVListItem *newItem = new NVListItem;
        *newItem = val;

        for (uint16_t i = 0; i < idx; ++i)
        {
            prevItem = tempItem;
            tempItem = tempItem->next;
        }

        if (idx == 0)
        {
            newItem->next = this->head;
            this->head = newItem;
        }
        else
        {
            prevItem->next = newItem;
            newItem->next = tempItem;
        }

        this->len++;
    }
}

void NVList::insert(const uint16_t index, const String val)
{

    uint16_t idx = (index > this->len) ? this->len : index;

    if (this->len == 0 || idx == this->len)
        this->append(val);
    else
    {
        NVListItem *tempItem = this->head;
        NVListItem *prevItem = nullptr;
        NVListItem *newItem = new NVListItem;
        *newItem = val;

        for (uint16_t i = 0; i < idx; ++i)
        {
            prevItem = tempItem;
            tempItem = tempItem->next;
        }

        if (idx == 0)
        {
            newItem->next = this->head;
            this->head = newItem;
        }
        else
        {
            prevItem->next = newItem;
            newItem->next = tempItem;
        }

        this->len++;
    }
}

NVListItem NVList::pop(const uint16_t index)
{
    if (this->len == 0)
        return NVListItem();

    uint16_t idx = (index > (this->len - 1)) ? (this->len - 1) : index;
    NVListItem *tempItem = this->head;
    NVListItem *prevItem = nullptr;

    for (uint16_t i = 0; i < idx; ++i)
    {
        prevItem = tempItem;
        tempItem = tempItem->next;
    }

    if (prevItem == nullptr)
        this->head = tempItem->next;
    else
        prevItem->next = tempItem->next;

    NVListItem retVal = *tempItem;
    retVal.next = nullptr;

    tempItem->clear();
    delete tempItem;
    this->len--;
    return retVal;
}

NVListItem &NVList::operator[](const uint16_t index)
{
    uint16_t idx = (index > (this->len - 1)) ? (this->len - 1) : index;
    NVListItem *tempItem = this->head;

    for (uint16_t i = 0; (i < idx) && (i < this->len); ++i)
    {
        tempItem = tempItem->next;
    }
    return *tempItem;
}

uint16_t NVList::length()
{
    return this->len;
}