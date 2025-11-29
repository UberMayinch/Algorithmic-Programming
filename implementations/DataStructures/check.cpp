#include <iostream>
#define MAX_CAPACITY 100
using namespace std;

template <typename T>

class mypair{
    private:

    public:
        mypair(T a, T b){
            p[0]=a;
            p[1]=b;
        };
        T first(){
            return p[0];
        }
        T second(){
            return p[1];
        }

    T p[2];
};

template <typename T>
class mystack {
    size_t size;
    int top;
    T arr[MAX_CAPACITY];

public:
    mystack();
    void push(T a);
    T pop();
};

// Constructor definition
template <typename T>
mystack<T>::mystack() {
    size = 0;
    top = -1;
}

// Push function definition
template <typename T>
void mystack<T>::push(T a) {
    if (size != MAX_CAPACITY) {
        arr[++top] = a;
        size++;
    }
}

// Pop function definition
template <typename T>
T mystack<T>::pop() {
    if (size != 0) {
        size--;
        return arr[top--];
    } else {
        throw std::out_of_range("Stack is empty");
    }
}

int main(){
    int a=5;
    int b=3;
    mypair p(a, b);
    cout << p.first() << endl;
    cout << p.second() << endl;

}