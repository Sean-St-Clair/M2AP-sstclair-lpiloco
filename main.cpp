#include <iostream>
#include <vector>
#include "ShuffleVector.h"

using namespace std;

int main() {
    // Create shuffle vectors
    vector<char> v1 = {'b', 'y', 'e', 'c', 'a'};
    ShuffleVector<char> shuffleVec(v1);
    shuffleVec.sortVector();
    cout << shuffleVec << endl;

    // Test randomness
    /*shuffleVec.randomizeSstclair();
    testRelativeFrequency(shuffleVec);
    testRelativeFrequencePerIndex(shuffleVec);
    testConsecutiveIdenticalItems(shuffleVec);
    testMaxConsecutiveIndenticalItems(shuffleVec);*/

    shuffleVec.randomizeLpiloco();
    return 0;
}
