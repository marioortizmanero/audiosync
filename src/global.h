#ifndef _H_DEFINES
#define _H_DEFINES

#include <stdlib.h>
#include <pthread.h>

// Information about the audio tracks. Both must have the same formats for
// the analysis to work.
#define NUM_CHANNELS 1
#define NUM_CHANNELS_STR "1"
#define SAMPLE_RATE 48000
#define SAMPLE_RATE_STR "48000"
// Conversion from the used sample rate to milliseconds: 48000 / 1000
#define SAMPLES_TO_MS 48

// The value of the last interval in audiosync.c in seconds.
#define MAX_SECONDS_STR "15"

// The minimum cross-correlation coefficient accepted.
#define MIN_CONFIDENCE 0.75

// Structs used to pass the parameters to the threads.
struct thread_data {
    double *buf;
    size_t total_len;
    size_t len;
    const size_t *intervals;
    const int n_intervals;
    pthread_mutex_t *mutex;
    pthread_cond_t *done;
    int *end;
};
struct down_data {
    char *url;
    struct thread_data *th_data;
};

#endif /* _H_DEFINES */
