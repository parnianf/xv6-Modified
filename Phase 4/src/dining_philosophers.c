#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
  
int main(int argc, char *argv[])
{
    initialization();
    for(int i=0;i<5;i++)
    {
        int p = fork();
        if(p == 0)
            dining_philosophers(i);
        
    }
    for(int i=0;i<5;i++)
        wait();

    exit();
}