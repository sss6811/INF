#include <iostream>
#include <vector>
#include "MyQueue.h"

int main(){
    MyQueue<int> q;
    std::cout << "Enter the initial number of numbers in the queue:";
    int n; std::cin >> n;
    q.push(n, 0.0, 100.0);
    std::cout << "1) Add an item to the queue\n" << "2) Add N items to the queue\n" <<
                 "3) Add N random items to the queue\n" << "4) Delete an item\n" <<
                 "5) Delete N items\n" << "6) Check the queue for emptiness\n" <<
                 "7) Print the queue\n";
    std::cout << "Enter the command number:";
    int command, a; std::cin >> command;
    switch(command) {
        case 1: {
            std::cout << "Enter a number:";
            std::cin >> a;
            q.push(a);
            q.print();
            break;
        }    
            
        case 2: {
            int count_2;
            std::cout << "Enter the number of numbers:";
            std::cin >> count_2;
            std::vector<int> nums(count_2);
            std::cout << "Enter the numbers:";
            for (int i = 0; i < count_2; i++) {
                int b;
                std::cin >> b;
                nums[i] = b;
            }
            q.push(nums);
            q.print();
            break;
        }    
        
        case 3: {
            int count_3;
            int min, max;
            std::cout << "Enter the number of numbers:";
            std::cin >> count_3;
            std::cout << "Enter the range boundaries:";
            std::cin >> min >> max;
            q.push(count_3, min, max);
            q.print();
            break;
        } 
        
        case 4: {
            q.pop();
            q.print();
            break;
        }    
            
        case 5: {
            int count_5;
            std::cout << "Enter the number of numbers:";
            std::cin >> count_5;
            q.pop(count_5);
            q.print();
            break;
        }
        
        case 6: {
            std::cout << q.empty() << "\n";
            q.print();
            break;
        }
        
        case 7: {
            q.print();
            break;
        }

        default: break;
    }

    return 0;

}