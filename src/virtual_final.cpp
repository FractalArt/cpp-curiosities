// A purely virtual final class that cannot be instantiated
// and not derived from.

#include <iostream>

class UseLess final {
public:
    virtual void purely_virtual() = 0;

    static void still_useful() { std::cout << "I can't be instantiated... So what?!" << std::endl; }
};

int main() {
    UseLess::still_useful();
    return 0;
}
