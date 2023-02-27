#include "ShuffleVector.h"

using namespace std;

// TODO: Add good comments

/*
 * For each index in the given ShuffleVector, prints any time there is any discrepancy
 * between the expected relative frequency distribution of items and the actual
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

    // Demonstrate sorting (before shuffling)
    cout << "Shuffle Vector before sorting: " << endl;
    cout << svec << endl << endl;
    cout << "Shuffle Vector after sorting: " << endl;
    svec.sortVector();
    cout << svec << endl << endl;

    // Shuffles according to first algorithm (static seed)
    svec.randomizeSstclair(0);
    cout << "Shuffle Vector after randomizeSstclair with static seed: " << endl;
    cout << svec << endl << endl;
    cout << "Shuffle Vector after sorting: " << endl;
    svec.sortVector();
    cout << svec << endl << endl;

    // Shuffles according to first algorithm (dynamic seed)
    svec.randomizeSstclair(time(0));
    cout << "Shuffle Vector after randomizeSstclair with dynamic seed: " << endl;
    cout << svec << endl << endl;
    cout << "Shuffle Vector after sorting: " << endl;
    svec.sortVector();
    cout << svec << endl << endl;

    // Shuffles according to second algorithm
    svec.randomizeLpiloco();
    cout << "Shuffle Vector after randomizeLpiloco: " << endl;
    cout << svec << endl << endl;
    cout << "Shuffle Vector after sorting: " << endl;
    svec.sortVector();
    cout << svec << endl << endl;

    cout << "Relative Frequency Test:" << endl;
    testRelativeFrequencyPerIndex(svec);

    cout << "Consecutive Items Test:" << endl;
    testConsecutiveIdenticalItems(svec);
    return 0;
}

// TODO: All of the methods have been demonstrated, so now each of these
//  methods needs to test the randomness of both randomization algorithms
template<typename T>
void testRelativeFrequencyPerIndex(ShuffleVector<T> &vec) {
    vector<T> originalVector = vec.getVector();
    vector<T> newVector;

    // Testing with static seed
    vec.randomizeSstclair(0);

    // Testing with dynamic seed
    vec.randomizeSstclair(time(0));
}

// TODO: All of the methods have been demonstrated, so now each of these
//  methods needs to test the randomness of both randomization algorithms
template<typename T>
void testConsecutiveIdenticalItems(ShuffleVector<T> &vec) {
    vector<T> originalVector = vec.getVector();
    vector<T> consecutiveItemsL = {};
    vec.randomizeLpiloco();
    vector<T> newVectorL = vec.getVector();

    vec.sortVector();
    vector<T> consecutiveItemsS = {};
    vec.randomizeSstclair(2);
    vector<T> newVectorS = vec.getVector();

    int counterL = 0;
    int counterS = 0;
    for (int i = 0; i < size(originalVector) - 1; ++i) {
        for (int j = 0; j < size(originalVector) - 1; ++j) {
            if (newVectorL[i] == originalVector[j] && newVectorL[i + 1] == originalVector[j + 1]) {
                consecutiveItemsL.push_back(newVectorL[i]);
                consecutiveItemsL.push_back(newVectorL[i + 1]);
                ++counterL;
            }
            if (newVectorS[i] == originalVector[j] && newVectorS[i + 1] == originalVector[j + 1]) {
                consecutiveItemsS.push_back(newVectorS[i]);
                consecutiveItemsS.push_back(newVectorS[i + 1]);
                ++counterS;
            }
        }
    }

    int currentMax = 0;
    int tempCount = 2;
    for (int i = 1; i < size(consecutiveItemsL); ++i) {
        if (tempCount > currentMax && tempCount > 2) {
            currentMax = tempCount;
        }

        if (consecutiveItemsL[i] == consecutiveItemsL[i + 1]) {
            ++tempCount;
        }
        else {
            tempCount = 2;
        }
    }

    cout << "Consecutive pairs in randomizeLpiloco: " << counterL << endl;
    cout << "Length of longest consecutive items: " << currentMax << endl << endl;

    cout << "Consecutive pairs in randomizeSstclair: " << counterS << endl;
    cout << "Length of longest consecutive items: " << endl;
}
