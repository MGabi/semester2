//
// Created by mgabi on 19.04.2018.
//
#include <string>
using namespace std;

#ifndef TESTW8_MEMORYALLOCATION_H
#define TESTW8_MEMORYALLOCATION_H


class MemoryAllocation {
private:
    /**
     * type:
     *  1 - static
     *  2 - dynamic
     */
    string type;

    /**
     * location in memory
     */
    int offset;

    /**
     * name of the variable
     */
    string label;

    /**
     * the size of the representation
     */
    int dataType;

    /**
     * used or not during runtime
     */
    bool used;

public:
    MemoryAllocation();
    MemoryAllocation(string type, int location, string label, int dataType, bool used);
    MemoryAllocation(const MemoryAllocation &alloc);
    int getDataType() const;

    void setDataType(int dataType);

    const string &getType() const;

    void setType(const string &type);

    int getOffset() const;

    void setOffset(int location);

    const string &getLabel() const;

    void setLabel(const string &label);

    bool isUsed() const;

    void setUsed(bool used);
};


#endif //TESTW8_MEMORYALLOCATION_H
