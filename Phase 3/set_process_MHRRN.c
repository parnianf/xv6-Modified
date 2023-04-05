#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"

int main(int argc, char const *argv[])
{
    set_process_MHRRN(atoi(argv[1]), atoi(argv[2]));
    exit();
}
