#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>

// Configuration parameters
#define MAX_LOCKS 32
#define NUM_ITERATIONS 1000000
#define MAX_THREADS 48

typedef struct {
    pthread_mutex_t mutex;
    int value;
} protected_counter_t;

typedef struct {
    int thread_id;
    int num_threads;
    int nesting_depth;
    int work_amount;  // Simulated work between locks
    protected_counter_t* counters;
    uint64_t* ops_completed;
} thread_args_t;

// Global variables
protected_counter_t counters[MAX_LOCKS];
uint64_t total_operations = 0;

// Get time in microseconds
uint64_t get_time_usec() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000000 + ts.tv_nsec / 1000;
}

// Simulated work
void do_work(int amount) {
    volatile int dummy = 0;
    for(int i = 0; i < amount; i++) {
        dummy += i;
    }
}

// Recursive lock acquisition
void acquire_nested_locks(protected_counter_t* counters, int start, int depth) {
    if (depth <= 0) return;
    
    pthread_mutex_lock(&counters[start].mutex);
    counters[start].value++;
    
    // Acquire next lock in sequence
    if (depth > 1) {
        acquire_nested_locks(counters, (start + 1) % MAX_LOCKS, depth - 1);
    }
    
    counters[start].value--;
    pthread_mutex_unlock(&counters[start].mutex);
}

void* worker_thread(void* arg) {
    thread_args_t* args = (thread_args_t*)arg;
    uint64_t local_ops = 0;
    
    // Seed random for this thread
    unsigned int seed = args->thread_id;
    
    for(int i = 0; i < NUM_ITERATIONS; i++) {
        // Random starting lock
        // int start_lock = rand_r(&seed) % MAX_LOCKS; ///Check this cycle
        int start_lock = 0;
        // Perform nested lock acquisition
        acquire_nested_locks(args->counters, start_lock, args->nesting_depth);
        
        // Simulated work between lock operations
        do_work(args->work_amount);
        
        local_ops++;
    }
    
    args->ops_completed[args->thread_id] = local_ops;
    return NULL;
}

void run_benchmark(int num_threads, int nesting_depth, int work_amount) {
    // Sanity checks
    if (num_threads > MAX_THREADS) {
        fprintf(stderr, "Error: Number of threads exceeds MAX_THREADS\n");
        return;
    }

    pthread_t* threads = malloc(sizeof(pthread_t) * num_threads);
    if (threads == NULL) {
        fprintf(stderr, "Memory allocation failed for threads\n");
        return;
    }

    thread_args_t* thread_args = malloc(sizeof(thread_args_t) * num_threads);
    if (thread_args == NULL) {
        fprintf(stderr, "Memory allocation failed for thread args\n");
        free(threads);
        return;
    }

    uint64_t* ops_completed = calloc(num_threads, sizeof(uint64_t));
    if (ops_completed == NULL) {
        fprintf(stderr, "Memory allocation failed for ops_completed\n");
        free(threads);
        free(thread_args);
        return;
    }
    // Initialize mutexes
    for(int i = 0; i < MAX_LOCKS; i++) {
        pthread_mutex_init(&counters[i].mutex, NULL);
        counters[i].value = 0;
    }
    
    // Start timing
    uint64_t start_time = get_time_usec();
    
    // Create threads
    for(int i = 0; i < num_threads; i++) {
        thread_args[i].thread_id = i;
        thread_args[i].num_threads = num_threads;
        thread_args[i].nesting_depth = nesting_depth;
        thread_args[i].work_amount = work_amount;
        thread_args[i].counters = counters;
        thread_args[i].ops_completed = ops_completed;
        
        pthread_create(&threads[i], NULL, worker_thread, &thread_args[i]);
    }
    
    // Wait for threads to complete
    for(int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
        total_operations += ops_completed[i];
    }
    
    uint64_t end_time = get_time_usec();
    double duration = (end_time - start_time) / 1000000.0; // Convert to seconds
    
    // Print results
//    printf("Benchmark Results:\n");
//    printf("Threads: %d, Nesting Depth: %d, Work Amount: %d\n", 
//           num_threads, nesting_depth, work_amount);
//    printf("Total Operations: %lu\n", total_operations);
//    printf("Duration: %.2f seconds\n", duration);
//    printf("Operations/second: %.2f\n", total_operations / duration);
//    printf("Average latency: %.2f microseconds\n", 
//           (duration * 1000000) / total_operations);
//    printf("\n");
      printf("%d,%d,%d,%.2f,%.2f\n",num_threads, nesting_depth, work_amount,duration,total_operations / duration);
    
    // Cleanup
    for(int i = 0; i < MAX_LOCKS; i++) {
        pthread_mutex_destroy(&counters[i].mutex);
    }
    
    free(threads);
    free(thread_args);
    free(ops_completed);
}

int main(int argc, char* argv[]) {
    if(argc != 4) {
        fprintf(stderr, "Error: Incorrect number of arguments\n");
        printf("Usage: %s <num_threads> <nesting_depth> <work_amount>\n", argv[0]);
        exit(1);
    }
    
//    printf("Lock Nesting Benchmark\n");
    
    // Debug: Print parsed arguments
    int thread_counts = atoi(argv[1]);
    int nesting_depths = atoi(argv[2]);
    int work_amounts = atoi(argv[3]);
    
//    printf("Parsed arguments:\n");
//    printf("Threads: %d\n", thread_counts);
//    printf("Nesting Depth: %d\n", nesting_depths);
//    printf("Work Amount: %d\n", work_amounts);
    
    // Add error checking for argument parsing
    if (thread_counts <= 0 || nesting_depths <= 0 || work_amounts < 0) {
        fprintf(stderr, "Error: Invalid arguments. All must be positive numbers.\n");
        exit(1);
    }

    run_benchmark(thread_counts, nesting_depths, work_amounts);
    
    return 0;
}
