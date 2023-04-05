#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"

int main(int argc, char const *argv[])
{
    int number_of_children = atoi(argv[1]);


    for (int i = 0; i < number_of_children; i++)
    {
        int p = fork();
        if (p < 0)
        {
            printf(1, "Error!\n");
            exit();
        }
        
        long long temp = 0;
        if (p == 0)
        {      
            for(float j = 0 ; j < 10000; j += 0.1)
            {
                for(float k = 0; k < 10000; k += 0.1)
                {
                    for(float z = 0; z < 10000; z += 0.1)
                    {
                        temp += 1;
                    }
                }
                
            }
            exit();
        }        
    }

    for(int i = 0; i < number_of_children; i++)
        wait();

    exit();
}