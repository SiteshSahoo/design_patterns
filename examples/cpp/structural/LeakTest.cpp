#include <iostream>

int main() {
    auto x = new int(10);
    delete x;
    //delete x;
    std::cout << *x;
}

