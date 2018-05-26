//
// Created by mgabi on 19.04.2018.
//

#include "../../headers/MemoryAllocation.h"

const string &MemoryAllocation::getType() const {
    return this->type;
}

void MemoryAllocation::setType(const string &type) {
    this->type = type;
}

int MemoryAllocation::getOffset() const {
    return this->offset;
}

void MemoryAllocation::setOffset(int location) {
    this->offset = location;
}

const string &MemoryAllocation::getLabel() const {
    return this->label;
}

void MemoryAllocation::setLabel(const string &label) {
    this->label = label;
}

bool MemoryAllocation::isUsed() const {
    return this->used;
}

void MemoryAllocation::setUsed(bool used) {
    this->used = used;
}

int MemoryAllocation::getDataType() const {
    return this->dataType;
}

void MemoryAllocation::setDataType(int dataType) {
    this->dataType = dataType;
}

MemoryAllocation::MemoryAllocation(string type, int location, string label, int dataType, bool used) {
    this->type = type;
    this->offset = location;
    this->label = label;
    this->dataType = dataType;
    this->used = used;
}

MemoryAllocation::MemoryAllocation(const MemoryAllocation &alloc) {
    this->type = alloc.getType();
    this->offset = alloc.getOffset();
    this->label = alloc.getLabel();
    this->dataType = alloc.getDataType();
    this->used = alloc.isUsed();
}

MemoryAllocation::MemoryAllocation() = default;
