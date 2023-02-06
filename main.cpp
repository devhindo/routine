#include <bits/stdc++.h>
using namespace std;

queue<string> tasksQ;
map<string, string> cmds = {
    {"ls", "List tasks"},
    {"add", "Add a task"},
    {"rm", "Remove a task"},
    {"help", "Show this help message"},
    {"exit", "Exit the program"}
};

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
}