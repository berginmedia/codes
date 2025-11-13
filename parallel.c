#include <stdio.h>
#include <pthread.h>

#define MAX 100
#define THREADS 4

int arr[MAX];
int n;
int sum = 0;
pthread_mutex_t lock;

void* partial_sum(void* arg) {
    int thread_part = *(int*)arg;
    int start = thread_part * (n / THREADS);
    int end = (thread_part + 1) * (n / THREADS);

    int local_sum = 0;
    for (int i = start; i < end && i < n; i++)
        local_sum += arr[i];

    pthread_mutex_lock(&lock);
    sum += local_sum;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    printf("Enter number of elements (max 100): ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    pthread_t threads[THREADS];
    pthread_mutex_init(&lock, NULL);

    int thread_id[THREADS];
    for (int i = 0; i < THREADS; i++) {
        thread_id[i] = i;
        pthread_create(&threads[i], NULL, partial_sum, &thread_id[i]);
    }

    for (int i = 0; i < THREADS; i++)
        pthread_join(threads[i], NULL);

    pthread_mutex_destroy(&lock);
    printf("Total Sum = %d\n", sum);
    return 0;
}