#include <iostream>
#include "graph.h"


int main() {
    graph gr(6); // Создаем объект класса graph с 5 вершинами
    // Добавляем рёбра
    gr.add_edge(0, 3);
    gr.add_edge(0, 2);
    gr.add_edge(1, 2);
    gr.add_edge(1, 4);
    gr.add_edge(2, 3);
    gr.add_edge(4, 3);
    gr.add_edge(5, 5);
    int operation, n;
    std::cout << "List of functions:\n" <<
                    "1) Neighboring vertices\n" << "2) Edge output\n" <<
                    "3) The DFS algorithm\n" << "4) The BFS algorithm\n" <<
                    "5) Checking for connectivity\n" << "6) Output connected components\n";
                        std::cin >> operation;
    switch (operation) {
        case 1:
            gr.display();
            break;
        case 2:
            gr.print_edges();
            break;
        case 3:
            std::cout << "Enter the vertex number for DFS:\n";
            std::cin >> n;
            if (n >= 0 && n < 6) {
                gr.print_DFS(n);
            } else {
                std::cout << "Stupid" << std::endl;
            }
            break;
        case 4:
            std::cout << "Enter the vertex number for BFS:";
            std::cin >> n;
            if (n >= 0 && n < 6) {
                gr.print_BFS(n);
            } else {
                std::cout << "Stupid" << std::endl;
            }
            break;
        case 5:
            if (gr.is_connected())
                std::cout << "Connected graph\n";
            else
                std::cout << "Not connected graph\n";
            break;
        case 6:
            gr.connected_components();
            break;
        default:
            std::cout << "Unknown command!!!\n";
            break;


    }
}