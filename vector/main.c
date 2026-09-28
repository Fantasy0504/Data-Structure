#include "vector.h"
#include "Head.h"

int main(void)
{
    vector vec = {0};
    init(&vec);
    push_back(&vec, 3);
    push_back(&vec, 1);
    push_back(&vec, 5);
    push_back(&vec, 2);
    print(&vec);
    printf("\n");
    Bubblesort(&vec, FALSE);
    print(&vec);
    printf("\n");

    reverse(&vec);

    print(&vec);
    printf("\n");

    clear(&vec);

    return 0;
}