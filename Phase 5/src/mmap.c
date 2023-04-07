#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
// #include "defs.h"

#define MAP_PRIVATE 0

int main(int argc, char *argv[])
{
  int pid1 = fork();
  if(pid1 < 0)
  {
    printf(1, "Error!\n");
    exit();
  }
  if(pid1 == 0)
  {
    char* file;
    int fd = 0;
    int prot = 0;
    void* addr = 0;
    
    fd = open("temp.txt", O_CREATE | O_RDWR);    

    write(fd, "abcdefg!\n", 10);

    file = mmap(addr, 20, prot, MAP_PRIVATE, fd, 0);

    printf(0, "map: %c\n", file[3]);
    close(fd);

    fd = open("temp.txt", O_CREATE | O_RDWR);

    write(fd, "abcdefg!\n", 10);

    file = mmap(addr, 10, prot, MAP_PRIVATE, fd, 0);

    printf(0, "map: %c\n", file[4]);
    close(fd);
  } 
  else
    wait();  

  int pid2 = fork();
  if(pid2 < 0)
  {
    printf(1, "Error!\n");
    exit();
  }
  if(pid2 == 0)
  {
    char* file;
    int fd = 0;
    int prot = 0;
    void* addr = 0;

    fd = open("temp.txt", O_CREATE | O_RDWR);

    write(fd, "abcdefg!\n", 10);

    file = mmap(addr, 20, prot, MAP_PRIVATE, fd, 0);

    printf(0, "map: %c\n", file[1]);
    close(fd);
  } 
  else
    wait();

  exit();
  exit();
}