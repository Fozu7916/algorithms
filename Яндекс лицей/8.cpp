#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  int X, D_max;
  cin >> X >> D_max;

  double cube_root_X = cbrt(X);

  int best_N = 1;
  int best_D = 1;
  double min_error = abs((double)best_N / best_D - cube_root_X);

  for (int D = 1; D <= D_max; ++D) {
    int N = round(cube_root_X * D);
    double current_error = abs((double)N / D - cube_root_X);

    if (current_error < min_error) {
      min_error = current_error;
      best_N = N;
      best_D = D;
    }
  }

  cout << best_N << " " << best_D << endl;
  cout << fixed << setprecision(3) << cube_root_X << " "
       << fixed << setprecision(3) << (double)best_N / best_D << " "
       << fixed << setprecision(6) << min_error << endl;

  return 0;
}