#include <types.h>
#include <kern/errno.h>
#include <kern/reboot.h>
#include <kern/unistd.h>
#include <limits.h>
#include <lib.h>
#include <uio.h>
#include <clock.h>
#include <thread.h>
#include <proc.h>
#include <vfs.h>
#include <sfs.h>
#include <syscall.h>
#include <test.h>
#include "opt-sfs.h"
#include "opt-net.h"

void hello (void){
	kprintf("hello world\n");
}
