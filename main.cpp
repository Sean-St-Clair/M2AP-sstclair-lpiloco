#include <iostream>
#include <vector>
#include "ShuffleVector.h"

using namespace std;

int main() {
    // Create shuffle vectors
    vector<int> v1 = {1, 2, 3, 4, 7};
    ShuffleVector<int> shuffleVec(v1);
    shuffleVec.sortVector();

    // Test randomness
    shuffleVec.randomizeSstclair();
    testRelativeFrequency(shuffleVec);
    testRelativeFrequencePerIndex(shuffleVec);
    testConsecutiveIdenticalItems(shuffleVec);
    testMaxConsecutiveIndenticalItems(shuffleVec);

    shuffleVec.randomizeLpiloco();
    return 0;
}
