#include <iostream>
#include <thread>
#include <mutex>

#include <chrono>

using namespace std::chrono;
using namespace std;

int myAmount = 0;

std::mutex m;

int counter=0;

void increaseCounterInLoop(){
    for(int i=0;i<100000;i++){
        // if(m.try_lock()){
        //     ++counter;
        //     m.unlock();
        // }
        ++counter;
    }
}

void addMoney()
{
    int am = myAmount;
    if (m.try_lock())
    {
        cout<<"Obtained lock"<<endl;
        std::this_thread::sleep_for(chrono::seconds(2));
        myAmount = am + 1;
        m.unlock();
    }
}

int main()
{
    // thread t1(addMoney);
    // thread t2(addMoney);
    // thread t3(addMoney);
    // thread t4(addMoney);
    // thread t5(addMoney);

    // t1.join();
    // t2.join();
    // t3.join();
    // t4.join();
    // t5.join();

    thread t1(increaseCounterInLoop);
    thread t2(increaseCounterInLoop);

    t1.join();
    t2.join();

    cout << counter << endl;
}