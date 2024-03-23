#ifndef SIGNAL_H
#define SIGNAL_H

#define SIG_ABORT 6

/**
 * @brief       Raises a signal to the calling process.
 * 
 * @param sig   The id of the signal to raise.
 * @return int  On success, returns 0. Otherwise, returns a non-zero integer.
 */
int raise(int sig);

#endif /* SIGNAL_H */
