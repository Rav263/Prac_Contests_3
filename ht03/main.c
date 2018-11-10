#include <stdio.h>
typedef struct RandomGenerator RandomGenerator;

typedef struct RandomOperations
{
    int (*next)(RandomGenerator *);
    void (*destroy)(RandomGenerator *);
} RandomOperations;


typedef struct RandomGenerator
{
    int now;
    RandomOperations *ops;
} RandomGenerator;


RandomGenerator *random_create(int);


int main(void) {
    RandomGenerator *rr = random_create(1234);
    for (int j = 0; j < 100; ++j) {
        printf("%d\n", rr->ops->next(rr));
    }
    rr->ops->destroy(rr);
}
