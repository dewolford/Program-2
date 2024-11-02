#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

template <typename T>
class SmartPointer {
private:
    T* ptr;

public:
    explicit SmartPointer(T* p = nullptr) : ptr(p) {}
    ~SmartPointer() { delete ptr; }

    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
    T* get() const { return ptr; }

    bool operator==(const SmartPointer& other) const { return ptr == other.ptr; }
    bool operator!=(const SmartPointer& other) const { return !(*this == other); }
};

#endif
