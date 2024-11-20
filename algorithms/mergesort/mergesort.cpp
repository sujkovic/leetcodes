#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;


void merge(vector<int> &vec, vector<int> &left, vector<int> &right) {
    int leftIndex = 0;
    int rightIndex = 0;
    int i = 0;

    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (left[leftIndex] < right[rightIndex]) {
            vec[i] = left[leftIndex];
            leftIndex++;
            i++;
        }
        else {
            vec[i] = right[rightIndex];
            rightIndex++;
            i++;
        }
    }

    while (leftIndex < left.size()) {
        vec[i] = left[leftIndex];
        leftIndex++;
        i++;
    }

    while (rightIndex < right.size()) {
        vec[i] = right[rightIndex];
        rightIndex++;
        i++;
    }

}

void mergesort(vector<int> &vec) {
    int length = vec.size();
    if (length <= 1) {
        return;
    }

    vector<int> leftVec;
    vector<int> rightVec;
    int middle = length / 2;

    for (int i = 0; i < length; i++) {
        if (i < middle) {
            leftVec.push_back(vec[i]);
        }
        else {
            rightVec.push_back(vec[i]);
        }
    }

    mergesort(leftVec);
    mergesort(rightVec);
    merge(vec, leftVec, rightVec);
}



int main(int argv, char **argc) {
    cout << "bruh\n";
    vector<int> input = {6, 21, 43, 3426, 46758, 34, 57, 34, 46, 324, 45, 1, 67, 4, 7, 6, 3, 46};
    mergesort(input);

    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
    }
    cout << endl << "done\n";

}