// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/770/
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Number of layers in the matrix from perim to center.
        int layers = matrix.size() / 2;

        int temp;

        /* Corners: top left, top right, bottom right, bottom left.
        tl = &matrix[depth][depth];
        tr = &matrix[depth][matrix.size()-1-depth];
        br = &matrix[matrix.size()-1-depth][matrix.size()-1-depth];
        bl = &matrix[matrix.size()-1-depth][depth];
        */

        // Iterate over layers.
        for (int depth = 0; depth < layers; depth++) {
            // Iterate over side length.
            // The -(depth*2) is to shrink the side length whenever the
            // layer is deeper.
            // The -1 prevents the next corner from being included.
            for (int offset = 0; offset < matrix.size()-(depth*2)-1; offset++) {
                int* a = &matrix[depth][depth+offset];
                int* b = &matrix[depth+offset][matrix.size()-1-depth];
                int* c = &matrix[matrix.size()-1-depth][matrix.size()-1-depth-offset];
                int* d = &matrix[matrix.size()-1-depth-offset][depth];
                temp = *a;
                *a = *d;
                *d = *c;
                *c = *b;
                *b = temp;
            }
        }
    }
};
