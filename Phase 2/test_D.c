#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char const *argv[])
{   
    int pid_A = atoi(argv[1]);
    set_process_parent(pid_A);
    
    exit();
}
