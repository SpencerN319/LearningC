## Notes

## Semaphores vs. Mutex locks

### Semaphore:

- No notion of ownership
- Can be locked and unlocked by any part of the program

### Mutex locks:

- Locked and unlocked only by the calling thread
- Require a builtin failsafe to ensure the lock will be released.
