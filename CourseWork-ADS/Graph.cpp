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
    cout << "������������ ������ ������" << endl;
  }
}

void Graph::remove(int first, int second) {
  if (verticlesIsValid(first, second)) {
    matrix_[first][second] = 0;
    matrix_[second][first] = 0;
  } else {
    cout << "������������ ������ ������" << endl;
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
        matrix_ = new int *[size_];
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
    cout << "������������ ������ �����" << endl;
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

void Graph::getMaxClique() const {
  vector<int> *maxClique = new vector<int>();  //��������� ������������ �����
  vector<int> *currentClique = new vector<int>();  //������� �����

  for (int i = 0; i < size_; ++i) {
    currentClique->push_back(i);  //� ������� ������� ���������� ����� �����

    for (int j = i + 1; j < size_; ++j) {  //����� ������ ��������� ��� �����
      bool adjacencyForAll = true;
      //��������� ��������� � ���������� �������� ���������

      //� ��������� ����� �����������, ���� �� ���������� ���������
      //� ���� �� ����� �� ������ ������� �����
      for (auto it = currentClique->begin(); it != currentClique->end(); ++it) {
        if (matrix_[j][*it] == 0) {
          adjacencyForAll = false;
          //��������� �����������, �������� �� �����������
        }
      }

      if (adjacencyForAll) {
        //���� �������� ������ � ������� ���������, �� ����������� � �����
        currentClique->push_back(j);
      }
    }

    if (currentClique->size() > 1 &&
        maxClique->size() < currentClique->size()) {
      //� ������ ����� ������ ���� 2 �������. ����� currentClique ��
      //��������������
      //���� ����� ����� ������ ��������� ������������
      //����������� � ���������� � ���������� ������������ �����
      maxClique->clear();
      for (auto it = currentClique->begin(); it != currentClique->end(); ++it) {
        maxClique->push_back(*it);
      }
    }
    currentClique->clear();
  }

  delete currentClique;

  //����� ������������ �����
  if (maxClique->size() > 0) {
    sort(maxClique->begin(), maxClique->end());
    cout << "������������ ����� ������� �� ������: ";
    for (auto it = maxClique->begin(); it != maxClique->end(); ++it) {
      cout << *it << " ";
    }
    cout << endl;
  }

  delete maxClique;
}