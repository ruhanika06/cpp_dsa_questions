#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

class SparseMatrix {
    int rows, cols, numTerms;
    Element *elements;

public:
    SparseMatrix(int r, int c, int n) {
        rows = r;
        cols = c;
        numTerms = n;
        elements = new Element[numTerms];
    }

    void read() {
        cout << "Enter non-zero elements (row col value):\n";
        for (int i = 0; i < numTerms; i++) {
            cin >> elements[i].row >> elements[i].col >> elements[i].val;
        }
    }

    void display() {
        cout << "\nSparse Matrix (Triplet Form):\n";
        cout << "Row\tCol\tValue\n";
        for (int i = 0; i < numTerms; i++)
            cout << elements[i].row << "\t" << elements[i].col << "\t" << elements[i].val << endl;
    }

    SparseMatrix transpose() {
        SparseMatrix t(cols, rows, numTerms);
        int k = 0;
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < numTerms; j++) {
                if (elements[j].col == i) {
                    t.elements[k].row = elements[j].col;
                    t.elements[k].col = elements[j].row;
                    t.elements[k].val = elements[j].val;
                    k++;
                }
            }
        }
        return t;
    }

    SparseMatrix add(SparseMatrix &s2) {
        if (rows != s2.rows || cols != s2.cols) {
            cout << "Addition not possible! Dimension mismatch.\n";
            return SparseMatrix(0, 0, 0);
        }

        SparseMatrix sum(rows, cols, numTerms + s2.numTerms);
        int i = 0, j = 0, k = 0;

        while (i < numTerms && j < s2.numTerms) {
            if (elements[i].row < s2.elements[j].row ||
                (elements[i].row == s2.elements[j].row && elements[i].col < s2.elements[j].col)) {
                sum.elements[k++] = elements[i++];
            } 
            else if (s2.elements[j].row < elements[i].row ||
                    (s2.elements[j].row == elements[i].row && s2.elements[j].col < elements[i].col)) {
                sum.elements[k++] = s2.elements[j++];
            } 
            else {
                sum.elements[k] = elements[i];
                sum.elements[k].val = elements[i].val + s2.elements[j].val;
                i++; j++; k++;
            }
        }

        for (; i < numTerms; i++) sum.elements[k++] = elements[i];
        for (; j < s2.numTerms; j++) sum.elements[k++] = s2.elements[j];

        sum.numTerms = k;
        return sum;
    }

    SparseMatrix multiply(SparseMatrix &s2) {
        if (cols != s2.rows) {
            cout << "Multiplication not possible! Dimension mismatch.\n";
            return SparseMatrix(0, 0, 0);
        }

        SparseMatrix result(rows, s2.cols, rows * s2.cols); // upper bound on terms
        int k = 0;

        // Convert s2 to fast-access form by column
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < s2.cols; j++) {
                int sum = 0;
                for (int x = 0; x < numTerms; x++) {
                    if (elements[x].row == i) {
                        for (int y = 0; y < s2.numTerms; y++) {
                            if (s2.elements[y].col == j && elements[x].col == s2.elements[y].row) {
                                sum += elements[x].val * s2.elements[y].val;
                            }
                        }
                    }
                }
                if (sum != 0) {
                    result.elements[k++] = {i, j, sum};
                }
            }
        }
        result.numTerms = k;
        return result;
    }
};

int main() {
    int r1, c1, n1, r2, c2, n2;
    cout << "Enter rows, cols and number of non-zero elements for Matrix 1: ";
    cin >> r1 >> c1 >> n1;
    SparseMatrix s1(r1, c1, n1);
    s1.read();

    cout << "Enter rows, cols and number of non-zero elements for Matrix 2: ";
    cin >> r2 >> c2 >> n2;
    SparseMatrix s2(r2, c2, n2);
    s2.read();

    cout << "\n--- Matrix 1 ---";
    s1.display();
    cout << "\n--- Matrix 2 ---";
    s2.display();

    cout << "\n\n--- Transpose of Matrix 1 ---";
    SparseMatrix t1 = s1.transpose();
    t1.display();

    cout << "\n\n--- Addition Result ---";
    SparseMatrix add = s1.add(s2);
    add.display();

    cout << "\n\n--- Multiplication Result ---";
    SparseMatrix mul = s1.multiply(s2);
    mul.display();

    return 0;
}
