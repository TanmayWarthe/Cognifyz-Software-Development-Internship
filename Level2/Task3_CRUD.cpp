#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    int id;
    string title;
    string status;
};

void addTask(vector<Task>& tasks){
    Task t;
    
    cout << "Enter Task ID: ";
    cin >> t.id;
    
    cout << "Enter Task Title: ";
    cin >> t.title;
    
    t.status = "Pending";  
    
    tasks.push_back(t);
    cout << "Task Added!\n";
}

void viewTasks(vector<Task>& tasks){
    if(tasks.empty()){
        cout << "No tasks available!\n";
        return;
    }
    
    for(int i = 0; i < tasks.size(); i++){
        cout << "ID: " << tasks[i].id 
             << " | Title: " << tasks[i].title 
             << " | Status: " << tasks[i].status << endl;
    }
}

void updateTask(vector<Task>& tasks){
    int inputId;
    cout << "Enter Task ID to update: ";
    cin >> inputId;

    for(int i = 0; i < tasks.size(); i++){
        if(tasks[i].id == inputId){
            cout << "Enter new Task Title: ";
            cin >> tasks[i].title;

            cout << "Enter new Task Status: ";
            cin >> tasks[i].status;

            cout << "Task Updated!\n";
            return;
        }
    }

    cout << "Task not found!\n";
}

void deleteTask(vector<Task>& tasks){
    int inputId;
    cout << "Enter Task ID to delete: ";
    cin >> inputId;

    for(int i = 0; i < tasks.size(); i++){
        if(tasks[i].id == inputId){
            tasks.erase(tasks.begin() + i);
            cout << "Task Deleted!\n";
            return;
        }
    }

    cout << "Task not found!\n";
}

int main() {
    vector<Task> tasks;
    int choice;
    
    while(true){
        cout << "\n=== Task Manager ===" << endl;
        cout << "1. Add Task\n2. View Tasks\n3. Update Task\n4. Delete Task\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice){
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: updateTask(tasks); break;
            case 4: deleteTask(tasks); break;
            case 5: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}