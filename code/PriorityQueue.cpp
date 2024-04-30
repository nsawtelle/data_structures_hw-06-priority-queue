// Nicole Sawtelle
// nisa1697
// github username: nsawtelle

#include "PriorityQueue.h"

#include <iostream>
using namespace std;
// Implement this after defining struct in .h file
pq* init_priority_queue() {
  pq* queue = new pq();
  queue->data = new string[INITIAL_PQ_CAPACITY];
  queue->priority = new float[INITIAL_PQ_CAPACITY];
  queue->capacity = INITIAL_PQ_CAPACITY;
  queue->size = 0;
  return queue;
}

//Peek at the highest priority item in the queue
string peek_pq(pq*& queue) {
  if (queue->size == 0)
    return ""; //Return an empty string if the queue is empty
  return queue->data[0]; //Return the first element in the queue
}

void insert_pq(pq*& queue, string text, float priority) {
  if (queue->size == queue->capacity) {
    //resize arrays if the capacity is full
    int new_capacity = queue->capacity * 2;
    string* new_data = new string[new_capacity];
    float* new_priority = new float[new_capacity];
    for (int i = 0; i < queue->size; ++i) {
      new_data[i] = queue->data[i];
      new_priority[i] = queue->priority[i];
    }

    delete[] queue->data;
    delete[] queue->priority;

    queue->data = new_data;
    queue->priority = new_priority;
    queue->capacity = new_capacity;
  }

// Insert the new item into the queue
  int index = queue->size;
  queue->data[index] = text;
  queue->priority[index] = priority;
  ++queue->size;

// Heapify up
  int parent_index = (index - 1) / 2;
  while (index > 0 && queue->priority[index] > queue->priority[parent_index]) {
    swap(queue->data[index], queue->data[parent_index]);
    swap(queue->priority[index], queue->priority[parent_index]);
    index = parent_index;
    parent_index = (index - 1) / 2;
  }

}

string remove_pq(pq*& queue) {
  if (queue->size == 0)
  return "";

  string max_element = queue->data[0]; //Store the highest priority element to return
  queue->data[0] = queue->data[queue->size - 1]; // Replace root with the last element
  queue->priority[0] = queue->priority[queue->size - 1];
  --queue->size;

// Heapify down
  int index = 0;
  while(true) {
    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;
    int largest = index;

    if (left_child_index < queue->size && queue->priority[left_child_index] > queue->priority[largest])
      largest = left_child_index;
    if (right_child_index < queue->size && queue->priority[right_child_index] > queue->priority[largest])
      largest = right_child_index;

    if (largest!= index) {
      swap(queue->data[index], queue->data[largest]);
      swap(queue->priority[index], queue->priority[largest]);
      index = largest;
    } else {
        break;
    }
  }

  return max_element;

}
