#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"

int main(int argc, char const *argv[])
{
    change_queue(atoi(argv[1]), atoi(argv[2]));
    exit();
}