#include <windows.h>

void DelayMilliseconds(double milliseconds) {
    LARGE_INTEGER frequency, start, end;

    QueryPerformanceFrequency(&frequency);
    double _waitCounts = ((milliseconds - 50) / 1e3) * frequency.QuadPart;
    double waitCounts = (milliseconds / 1e3) * frequency.QuadPart;

    QueryPerformanceCounter(&start);
    do {

        Sleep(1);
        QueryPerformanceCounter(&end);

    } while ((end.QuadPart - start.QuadPart) < _waitCounts);
    do {

        QueryPerformanceCounter(&end);

    } while ((end.QuadPart - start.QuadPart) < waitCounts);
}
