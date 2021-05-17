#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <future>

using namespace std;
using namespace std::chrono;

typedef long int ull;

void findOdd(std::promise<ull> &&oddSumPrice, ull start, ull end)
{
    ull oddSum = 0;
    for (ull i = start; i <= end; ++i)
    {
        if (i & 1)
        {
            oddSum += i;
        }
    }
    //std::this_thread::sleep_for(chrono::seconds(3));
    oddSumPrice.set_value(oddSum);
}

int main()
{
    ull start = 0, end = 10;

    std::promise<ull> oddSum;
    std::future<ull> oddFuture = oddSum.get_future();

    cout << "Thread Created " << endl;
    std::thread t1(findOdd, std::move(oddSum), start, end);


    cout<< "Waiting for result"<<endl;

    cout<< "Future "<<oddFuture.get()<<endl;

    t1.detach();
    return 0;
}