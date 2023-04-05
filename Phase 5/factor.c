#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


void factor(int num){

    int fd = open("factor_result.txt", O_CREATE | O_RDWR);
    if(fd != -1)
    {
        unlink("factor_result.txt");
        fd = open("factor_result.txt", O_CREATE | O_RDWR);
    }

    char buf[16];
    for(int i = 1; i <= num; i++)
    {
        if(num % i == 0)
        {
            int divisor = i;
            int j = 0;
            
            while(divisor != 0)
            {
                buf[j++] = '0' + divisor % 10;
                divisor /= 10;
            }

            while (j-- >= 0)
            {
                write(fd, &buf[j], sizeof(char));
            }

            write(fd, " ", sizeof(char));
        }
    }
    write(fd, "\n", sizeof(char));
    close(fd);
}
    
int main(int argc, char *argv[])
{
  factor(atoi(argv[1]));
  exit();
}