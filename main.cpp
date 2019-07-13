#include <cstdint>
#include <iostream>
#include <string>

struct LongInt
{
    LongInt(int left, int right) : left(left), right(right) {}
    LongInt(std::string tekst) : left (stoi(tekst)/100), right(stoi(tekst)%100)
    {
    }

    std::string toString()
    {
        return std::to_string(left) + std::to_string(right);
    }

    void operator+=(const LongInt& r)
    {
        left += r.left;
        right += r.right;
        left += right / 100;
        right = right % 100;
    }

    LongInt& operator=(const LongInt& other)
    {
        left = other.left;
        right = other.right;
        return *this;
    }

    int left;
    int right;
};

int main()
{
    LongInt int1(1, 70);
    LongInt int3("467");
    // 170

    LongInt int2(5, 70);
    // 570

    int1 += int2;

    //740
    std::cout << int1.toString() << std::endl;

    int1 = int2;
    std::cout << int1.toString() << std::endl;
}
