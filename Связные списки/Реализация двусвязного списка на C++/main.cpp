#include <iostream>
#include <ctime>
#include "DoubleLinkedList.h"

int generate_random_number(int a, int b) { // функция генерации случайных чисел
    return rand() % (b - a + 1) + a; // генерация простых чисел
}

int main () {

    DoubleLinkedList<int> myList_1;

    std::cout << "Введите диапазон значений и количество значений" << std::endl;
    int a, b, n;
    std::cin >> a >> b >> n;
    srand(static_cast<unsigned>(time(nullptr))); // статическое определение точки отсчета для создания псевдорандомных беззнаковых чисел относительно текущего времени
    for (int i = 0; i < n; i++) {
        myList_1.push_back(generate_random_number(a, b));
    }
    myList_1.display();
    std::cout << myList_1.getSize() << " - это размер списка на данный момент" << std::endl;

    // удаление первого и последнего элемента
    std::cout << "Сейчас удалим первый и последний элементы" << std::endl;
    myList_1.pop_back();
    myList_1.pop_front();
    myList_1.display();
    std::cout << myList_1.getSize() << " - это размер списка на данный момент" << std::endl;

    // вставка в конец списка
    std::cout << "Введите число, которое вы хотите вставить в конец списка" << std::endl;
    int x; std::cin >> x;
    myList_1.push_back(x);
    myList_1.display();
    std::cout << myList_1.getSize() << " - это размер списка на данный момент" << std::endl;

    // вставка в начало списка
    std::cout << "Введите число, которое вы хотите вставить в начало списка" << std::endl;
    int y; std::cin >> y;
    myList_1.push_front(y);
    myList_1.display();
    std::cout << myList_1.getSize() << " - это размер списка на данный момент" << std::endl;

    // поиск элемента по индексу
    std::cout << "Введите индекс искомого элемента" << std::endl;
    size_t i; std::cin >> i;
    myList_1.find_by_index(i);

    // первый индекс
    std::cout << "Введите значение искомого элемента   (ожидается вывод 'первого' индекса)" << std::endl;
    int q; std::cin >> q;
    if (myList_1.find_first_index(q) != -1) {
        std::cout << "Индекс введенного элемента - это " << myList_1.find_first_index(q) << std::endl;
    } else {
        std::cout << "Такого элемента не существует" << std::endl;
    }

    // последний индекс
    std::cout << "Введите значение искомого элемента   (ожидается вывод 'последнего' индекса)" << std::endl;
    std::cin >> q;
    if (myList_1.find_last_index(q) != -1) {
        std::cout << "Индекс введенного элемента - это " << myList_1.find_last_index(q) << std::endl;
    } else {
        std::cout << "Такого элемента не существует" << std::endl;
    }

    // вставка элемента перед указанным индексом
    std::cout << "Введите индекс, перед которым будет выполнена вставка нового элемента, а потом и значение добавляемого элемента" << std::endl;
    std::cin >> i >> q;
    myList_1.insert_before_index(i, q);
    myList_1.display();
    std::cout << myList_1.getSize() << " - это размер списка на данный момент" << std::endl;

    // вставка элемента после указанного индекса
    std::cout << "Введите индекс, после которого будет выполнена вставка нового элемента, а потом и значение добавляемого элемента" << std::endl;
    std::cin >> i >> q;
    myList_1.insert_after_index(i, q);
    myList_1.display();
    std::cout << myList_1.getSize() << " - это размер списка на данный момент" << std::endl;

    // вставка элемента перед указанным значением
    int value;
    std::cout << "Введите значение элемента, перед которым будет выполнена вставка нового элемента, а потом и значение добавляемого элемента" << std::endl;
    std::cin >> value >> q;
    myList_1.insert_before_value(value, q);
    myList_1.display();
    std::cout << myList_1.getSize() << " - это размер списка на данный момент" << std::endl;

    // вставка элемента после указанного значения
    std::cout << "Введите значение элемента, после которого будет выполнена вставка нового элемента, а потом и значение добавляемого элемента" << std::endl;
    std::cin >> value >> q;
    myList_1.insert_after_value(value, q);
    myList_1.display();
    std::cout << myList_1.getSize() << " - это размер списка на данный момент" << std::endl;

    // сортировка двусвязного списка
    std::cout << "А теперь мы отсортируем получившийся список" << std::endl;
    myList_1.sort();
    myList_1.display();

    myList_1.~DoubleLinkedList();
}