#include <iostream>
#include <vector>
#include <string>
#include <fstream>      
#include <sstream>      
using namespace std;

struct Task {
    int id;
    string title;
    string status;
};


void saveToFile(vector<Task>& tasks){
    ofstream file("tasks.txt");
    
    for(int i = 0; i < tasks.size(); i++){
        file << tasks[i].id << "|" 
             << tasks[i].title << "|" 
             << tasks[i].status << "\n";
    }
    
    file.close();
    cout << "Tasks saved!\n";
}

void loadFromFile(vector<Task>& tasks){
    ifstream file("tasks.txt");
    
    if(!file.is_open()){
         return;
    }
    
    string line;
    while(getline(file, line)){
        stringstream ss(line);
        string idStr, title, status;
        
        // id | title | status
        getline(ss, idStr, '|');
        getline(ss, title, '|');
        getline(ss, status, '|');
        
        Task t;
        t.id = stoi(idStr);   
        t.title = title;
        t.status = status;
        
        tasks.push_back(t);
    }
    
    file.close();
}

void addTask(vector<Task>& tasks){
    Task t;
    
    cout << "Enter Task ID: ";
    cin >> t.id;
    
    cout << "Enter Task Title: ";
    cin >> t.title;
    
    t.status = "Pending";  
    
    tasks.push_back(t);
    cout << "Task Added!\n";
    saveToFile(tasks);   // save after adding
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
            saveToFile(tasks);   
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
            saveToFile(tasks);   
            return;
        }
    }

    cout << "Task not found!\n";
}

int main() {
    vector<Task> tasks;
    loadFromFile(tasks);   
    
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
            case 5: 
                saveToFile(tasks);   
                return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}