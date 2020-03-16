#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sodium.h>

// init the random generator
void init(void);

// generates n random ints from min to max, including both
uint64_t* generate(int min, int max, int n);

// the default formula with numbers and extra numbers
void def(int min1, int max1, int n1, int min2, int max2, int n2);

// prints numbers
void print(uint64_t* numbers, int length);

// needed to sort the output
int compare( const void* a, const void* b);

// needed to check if a given number is already drawn
int contains(uint64_t num, uint64_t* array, int length);