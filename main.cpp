#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;

queue<string>tasksQ;

void checkTasksFile() {
    string filename = "tasks.txt";
    ifstream tasks;
    tasks.open(filename);
    if(!tasks.good()) {
        ofstream newfile(filename);
    }
}

void load() {
    checkTasksFile();
    fstream tasks("tasks.txt");
    string task;
    while(getline(tasks, task)) {
        tasksQ.push(task);
    }
}


int main() {
    load();
    cout << tasksQ.size();
    cout << tasksQ.front();
}