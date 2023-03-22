#include <assert.h>
#include "../second_task.h"

int main()
{
    A A1(5, 10);
    A A2(5, 10);
    A A3(55, 110);

    assert(A1 != 77);
    assert(A1 != A3);

    assert(A1 == 5);
    assert(A1 == A2);

    assert(A1 <= 6);
    assert(A1 <= 5);
    assert(A1 <= A3);
    assert(A1 <= A2);

    assert(A1 >= 4);
    assert(A1 >= 5);
    assert(A3 >= A1);
    assert(A2 >= A1);

    B B1(44, 1);
    B B2(55, 110);
    B B3(66, 220);

    assert(A3 != B3);
    assert(A3 == B2);

    assert(A3 <= B3);
    assert(A3 <= B2);

    assert(A3 >= B1);
    assert(A3 >= B2);

    return 0;
}
