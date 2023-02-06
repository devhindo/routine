#include <bits/stdc++.h>
using namespace std;


queue<string> tasksQ;

map<string, string> cmds = {
    {"ls", "List tasks."},
    {"add", "Add a task."},
    {"done", "Current task done."},
    {"exit", "Exit the program."}
};

void listTasks() {
    for (auto& cmd : cmds) {
        cout << cmd.first << " => " << cmd.second << endl;
    }
}

typedef void (*cmdFunc)();


void printCurrTask() {
    cout << tasksQ.front() << endl;
}



void addTask() {
    string task;
    cout << "task: ";
    cin >> task;
    tasksQ.push(task);
}

void exit() {
    ofstream tasks("tasks.txt");
    while(!tasksQ.empty()) {
        tasks << tasksQ.front() << endl;
        tasksQ.pop();
    }
    tasks.close();
}


void checkTasksFile()
{
    string filename = "tasks.txt";
    ifstream tasks;
    tasks.open(filename);
    if (!tasks.good())
    {
        ofstream newfile(filename);
    }

}

void currTask() {
    if(tasksQ.empty()) {
        cout << "Not tasks yet, Try adding new task by typing \"add\"" << endl;
    } else {
        cout << tasksQ.front() << endl;
    }
}

void taskDone() {
    string currTask = tasksQ.front();
    tasksQ.pop();
    cout << currTask << " done!" << endl;
}

map<string,cmdFunc> InitializeTasksFunctions() {
    map<string,cmdFunc> tasksFunctions;
    tasksFunctions["ls"] = &listTasks;
    tasksFunctions["add"] = &addTask;
    tasksFunctions["curr"] = &currTask;
    tasksFunctions["exit"] = &exit;
    tasksFunctions["done"] = &taskDone;
    return tasksFunctions;
}


void load()
{
    checkTasksFile();
    fstream tasks("tasks.txt");
    string task;
    while (getline(tasks, task))
    {
        tasksQ.push(task);
    }
}


int main()
{
    load();
    map<string,cmdFunc> tasksFunctions = InitializeTasksFunctions();
    string cmd;
    while(cmd.empty()) {
        cin >> cmd;
        tasksFunctions[cmd]();
        if(cmd == "exit") break;
        cmd.clear();
    }
    return 0;
}