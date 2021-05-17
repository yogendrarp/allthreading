#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <future>

using namespace std;
using namespace std::chrono;
typedef long int ull;

ull findOdd(ull start, ull end)
{
    ull oddSum = 0;
    for (ull i = start; i <= end; i++)
    {
        if (i & 1)
        {
            oddSum += i;
        }
    }
    return oddSum;
}

int main()
{
    ull start = 0, end = 10;
    std::future<ull> oddSum = std::async(std::launch::async, findOdd, start, end);
    //std::future<ull> oddSum = std::async(std::launch::deferred, findOdd, start, end); creates task at get!!
    cout << "Oddsum : " << oddSum.get() << endl;
    cout << "Completed !!" << endl;
}