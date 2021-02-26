#include <iostream>
#include <vector>
#include <algorithm>

#include "Header.h"

using namespace std;


vector<int> findArrayQuadruplet(const vector<int>& arr, int s)
{
    if (arr.size() < 4) {
        return {};
    }

    vector<int> input(arr.begin(), arr.end());

    sort(input.begin(), input.end());

    cout << "input = ";
    for (auto e : input) {
        cout << " " << e;
    }
    cout << endl;

    vector<int> result(4);
    int size = input.size();
    for (int i = 0; i < size - 3; i++) {
        for (int j = i + 1; j < size - 2; j++) {

            int left = j + 1, right = size - 1;
            while (left < right) {
                int sum = input[i] + input[j] + input[left] + input[right];
                if (sum == s) {
                    result[0] = input[i];
                    result[1] = input[j];
                    result[2] = input[left];
                    result[3] = input[right];

                    return result;
                }

                if (sum < s) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
    }

    return {};
}

vector<int> findArrayQuadruplet_1(const vector<int>& arr, int s)
{
    if (arr.size() < 4) {
        return {};
    }

    vector<int> numbers(arr.begin(), arr.end());

    sort(numbers.begin(), numbers.end());

    cout << "numbers = ";
    for (auto e : numbers) {
        cout << " " << e;
    }
    cout << endl;

    vector<int> result(4);
    int size = numbers.size();
    for (int i = 0; i < size - 3; i++) {
        for (int j = i + 1; j < size - 2; j++) {
            for (int k = j + 1; k < size - 1; k++) {
                for (int l = k + 1; l < size; l++) {
                    int sum = numbers[i] + numbers[j] + numbers[k] + numbers[l];
                    if (sum == s) {
                        return { numbers[i], numbers[j], numbers[k], numbers[l] };
                    }

                    if (sum > s) {
                        break;
                    }
                }
            }
        }
    }

    return {};
}



