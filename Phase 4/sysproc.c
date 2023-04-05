#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "spinlock.h"

struct spinlock lock;

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

int sys_sem_init(void)
{
  int i; 
  int v;
  int init;
  if(argint(0, &i) < 0)
    return -1;
  if(argint(1, &v) < 0)
    return -1;
  if(argint(1, &init) < 0)
    return -1;
  sem_init(i, v, init);
  return 0;
}

int sys_sem_acquire(void)
{
  int i; 
  if(argint(0, &i) < 0)
    return -1;
  sem_acquire(i);
  return 0;
}

int sys_sem_release(void)
{
  int i; 
  if(argint(0, &i) < 0)
    return -1;
  sem_release(i);
  return 0;
}

int
sys_dining_philosophers(void){
  int phnum;
  argint(0, &phnum);
  int temp = 0;
  while (1) {
    pickup(phnum);
    
    for(float j = 0 ; j < 1000; j += 0.1)
    {
        for(float k = 0; k < 400; k += 0.1)
        {
            for(float z = 0; z < 10; z += 0.1)
            {
                temp += 1;
            }
        }
    }
    
    putdown(phnum);
	}
  return 0;
}

int sys_initialization(void)
{
  initialization();
  return 0;
}