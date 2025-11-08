#include <iostream>
using namespace std;

int main() {
    int arr[100], n;
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n / 2; i++)
        swap(arr[i], arr[n - i - 1]);

    cout << "Reversed array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
