#include <iostream>

std::string findBestCell(int** grid, int H, int W) {

  int sum = 0;
  int sumLargest = 0;
  int largestI = 0;
  int largestJ = 0;

  for(int i = 1; i < H-1; i++) {
    for(int j = 1; j < W-1; j++) {

      sum = grid[i-1][j-1] + grid[i][j-1] + grid[i+1][j-1] + grid[i-1][j] + grid[i][j] + grid[i+1][j] + grid[i-1][j+1] + grid[i][j+1] + grid[i+1][j+1];
      if(sum > sumLargest) {
        sumLargest = sum;
        largestI = i;
        largestJ = j;
      }
    }
  }

  std::string out = "(" + std::to_string(largestJ) + "," + std::to_string(largestI) + ") " + std::to_string(sumLargest);

  return out;
}

int main() {

  int T;
  int W;
  int H;

  std::cin >> T;

  for(int i = 0; i < T; i++) {
    std::cin >> W;
    std::cin >> H;
    int** grid = new int*[H];
    for(int i = 0; i < H; ++i){
      grid[i] = new int[W];
    }
    for(int i = 0; i < H; i++) {
      for(int j = 0; j < W; j++) {
        std::cin >> grid[i][j];
      }
    }
    // Print out entered grid
    // for(int i = 0; i < H; i++) {
    //   for(int j = 0; j < W; j++) {
    //     std::cout << " " << grid[i][j];
    //   }
    //   std::cout << std::endl;
    // }
    std::cout << "#" + std::to_string(i) + ": " + findBestCell(grid, H, W) << std::endl;
    delete[] grid;
  }

  return 0;
}
