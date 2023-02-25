//fork1.cpp
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

int main()
{
    int num;
    cout << "Type a number:";
    cin >> num;
    int pid;
	for (int i = 0; i < num; i++)
    {
        /* fork another process */
	    pid = fork();
        if (pid < 0)
        {
            //error
            cout << "Fork Failed\n";
            exit(-1);
        }
        else if (pid == 0)
        {
            //child process
            cout << "Hello world from child " << i + 1 << "\n";
            break;
        }
        else
        {
            //parent process
            wait((int*)NULL);
        }
    }
}