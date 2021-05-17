#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;

void fun(int x)
{
    while (x-- > 0)
    {
        cout << x << endl;
    }

    std::this_thread::sleep_for(chrono::seconds(3));
    cout<<"thread compelted"<<endl;
}

int main()
{
    std::thread t1(fun, 10);
    std::thread t2(fun, 100000);
    cout<<"main function"<<endl;
    t2.detach();
    t1.join();

    // Incase you dont remember 
    if (t1.joinable())
        t1.join();

    if (t2.joinable())
        t2.detach();

    

    cout<<"out of main thread"<<endl;
}