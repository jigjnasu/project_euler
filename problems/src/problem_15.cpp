#include "Problem_15.h"
#include "Maths.h"

project_euler::problems::Problem_15::Problem_15() {}

project_euler::problems::Problem_15::~Problem_15() {}

void project_euler::problems::Problem_15::lattice_paths() const {
    // Let's use the Binomial Coefficient to calculate the all paths
    printf("-------------------------------------------\n");
    // As the grid size is 20, there can 2 grid size
    const int n = 40;
    const int k = 20;
    utility::maths::Maths<double> maths;
    printf("Exact routes for 20 X 20 grid == [%.0lf]\n", maths.binomial(n, k));
    printf("-------------------------------------------\n");    
}
