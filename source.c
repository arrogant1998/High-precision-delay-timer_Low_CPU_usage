#include <windows.h>

void DelayMilliseconds(double milliseconds) {
    LARGE_INTEGER frequency, start, end;

    QueryPerformanceFrequency(&frequency);
    double waitCounts = (milliseconds / 1e3) * frequency.QuadPart;
    QueryPerformanceCounter(&start);
    Sleep(((int)milliseconds - (int)milliseconds % 50));
    do {

        QueryPerformanceCounter(&end);

    } while ((end.QuadPart - start.QuadPart) < waitCounts);
}
