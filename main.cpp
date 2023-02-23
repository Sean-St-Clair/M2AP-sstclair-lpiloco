#include <iostream>
#include <vector>
#include "ShuffleVector.h"

using namespace std;

int main() {
    ShuffleVector<int> vec({1, 2, 3, 4, 7});
    ShuffleVector<int> v = vec.sortVec();

    return 0;
}
