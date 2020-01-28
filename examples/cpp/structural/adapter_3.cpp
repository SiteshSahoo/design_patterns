#include<iostream>
using namespace std;

//Interface class for Duck
class Duck
{
    public:
    virtual void quak() = 0;
    virtual void fly() = 0; 
};

class MallardDuck : public Duck
{
    public:
    virtual void quak()
    {
        std::cout<<"Quak Quak!!\n";
    }

    virtual void fly()
    {
        std::cout<<"I am flying!!\n";
    }
};


class Turkey
{
    public:
    virtual void gobble() = 0;
    virtual void fly() = 0; 
};

class WildTurkey : public Turkey
{
    public:
    virtual void gobble()
    {
        std::cout<<"Gobble Gobble!!\n";
    }

    virtual void fly()
    {
        std::cout<<"I am flying short distance!!\n";
    }
};



class TurkeyAdapter : public Duck
{
    public:
    WildTurkey turkey;
    TurkeyAdapter(const WildTurkey turkey)
    {
        this->turkey = turkey;
    }
    virtual void quak()
    {
        turkey.gobble();
    }
    virtual void fly()
    {
        for(int i = 0; i<5 ; i++)
        {
            turkey.fly();
        }
    }

};


int main()
{
    MallardDuck* mDuck = new MallardDuck();
    mDuck->quak();
    mDuck->fly();

    WildTurkey* wTurkey = new WildTurkey();
    Duck* turkeyAdapter = new TurkeyAdapter(*wTurkey);
    turkeyAdapter->fly();
    turkeyAdapter->quak();

}