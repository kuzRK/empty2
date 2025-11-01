#include <iostream>

int make(int rows, int cols)
{
  int **mtx = new int*[rows];
  for (size_t i = 0; i < r ; ++i) {
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

void output(const int *const*mtx)
{

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
  if (std::cin.fail()) {
    return 1;
  }
  int **mtx = nullptr;
  try {
    mtx = make(rows,cols);
  }
  catch(const std::bad_alloc &) {
    return 2;
  output(mtx);
  rm(mtx);
}
