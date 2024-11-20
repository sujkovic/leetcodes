#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int partition(vector<int> &vec, int start, int end)
{
    int pivot = vec[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++)
    {
        if (vec[j] < pivot)
        {
            i++;
            int temp = vec[j];
            vec[j] = vec[i];
            vec[i] = temp;
        }
    }

    i++;
    int temp = vec[end];
    vec[end] = vec[i];
    vec[i] = temp;

    return i; //  <- pivot index
}

void quicksort(vector<int> &vec, int start, int end)
{
    if (end <= start)
    {
        return;
    }

    int middle = partition(vec, start, end);
    quicksort(vec, start, middle - 1);
    quicksort(vec, middle + 1, end);
}

int main(int argc, char **argv)
{
    cout << "bruh\n";
    vector<int> input = {6, 21, 43, 3426, 46758, 34, 57, 34, 46, 324, 45, 1, 67, 4, 7, 6, 3, 46};
    quicksort(input, 0, input.size() - 1);

    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
    }
    cout << endl << "done\n";

    return 0;
}