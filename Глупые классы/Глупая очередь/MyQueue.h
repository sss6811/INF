#ifndef MYQUEUE_MYQUEUE_H
#define MYQUEUE_MYQUEUE_H

/* Использование this-> позволяет явно указать,
 * что методы и члены класса вызываются для объекта,
 * который является экземпляром этого класса,
 * а не для какого-то другого объекта или локальной
 * переменной с таким же именем.
 * Таким образом, this-> в данном контексте помогает явно указать,
 * что члены класса используются внутри методов класса для текущего объекта.
*/

#include <iostream>
#include <vector>
#include <ctime>

template <typename T>

class MyQueue {

private:

    std::vector <T> elements; //вектор элементов стека

public:

    MyQueue(): elements(std::vector <T>(0)){ }

    void push(T data) {
        this->elements.push_back(data);
    }

    void push(std::vector<T> data) {
        for (int i = 0; i < data.size(); i++)
            this->push(data[i]);
    }

    void push(int n, T min, T max) {
        srand(time(0));
        for (int i = 0; i < n; i++)
            this->push(rand() % (max - min + 1) + min);
    }

    void pop() { // дружественный метод
        this->elements.erase(elements.begin());
    }

    void pop(int n) { // дружественный метод
        for (int i = 0; i < n; i++)
            this->pop();
    }

    int size() {
        return this->elements.size();
    }

    bool empty() {
        return this->size() == 0;
    }

    void print() {
        for(int i = 0; i < this->size(); i++)
            std::cout << this->elements[i] << " ";
        std::cout << std::endl;
    }
};

#endif //MYQUEUE_MYQUEUE_H
