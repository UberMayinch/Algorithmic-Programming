#include <iostream>

template <typename T>
class pair{
    T pair[2];

    public:
    pair(T a, T b){
        T pair[2];
        pair[0]=a;
        pair[1]=b;
        return pair;
    }

    T first(pair a){
        return a[0];
    }

    T second(pair a){
        return a[1];
    }
};

