#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void concatenate() {
    string s1, s2;
    cout << "Enter first string: "; cin >> s1;
    cout << "Enter second string: "; cin >> s2;
    cout << "Concatenated: " << s1 + s2 << endl;
}

void reverseString() {
    string s;
    cout << "Enter string: "; cin >> s;
    reverse(s.begin(), s.end());
    cout << "Reversed: " << s << endl;
}

void deleteVowels() {
    string s, res = "";
    cout << "Enter string: "; cin >> s;
    for (char c : s)
        if (string("aeiouAEIOU").find(c) == string::npos)
            res += c;
    cout << "Without vowels: " << res << endl;
}

void sortStrings() {
    int n;
    cout << "Enter number of strings: "; cin >> n;
    string arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    cout << "Sorted: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

void toLowercase() {
    char c;
    cout << "Enter uppercase character: "; cin >> c;
    if (c >= 'A' && c <= 'Z') c = c + 32;
    cout << "Lowercase: " << c << endl;
}

int main() {
    int choice;
    do {
        cout << "\n1.Concat 2.Reverse 3.Del Vowels 4.Sort 5.Lowercase 6.Exit\n";
        cin >> choice;
        switch(choice) {
            case 1: concatenate(); break;
            case 2: reverseString(); break;
            case 3: deleteVowels(); break;
            case 4: sortStrings(); break;
            case 5: toLowercase(); break;
        }
    } while(choice != 6);
}
