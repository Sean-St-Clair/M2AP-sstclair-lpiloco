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
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    ShuffleVector<int> svec(v1);
    svec.sortVector();

    // Test randomness for first algorithm
    svec.randomizeSstclair();
    testRelativeFrequencyPerIndex(svec);
    //testConsecutiveIdenticalItems(svec);

    // Test randomness for second algorithm
    svec.randomizeLpiloco();
    cout << svec << endl;
    testRelativeFrequencyPerIndex(svec);
    testConsecutiveIdenticalItems(svec);
    return 0;
}

template<typename T>
void testRelativeFrequencyPerIndex(ShuffleVector<T> &vec) {

}

template<typename T>
void testConsecutiveIdenticalItems(ShuffleVector<T> &vec) {
    vector<T> originalVector = vec.getVector();
    vector<T> consecutiveItems = {};
    vec.randomizeLpiloco();
    vector<T> newVector = vec.getVector();

    int counter = 0;
    for (int i = 0; i < size(originalVector) - 1; ++i) {
        for (int j = 0; j < size(originalVector) - 1; ++j) {
            if (newVector[i] == originalVector[j] && newVector[i + 1] == originalVector[j + 1]) {
                consecutiveItems.push_back(newVector[i]);
                consecutiveItems.push_back(newVector[i + 1]);
                ++counter;
            }
        }
    }
    cout << "Consecutive values: " << counter << endl;
}
