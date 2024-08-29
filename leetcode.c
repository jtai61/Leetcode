#include <stdio.h>
#include <stdlib.h>

/* 1. Two Sum */
int *twoSum(int *nums, int numsSize, int target)
{    
    int *index = (int *)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize - 1; i++)
    {
        if ((nums[i] + nums[i + 1]) == target)
        {
            index[0] = i;
            index[1] = i + 1;
            break;
        }
    }

    return index;
}

int main()
{
    int numbers[4] = {2, 7, 11, 15};
    int target = 26;
    int *output;

    output = twoSum(numbers, 4, target);

    free(output);

    return 0;
}