#include <iostream>
#include <vector>
#include <string>
#include <limits>

class ToDoListManager {
private:
    struct Task {
        std::string description;
        bool completed;

        Task(const std::string& desc) : description(desc), completed(false) {}
    };

    std::vector<Task> tasks;

public:
    void addTask(const std::string& taskDescription) {
        tasks.emplace_back(taskDescription);
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks in the list." << std::endl;
        } else {
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i].description << " - "
                          << (tasks[i].completed ? "Completed" : "Pending") << std::endl;
            }
        }
    }

    void markTaskCompleted(size_t taskIndex) {
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].completed = true;
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            tasks.erase(tasks.begin() + taskIndex - 1);
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }
};

void printMenu() {
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. View Tasks" << std::endl;
    std::cout << "3. Mark Task as Completed" << std::endl;
    std::cout << "4. Remove Task" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

int main() {
    ToDoListManager manager;
    int choice;
    std::string taskDescription;
    size_t taskIndex;

    while (true) {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Flush input buffer

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::getline(std::cin, taskDescription);
                manager.addTask(taskDescription);
                break;
            case 2:
                manager.viewTasks();
                break;
            case 3:
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> taskIndex;
                if(std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a valid task number." << std::endl;
                } else {
                    manager.markTaskCompleted(taskIndex);
                }
                break;
            case 4:
                std::cout << "Enter task number to remove: ";
                std::cin >> taskIndex;
                if(std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a valid task number." << std::endl;
                } else {
                    manager.removeTask(taskIndex);
                }
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}

