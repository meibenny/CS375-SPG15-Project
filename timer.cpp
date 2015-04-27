
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

struct timeval startTime(struct timeval * start);

struct timeval endTime(struct timeval * end);

float calculateTime(struct timeval * t1, struct timeval * t2);



using namespace std;

struct timeval startTime(struct timeval * start)
{
  gettimeofday(start, NULL);
  return *start;

}
struct timeval endTime(struct timeval * end)
{
  gettimeofday(end, NULL);
  return *end;

}

float calculateTime(struct timeval *t1, struct timeval *t2)
{
  std::cout << "Time in microseconds: " << ((t2->tv_sec - t1->tv_sec)*1000000L +t2->tv_usec) - t1->tv_usec << std::endl;

  return ((t2->tv_sec - t1->tv_sec)*1000000L +t2->tv_usec) - t1->tv_usec;
}

