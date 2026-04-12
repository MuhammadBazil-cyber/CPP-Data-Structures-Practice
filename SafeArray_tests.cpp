#include "SafeArray.cpp"

int main()
{
    cout << "--- Standard Functionality ---" << endl;
    SafeArray a(5);
    for (int i = 0; i < 5; i++) a[i] = i;
    cout << "Array A: " << a << endl;

    cout << "\n--- Reliability Test: Deep Copy ---" << endl;
    SafeArray b = a; // Copy Constructor
    b[0] = 99;       // Change the copy
    if (a[0] != b[0])
        cout << "[PASS] Deep Copy: Changing B did not affect A." << endl;
    else
        cout << "[FAIL] Shallow Copy: A was modified by B!" << endl;

    cout << "\n--- Reliability Test: Self-Assignment ---" << endl;
    a = a; // Should not crash or delete data
    cout << "[PASS] Self-assignment handled. Array A still: " << a << endl;

    cout << "\n--- Safety Test: Out of Bounds ---" << endl;
    cout << "Attempting to access index 10 in an array of size 5..." << endl;
    // This should trigger your internal error handling/assert
    a[10] = 100;

    return 0;
}
