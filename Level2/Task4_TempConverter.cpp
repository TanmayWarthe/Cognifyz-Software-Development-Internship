#include <iostream>
using namespace std;

int main() {
    int choice;
    double temp, result;
    
    cout << "1. Celsius to Fahrenheit\n";
    cout << "2. Fahrenheit to Celsius\n";
    cout << "Enter choice: ";
    cin >> choice;
    
    cout << "Enter temperature: ";
    cin >> temp;
    
    switch(choice){
        case 1:
            result = (temp * 9.0 / 5.0) + 32.0;
            break;
        case 2:
            result = (temp - 32.0) * 5.0 / 9.0;
            break;
        default:
            cout << "Invalid choice!";
            return 0;
    }
    
    cout << "Converted temperature: " << result << endl;
    
    return 0;
}