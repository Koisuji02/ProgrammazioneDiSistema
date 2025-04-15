#ifndef _SYSCALL_H_
#define _SYSCALL_H_

#include <cdefs.h> /* for __DEAD */
#include "opt-syscalls.h"

struct trapframe; /* from <machine/trapframe.h> */
void syscall(struct trapframe *tf);

/* Helper for fork(). You write this. */
void enter_forked_process(struct trapframe *tf);

/* Enter user mode. Does not return. */
__DEAD void enter_new_process(int argc, userptr_t argv, userptr_t env,
		       vaddr_t stackptr, vaddr_t entrypoint);

int sys_reboot(int code);
int sys___time(userptr_t user_seconds, userptr_t user_nanoseconds);

#if OPT_SYSCALLS
int sys_write(int fd, userptr_t buf_ptr, size_t size);
int sys_read(int fd, userptr_t buf_ptr, size_t size);
void sys__exit(int status);
#endif

#endif /* _SYSCALL_H_ */
