#include "Integer.h"
#include <ctime>

int main() {
    Integer A(0);
    Integer B(1);

    //A.Print();
    //B.Print();

    std::clock_t start = clock();
    for (int i = 0 ; i < 100001; ++i) {
        Integer C = A + B;
        //C.Print();                
        A = B;
        B = C;
    }
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("Length         == [%lu]\n", B.Size());    
    B.Print();

    return 0;
}
