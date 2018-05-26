//
// Created by mgabi on 19.04.2018.
//

#include <utility>
#include "../headers/RepoMemory.h"

vector<MemoryAllocation> RepoMemory::getAllStatic() {
    return this->staticMemories;
}

vector<MemoryAllocation> RepoMemory::getAllDynamic() {
    return this->dynamicMemories;
}

void RepoMemory::addStatic(MemoryAllocation allocation) {
    if (this->staticOffsetFree(allocation.getOffset())){
        int pos = this->fitInsideStatic(allocation.getOffset(), allocation.getDataType());
        if (pos != -1)
            this->insertStaticOnPosition(allocation, pos-1);
        else
            this->insertStaticAtEnd(allocation);
    }
}

void RepoMemory::addDynamic(MemoryAllocation allocation) {
    if (this->dynamicOffsetFree(allocation.getOffset())){
        int pos = this->fitInsideDynamic(allocation.getOffset(), allocation.getDataType());
        if (pos != -1)
            this->insertDynamicOnPosition(allocation, pos-1);
        else
            this->insertDynamicAtEnd(allocation);
    }
}

bool RepoMemory::staticOffsetFree(int offset) {
    for (const auto &mem : this->staticMemories){
        if (mem.getOffset() == offset)
            return false;
    }
    return true;
}

int RepoMemory::fitInsideStatic(int offset, int dataSize) {
    /**
     * Find a position where a memory can be inserted
     * @return : position where to be inserted
     *          -1 if this memory has to be inserted at the end
     */
    for (int i = 0; i < this->staticMemories.size(); i++) {
        if (this->staticMemories[i].getOffset() > offset) {
            if (offset + dataSize < this->staticMemories[i].getOffset()) {
                return i;
            }
            return -1;
        }
    }
}

void RepoMemory::insertStaticOnPosition(MemoryAllocation allocation, int position) {
    MemoryAllocation newAlloc(allocation);

    this->staticMemories.push_back(MemoryAllocation{"empty", -1, "empty", -1, false});
    for (int i = static_cast<int>(this->staticMemories.size() - 1); i > position ; i--) {
        this->staticMemories[i] = this->staticMemories[i-1];
    }
    this->staticMemories[position] = newAlloc;
}

void RepoMemory::insertStaticAtEnd(MemoryAllocation allocation) {
    allocation.setOffset(this->getLastOffsetStatic() + 1);
    this->staticMemories.push_back(allocation);
}

int RepoMemory::getLastOffsetStatic() {
    return this->staticMemories[this->staticMemories.size() - 1].getOffset() + this->staticMemories[this->staticMemories.size() - 1].getDataType();
}

bool RepoMemory::dynamicOffsetFree(int offset) {
    for (const auto &mem : this->dynamicMemories){
        if (mem.getOffset() == offset)
            return false;
    }
    return true;
}

int RepoMemory::fitInsideDynamic(int offset, int dataSize) {
    /**
     * Find a position where a memory can be inserted
     * @return : position where to be inserted
     *          -1 if this memory has to be inserted at the end
     */
    for (int i = 0; i < this->dynamicMemories.size(); i++) {
        if (this->dynamicMemories[i].getOffset() > offset) {
            if (offset + dataSize < this->dynamicMemories[i].getOffset()) {
                return i;
            }
            return -1;
        }
    }
}

void RepoMemory::insertDynamicOnPosition(const MemoryAllocation &allocation, int position) {
    MemoryAllocation newAlloc(allocation);

    this->dynamicMemories.push_back(MemoryAllocation{"empty", -1, "empty", -1, false});

    for (int i = static_cast<int>(this->dynamicMemories.size()) - 1; i > position ; i--) {
        this->dynamicMemories[i] = this->dynamicMemories[i-1];
    }
    this->dynamicMemories[position] = newAlloc;
}

void RepoMemory::insertDynamicAtEnd(MemoryAllocation allocation) {
    allocation.setOffset(this->getLastOffsetDynamic() + 1);
    this->dynamicMemories.push_back(allocation);
}

int RepoMemory::getLastOffsetDynamic() {
    return this->dynamicMemories[this->dynamicMemories.size() - 1].getOffset() + this->dynamicMemories[this->dynamicMemories.size() - 1].getDataType();

}

void RepoMemory::removeStatic(string basic_string) {
    int pos = -1;
    for (int i = 0; i<this->staticMemories.size(); i++){
        if (this->staticMemories[i].getLabel() == basic_string){
            pos = i;
        }
    }

    this->staticMemories.erase(this->staticMemories.begin()+pos);
}

void RepoMemory::removeDynamic(string basic_string) {
    int pos = -1;
    for (int i = 0; i<this->dynamicMemories.size(); i++){
        if (this->dynamicMemories[i].getLabel() == basic_string){
            pos = i;
        }
    }

    this->dynamicMemories.erase(this->dynamicMemories.begin()+pos);
}

void RepoMemory::markMemory(string name) {

}

void RepoMemory::markMemoryStatic(string name) {
    for (int i = 0; i < this->staticMemories.size(); ++i) {
        if (this->staticMemories[i].getLabel() == name)
            this->staticMemories[i].setUsed(true);
    }
}

void RepoMemory::markMemoryDynamic(string basic_string) {
    for (int i = 0; i < this->dynamicMemories.size(); ++i) {
        if(this->dynamicMemories[i].getLabel() == basic_string)
            this->dynamicMemories[i].setUsed(true);
    }
}
