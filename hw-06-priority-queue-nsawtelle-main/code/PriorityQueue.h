#ifndef PRIORITYQUEUE_H__
#define PRIORITYQUEUE_H__

#include <memory>
#include <string>

using namespace std;

// Edit this to flesh out the pq structure as appropriate. You may
// also add the function prototypes for anything else, and implement
// them in pq.cpp.

#define INITIAL_PQ_CAPACITY 256
struct pq {
  string* data;
  float* priority;
  int capacity;
  int size;

  // First implement this struct. Use whatever you like: linked list, max heap,
  // other. The only caveat is that you should not use a C++ library type
  // directly.
  //
  // Subtle hint: heaps will be featured in exam 2. Might as well get some
  // practice in with them here.
};

// init_priority_queue initializes pq structure, which you are responsble for
// defining above.
pq* init_priority_queue();

// peek_pq will access the highest priority element in the queue and return it
// without modifying the queue. If the queue is empty it should return the empty
// string.
string peek_pq(pq*& queue);

// insert_pq adds the given string to the queue, using the specified priority.
// If there is a tie, the given string should be placed at the back of the group
// that it ties with, so all other strings with this priority will be removed
// first.
void insert_pq(pq*& queue, string text, float priority);

// remove_pq will access the highest priority element in the queue, remove it
// from the queue, and return it. If the queue is empty it should return the
// empty string ("").
string remove_pq(pq*& queue);

#endif // PRIORITYQUEUE_H__
