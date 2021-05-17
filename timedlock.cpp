#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std::chrono;
using namespace std;

int myAmount = 0;

std::timed_mutex m;

void increment(int i)
{
    if (m.try_lock_for(std::chrono::seconds(1)))
    {
        ++myAmount;
        std::this_thread::sleep_for(std::chrono::seconds(10));
        cout << " thread " << i << " entered \n";
        m.unlock();
    }
    else
    {
        cout << " thread " << i << " couldnt enter \n";
    }
}

int main(){
    thread t1(increment,1);    
    thread t2(increment,2);

    t1.join();
    t2.join();

    cout<<myAmount<<endl;
}