#ifndef _SYS_CONDVAR_H_
#define _SYS_CONDVAR_H_

typedef struct condvar condvar_t;
typedef struct mutex mutex_t;

void cv_init(condvar_t *cv, const char *name);
void cv_destroy(condvar_t *cv);
void cv_wait(condvar_t *cv, mutex_t *mtx);
void cv_signal(condvar_t *cv);
void cv_broadcast(condvar_t *cv);

#endif
