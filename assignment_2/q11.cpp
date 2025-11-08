#include <iostream>
#include <algorithm>  // for sort
#include <string>
using namespace std;

bool areAnagrams(string str1, string str2) {
    // If lengths are not same, cannot be anagrams
    if (str1.length() != str2.length())
        return false;

    // Sort both strings
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // If sorted versions are same → anagram
    return (str1 == str2);
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    if (areAnagrams(str1, str2))
        cout << "YES, they are anagrams\n";
    else
        cout << "NO, they are not anagrams\n";

    return 0;
}