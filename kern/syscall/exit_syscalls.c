#include <types.h>
#include <kern/errno.h>
#include <kern/syscall.h>
#include <lib.h>
#include <mips/trapframe.h>
#include <thread.h>
#include <current.h>
#include <syscall.h>
#include <proc.h>
#include <vm.h>
#include <proc.h>
#include <addrspace.h>
//partial/temporary: (1) record status, (2) relase addres space, (3) exit thread

int sys__exit(int status) {
	curproc->exit_status = status;
	V(curproc->proc_sem);
	thread_exit();
}
