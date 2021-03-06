#include <types.h>
#include <kern/errno.h>
#include <kern/syscall.h>
#include <lib.h>
#include <mips/trapframe.h>
#include <thread.h>
#include <current.h>
#include <syscall.h>
#include <proc.h>

/*write system call*/

ssize_t sys_write(int fd, const void *buf, size_t nbytes){
	if (fd == 1){
		size_t i=0;
		for(i=0; i<nbytes; i++) {
			kprintf("%c",*(char*)buf);
			buf++;
		}
		return 1;
	}
	else{
		kprintf("Not yet implemented (write)\n");
		return -1;
	}
}

/*read system call*/

ssize_t sys_read(int fd, userptr_t buf, size_t nbytes) {
	if (fd == 0 && nbytes == 1) {
		char tmp[2];
		kgets(tmp, 1);
		*(char *)buf = tmp[0];
		return 1;
	}
	else {
		kprintf("Not yet implemented (read)\n");
		return -1;
	}
}
/*WAIT-IMPROVED*/
pid_t sys_waitpid(pid_t pid, int* returncode, int flags){
	/*flags has been inserted in parameters list to mantain compatibility
	but their function ain't implemented yet*/
	(void)flags; //suppress warning;
	struct proc* proc;
	spinlock_acquire(&proc_table_spinlock);
	proc = proc_table[pid];
	spinlock_release(&proc_table_spinlock);
	if (proc == NULL) return -1;
	*returncode = proc_wait(proc);
	return pid;
}
int sys_getpid(int *retval){
	*retval = curproc->pid;
	return 0;
}
