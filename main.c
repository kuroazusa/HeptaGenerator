#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include "heptachess_simulate.h"
#include <signal.h>

#define MAX_THREADS 64

typedef struct {
    int thread_id;
    int start_index;
    int game_count;
    int sims_per_move;
    char outdir[256];
} ThreadArgs;

void handle_fpe(int sig) {
    fprintf(stderr, "🔥 Floating Point Exception occurred!\\n");
    exit(1);
}

void* thread_worker(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    char prefix[512];
    for (int i = 0; i < args->game_count; ++i) {
        snprintf(prefix, sizeof(prefix), "%s/game_%06d", args->outdir, args->start_index + i);
        simulate_game(prefix, args->sims_per_move);
    }
    return NULL;
}

int main(int argc, char** argv) {
    signal(SIGFPE, handle_fpe);

    if (argc < 5) {
        fprintf(stderr, "Usage: %s [outdir] [num_games] [num_threads] [sims_per_move]\\n", argv[0]);
        return 1;
    }

    const char* outdir = argv[1];
    int total_games = atoi(argv[2]);
    int num_threads = atoi(argv[3]);
    int sims = atoi(argv[4]);
    if (num_threads > MAX_THREADS) num_threads = MAX_THREADS;
    mkdir(outdir, 0755);

    pthread_t threads[MAX_THREADS];
    ThreadArgs args[MAX_THREADS];
    int games_per_thread = total_games / num_threads;
    int remainder = total_games % num_threads;
    int idx = 0;

    for (int i = 0; i < num_threads; ++i) {
        int count = games_per_thread + (i < remainder ? 1 : 0);
        args[i].thread_id = i;
        args[i].start_index = idx;
        args[i].game_count = count;
        args[i].sims_per_move = sims;
        strncpy(args[i].outdir, outdir, sizeof(args[i].outdir) - 1);
        args[i].outdir[sizeof(args[i].outdir) - 1] = '\0';
        pthread_create(&threads[i], NULL, thread_worker, &args[i]);
        idx += count;
    }

    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("All %d games finished.\\n", total_games);
    return 0;
}