#include <iostream>
#include <vector>
#include "ShuffleVector.h"

using namespace std;

int main() {
    vector<int> v1 = {1, 2, 3, 4, 7};
    ShuffleVector<int> vec(v1);
    vec.sortVector();
    return 0;
}
