#include <iostream>
#include <cstdlib>

// RAII((Resource Acquisition Is Initialization))

using namespace std;

class SafeArray
{
    private:
    // this is a pointer that will store the address of the first element of the array
        int* data;
        int size;
    public:
    // Constructor (initialize array with given size)
    SafeArray(int s)
    {
        // When you say new int[size], you are saying:
        // "Hey computer, find me a continuous block of empty space big enough to hold 'size' number of integers."
        (*this).size = s;
        // Rent the block and save the address of first element in 'data'
        // rest can be accessed because in lecture example as well we don't need derefrencing to access other array elements
        (*this).data = new int [size];
        for(int i = 0; i < size; i++)
        {
            data[i] = 0;
        }
    }
    // Copy Constructor
// The Copy Constructor is triggered anytime you create a brand-new object based on an existing one
// SafeArray c = a + b; a + b creates a temporary array behind the scenes,
// C++ relies on the Copy Constructor to build c using the data from that temporary array.
    SafeArray(const SafeArray& other)
    {
        (*this).size = other.size;
        (*this).data = new int[(*this).size];
        for(int i = 0; i < other.size; i++)
        {
            (*this).data[i] = other.data[i];
        }
    }
    // Destructor
    ~SafeArray(void)
    {
        cout<< "Deconstructor working"<< endl;
        // releasing memory rented
        // you must match the type of delete like [] for arrays
        delete[] data;
    }
    // getSize() function
    int getSize(void)
    {
        return (*this).size;
    }
    // Subscript Operator []
    int& operator [](int index)
    {
        // this is so that  it behaves like an actual array
        // first is bound checking or limit checking part
        if (index < 0 || index >= size)
        {
            cout<< "Bound checking failed"<<endl;
            exit(1);
        }
        // now is the part to return the array index manually
        // return by reference so the actual value slot is returned and not just a copy
        // so the actual value is changed and not the copy
        return (*this).data[index];
    }
//  this is the address of the current object (the GPS coordinates).
// *this is the actual object at that address (the house itself).
    SafeArray& operator=(const SafeArray& other)
    {
        if (this != &other)
        {
            delete[] (*this).data;
            (*this).data = new int [other.size];
            (*this).size = other.size;
            for(int i = 0; i < other.size; i++)
            {
                (*this).data[i] = other.data[i];
            }
        }
        // Return yourself so you can chain: a = b = c.
        return *this;
    }
// const This tells the compiler that this function won't change the array it's checking. It’s just "looking," not "touching."
    bool operator==(const SafeArray& other) const
    {
        if ((*this).size != other.size)
        {
            return false;
        }
        else
        {
            for(int i = 0; i < other.size; i++)
            {
                // if((*this).data[i] == other.data[i])
                if((*this).data[i] == other.data[i])
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
    }
    SafeArray operator+(const SafeArray& other) const
    {
        if ((*this).size != other.size)
        {
            cout << "Arrays are not of the same size" << endl;
            exit(1);
        }
        // to store the addition result
        SafeArray result(other.size);
        // not loop for adding each element of the array
        for(int i = 0; i < other.size; i++)
        {
            result.data[i] = (*this).data[i] + other.data[i];
        }
        return result;
    }
    friend ostream& operator<<(ostream& out, const SafeArray& arr)
    {
        out <<"[";
        for(int i = 0; i < arr.size; i++)
        {
            out<<arr.data[i];
            if(i == (arr.size-1))
            {
                break;
            }
            out<< ",";
        }
        out <<"]";
        return out;
    }
};


int main() {
    SafeArray a(5);
    SafeArray b(5);

    // Fill arrays
    for (int i = 0; i < 5; i++) {
        a[i] = i;
        b[i] = i * 2;
    }

    SafeArray c = a + b;

    cout << "Array A: " << a << endl;
    cout << "Array B: " << b << endl;
    cout << "Array C (A + B): " << c << endl;

    if (a == b)
        cout << "Arrays are equal" << endl;
    else
        cout << "Arrays are NOT equal" << endl;

    return 0;
}
