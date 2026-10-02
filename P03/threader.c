#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>

void *print_message_function(void *ptr)
{
    int retval = 4;
    char *message = (char *)ptr;

    printf("%s\n", message);

    return (void *)(intptr_t)(++retval);
}

int main()
{
    pthread_t thread1, thread2;

    const char *message1 = "Thread 1";
    const char *message2 = "Thread 2";

    pthread_create(&thread1, NULL, print_message_function, (void *)message1);
    pthread_create(&thread2, NULL, print_message_function, (void *)message2);

    void *result1;
    void *result2;

    pthread_join(thread1, &result1);
    pthread_join(thread2, &result2);

    printf("Thread 1 returns: %ld\n", (intptr_t)result1);
    printf("Thread 2 returns: %ld\n", (intptr_t)result2);

    return 0;
}
