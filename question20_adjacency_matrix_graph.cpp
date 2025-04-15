#include <iostream>
using namespace std;

int main() {
    int vertices = 4;
    // Initialize a 4x4 adjacency matrix with 0s.
    int adjMatrix[4][4] = { {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} };

    // Let's assume edges: 0-1, 0-2, 1-2, 1-3
    adjMatrix[0][1] = adjMatrix[1][0] = 1;
    adjMatrix[0][2] = adjMatrix[2][0] = 1;
    adjMatrix[1][2] = adjMatrix[2][1] = 1;
    adjMatrix[1][3] = adjMatrix[3][1] = 1;

    // Display the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
