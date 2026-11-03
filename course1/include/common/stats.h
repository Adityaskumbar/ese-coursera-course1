/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats.h
 * @brief Function declarations for the Week 1 statistics application
 *
 * Declares the functions used to analyze an array of unsigned char data:
 * finding the maximum, minimum, mean and median, sorting the array from
 * largest to smallest, and printing the array and its statistics.
 *
 * @author Verril
 * @date November 2, 2026
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints the statistics of an array
 *
 * Calculates the minimum, maximum, mean and median of the given array and
 * prints them to the screen in a formatted report.
 *
 * @param data   Pointer to the unsigned char data set
 * @param length Number of items in the data set
 *
 * @return void
 */
void print_statistics(unsigned char *data, unsigned int length);

/**
 * @brief Prints an array to the screen
 *
 * Prints every element of the given array, with its index, in a formatted
 * table so the data set can be inspected easily.
 *
 * @param data   Pointer to the unsigned char data set
 * @param length Number of items in the data set
 *
 * @return void
 */
void print_array(unsigned char *data, unsigned int length);

/**
 * @brief Finds the median of an array
 *
 * Sorts a copy of the data and returns the middle value. For an even number
 * of items it returns the average of the two middle values, rounded down.
 * The original array is not modified.
 *
 * @param data   Pointer to the unsigned char data set
 * @param length Number of items in the data set
 *
 * @return The median value, rounded down to the nearest integer
 */
unsigned char find_median(unsigned char *data, unsigned int length);

/**
 * @brief Finds the mean of an array
 *
 * Adds every element of the array and divides the total by the number of
 * items, using integer division so the result is rounded down.
 *
 * @param data   Pointer to the unsigned char data set
 * @param length Number of items in the data set
 *
 * @return The mean value, rounded down to the nearest integer
 */
unsigned char find_mean(unsigned char *data, unsigned int length);

/**
 * @brief Finds the maximum value in an array
 *
 * Walks through every element of the array and keeps track of the largest
 * value seen.
 *
 * @param data   Pointer to the unsigned char data set
 * @param length Number of items in the data set
 *
 * @return The largest value in the array
 */
unsigned char find_maximum(unsigned char *data, unsigned int length);

/**
 * @brief Finds the minimum value in an array
 *
 * Walks through every element of the array and keeps track of the smallest
 * value seen.
 *
 * @param data   Pointer to the unsigned char data set
 * @param length Number of items in the data set
 *
 * @return The smallest value in the array
 */
unsigned char find_minimum(unsigned char *data, unsigned int length);

/**
 * @brief Sorts an array from largest to smallest
 *
 * Sorts the array in place in descending order, so the zeroth element holds
 * the largest value and the last element holds the smallest value.
 *
 * @param data   Pointer to the unsigned char data set
 * @param length Number of items in the data set
 *
 * @return void
 */
void sort_array(unsigned char *data, unsigned int length);

#endif /* __STATS_H__ */
