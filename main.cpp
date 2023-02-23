#include <iostream>
#include <vector>
#include "ShuffleVector.h"

using namespace std;

// TODO: Add good comments

/*
 * For each index in the given ShuffleVector, prints any time there is any discrepancy
 * between the expected relative frequency distribution of unique items and the actual
 * relative frequency distribution.
*/
template<typename T>
void testRelativeFrequencyPerIndex(ShuffleVector<T> &vec);

/*
 * Runs a series of tests based on the presence of sequences of consecutive, identical
 * items in the ShuffleVector. Sequences of different lengths should appear at expected
 * frequencies, so this method prints if there are any discrepancies between these values.
 * This method also prints the length of the longest sequence.
*/
template<typename T>
void testConsecutiveIdenticalItems(ShuffleVector<T> &vec);

int main() {
    // Create shuffle vectors
    vector<char> v1 = {'b', 'y', 'e', 'c', 'a'};
    ShuffleVector<char> shuffleVec(v1);
    shuffleVec.sortVector();
    cout << shuffleVec << endl;

    // Test randomness for first algorithm
    svec.randomizeSstclair();
    testRelativeFrequencyPerIndex(svec);
    testConsecutiveIdenticalItems(svec);

    // Test randomness for second algorithm
    svec.randomizeLpiloco();
    testRelativeFrequencyPerIndex(svec);
    testConsecutiveIdenticalItems(svec);
    return 0;
}

template<typename T>
void testRelativeFrequencyPerIndex(ShuffleVector<T> &vec) {

}

template<typename T>
void testConsecutiveIdenticalItems(ShuffleVector<T> &vec) {

}
