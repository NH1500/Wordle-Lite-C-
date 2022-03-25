#pragma once
#include <assert.h>
#include <stdlib.h>

int randint(int n) {
    if ((n - 1) == RAND_MAX) {
        return rand();
    }
    else {

        assert(n <= RAND_MAX);

        // Chop off all of the values that would cause skew...
        int end = RAND_MAX / n; // truncate skew
        assert(end > 0);
        end *= n;

        int r;
        while ((r = rand()) >= end);

        return r % n;
    }
}