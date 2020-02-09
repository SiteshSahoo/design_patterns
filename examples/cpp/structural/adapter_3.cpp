#include<iostream>

using namespace std;

//Interface class for Duck
class Duck {
public:
    virtual void quak() = 0;

    virtual void fly() = 0;
};

class MallardDuck : public Duck {
public:
    void quak() override {
        std::cout << "Quak Quak!!\n";
    }

    void fly() override {
        std::cout << "I am flying!!\n";
    }
};


class Turkey {
public:
    virtual void gobble() = 0;

    virtual void fly() = 0;
};

class WildTurkey : public Turkey {
public:
    void gobble() override {
        std::cout << "Gobble Gobble!!\n";
    }

    void fly() override {
        std::cout << "I am flying short distance!!\n";
    }
};


class TurkeyAdapter : public Duck {
public:
    WildTurkey turkey;

    explicit TurkeyAdapter(const WildTurkey &turkey) {
        this->turkey = turkey;
    }

    void quak() override {
        turkey.gobble();
    }

    void fly() override {
        for (int i = 0; i < 5; i++) {
            turkey.fly();
        }
    }

};


int main() {
    auto *mDuck = new MallardDuck();
    mDuck->quak();
    mDuck->fly();

    auto *wTurkey = new WildTurkey();
    Duck *turkeyAdapter = new TurkeyAdapter(*wTurkey);
    turkeyAdapter->fly();
    turkeyAdapter->quak();

}