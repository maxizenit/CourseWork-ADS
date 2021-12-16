#include "Graph.h"

bool Graph::verticlesIsValid(int first, int second) {
  return first >= 0 && second >= 0 && first < size_ && second < size_ &&
         first != second;
}

Graph::Graph() : size_(0), matrix_(nullptr) {}

Graph::~Graph() { resize(0); }

void Graph::add(int first, int second) {
  if (verticlesIsValid(first, second)) {
    matrix_[first][second] = 1;
    matrix_[second][first] = 1;
  } else {
    cout << "Некорректные номера вершин" << endl;
  }
}

void Graph::remove(int first, int second) {
  if (verticlesIsValid(first, second)) {
    matrix_[first][second] = 0;
    matrix_[second][first] = 0;
  } else {
    cout << "Некорректные номера вершин" << endl;
  }
}

void Graph::clear() {
  if (size_ != 0) {
    for (int i = 0; i < size_; ++i) {
      for (int j = 0; j < size_; ++j) {
        matrix_[i][j] = 0;
      }
    }
  }
}

void Graph::resize(int newSize) {
  if (newSize >= 0) {
    if (newSize != size_) {
      clear();

      size_ = newSize;

      if (size_ > 0) {
        matrix_ = new int*[size_];
        for (int i = 0; i < size_; ++i) {
          matrix_[i] = new int[size_]{};
        }
      }
    } else if (newSize == 0) {
      for (int i = 0; i < size_; ++i) {
        delete[] matrix_[i];
      }

      delete[] matrix_;
      matrix_ = nullptr;

      size_ = newSize;
    }
  } else {
    cout << "Некорректный размер графа" << endl;
  }
}

void Graph::show() const {
  if (size_ > 0) {
    int fieldWidth = (int)log10(size_ - 1) + 2;
    int lineLength = fieldWidth * (size_ + 1) + 2;

    cout << setw(fieldWidth) << " |";

    for (int i = 0; i < size_; ++i) {
      cout << setw(fieldWidth) << i;
    }
    cout << endl;

    for (int i = 0; i < lineLength; ++i) {
      cout << '-';
    }
    cout << endl;

    for (int i = 0; i < size_; ++i) {
      cout << setw(fieldWidth) << i;
      cout << " |";

      for (int j = 0; j < size_; ++j) {
        cout << setw(fieldWidth) << matrix_[i][j];
      }
      cout << endl;
    }
  }
}