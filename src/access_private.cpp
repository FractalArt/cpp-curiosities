/**
 * In this example, a private method of a derived class is called
 * through a pointer of the base class type.
 * 
 * Answer can be found on stack overflow:
 * https://stackoverflow.com/questions/3610936/why-can-i-access-a-derived-private-member-function-via-a-base-class-pointer-to-a
 */
#include <iostream>
#include <memory>

class Base {
public:
    virtual ~Base() = default;
    virtual void print() = 0;
};

class Derived : public Base {
private:
    // This method is private
    void print() override { std::cout << "I am private!" << std::endl; }
};

int main() {
    std::unique_ptr<Derived> derived_ptr = std::make_unique<Derived>();
    // This won't work because for Derived the method is private
    // derived_ptr->print();

    std::unique_ptr<Base> base_ptr = std::make_unique<Derived>();
    base_ptr->print();
    return 0;
}
