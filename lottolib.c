#include "lottolib.h"

void init(void)
{
    int err = sodium_init();
    switch(err)
    {
        case -1:

            fprintf(stderr, "Error, Sodium could not be initialised\n");
            exit(1);
            break;

        case 1:

            fprintf(stderr, "Sodium has already been initialised\n");
            break;

        case 0:

            return;

        default:

            fprintf(stderr, "This should never happen! sodium_init returned %d\n", err);
            exit(err);
    }
}

// uint32_t randombytes_uniform(const uint32_t upper_bound);
// upper bound is EXCLUDED!!

uint64_t * generate(int min, int max, int n)
{
    uint64_t* numbers = malloc(sizeof(uint64_t)*n);
    if(numbers == NULL)
    {
        fprintf(stderr, "Could not allocate memory!\n");
        exit(1);
    }
    memset(numbers, 255, sizeof(uint64_t)*n);
    for(int i = 0; i<n; i++)
    {
        uint64_t new;
        loop:
            new = randombytes_uniform(max-min+1) + min;
            if(contains(new, numbers, n))
                goto loop;
        numbers[i] = new;
    }
    qsort(numbers, n, sizeof(uint64_t), compare);
    return numbers;
}

void def(int min1, int max1, int n1, int min2, int max2, int n2)
{
    printf("Number%s:\n", n1>1?"s":"");

    init();

    uint64_t* numbers = generate(min1, max1, n1);
    print(numbers, n1);
    free(numbers);
    numbers = NULL;

    printf("\nAdditional Number%s:\n", n2>1?"s":"");

    numbers = generate(min2, max2, n2);
    print(numbers, n2);
    free(numbers);
    numbers = NULL;

    printf("\n");
}

void print(uint64_t* numbers, int length)
{
    if(numbers == NULL)
    {
        fprintf(stderr, "Generated Numbers are NULL\n");
        exit(1);
    }
    for(int i = 0; i<length; i++)
    {
        printf("%lu%s", numbers[i], i+1==length?"":", ");
    }
}

int contains(uint64_t num, uint64_t* array, int length)
{
    for(int offset = 0; offset< length; offset++)
    {
        if(array[offset] == num)
            return 1;
    }
    return 0;
}

int compare( const void* a, const void* b)
{
    int int_a = * ( (int*) a );
    int int_b = * ( (int*) b );

    // an easy expression for comparing
    return (int_a > int_b) - (int_a < int_b);
}