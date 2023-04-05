#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}


//////////////////////////////////

int sys_get_parent_pid(void){
  cprintf("in sys_get_parent_pid\n");
  return myproc()->parent->pid;
}

int sys_calculate_sum_of_digits(void)
{
  int number = myproc()->tf->ebx;
  cprintf("in sys_calculate_sum_of_digits --> n : %d\n", number);
  int sum = 0;
  while(number > 0)    
  {       
      sum += number % 10;   
      number /= 10;    
  }
  return sum;  
}

int sys_set_process_parent(void)
{
  int pid;
  cprintf("in sys_set_process_parent\n");
  if(argint(0, &pid) < 0)
    return -1;
  return set_process_parent(pid);  
}

int sys_change_queue(void)
{
  int pid, queue;
  if(argint(0, &pid) < 0)
    return -1;
  if(argint(1, &queue) < 0)
    return -1;

  return change_queue(pid, queue);
}

int sys_get_queue(void)
{
  int pid;
  if(argint(0, &pid) < 0)
    return -1;

  return get_queue(pid);
}

int sys_set_process_MHRRN(void)
{
  int pid; 
  int MHRRN_priority;
  if(argint(0, &pid) < 0)
    return -1;
  if(argint(1, &MHRRN_priority) < 0)
    return -1;
  return set_process_MHRRN(pid, MHRRN_priority);
}

int sys_set_system_MHRRN(void)
{
  int MHRRN_priority;
  if(argint(0, &MHRRN_priority) < 0)
    return -1;
  return set_system_MHRRN(MHRRN_priority);
}

int sys_print_info(void)
{
  print_info();
  return 1;
}
//////////////////////////////////


