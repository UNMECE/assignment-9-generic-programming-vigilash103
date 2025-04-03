#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class GenericArray 
{
    private:
        std::unique_ptr<T[]> array;
        int arraySize;
    public:
        ~GenericArray()
        {
            // Destructor
        }
        GenericArray(int size)
        {
            arraySize = size;
            array = std::make_unique<T[]>(size);
        }
        void addElement(int index, T value)
        {
            if (index >= 0 && index < arraySize)
            {
                array[index] = value;
            }
        }

        T at(int param)
        {
            if (param >= 0 && param < arraySize)
            {
                return array[param];
            }
            throw std::out_of_range("Index out of range");
        }

        T sum()
        {
            T sum = 0;
            for (int i = 0; i < arraySize; i++)
            {
                sum += array[i];
            }
            return sum;
        }

        T size()
        {
            return arraySize;
        }

        T max()
        {
            T max = array[0];
            for (int i = 1; i < arraySize; i++)
            {
                if (array[i] > max)
                {
                    max = array[i];
                }
            }
            return max;
        }

        T min()
        {
            T min = array[0];
            for (int i = 1; i < arraySize; i++)
            {
                if (array[i] < min)
                {
                    min = array[i];
                }
            }
            return min;
        }

        T* slice(int start, int end)
        {
            if (start < 0 || end > arraySize || start >= end)
            {
                throw std::out_of_range("Invalid slice range");
            }
            T* slicedArray = new T[end - start];
            for (int i = start; i < end; i++)
            {
                slicedArray[i - start] = array[i];
            }
            return slicedArray;
        }
};

int main()
{
    // Instance of GenericArray for integers
    // The array will be of size 10
    GenericArray<int> int_array(10);

    // Adding elements to the array
    int_array.addElement(0, 12);
    int_array.addElement(1, 32);
    int_array.addElement(2, 4);
    int_array.addElement(3, 65);
    int_array.addElement(4, 1);
    int_array.addElement(5, 90);
    int_array.addElement(6, 4);
    int_array.addElement(7, 35);
    int_array.addElement(8, 26);
    int_array.addElement(9, 74);
  
    // Accessing elements in the array
    // Finding the size of the array
    std::cout << "size of array is " << int_array.size() << std::endl;
    // Finding the sum of the array
    std::cout << "sum of the array is " << int_array.sum() << std::endl;
    // Finding the Minimum and Maximum of the array
    std::cout << "maximum and minimum of array is: " << int_array.max() << "\t" << int_array.min() << std::endl;
    //Slicing the array
    // The slice will be from index 5 to 10 (exclusive)
    int *sliced_array = int_array.slice(5,10);
    // Output the sliced array
    std::cout << "sliced array is " << *sliced_array << std::endl;
    
    return 0;
}