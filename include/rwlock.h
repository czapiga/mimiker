#ifndef _SYS_RWLOCK_H_
#define _SYS_RWLOCK_H_

#include <stdbool.h>

typedef struct rwlock rwlock_t;

typedef enum { RW_READER, RW_WRITER } rwo_t;
typedef enum {
  RW_UNLOCKED = 0,
  RW_RLOCKED = 1,
  RW_WLOCKED = 2,
  RW_LOCKED = 3,
  RW_RECURSE = 4
} rwf_t;

void rw_init(rwlock_t *rw, const char *name, bool recurse);
void rw_destroy(rwlock_t *rw);
void rw_enter(rwlock_t *rw, rwo_t who);
void rw_leave(rwlock_t *rw);
bool rw_try_upgrade(rwlock_t *rw);
void rw_downgrade(rwlock_t *rw);

#define rw_assert(rw, flag) __rw_assert((rw), (flag), __FILE__, __LINE__)
void __rw_assert(rwlock_t *rw, rwf_t flag, const char *file, unsigned line);

#endif /* !_SYS_RWLOCK_H_ */
