#include "check.cpp"
#include <cassert>

void test_mystack() {
    mystack<int> stack;

    // Test pushing elements
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Test popping elements
    assert(stack.pop() == 30);
    assert(stack.pop() == 20);
    assert(stack.pop() == 10);

    // Test popping from an empty stack
    try {
        stack.pop();
        assert(false); // Should not reach here
    } catch (const std::out_of_range& e) {
        assert(true); // Exception should be thrown
    }
}

void test_mypair() {
    mypair<int> p(5, 3);
    assert(p.first() == 5);
    assert(p.second() == 3);
}

int main() {
    test_mystack();
    test_mypair();
    cout << "All tests passed!" << endl;
    return 0;
}