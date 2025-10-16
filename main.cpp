#include <iostream>

int main() {
    int codeArray[48] = {16, 6, 19, 24, 14, 11, 18, 12, 15, 17, 2, 13, 22, 7, 10, 3, 23, 5, 20, 8, 9, 1, 4, 21, 116, 108, 32, 33, 104, 119, 101, 105, 32, 104, 111, 116, 97, 117, 32, 111, 109, 32, 101, 99, 107, 71, 100, 120};
    int* pointerArray[24] = {};
    int n = 24;

    // TODO: Implement the main function to print out secret code from codeArray using pointerArray.

    //  1) Build an index map:
    //     Scan the first half of codeArray. Each position p contains a rank from 1 to n.
    //     At index i of pointerArray, store a pointer to the cell in ascending order of rank.
    for (int idx = 0; idx < n; ++idx) {
        int rank = codeArray[idx];
        if (rank >= 1 && rank <= n) {
            pointerArray[rank - 1] = &codeArray[idx];
        }
    }

    //  2) Decode and print:
    //     Iterate index of pointerArray i from 0 to n-1.
    //     For each i, move forward by n elements to reach the paired ASCII code in the second half of codeArray.
    //     Convert that ASCII value to a character and print it.
    
    for (int i = 0; i < n; i++) {
        if (pointerArray[i] != nullptr) {
            int ascii = *(pointerArray[i] + n);
            std::cout << static_cast<char>(ascii);
        }
    }
    
    return 0;
}
