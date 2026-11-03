/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Author: Aditya Kumbar
 * Description: Statistical analysis of an array of unsigned characters.
 ******************************************************************************/

#include <stdio.h>
#include "stats.h"

#define SIZE (40)

void print_statistics(unsigned char data[], unsigned int length)
{
    printf("\nMinimum: %u\n", find_minimum(data, length));
    printf("Maximum: %u\n", find_maximum(data, length));
    printf("Mean: %u\n", find_mean(data, length));
    printf("Median: %u\n", find_median(data, length));
}

void print_array(unsigned char data[], unsigned int length)
{
    unsigned int i;

    for (i = 0; i < length; i++)
        printf("%u ", data[i]);

    printf("\n");
}

unsigned char find_median(unsigned char data[], unsigned int length)
{
    unsigned char sorted[length];
    unsigned int i;

    if (length == 0)
        return 0;

    for (i = 0; i < length; i++)
        sorted[i] = data[i];

    sort_array(sorted, length);

    if (length % 2 == 0)
        return (sorted[length / 2 - 1] + sorted[length / 2]) / 2;

    return sorted[length / 2];
}

unsigned char find_mean(unsigned char data[], unsigned int length)
{
    unsigned int sum = 0;
    unsigned int i;

    if (length == 0)
        return 0;

    for (i = 0; i < length; i++)
        sum += data[i];

    return (unsigned char)(sum / length);
}

unsigned char find_maximum(unsigned char data[], unsigned int length)
{
    unsigned char maximum;
    unsigned int i;

    if (length == 0)
        return 0;

    maximum = data[0];

    for (i = 1; i < length; i++)
        if (data[i] > maximum)
            maximum = data[i];

    return maximum;
}

unsigned char find_minimum(unsigned char data[], unsigned int length)
{
    unsigned char minimum;
    unsigned int i;

    if (length == 0)
        return 0;

    minimum = data[0];

    for (i = 1; i < length; i++)
        if (data[i] < minimum)
            minimum = data[i];

    return minimum;
}

void sort_array(unsigned char data[], unsigned int length)
{
    unsigned int i, j;
    unsigned char temp;

    for (i = 0; i < length - (length > 0); i++)
    {
        for (j = 0; j < length - i - 1; j++)
        {
            if (data[j] < data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    unsigned char test[SIZE] = {
        34, 201, 190, 154, 8, 194, 2, 6,
        114, 88, 45, 76, 123, 87, 25, 23,
        200, 122, 150, 90, 92, 87, 177, 244,
        201, 6, 12, 60, 8, 2, 5, 67,
        7, 87, 250, 230, 99, 3, 100, 90
    };

    print_statistics(test, SIZE);

    printf("\nSorted array:\n");
    sort_array(test, SIZE);
    print_array(test, SIZE);

    return 0;
}
