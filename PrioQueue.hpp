#pragma once

#include <vector>
#include <string>

class PrioQueue {
public:
    virtual void insert(T e, int p) = 0;
    virtual T extractMax() = 0;
    virtual T findMax() const = 0;
    virtual void modifyKey(T e, int p) = 0;
    virtual size_t size() = 0;
    virtual bool hasValue(T value) = 0;
}
