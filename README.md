# xv6-Modified

The goal of this project is to modify the [xv6 Operating System](https://github.com/mit-pdos/xv6-public) by adding new features and functionalities like new keyboard shortcuts for console, new system calls, CPU scheduling, and synchronization.

## Phase 1 (Introduction to xv6)

* Add names of contributors to message boot
* Add three new keyboard shortcuts to xv6 shell:
    1. `Ctrl + T`: Swap the last two letters before the cursor
    2. `Ctrl + O`: Uppercase all letters before the cursor
    3. `Ctrl + A`: Change the position of the cursor to the beginning of the line
* Design and Implementation of user level program

## Phase 2 (System calls)
* `calculate_sum_of_digits (int num)`: returns the sum value of all digits in `num`
* `get_file_sectors(int fd)`: prints the block number on disk for each block of the file
* `get_parent_id(void)`: prints the parent process id of the currently running process
* `set_process_parent(int pid)`: sets the currently running process as the parent of input process (`pid`)


## Phase 3 (CPU Scheduling)
In this scheduler, processes are placed in different levels according to their priority, which is assumed in this project that there are three levels and subsequently three priorities:

1. Round Robin (RR)
2. Last Come First Serve (LCFS)
3. Modified Highest Response Ratio Next (MHRRN)

Requiered system calls:
* `change_queue(int pid, int queue)`
* `get_queue(int pid)`
* `set_process_MHRRN(int pid, int MHRRN_priority)`
* `set_system_MHRRN(int MHRRN_priority)`
* `print_info(void)`

## Phase 4 (Synchronization)
* Implement `Counting Semaphore` with required system calls:
  * `sem_init(int i, int v, int init)`
  * `sem_acquire(int i)`
  * `sem_release(int i)`
* Simulate `Dining Philosophers` problem with 5 philosophers by using a monitor

## Phase 5 (Memory management)
Implement a POSIX-compliant Unix system call called `mmap` that maps files or devices into memory. It is a method of memory-mapped file I/O.
Required system calls:
* `get_free_pages_count()`
* `mmap(void *addr, size_t length, int prot, int flags, int fd, int offset)`

<br><br>

**Contributors**: [Paria Khoshtab](https://github.com/Theparia/), [Ali Akhgari](https://github.com/AliAkhgari)

