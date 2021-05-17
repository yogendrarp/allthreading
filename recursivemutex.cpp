#include <iostream>
#include <thread>
#include <mutex>

using namespace std;


//Example 1: With recursion
// std::recursive_mutex m1;
// int buffer = 0;

// void recursion(char c, int loopFor)
// {
//     if (loopFor < 0)
//         return;

//     m1.lock();
//     cout << c << " " << buffer++ << endl;
//     recursion(c, --loopFor);
//     m1.unlock();
//     cout<<"Unlock by "<<c<<endl;
// }

// int main()
// {
//     thread t1(recursion, '0', 10);
//     thread t2(recursion, '1', 10);

//     t1.join();
//     t2.join();
// }


std::recursive_mutex m1;

int main()
{
    for(int i=0;i<5;i++){
        m1.lock();
        std::cout<<"locked "<<i<<endl;
    }

    for(int i=0;i<5;i++){
        m1.unlock();
        std::cout<<"unlocked "<<i<<endl;
    }

}