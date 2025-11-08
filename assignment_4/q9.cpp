#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
    for (int s : students) q.push(s);

    int index = 0, count = 0;

    while (!q.empty() && count < q.size()) {
        if (q.front() == sandwiches[index]) {
            q.pop();
            index++;
            count = 0; // reset since a match happened
        } else {
            q.push(q.front());
            q.pop();
            count++;
        }
    }

    return q.size();
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> students(n), sandwiches(n);
    cout << "Enter student preferences (0 for circular, 1 for square): ";
    for (int i = 0; i < n; i++) cin >> students[i];
    cout << "Enter sandwich stack (top to bottom): ";
    for (int i = 0; i < n; i++) cin >> sandwiches[i];

    cout << "Number of students unable to eat: " << countStudents(students, sandwiches) << endl;
    return 0;
}
