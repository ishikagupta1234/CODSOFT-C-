#include <iostream>
#include <vector>
#include <limits> // Added for clearing input buffer

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.push_back(Task(description));
        std::cout << "Task added successfully.\n";
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available.\n";
        } else {
            std::cout << "Tasks:\n";
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << "[" << i + 1 << "] ";
                if (tasks[i].completed) {
                    std::cout << "[X] ";
                } else {
                    std::cout << "[ ] ";
                }
                std::cout << tasks[i].description << "\n";
            }
        }
    }

    void deleteTask(int index) {
        if (index >= 1 && static_cast<size_t>(index) <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            std::cout << "Task deleted successfully.\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }
};

int main() {
    TodoList todoList;

    while (true) {
        std::cout << "\n====== ToDo List Manager ======\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Delete Task\n";
        std::cout << "4. Exit\n";
        std::cout << "===============================\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Clear input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::string description;
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                todoList.addTask(description);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                int index;
                std::cout << "Enter the index of the task to delete: ";
                std::cin >> index;

                // Clear input buffer
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                todoList.deleteTask(index);
                break;
            }
            case 4:
                std::cout << "Exiting the ToDo List Manager. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

