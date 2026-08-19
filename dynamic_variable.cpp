#include <bits/stdc++.h>

using namespace std;

int *fun()
{
    // Create an integer dynamically in heap memory.
    int *a = new int;

    // 'a' stores the address of the dynamically allocated memory.
    cout << "Fun: " << a << endl; // Example: Fun: 0x101405be0

    // Store 100 in the heap memory.
    *a = 100;

    // Return the address of the heap memory.
    return a;
}

int main()
{
    // Normal variable:
    // int a = 10;

    /*
        Dynamic memory allocation:

        'new int' creates an integer in heap memory and returns its address.

        int *a = new int;

        Here, 'a' is a pointer that stores the address of the heap memory.

        We can use *a to access or modify the value stored at that address.

        Example:

            *a = 10;
            cout << *a;
    */

    // int *a = new int;
    // *a = 10;
    // cout << *a << endl;

    // float *f = new float;
    // *f = 1.5667;
    // cout << *f << endl;

    /*
        The function fun() returns the address of dynamically allocated
        heap memory.

        We receive that address in the pointer reciveA.

        reciveA contains the same address that was stored in 'a' inside fun().
    */

    int *reciveA = fun();

    cout << "Main: " << reciveA << endl;
    // Example: Main: 0x101405be0

    /*
        The address printed inside fun() and the address printed in main()
        are the same because the pointer returned by fun() contains the
        address of the same heap memory.

        The local pointer variable 'a' belongs to the function fun() and
        disappears when the function finishes.

        However, the dynamically allocated memory created using 'new'
        remains in the heap.

        Because reciveA still contains its address, we can access that
        heap value by dereferencing reciveA.

        *reciveA gives us the value stored in that heap memory.
    */

    cout << "Value: " << *reciveA << endl;
    // Output: Value: 100

    /*
        Important:

        The pointer variable 'a' inside fun() is a local variable, so it
        disappears when fun() finishes.

        But the memory created by:

            new int

        does NOT disappear automatically when fun() finishes.

        It remains allocated until we release it using delete.

        Therefore, after using the dynamically allocated memory, we should
        release it:

            delete reciveA;
    */

    delete reciveA;

    /*
        A pointer to a pointer is different from the situation above.

        If we have:

            int *p;

        then 'p' is a pointer to an integer.

        If we have:

            int **pp;

        then 'pp' is a pointer to a pointer.

        The number of '*' tells us the pointer level:

            int *p;       // pointer to int
            int **pp;     // pointer to pointer
            int ***ppp;   // pointer to pointer to pointer

        But we should NOT return the address of a local pointer variable
        from a function, because that local variable no longer exists after
        the function returns.
    */

    return 0;
}