#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& values, int target) {
    int low = 0;
    int high = static_cast<int>(values.size()) - 1; // - index 0

    while (low <= high) {
        int middle = low + (high - low) / 2; //overflow

        if (values[middle] == target) {
            return middle;
        }

        if (target < values[middle]) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }

    return -1;
}

int main() {
    std::vector<int> values = {4, 8, 15, 16, 23, 42};
    int target = 23;
    int result = binarySearch(values, target);

    if (result != -1) {
        std::cout << "Elemento encontrado no indice: "
                  << result << '\n';
    } else {
        std::cout << "Elemento nao encontrado.\n";
    }

    return 0;
}