
// If you change anything in this file, your changes will be ignored
// in your homework submission.
// Chekout TEST_F functions bellow to learn what is being tested.
#include "../code/PriorityQueue.h"
#include <gtest/gtest.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <math.h>

class test_PriorityQueue : public ::testing::Test {
protected:
  // This function runs only once before any TEST_F function
  static void SetUpTestCase() {
    std::ofstream outgrade("./total_grade.txt");
    if (outgrade.is_open()) {
      outgrade.clear();
      outgrade << (int)0;
      outgrade.close();
    }
  }

  // This function runs after all TEST_F functions have been executed
  static void TearDownTestCase() {
    std::ofstream outgrade("./total_grade.txt");
    if (outgrade.is_open()) {
      outgrade.clear();
      outgrade << (int)std::ceil(100 * total_grade / max_grade);
      outgrade.close();
      std::cout << "Total Grade is : "
                << (int)std::ceil(100 * total_grade / max_grade) << std::endl;
    }
  }

  void add_points_to_grade(double points) {
    if (!::testing::Test::HasFailure()) {
      total_grade += points;
    }
  }

  // this function runs after every TEST_F function
  void TearDown() override {
    std::ofstream outgrade("./total_grade.txt");
    if (outgrade.is_open()) {
      outgrade.clear();
      outgrade << (int)std::ceil(100 * total_grade / max_grade);
      outgrade.close();
    }
  }
  static double total_grade;
  static double max_grade;
};

double test_PriorityQueue::total_grade = 0;
double test_PriorityQueue::max_grade = 22;

TEST_F(test_PriorityQueue, TestInitialize) {
  pq* queue = init_priority_queue();
  ASSERT_TRUE(queue);
  add_points_to_grade(5);
}

TEST_F(test_PriorityQueue, TestEmptyPeek) {
  pq* queue = init_priority_queue();
  ASSERT_TRUE(queue);
  ASSERT_EQ("", peek_pq(queue)); // should return empty string for empty list
  add_points_to_grade(5);
}

TEST_F(test_PriorityQueue, TestInsertAndPeek) {
  pq* queue = init_priority_queue();
  ASSERT_TRUE(queue);

  string origCat = string("Cat Video");
  insert_pq(queue, origCat, 3);
  string front = peek_pq(queue);
  ASSERT_EQ(front, origCat);
  add_points_to_grade(1);

  string origGame = "Game Packet";
  insert_pq(queue, origGame, 5);
  front = peek_pq(queue);
  ASSERT_EQ(front, origGame);
  add_points_to_grade(1);

  string origMed = "Medical Packet";
  insert_pq(queue, origMed, 10.5);
  front = peek_pq(queue);
  ASSERT_EQ(front, origMed);
  add_points_to_grade(1);

  // now insert things less important
  string origCat2 = "Another Cat Video";
  insert_pq(queue, origCat2, 3.1);
  front = peek_pq(queue);
  ASSERT_EQ(front, origMed); // med packet should win
  add_points_to_grade(1);

  string origGame2 = "Another Game Packet";
  insert_pq(queue, origGame2, 1.5);
  front = peek_pq(queue);
  ASSERT_EQ(front, origMed);
  add_points_to_grade(1);
}

TEST_F(test_PriorityQueue, TestInsertAndRemove) {
  pq* queue = init_priority_queue();
  ASSERT_TRUE(queue);

  insert_pq(queue, "Camel", 5.0);   // C
  insert_pq(queue, "Aardvark", 10); // C A
  insert_pq(queue, "Firefly", 2);   // F C A
  insert_pq(queue, "Doggie", 7);    // F C D A
  insert_pq(queue, "Gorilla", 5);   // F G C D A
  insert_pq(queue, "Elephant", 11); // F G C D A E
  insert_pq(queue, "Bobcat", 2);    // B F G C D A E

  string popped;
  popped = remove_pq(queue); // B F G C D A
  ASSERT_EQ("Elephant", popped);
  add_points_to_grade(1);

  popped = remove_pq(queue); // B F G C D
  ASSERT_EQ("Aardvark", popped);
  add_points_to_grade(1);

  popped = remove_pq(queue); // B F G C
  ASSERT_EQ("Doggie", popped);
  add_points_to_grade(1);

  popped = remove_pq(queue); // B F G
  ASSERT_TRUE(popped == "Camel" || popped == "Gorilla");
  add_points_to_grade(1);

  popped = remove_pq(queue); // B F
  ASSERT_TRUE(popped == "Camel" || popped == "Gorilla");
  add_points_to_grade(1);

  popped = remove_pq(queue); // B
  ASSERT_TRUE(popped == "Firefly" || popped == "Bobcat");
  add_points_to_grade(1);

  popped = remove_pq(queue); // empty
  ASSERT_TRUE(popped == "Firefly" || popped == "Bobcat");
  add_points_to_grade(1);
}
