#include <iostream>
#include<string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    
    srand(time(0));  
    int num = rand() % 100 + 1;  

    int guess, attempts = 0 , maxAttempts=5;
    string res;
    
    while(attempts < maxAttempts){
        
        cout << "\nEnter guess (" << maxAttempts - attempts << " attempts left): ";
        cin >> guess;

        if(guess == num){
            res = "Won!!";
            break;
        }else if(guess > num){
            cout << "Too High" << endl;
        }else{
            cout << "Too Low" << endl;
        }

        attempts++;
        
    }    
    
    if(guess != num){
            res = "Lost";
        }
    
    if(guess == num){
        cout << "Yeahh ! You Won...."<< endl;
        cout << "Result : " << res << endl;
    }else{
        cout << "Nice try !!" << endl;
        cout << "User Number : "<< guess << endl;
        cout << "Computer Number : "<< num << endl;
        cout << "Result : " << res << endl;
    }
    
    return 0;
}