#include "onyxshell.h"

/**
 * freeAllocatedMemory - Frees dynamically allocated memory
 * @ptr: Pointer to the memory to be freed
 *
 * Return: None
 */

void free_resources(void *ptr)
{
 if (ptr != NULL)
    {
        free(ptr);
    }
}
