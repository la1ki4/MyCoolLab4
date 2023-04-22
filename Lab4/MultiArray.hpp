#pragma once

class MultiArray {
private:
    int* arr;
    int n_dims;
    int* dim_sizes;

public:
    MultiArray(int n, int* dim_sizes) {
        n_dims = n;
        this->dim_sizes = new int[n_dims];
        int size = 1;
        for (int i = 0; i < n_dims; i++) {
            this->dim_sizes[i] = dim_sizes[i];
            size *= dim_sizes[i];
        }
        arr = new int[size];
    }

    ~MultiArray() {
        delete[] arr;
        delete[] dim_sizes;
    }

    void setElement(int* indices, int value) {
        int index = 0;
        int multiplier = 1;
        for (int i = n_dims - 1; i >= 0; i--) {
            index += indices[i] * multiplier;
            multiplier *= dim_sizes[i];
        }
        arr[index] = value;
    }

    int getElement(int* indices) {
        int index = 0;
        int multiplier = 1;
        for (int i = n_dims - 1; i >= 0; i--) {
            index += indices[i] * multiplier;
            multiplier *= dim_sizes[i];
        }
        return arr[index];
    }

    int getElementsByAyliff(int* ayliff_indices) {
        int index = 0;
        int multiplier = 1;
        for (int i = n_dims - 1; i >= 0; i--) {
            index += ayliff_indices[i] * multiplier;
            multiplier *= (dim_sizes[i] + 1) / 2;
        }
        return arr[index];
    }

    int** getVectors() {
        int** vectors = new int* [n_dims];
        for (int i = 0; i < n_dims; i++) {
            vectors[i] = &arr[i];
        }
        return vectors;
    }
};
