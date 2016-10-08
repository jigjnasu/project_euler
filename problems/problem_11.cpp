#include <cstdio>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstdlib>

int largest_product(const std::string& file) {
  std::vector<std::vector<int> > grid;
  int product = 0;
  std::fstream ifs(file.c_str());
  if (ifs.is_open()) {
    for (int i = 0; i < 20; ++i) {
      std::string line;
      std::getline(ifs, line);

      std::vector<int> row;
      std::size_t pos = 0;
      for (int j = 0; j < 19; ++j) {
		  std::size_t next_pos = line.find(" ", pos + 1);
		  if (next_pos != std::string::npos) {
			  row.push_back(std::atoi(line.substr(pos, next_pos).c_str()));
			  pos = next_pos;
		  }
      }
      row.push_back(std::atoi(line.substr(pos + 1, line.size() - 1).c_str()));

      grid.push_back(row);
    }
  } else {
    printf("Error while opening [%s] file\n", file.c_str());
  }

  for (int r = 0; r < 17; ++r) {
    for (int c = 0; c < 17; ++c) {
      // left -- right largest product
      const int P1 = grid[r][c] * grid[r][c + 1] * grid[r][c + 2] * grid[r][c + 3];
      // up -- down largest product
      const int P2 = grid[r][c] * grid[r + 1][c] * grid[r + 2][c] * grid[r + 3][c];
      // diagonally, left to right
      const int P3 = grid[r][c] * grid[r + 1][c + 1] * grid[r + 2][c + 2] * grid[r + 3][c + 3];
      // diagonally, right to left
      const int P4 = grid[r + 3][c] * grid[r + 2][c + 1] * grid[r + 1][c + 2] * grid[r][c + 3];

      if (P1 > product)
	product = P1;
      if (P2 > product)
	product = P2;
      if (P3 > product)
	product = P3;
      if (P4 > product)
	product = P4;
    }
  }

  return product;
}

int main() {
  std::clock_t start = clock();
  printf("largest product == [%d]\n", largest_product("data/large_sum.txt"));
  printf("Execution time == [%.2f]\n", (clock() - static_cast<double>(start)) / CLOCKS_PER_SEC);

  return 0;
}
