
// Created by sesab on 15.01.2024.

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>

class Node { // класс для создания одной "ячейки" связного списка
public:
    int data;
    Node* next;
    Node (int val) { // конструктор для узла
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() { // конструктор связного списка
        head = nullptr;
        tail = nullptr;
    }

    void append(int  value) { // метод вставки элементов в список
        Node* newNode = new Node(value);
        if (!head) { // если элемент единственный
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
        tail = newNode;
    }

    void push_back(int val) { // задание 2.1
        Node* newNode = new Node(val);
        if (!head) { // если списка не существует, создаем его
            head = tail = newNode; // этот узел будет головой и хвостом
        } else { // в противном случае добавляем узел после хвоста
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() { // метод вывода связного списка на экран
        Node* current = head; // создаем узел, которая указывает на голову
        while (current) { // двигаемся по списку и выводим элементы
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    int countNodes() { // метод подсчета количества элементов в связном списке
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void print(int l, int k) { // странный метод print из задания 1.2
        // определяем вводимые значения
        if (l < 0 || l > countNodes()) {
            std::cout << "Неправильный ввод номера начального элемента" << std::endl;
            return;
        }
        else if(k <= 0) {
            std::cout << "Неправильный ввод количества выводимых элементов" << std::endl;
            return;
        }
        // если значения "правильные", то продолжаем
        Node* current = head;
        for (int i = 0; i < l && current != nullptr; i++) { // l - 1
            current = current->next;
        }
        for (int i = 0; i < k && current != nullptr; i++) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    /* bool empty() {
        if(!head) {
            return false;
        }
        return true;
    } */

    void pop_back() {
        if (!head) { // Если список пустой
            return;
        }
        if (head->next == nullptr) {// Если в списке только один элемент
            delete head;
            head = tail = nullptr;
        }
        // иначе создаем текущий узел, указывающий на голову и предыдущий, указывающий на nullptr
        Node* current = head;
        Node* prev = nullptr;
        while (current->next != nullptr) { // перебираем элементы, пока не дойдем до конца списка
            prev = current;
            current = current->next;
        }
        // Удаляем последний элемент
        delete current;
        prev->next = nullptr;
        tail = prev; // Обновляем указатель на хвост
    }


    void pop_front() { // метод удаления переднего (головного) элемента
        if (!head) { // Список пуст, ничего не удаляем
            return;
        }
        // если список не пустой, то в голову записываем следующий узел
        Node* current = head;
        head = head->next;
        delete current; // удаляем "старую голову"
    }

    void pop(int index) { // метод удаления по индексу
        if (!head) { // Список пуст, ничего не удаляем
            return;
        }
        if (index < 0) { // если неправильный ввод, то выводим ошибку
            std::cout << "Неправильный ввод" << std::endl;
            return;
        }
        if (index == 0) { // если выбран нулевой элемент, то удаляем его
            pop_front();
            return;
        }
        // иначе создаем текущий узел, указывающий на голову и предыдущий, указывающий на nullptr
        Node* current = head;
        Node* prev = nullptr;
        for (int i = 0; current != nullptr and i < index; i++) {
            prev = current;
            current = current->next;
        }
        if (current == nullptr) { // если не удалось найти элемент, то выводим ошибку
            std::cout << "Такого элемента не существует" << std::endl;
            return;
        }
        prev->next = current->next;
        delete current;
    }

    void pop_first_find(int val) { // Метод удаления первого найденного
        if (!head) { // Если список пустой
            return;
        }
        if (head->data == val) { // Если наш элемент является головой
            Node* current = head;
            head = head->next;
            delete current;
            return;
        }
        // иначе создаем текущий узел, указывающий на голову и предыдущий, указывающий на nullptr
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr && current->data != val) {
            prev = current;
            current = current->next;
        }
        if (!current) { // Если элемент не найден
            std::cout << "Элемент не найден" << std::endl;
            return;
        }
        prev->next = current->next;
        delete current; // удаляем элемент, если такой найден
    }

    void pop_last_find(int val) { // Метод удаления последнего найденного
        if (!head) { // если список пустой
            return;
        }
        if (!head->next) { // Если в списке только один элемент
            if (head->data == val) {
                delete head;
                head = nullptr;
            }
            return;
        }
        // иначе создаем текущий узел, указывающий на голову и предыдущий, указывающий на nullptr
        Node* current = head;
        Node* prev = nullptr;
        Node* del = nullptr; // создаем "удаляемый" элемент, который пока равен nullptr
        while (current->next != nullptr) {
            if (current->next->data == val) {
                prev = current;
                del = current->next;
            }
            current = current->next;
        }
        if (del != nullptr) { // если удаляемый элемент найден
            if (del == tail) { // если удаляемый элемент является хвостом
                tail = prev; // то хвостом становится предыдущий элемент
            }
            prev->next = del->next;
            delete del; // удаляем элемент
        }
    }

    void pop_all_find(int val) { // Метод удаления всех найденных элементов
        // создаем текущий узел, указывающий на голову и предыдущий, указывающий на nullptr
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr) { // проходим в цикле до конца списка
            if (current->data == val) { // если элемент текущего узла совпадает с тем, который нужно удалить
                if (current == head) { // если является головой, то смещаем голову
                    head = current->next;
                }
                else { // иначе смещаем указатель на предыдущий элемент
                    prev->next = current->next;
                }
                Node* del = current;
                current = current->next;
                delete del;
            }
            else {
                prev = current;
                current = current->next;
            }
        }
        tail = prev;
    }

    /* int find(int target) { // метод поиска элемента
         Node* current = head;
         int position = 0;
         while (current) {
             if (current->data == target) {
                 return position;
             }
             current = current->next;
             position++;
         }
         std::cout << "Такого элемента не существует" << std::endl;
         return -1; // такого элемента не существует
     } */

    ~LinkedList() { // деструктор, нужен, потому что это ООП на C++
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr; // После удаления всех узлов, устанавливаем указатель на хвост в nullptr
    }
};

#endif //LINKEDLIST_LINKEDLIST_H