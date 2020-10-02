#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);



/*
 * Complete the 'filledOrders' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY order
 *  2. INTEGER k
 */
 int   *sortNums(int* nums)
 {
     int    len = 0;

     while (nums)
        len++;
     for (int i = 0; i < len; i++)
     {
         int tmp;
         
         if (nums[i] > nums[i + 1])
         {
             tmp = nums[i];
             nums[i] = nums[i + 1];
             nums[i + 1] = tmp;
         }
     }
     return nums;
 }

int filledOrders(int order_count, int* order, int k) {
    int ret = 0;
    int sum = 0;

    order = sortNums(order);
//    if (order[0] > k)
//      return 0;
    for (int i = 0; i < order_count; i++)
    {
        sum += order[i];
        if (sum > k)
            return ret;
        ret++;
    }
    return 0;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int order_count = parse_int(ltrim(rtrim(readline())));

    int* order = malloc(order_count * sizeof(int));

    for (int i = 0; i < order_count; i++) {
        int order_item = parse_int(ltrim(rtrim(readline())));

        *(order + i) = order_item;
    }

    int k = parse_int(ltrim(rtrim(readline())));

    int result = filledOrders(order_count, order, k);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
