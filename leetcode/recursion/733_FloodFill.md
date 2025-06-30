733. Flood Fill
     Solved
     Easy
     Topics
     premium lock icon
     Companies
     Hint
     You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation:

From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.

Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.

```
class Solution {
public:
    void helper(vector<vector<int>>&image, int i, int j, int newc, int oldc){
        if(i >= image.size() || i<0 || j >= image[0].size() || j<0) return;
        if(image[i][j]!=oldc || image[i][j]==newc) return;
        image[i][j]=newc;
        helper(image,i+1,j,newc,oldc);
        helper(image,i,j+1,newc,oldc);
        helper(image,i-1,j,newc,oldc);
        helper(image,i,j-1,newc,oldc);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        helper(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};
```
