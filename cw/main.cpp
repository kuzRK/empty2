#include <iostream>


void rm(int *mtx)
{
  delete[] mtx;
}

int *make(size_t n)
{
  int *mtx = nullptr;
  try {
    mtx = new int[n];
  }
  catch(const std::bad_alloc &) {
    rm(mtx);
    throw;
  }
  return mtx;
}

void input(int *mtx,size_t n)
{
  for (size_t i = 0 ; i < n; ++i) {
    std::cin >> mtx[i];
  }
}
void output(int **mtx,size_t *lns, int rows)
{
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < lns[i]; ++j) {
      std::cout << mtx[i][j] << " ";
    }
  std::cout << "\n";
  }
}

int ** convert(const int * t, size_t n, const size_t * lns, size_t rows)
{
  int **res = new int*[rows];
  size_t k = 0;
  for (size_t i = 0; i < rows; ++i) {
    res[i] = new int[lns[i]];
    for (size_t j = 0; j < lns[i]; ++j) {
      res[i][j] = t[k++];
    }
  }
  return res;
}
int main()
{
  int rows = 0;
  size_t n = 0;
  std::cin >> rows;
  size_t *lns = new size_t[rows];
  for (size_t i = 0; i < rows; ++i) {
    std::cin >> lns[i];
    n += lns[i];
  }

  int *mtx = nullptr;
  try {
    mtx = make(n);
  }
  catch(const std::bad_alloc &) {
    return 2;
  }
  input(mtx,n);
  if (std::cin.fail()) {
    return 1;
  }
  int **c = convert(mtx,n,lns,rows);
  output(c,lns,rows);
  rm(mtx);
}
