#include "Integer.h"
#include "Maths.h"

int main() {
    utility::integer::Integer I(4);
    utility::maths::Maths<utility::integer::Integer> math;

    for (int = 1; i < 10; ++i) {
        printf("n == [%d] ", i);
        math.power(I, i).Print();
        printf("\n");
    }
}
