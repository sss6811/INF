//
// Created by sesab on 16.03.2024.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <iostream>
#include <vector>
#include <queue>

class graph {
private:
    int n; // Переменная для хранения количества вершин графа
    std::vector<std::vector<int>> adj; // Вектор векторов для хранения смежности графа
    std::vector<std::pair<int, int>> edge; // Вектор пар для хранения рёбер графа
public:

    graph(int n) { // Конструктор класса с одним параметром (количеством вершин)
        this->n = n; // Присваивание переданного количества вершин переменной n
        adj.resize(n); // Изменение размера вектора смежности для хранения n вершин
    }

    void add_edge(int first, int second) { // Метод для добавления ребра между вершинами
        adj[first].push_back(second); // Добавление второй вершины в список смежности первой
        adj[second].push_back(first); // Добавление первой вершины в список смежности второй
        edge.push_back({first, second}); // Добавление ребра в вектор рёбер
    }

    void display() { // Метод для отображения графа (соседние элементы: номер вершины: номера соседних)
        for(int i = 0; i < n; i++) { // Цикл по всем вершинам графа
            std::cout << i << ": "; // Вывод индекса вершины
            for(auto x: adj[i]) { // Цикл по списку смежности текущей вершины
                std::cout << x << " "; // Вывод вершин, смежных с текущей
            }
            std::cout << "\n"; // Переход на новую строку для следующей вершины
        }
    }

    void print_edges() { // Добавленный метод для вывода списка рёбер
        std::cout << "List of edges: ";
        for(auto x : edge) { // Цикл по всем рёбрам в векторе рёбер
            std::cout << "[" << x.first << ", " << x.second << "] "; // Вывод текущего ребра в формате (вершина1, вершина2)
        }
        std::cout << "\n"; // Переход на новую строку после вывода всех рёбер
    }

    std::vector<int> DFS(int start_vertex, std::vector<bool>& visited) { // Метод для выполнения поиска в глубину (DFS)
        visited[start_vertex] = true; // Помечаем текущую вершину как посещённую
        std::vector<int> dfs_result; // Вектор для хранения результатов DFS
        for (int u : adj[start_vertex]) { // Идём по всем смежным вершинам
            if (!visited[u]) { // Если вершина не посещена
                std::vector<int> sub_dfs_result = DFS(u, visited); // Рекурсивно выполняем DFS от неё
                dfs_result.insert(dfs_result.end(),
                                  sub_dfs_result.begin(), sub_dfs_result.end()); // Добавляем результаты под-DFS в общий вектор
            }
        }
        dfs_result.push_back(start_vertex); // Добавляем текущую вершину в результат DFS
        return dfs_result; // Возвращаем результат DFS
    }

    void print_DFS(int start_vertex) {
        std::vector<bool> visited(n, false); // Вектор для отслеживания посещенных вершин
        std::cout << "DFS from vertex " << start_vertex << ": ";
        std::vector<int> dfs_result = DFS(start_vertex, visited);
        for (int v : dfs_result) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    std::vector<int> BFS(int start_vertex, std::vector<bool>& visited) { // Метод для выполнения поиска в ширину (BFS)
        std::vector<int> bfs_result; // Вектор для хранения результатов BFS
        std::queue<int> q; // Очередь для выполнения поиска в ширину
        visited[start_vertex] = true; // Помечаем начальную вершину как посещенную
        q.push(start_vertex); // Добавляем начальную вершину в очередь
        while (!q.empty()) { // Пока очередь не пуста
            int v = q.front(); // Получаем вершину из передней части очереди
            q.pop(); // Удаляем вершину из очереди
            bfs_result.push_back(v); // Добавляем текущую вершину в результат BFS
            // Идем по всем смежным вершинам текущей вершины
            for (int u : adj[v]) {
                if (!visited[u]) { // Если вершина не посещена
                    visited[u] = true; // Помечаем её как посещенную
                    q.push(u); // Добавляем её в очередь
                }
            }
        }
        return bfs_result; // Возвращаем результат BFS
    }

    void print_BFS(int start_vertex) { // Метод для вывода результатов поиска в ширину (BFS)
        std::vector<bool> visited(n, false); // Вектор для отслеживания посещенных вершин
        std::vector<int> bfs_result = BFS(start_vertex, visited); // Выполняем поиск в ширину
        std::cout << "BFS from vertex " << start_vertex << ": ";
        for (int v : bfs_result) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    bool is_connected() { // Метод для проверки связности графа
        std::vector<bool> visited(n, false); // Вектор для отслеживания посещенных вершин
        DFS(0, visited); // Выполняем DFS от начальной вершины
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) return false;
        }
        return true;
    }

    void connected_components() { // Метод для вывода компонентов связности
        std::vector<bool> visited(n, false); // Вектор для отслеживания посещенных вершин
        int component_count = 0; // Счётчик компонент связности
        for (int i = 0; i < n; i++) {
            if (!visited[i]) { // Если вершина не посещена, значит, это новая компонента связности
                component_count++;
                std::cout << "Component number " << component_count << ": ";
                std::vector<int> dfs_result = DFS(i, visited); // Выполняем DFS от данной вершины
                for (int v : dfs_result) {
                    std::cout << v << " ";
                }
                std::cout << std::endl;
            }
        }
        std::cout << "Quantity connected components: " << component_count << std::endl;
    }
};

#endif //GRAPH_GRAPH_H