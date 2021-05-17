#include <iostream>
#include <thread>
using namespace std;

// 1. Function Pointers

// void fun(int x){
//     while(x-- > 0){
//         cout<<x<<endl;
//     }
// }

// int main(){
//     std::thread t1(fun,10);
//     std::thread t2(fun,32);

// }

//2. Lambda Functions

// int main()
// {
//     auto fun = [](int x) {
//         while (x-- > 0)
//         {
//             cout << x << endl;
//         }
//     }

//     std::thread t(fun, 10);
//     // we can also create like this

//     std:: thread t1([](int x){
//         while (x-- > 0)
//         {
//             cout << x << endl;
//         }, 20);
//         t.join();
// }

// 3. Function Pointer object functor

// class Base{
//     public:
//         void operator ()(int x){
//             while (x-- >0)
//             {
//                 cout<<x<<endl;
//             }

//         }
// };

// int main(){
//     std::thread t((Base()),10);
//     t.join();
//     return 0;
// }

// 4. Non static member function

// class Base
// {
// public:
//     void run(int x)
//     {
//         while (x-- > 0)
//         {
//             cout << x << endl;
//         }
//     }
// };


// int main(){
//     Base b;
//     std::thread t(&Base::run,&b,10);
//     t.join();
// }



// 4. static member function

class Base
{
public:
    static void run(int x)
    {
        while (x-- > 0)
        {
            cout << x << endl;
        }
    }
};


int main(){
    std::thread t(&Base::run,10);
    t.join();
}