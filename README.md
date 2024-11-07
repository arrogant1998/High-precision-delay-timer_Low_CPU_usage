# High-precision-delay-timer
 DelayMilliseconds Function
The DelayMilliseconds function introduces a delay of a specified duration (in milliseconds) with high precision, using the QueryPerformanceCounter and QueryPerformanceFrequency functions available on Windows.

# Description

This function is designed to implement a delay in the program for the exact number of milliseconds passed as an argument, using the system's high-resolution performance counter. It first calculates the required number of counts to match the requested delay based on the system's performance frequency, then it waits for that duration. The function ensures the delay is accurate by using a loop that checks the difference in counts from the start and end times, adjusting for the system's frequency.

# Parameters
`milliseconds`(double): The number of milliseconds to delay. This value determines how long the function will cause the program to pause.
# Details
* The function utilizes `QueryPerformanceFrequency` to determine the frequency of the performance counter.
* `QueryPerformanceCounter` is used to get the current count of the performance counter.
* `Sleep` is called to handle the initial coarse delay, and the loop ensures that the final wait duration is accurate to the specified milliseconds.
