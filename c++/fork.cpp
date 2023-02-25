//fork1.cpp
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

int main()
{
const int BASE_PROCESSES = 3;

  int i, j;

  for(i = 0; i < BASE_PROCESSES; i++)
    {
      j = fork();
      if(j == 0)
        {
          cout << "My ppid is " << getppid();
          cout << " and my pid is " << getpid() << "." << endl;
          sleep(2);
        }
      else
        wait(&j);
    }

  return (0);

     