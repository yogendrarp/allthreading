#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;

void findEvenSum(ull start, ull end)
{
    for (ull i = start; i <= end; i++)
    {
        
        if (i % 2 == 0)
        {
            evenSum += i;
        }
    }
}

void findOddSum(ull start, ull end)
{
    for (ull i = start; i <= end; i++)
    {
     
        if (i % 2 == 0)
        {
            oddSum += i;
        }
    }
}

int main()
{
    ull start = 0, end = 1900000000;
    auto startTime = high_resolution_clock::now();

    std::thread t1(findEvenSum,start,end);
    std::thread t2(findOddSum,start,end);
    t1.join();
    t2.join();
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime-startTime);
    cout << "Oddsum : " << oddSum << endl;
    cout << "Evensum : " << evenSum << endl;
    cout<<"duration for computation is : "<< duration.count()/1000000<< " sec"<<endl;

}