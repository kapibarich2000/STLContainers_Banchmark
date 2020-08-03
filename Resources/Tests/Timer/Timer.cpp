#include "Timer.h"

Timer::Timer() {
    m_StartTimepoint= std::chrono::high_resolution_clock::now();
}
Timer::~Timer() {
    Stop();
}
void Timer::Stop() {
    auto endTimepoint = std::chrono::high_resolution_clock::now();

    auto start = std::chrono::time_point_cast<std::chrono::milliseconds>(m_StartTimepoint).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::milliseconds>(endTimepoint).time_since_epoch().count();


    auto duration = end - start; //milliseconds
    double sec = duration * 0.001; //seconds

    std::cout << duration << "ms ("<<sec<<" sec)\n"; // Microseconds and Milliseconds
}