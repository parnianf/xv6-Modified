#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char const *argv[])
{
    int A_pid = fork();
    if (A_pid)
        printf(1, "\npid: %d, parent: %d\n", A_pid, get_parent_pid());

    sleep(2000);

    if (A_pid)
        printf(1, "\npid: %d, parent: %d\n", A_pid, get_parent_pid());

    exit();
}
