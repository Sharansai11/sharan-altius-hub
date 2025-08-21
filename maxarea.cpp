#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    heights.push_back(0);  

    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : (i - st.top() - 1);
            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }
    heights.pop_back();
    return maxArea;
}

int maximalRectangle(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;

    int n = matrix.size(), m = matrix[0].size();
    vector<int> heights(m, 0);
    int maxArea = 0;

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) {
            heights[j] = (matrix[i][j] == 0) ? 0 : heights[j] + 1;
        }
// Computing largest rectangle for this histogram 
//( finding the answers for all cases)
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    return maxArea;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>mat(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    cout << maximalRectangle(mat) << endl;
    return 0;
}
