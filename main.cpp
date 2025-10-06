#include <iostream>

class Stack {
    private:
    int *arr;
    int top;
    int capacity;

    public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int var_to_push) {
        if (top == capacity -1) throw std::overflow_error("overflow");
        arr[++top] = var_to_push;
    }

    int pop() {
        if (top == -1) throw std::overflow_error("underflow");
        return arr[--top];
    }

    int peek() {
        if (top == -1) throw std::overflow_error("underflow");
        return arr[top];
    }

    bool is_empty() {
        return top == -1;
    }

    void inspect(int** arr_extern = nullptr) {
        if (arr_extern == nullptr) {
            for (int i = 0; i < capacity; i++)
            {
                std::cout << arr[i] << std::endl; 
            }
        } else {
            *arr_extern = arr;
        }
    }
};

int main() {
    int* external;

    Stack stack(5);

    stack.push(50);
    stack.push(40);
    stack.push(30);
    stack.push(20);

    stack.inspect(&external);

    for (int i = 0; i < 5; i++)
    {
        std::cout << external[i] << " queue" << std::endl;
    }
}