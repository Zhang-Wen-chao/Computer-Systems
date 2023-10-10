/*
There are 2 int arrays with no more than 100 elements, each array has some different elements, but some elements are duplicated between these 2 arrays, let’s remove duplicated elements, e.g. 
if array#1 is { 1,2,3,4 }, array#2 is {2,3,4,5}, the result could be:
    1. Array#1={1,2,3,4}, Array#2={5} or
    2. Array#1={1,2,3}, Array#2={4,5} or
    3. Array#1={1,2}, Array#2={3,4,5} or
    4. Array#1={1,3}, Array#2={2,4,5}
    5. ……
But we define the best result is:
    1. Each element can keep 1 instance either in array#1 or array#2
    2. No element is missing.
    3. If an element is only in array1, it will not appear in array2 finally.
    4. Number of elements in Array#1 is as close as possible to the number of elements in Array#2.
        a. E.g. if array#1={1,2,3,4}, array#2={2,3,4}, we expect result are:
            i. array#1={1,2}, array#2={3,4} or
            ii. array#1={1,3}, array#2={2,4} or
            iii. array#1={1,4}, array#2={2,3}
            iv. array#1={1}, array#2={2,3,4}, bad result, array#1 size is not close to array#2 size.
            v. array#1={3,4}, array#2={1,2}, bad result, 1 shouldn’t appear in array#2
Please help implement a function:
Bool RemoveDup(int array1[], int &numOfElement1, int array2[], int &numOfElement2)
{
return true;
}
*/

#include <algorithm> // for std::sort
#include <cmath>     // for abs
#include <cstdio>    // for printf

bool RemoveDup(int array1[], int &numOfElement1, int array2[], int &numOfElement2) {
    std::sort(array1, array1 + numOfElement1);
    std::sort(array2, array2 + numOfElement2);

    int i = 0, j = 0;
    int new_numOfElement1 = 0, new_numOfElement2 = 0;
    int new_array1[numOfElement1], new_array2[numOfElement2];

    while (i < numOfElement1 && j < numOfElement2) {
        if (array1[i] == array2[j]) {
            // Remove duplicated element
            i++;
            j++;
        } else if (array1[i] < array2[j]) {
            // Add element to new array1
            new_array1[new_numOfElement1++] = array1[i++];
        } else {
            // Add element to new array2
            new_array2[new_numOfElement2++] = array2[j++];
        }
    }

    // Copy remaining elements from array1 to new array1
    while (i < numOfElement1) {
        new_array1[new_numOfElement1++] = array1[i++];
    }

    // Copy remaining elements from array2 to new array2
    while (j < numOfElement2) {
        new_array2[new_numOfElement2++] = array2[j++];
    }

    // Update input arrays and their sizes
    std::copy(new_array1, new_array1 + new_numOfElement1, array1);
    std::copy(new_array2, new_array2 + new_numOfElement2, array2);
    numOfElement1 = new_numOfElement1;
    numOfElement2 = new_numOfElement2;

    // Check if the result is valid
    int diff = abs(numOfElement1 - numOfElement2);
    if (diff > 1) {
        return false;
    } else if (diff == 1) {
        // Move one element from larger array to smaller array
        if (numOfElement1 > numOfElement2) {
            int temp = array1[numOfElement1 - 1];
            numOfElement1--;
            numOfElement2++;
            array1[numOfElement1] = 0;
            array2[numOfElement2 - 1] = temp;
        } else {
            int temp = array2[numOfElement2 - 1];
            numOfElement2--;
            numOfElement1++;
            array2[numOfElement2] = 0;
            array1[numOfElement1 - 1] = temp;
        }
    }

    return true;
}

int main() {
    int array1[] = {1, 2, 3, 4};
    int array2[] = {2, 3, 4, 5};
    int numOfElement1 = sizeof(array1) / sizeof(array1[0]);
    int numOfElement2 = sizeof(array2) / sizeof(array2[0]);

    if (RemoveDup(array1, numOfElement1, array2, numOfElement2)) {
        printf("Array#1: ");
        for (int i = 0; i < numOfElement1; i++) {
            printf("%d ", array1[i]);
        }
        printf("\nArray#2: ");
        for (int i = 0; i < numOfElement2; i++) {
            printf("%d ", array2[i]);
        }
        printf("\n");
    } else {
        printf("Invalid input!\n");
    }

    return 0;
}