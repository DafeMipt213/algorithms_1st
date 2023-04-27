#include <iostream>
#include <vector>

using namespace std;

class StackWithMin {
public:
    void push(int val) {
        stack.push_back(val);
        if (min_stack.empty() || val <= min_stack.back()) {
            min_stack.push_back(val);
        }
    }

    void pop() {
        if (stack.empty()) {
            return;
        }
        if (stack.back() == min_stack.back()) {
            min_stack.pop_back();
        }
        stack.pop_back();
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return min_stack.back();
    }

private:
    vector<int> stack;
    vector<int> min_stack;
};
