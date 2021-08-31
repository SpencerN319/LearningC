# POSIX threads or pthreads

Specifies a set of interfaces (functions, header files) for threaded
programming.

### Pthreads function return values

- Most pthreads functions return 0 on success and some error number on failure.

### Thread IDs

- A unique identifier, returned to the caller on pthread_create(3)
- A thread can obtain its own ID by calling pthread_self(3)

### Thread safe functions

- A thread-safe function is one that can be safely called from multiple threads
  at the same time.
- A list of non-thread-safe functions can be found in the man pages.

---

## pthread_detatch(3)

- Denoted by: `int pthread_detatch(pthread_t thread);`
- Marks the thread identified by `thread` as detached
- When a detached thread terminates, its resources are automatically released
  back to the system without need for another thread to join with the terminated
  thread.

### Errors

- EINVAL `thread` is not a joinable thread
- ESRCH No thread with the ID `thread` could be found.

### Notes

- Either pthread_join(3) or pthread_detach() should be called for each thread
  that an application creates, so that system resources for the thread can be
  released.
- Resources of any thraeds for which one of these actions has not been done will
  be freed when the process terminates.

---

## pthread_exit(3)

- Denoted by: `noreturn void pthread_exit(void *retval);`
- Terminates the calling thread and returns a value via `retval` that if the
  thread is joinable is available to another thread in the same process that
  calls pthread_join(3)
- This function always succeeds

### Notes

- Performing a return (`return 0;`) from the start function of any thread other
  than the main thread results in an implicit call to pthread_exit()
- To allow other threads to continue executiong the main thread should terminate
  by calling pthread_exit() rather than exit(3)



