#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Print 2D vectors coordinate values
void print2DVector(vector<vector<int> > vec)
{
     // Sorting the vector for grading purpose
    sort(vec.begin(), vec.end());
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = 0; j < vec[0].size(); ++j) {
                cout << vec[i][j] << "  ";
        }
        cout << endl;
    }
}

// ***TODO: Check for duplicate coordinates inside a 2D vector and delete them*** //
vector<vector<int> > delete_duplicate(vector<vector<int> > C)
{

    
    
    
    
    
}

// ***TODO: Compute the Minkowski Sum of two vectors***//
vector<vector<int> > minkowski_sum(vector<vector<int> > A, vector<vector<int> > B)
{
    vector<vector <int> > result;

    for(size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = 0; j < B.size(); j++)
        {
            vector<int> sum = {A[i][0] + B[j][0], A[i][1] + B[j][1]};
            result.push_back(sum);
        }
    }

    result = delete_duplicate(result);
    return result;
}

int main()
{
    // ***TODO: Define the coordinates of triangle A and B using 2D vectors*** //
    vector<vector<int>> A = {{1,0}, {0,1}, {0,-1}};
    vector<vector<int>> B = {{0,0}, {1,1}, {1,-1}};
    
    // Compute the minkowski sum of triangle A and B
    vector<vector<int>> C;
    C = minkowski_sum(A, B);

    // Print the resulting vector
    print2DVector(C);

    return 0;
}
