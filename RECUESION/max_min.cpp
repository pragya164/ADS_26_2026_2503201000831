#include <iostream>
#include <vector>
using namespace std;

int findMax(vector<int>& arr, int n)
{
    if (n == 1)
        return arr[0];

    return max(arr[n - 1], findMax(arr, n - 1));
}

int main()
{
    vector<int> arr = {5, 2, 9, 1, 7};

    cout << "Maximum = " << findMax(arr, arr.size());

    return 0;
}