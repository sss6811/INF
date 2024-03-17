#include <iostream>
#include <ctime>
#include <windows.h> // исключительно для 12 строчки в main()
#include "LinkedList.h"


int generate_random_number(int a, int b) { // функция генерации случайных чисел
    return rand() % (b - a + 1) + a; // генерация простых чисел
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // для отображения русского языка в консоли
    std::cout << "Тест задания 1.1" << std::endl;
    std::cout << "Введите диапазон значений и количество значений" << std::endl;
    int a, b, n;
    std::cin >> a >> b >> n;
    LinkedList myList_1; // myList_1 - тестовый односвязный список
    srand(static_cast<unsigned>(time(nullptr)));
    // статическое определение точки отсчета для создания псевдорандомных беззнаковых чисел относительно текущего времени
    for (int i = 0; i < n; i++) {
        myList_1.append(generate_random_number(a, b));
    }
    myList_1.display();

    std::cout << "Тест задания 1.2" << std::endl;
    std::cout << "Введите индекс начального элемента и количество элeментов" << std::endl;
    int left, count_of_numbers;
    std::cin >> left >> count_of_numbers;
    myList_1.print(left, count_of_numbers);

    std::cout << "Тест задания 2.1" << std::endl;
    std::cout << "Введите два числа, которые будут добавлены двумя разными способами" << std::endl;
    int first_add, second_add;
    std::cin >> first_add >> second_add;
    myList_1.append(first_add);
    myList_1.display();
    myList_1.push_back(second_add);
    myList_1.display();

    std::cout << "Пример удаления последнего элемента" << std::endl;
    myList_1.pop_back();
    myList_1.display();

    std::cout << "Тест задания 3.1 - удаление первого элемента" << std::endl;
    myList_1.pop_front();
    myList_1.display();

    std::cout << "Тест задания 3.2 - удаление по индексу" << std::endl;
    int remove_index;
    std::cout << "Введите индекс элемента, который вы хотите удалить" << std::endl;
    std::cin >> remove_index;
    myList_1.pop(remove_index);
    myList_1.display();

    std::cout << std::endl;
    myList_1.~LinkedList(); // отчистка памяти от первого листа
    myList_1.display(); // проверим "чисто или нет"


    std::cout << std::endl << std::endl;
    LinkedList myList_2; // заведем второй список, чтобы было нагляднее
    srand(static_cast<unsigned>(time(nullptr)));
    // статическое определение точки отсчета для создания псевдорандомных беззнаковых чисел относительно текущего времени
    for (int i = 0; i < 12; i++) { // заполним 1, 2, 3)
        myList_2.append(generate_random_number(1, 3));
    }
    myList_2.display(); // продемонстрируем наш список
    std::cout << "Тест задания 3.3 - удаление первого" << std::endl;
    int value_first_remove;
    std::cout << "Введите значение элемента, который вы хотите удалить" << std::endl;
    std::cin >> value_first_remove;
    myList_2.pop_first_find(value_first_remove);
    myList_2.display();

    std::cout << "Тест задания 3.4 - удаление удаление последнего" << std::endl;
    int value_last_remove;
    std::cout << "Введите значение элемента, который вы хотите удалить" << std::endl;
    std::cin >> value_last_remove;
    myList_2.pop_last_find(value_last_remove);
    myList_2.display();

    std::cout << "Тест задания 3.5 - удаление удаление всех" << std::endl;
    int value_all_remove;
    std::cout << "Введите значение элемента, который вы хотите удалить" << std::endl;
    std::cin >> value_all_remove;
    myList_2.pop_all_find(value_all_remove);
    myList_2.display();

    std::cout << std::endl;
    myList_2.~LinkedList(); // отчистка памяти от второго листа
    myList_2.display(); // проверим "чисто или нет"
}