//
//  main.cpp
//  MultiThreading
//
//  Created by Shubham Talbar on 11/13/22.
//

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void print(int n, string str) {
    cout << endl << n << " " << str << endl;
}

int main() {
    vector<string> setOfStrings = {"Thread 1", "Thread 2", "Thread 3", "Thread 4", "Thread 5"};
    vector<thread> threadPool;
    
    for(int i=0; i<size(setOfStrings); i++) {
        threadPool.push_back(thread(print, i, setOfStrings[i]));
    }
    
    for(auto& thread : threadPool) {
        thread.join();
    }
    
    return 0;
}
