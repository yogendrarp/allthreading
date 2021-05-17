#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

int X = 0, Y = 0;
std::mutex m1, m2;

void doSomeWork(int seconds)
{
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void incrementXY(int &XorY, std::mutex &m, const char *desc)
{
    for (int i = 0; i < 5; i++)
    {
        m.lock();
        ++XorY;
        cout<<desc<<XorY<<endl;
        m.unlock();
        doSomeWork(1);
    }
}

void consumeXY()
{
    int useCount = 5;
    int XPlusY = 0;
    while (1)
    {
        int lockResult = std::try_lock(m1, m2);
        if (lockResult == -1)
        {
            if (X != 0 && Y != 0)
            {
                --useCount;
                XPlusY += (X + Y);
                X = 0;
                Y = 0;
                cout << "XPLUSY " << XPlusY << endl;
            }
            m1.unlock();
            m2.unlock();
            if (useCount == 0)
            {
                break;
            }
        }
    }
}

int main()
{
    thread t1(incrementXY, std::ref(X), std::ref(m1), "X ");
    thread t2(incrementXY, std::ref(Y), std::ref(m2), "X ");
    thread t3(consumeXY);

    t1.join();
    t2.join();
    t3.join();
}