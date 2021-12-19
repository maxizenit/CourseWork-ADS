#pragma once

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Graph {
 private:
  int size_;
  int **matrix_;

  bool verticlesIsValid(int first, int second);

 public:
  Graph();
  ~Graph();

  void add(int first, int second);
  void remove(int first, int second);
  void clear();
  void resize(int newSize);
  void show() const;
  void getMaxClique() const;
};