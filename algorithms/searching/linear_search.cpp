#include <iostream>
#include <vector>

int linearSearch(const std::vector<int>& values, int target) {
    for (int i = 0; i < values.size(); i++) {
        if (values[i] == target) {
            return i;
        }
    }

    return -1;
}

int main() {
    std::vector<int> values = {4, 8, 15, 16, 23, 42};
    int target = 23;
    int result = linearSearch(values, target);

    if (result != -1) {
        std::cout << "Elemento encontrado no indice: "
                  << result << '\n';
    } else {
        std::cout << "Elemento nao encontrado.\n";
    }

    return 0;
}