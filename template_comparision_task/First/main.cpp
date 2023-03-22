#include <assert.h>
#include "../first_task.h"

int main()
{
    NewA A1(5, 10);
    NewA A2(5, 10);
    NewA A3(55, 110);

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


    NewB B1("abcd");

    assert(B1 == "abcd");
    assert(B1 != "efgh");

    assert(B1 <= "abcd");
    assert(B1 <= "efgh");

    assert(B1 >= "abcd");
    assert(B1 >= "aaaa");

    return 0;
}
