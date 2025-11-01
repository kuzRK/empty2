#include <iostream>

int make(int rows, int cols)
{
  int **mtx = new int*[rows];
  for (size_t i = 0; i < rows ; ++i) {
    try {
       mtx[i] = new int[cols];
    }
    catch(const std::bad_alloc &) {
      rm(mtx,i);
      throw;
    }
  }
  return mtx;
}

void input(int **mtx,int rows, int cols)
{
  for (size_t i = 0 ; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      std::cin >> mtx[i][j];
    }
  }
}
void output(const int *const*mtx, int rows, int cols)
{
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      std::cout << mtx[i][j] << " ";
    }
  std::cout << "\n";
  }
}

void rm(int **mtx, int rows)
{
  for (size_t i = 0; i < rows; ++i) {
    delete[] mtx[i];
  }
  delete[] mtx;
}
int main()
{
  int rows = 0;
  int cols = 0;
  std::cin >> rows >> cols;
  int **mtx = nullptr;
  try {
    mtx = make(rows,cols);
  }
  catch(const std::bad_alloc &) {
    return 2;
  }
  input(mtx,rows,cols);
  if (std::cin.fail()) {
    return 1;
  }
  output(mtx);
  rm(mtx);
