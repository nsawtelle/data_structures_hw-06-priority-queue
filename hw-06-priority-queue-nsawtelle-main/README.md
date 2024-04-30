# Priority Queues

In this assignment you will be implementing a _Priority Queue_.

In computer science, a _priority queue_ is an abstract data type (ADT) similar
to a (regular) queue or stack data structure where each element additionally has
a "priority" associated with it. In a priority queue, an element with high
priority is served before an element with low priority. In some implementations,
if two elements have the same priority, they are served according to the order
in which they were enqueued (this is what we'll do here); in other
implementations ordering of elements with the same priority remains undefined.

In the lectures, we covered the few operations for the priority queue
abstraction, including `insert` and `remove`. In the homework we will also
implement `peek`. There is usually an `is_empty` operation that can be used to
determine if there is data waiting in the queue; that isn't a requirement for
this assignment, though.

## Implementation Options

Your goal here is to use a low level data structure to implement a priority
queue. The choice of data structure is up to you. Keep in mind that a heap is a
common backing type for this ADT is a binary heap (max heap or min heap), and
such heaps will possibly appear on the test.

That said, you could use a modified linked list, a binary tree (not a binary
_search_ tree), or a simple list of things with associated priorities.

Whatever you choose, be aware of both the runtime complexity of your choice.

## Uh what do I put in the `pq` struct?

Good question! It is up to you. The wonderful thing about an ADT is that it does
not matter what structure you back it with - as long as it behaves correctly
according to the abstraction's interface, you're good.

So let's say we're going to implement the priority queue's operations using a
simple array of data. We're going to insert and remove from this data, so we
also need to record the capacity of the array, and the current length of the
data. And of course we need to store the priorities. Given that, here's a naive
way of defining the `pq` struct:

```cpp
#define INITIAL_PQ_CAPACITY 256
struct pq {
  // don't copy paste - this is a bad way to do it, but it is instructive.
  string data[INITIAL_PQ_CAPACITY];
  float priority[INITIAL_PQ_CAPACITY];
  int capacity = INITIAL_PQ_CAPACITY;
  int size = 0;
};
```

In this implementation, when we insert data we simply assign it to `data[size]`
and prioritize it with `priority[size]`, and increment `size`. When we want to
remove the top priority item, we (a) iterate through the entire `priority` array
and make a note of the index `i` of the maximum value, (b) record the value in
`data[i]` to return, and then (c) remove both `data[i]` and `priority[i]`, and
"shift" all elements with indexes greater than `i` down by one. Peeking is
similar, except we don't remove data.

That's a bad way to do it. Why? Think about the complexity of that? (What a
great test question, I wonder?)

It is inefficient. To remove the highest priority element you have to scan
through the entire `priority` array to identify which one it is, and then touch
every element of both arrays to clean up. A binary heap would let you do this in
`O(log n)`.

It also doesn't record the order of data elements that share a priority. The
homework will expect the oldest element with some priority to be accessed first,
and that is not possible to achieve with the above approach.

## Implementation Plan

I recommend you implement your functions in this order:

1. `init_priority_queue`
2. `peek_pq`
3. `insert_pq`
4. `remove_pq`

**Notice** that the queue parameter to these functions is pass-by-reference.
This might (or might not) be relevant to how you implement each function. It is
there for you if you need it.






