#include <stdio.h>

#define SIZE 10

int main()
{
    int id[] = {105, 210, 315, 420, 525, 630, 735, 840};
    int n = 8, h[SIZE], i, j, pos, col = 0;
    int key, hashComp = 0, linearComp = 0;

    for (i = 0; i < SIZE; i++)
        h[i] = -1;

    printf("HASH TABLE INSERTION\n");

    for (i = 0; i < n; i++)
    {
        pos = id[i] % SIZE;

        while (h[pos] != -1)
        {
            col++;
            pos = (pos + 1) % SIZE;
        }

        h[pos] = id[i];

        printf("\nAfter inserting %d:\n", id[i]);
        for (j = 0; j < SIZE; j++)
            printf("%d : %d\n", j, h[j]);
    }

    printf("\nTotal collisions = %d\n", col);

    /* Search using Hashing */
    printf("\nEnter ID to search: ");
    scanf("%d", &key);

    pos = key % SIZE;

    for (i = 0; i < SIZE; i++)
    {
        hashComp++;

        if (h[pos] == key)
        {
            printf("Hashing: Found at index %d\n", pos);
            break;
        }

        if (h[pos] == -1)
            break;

        pos = (pos + 1) % SIZE;
    }

    /* Linear Search */
    for (i = 0; i < n; i++)
    {
        linearComp++;

        if (id[i] == key)
        {
            printf("Linear Search: Found at position %d\n", i);
            break;
        }
    }

    printf("\nHashing comparisons = %d\n", hashComp);
    printf("Linear search comparisons = %d\n", linearComp);
    printf("\nLoad Factor = %.2f\n", (float)n / SIZE);

    return 0;
}
