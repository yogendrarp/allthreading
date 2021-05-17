#include<iostream>
#include<thread>
#include<mutex>

#include <chrono>

using namespace std::chrono;
using namespace std;

int myAmount=0;

std::mutex m;

void addMoney(){
    int am=myAmount;
    cout<<"Try lock"<<endl;
    m.lock();
    cout<<"Acquired lock"<<endl;
    std::this_thread::sleep_for(chrono::seconds(3));
    myAmount=am+1;
    m.unlock();
}


int main(){
    thread t1(addMoney);
    thread t2(addMoney);
    thread t3(addMoney);
    thread t4(addMoney);
    thread t5(addMoney);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    cout<<myAmount<<endl;
}