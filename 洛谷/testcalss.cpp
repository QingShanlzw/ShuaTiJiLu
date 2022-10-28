#include<bits/stdc++.h>


struct Animal
{
    virtual void make_voice() = 0;
    virtual std::string ClassName() const = 0;
    static std::string StaticClassName();
};
struct cat: public Animal
{
    static std::string StaticClassName()
    {
        return "cat";
    }
};
template <typename T>
Animal* CreateAnimal()
{
    auto name = T::StaticClassName();
    if(name == cat::StaticClassName())
    {
        return new cat();
    }
    else if(name == dong::StaticClassName())
    {
        return new dog();
    }
    else
    {
        return nullptr;
    }
}

struct dog: public Animal
{
    static std::string StaticClassName()
    {
        return "dog";
    }
};
int main()
{
	return 0;
}
