/*
 * Copyright (c) 2019 Qualcomm Technologies, Inc. All rights reserved.
 * Portions Copyright (c) 2008-2015 Travis Geiselbrecht
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef __KERNEL_THREAD_H
#define __KERNEL_THREAD_H

#include "sys/types.h"
#include "list.h"
#include "compiler.h"
#include "arch/defines.h"
#include "arch/ops.h"
#include "arch/thread.h"
#include "kernel/wait.h"
#include "kernel/spinlock.h"
#include "debug.h"

__BEGIN_CDECLS;

/* debug-enable runtime checks */
#if LK_DEBUGLEVEL > 1
#define SCHED_STATS 1
#define THREAD_STACK_HIGHWATER 1
#define THREAD_STACK_BOUNDS_CHECK 1
#ifndef THREAD_STACK_PADDING_SIZE
#define THREAD_STACK_PADDING_SIZE 256
#endif
#endif

struct thread_stats {
    uint32_t preempt_cnt;
    uint32_t blocked_cnt;

    uint64_t preempt_dur;
    uint64_t blocked_dur;
    uint64_t active_dur;
    uint64_t sleep_dur;
};

enum thread_state {
    THREAD_SUSPENDED = 0,
    THREAD_READY,
    THREAD_RUNNING,
    THREAD_BLOCKED,
    THREAD_SLEEPING,
    THREAD_DEATH,
};

typedef int (*thread_start_routine)(void *arg);

/* thread local storage */
enum thread_tls_list {
#ifdef WITH_LIB_UTHREAD
    TLS_ENTRY_UTHREAD,
#endif
#ifdef WITH_LIB_LKUSER
    TLS_ENTRY_LKUSER,
#endif
    MAX_TLS_ENTRY
};

#define THREAD_FLAG_DETACHED                  (1<<0)
#define THREAD_FLAG_FREE_STACK                (1<<1)
#define THREAD_FLAG_FREE_STRUCT               (1<<2)
#define THREAD_FLAG_REAL_TIME                 (1<<3)
#define THREAD_FLAG_IDLE                      (1<<4)
#define THREAD_FLAG_DEBUG_STACK_BOUNDS_CHECK  (1<<5)

struct thread;
typedef struct thread  thread_t;

int thread_curr_cpu(thread_t*);
int thread_pinned_cpu(thread_t*);
void thread_set_curr_cpu(thread_t*, int cpu);
void thread_set_pinned_cpu(thread_t*, int cpu);

/* thread priority */
#define NUM_PRIORITIES 32
#define LOWEST_PRIORITY 0
#define HIGHEST_PRIORITY (NUM_PRIORITIES - 1)
#define DPC_PRIORITY (NUM_PRIORITIES - 2)
#define IDLE_PRIORITY LOWEST_PRIORITY
#define LOW_PRIORITY (NUM_PRIORITIES / 4)
#define DEFAULT_PRIORITY (NUM_PRIORITIES / 2)
#define HIGH_PRIORITY ((NUM_PRIORITIES / 4) * 3)

/* stack size */
#ifdef CUSTOM_DEFAULT_STACK_SIZE
#define DEFAULT_STACK_SIZE CUSTOM_DEFAULT_STACK_SIZE
#else
#define DEFAULT_STACK_SIZE 0x1000
#endif

/* functions */
void thread_init_early(void);
void thread_init(void);
void thread_become_idle(void) __NO_RETURN;
void thread_secondary_cpu_init_early(void);
void thread_secondary_cpu_entry(void) __NO_RETURN;
void thread_set_name(const char *name);
void thread_set_priority(int priority);
thread_t *thread_create(const char *name, thread_start_routine entry, void *arg, int priority, size_t stack_size);
thread_t *thread_create_etc(thread_t *t, const char *name, thread_start_routine entry, void *arg, int priority, void *stack, size_t stack_size);
status_t thread_resume(thread_t *);
void thread_exit(int retcode) __NO_RETURN;
void thread_sleep(lk_time_t delay);
status_t thread_detach(thread_t *t);
status_t thread_join(thread_t *t, int *retcode, lk_time_t timeout);
status_t thread_detach_and_resume(thread_t *t);
status_t thread_set_real_time(thread_t *t);

void dump_thread(thread_t *t);
void arch_dump_thread(thread_t *t);
void dump_all_threads(void);

/* scheduler routines */
void thread_yield(void); /* give up the cpu voluntarily */
void thread_preempt(void); /* get preempted (inserted into head of run queue) */
void thread_block(void); /* block on something and reschedule */
void thread_unblock(thread_t *t, bool resched); /* go back in the run queue */

#ifdef WITH_LIB_UTHREAD
void uthread_context_switch(thread_t *oldthread, thread_t *newthread);
#endif

/* called on every timer tick for the scheduler to do quantum expiration */
enum handler_return thread_timer_tick(void);

/* the current thread */
thread_t *get_current_thread(void);
void set_current_thread(thread_t *);

/* scheduler lock */
extern spin_lock_t thread_lock;

#define THREAD_LOCK(state) spin_lock_saved_state_t state; spin_lock_irqsave(&thread_lock, state)
#define THREAD_UNLOCK(state) spin_unlock_irqrestore(&thread_lock, state)

static inline bool thread_lock_held(void)
{
    return spin_lock_held(&thread_lock);
}

/* thread local storage */
uint thread_get_max_tls_count (void);

uintptr_t tls_get(uint entry);

uintptr_t __tls_set(uint entry, uintptr_t val);

/* thread level statistics */
struct sched_stats {
    lk_bigtime_t idle_time;
    lk_bigtime_t last_idle_timestamp;
    ulong reschedules;
    ulong context_switches;
    ulong preempts;
    ulong yields;
    ulong interrupts; /* platform code increment this */
    ulong timer_ints; /* timer code increment this */
    ulong timers; /* timer code increment this */

    ulong reschedule_ipis;
};

struct sched_stats* get_cpu_sched_stats (uint cpu, struct sched_stats* tsp);

__END_CDECLS;

#endif
