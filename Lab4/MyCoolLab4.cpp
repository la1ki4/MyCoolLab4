#include <iostream>
#include "MultiArray.hpp"

int main() {
    int dim_sizes[] = { 3, 4, 5 };
    MultiArray arr(3, dim_sizes);

    // Заполнение массива элементами
    for (int i = 0; i < dim_sizes[0]; i++) {
        for (int j = 0; j < dim_sizes[1]; j++) {
            for (int k = 0; k < dim_sizes[2]; k++) {
                int indices[] = { i, j, k };
                int element = i * 100 + j * 10 + k;
                arr.setElement(indices, element);
            }
        }
    }

    // Изменение элемента массива
    int indices[] = { 2, 0, 4 };
    arr.setElement(indices, 921);

    // Вывод элемента массива
    std::cout << "Element [" << indices[0] << ", " << indices[1] << ", " << indices[2] << "] = " << arr.getElement(indices) << std::endl;
    std::cout << "Index of Element [" << indices[0] << ", " << indices[1] << ", " << indices[2] << "] = " << arr.getElementsByAyliff(indices) << std::endl;
    std::cout << "Address of Element [" << indices[0] << ", " << indices[1] << ", " << indices[2] << "] = " << arr.getVectors() << std::endl;

    return 0;
}
