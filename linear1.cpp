#include <iostream>
using namespace std;

int main() {
    int arr[20], i, num, index = -1, n;

    cout << "Enter the element to the array : ";
    cin>>n;
    for (i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nEnter a Number to Searched: ";
    cin >> num;

    for (i = 0; i < 10; i++) {
        if (arr[i] == num) {
            index = i;
            break;
        }
    }

    if (index != -1)
        cout << "\nItem Found at Position. " << index;
    else
        cout << "\nItem not found!.";

    cout << endl;
    return 0;
}

