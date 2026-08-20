#include <bits/stdc++.h>

using namespace std;

int *fun(int n)
{
    /*
        n is passed by value, so the function receives a copy of n.
        This copy is stored in the function's local memory and disappears
        when the function finishes.

        This is not a problem because we only need the value of n while
        creating and working with the array.
    */

    /*
        The array is dynamically created in heap memory using new[].

        The size of the array is decided at runtime using n.
        This is useful when we do not know the required array size
        until the program is running.
    */

    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    /*
        We return the address of the dynamically allocated array.

        The local pointer variable 'a' will disappear when this function
        finishes, but the heap memory will remain allocated.

        Therefore, main() can still access the array using the returned
        address.
    */

    return a;
}

int main()
{
    int n;
    cin >> n;

    // Receive the address of the dynamically allocated array.
    int *a = fun(n);

    // Print all elements of the array.
    for (int i = 0; i < n; i++)
    {
        cout << " " << a[i];
    }

    /*
        The array was created using new[], so we must use delete[]
        to release the allocated heap memory after we finish using it.

        new[]  -> delete[]
        new    -> delete
    */

    delete[] a;

    return 0;
}