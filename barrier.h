/*------------------------------------------
 * Name - Ayush Prakash
 * Roll no - CS15BTECH11008
 * Date - 10/02/2017
 * Declarations for the Barrier API. 
--------------------------------------------
*/

#ifndef BARRIER_H_
#define BARRIER_H_

#include<semaphore.h>
#include<cstdlib>

class Barrier 
{
private:
  int count;        /* count of threads at barrier */
  int size;    	    /* size of barrier */
  sem_t *mutex;     /* to increment count */
  sem_t *barrier;   /* to block/release barrier */
  
public:
  int init(int n);  
  int barrier_point(void);
  Barrier();
  ~Barrier();
};

#endif
