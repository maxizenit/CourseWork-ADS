#include <Windows.h>

#include <iostream>
#include <string>

#include "Graph.h"

using namespace std;

const string ADD_COMMAND = "add";
const string REMOVE_COMMAND = "remove";
const string CLEAR_COMMAND = "clear";
const string RESIZE_COMMAND = "resize";
const string SHOW_COMMAND = "show";
const string GETHELP_COMMAND = "help";
const string EXIT_COMMAND = "exit";

int main() {
  setlocale(LC_ALL, "Russian");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  Graph *graph = new Graph();

  string command;

  while (true) {
    cout << "Введите команду: ";
    cin >> command;

    if (command == ADD_COMMAND) {
      int first, second;
      cin >> first >> second;
      graph->add(first, second);

    } else if (command == REMOVE_COMMAND) {
      int first, second;
      cin >> first >> second;
      graph->remove(first, second);

    } else if (command == CLEAR_COMMAND) {
      graph->clear();

    } else if (command == RESIZE_COMMAND) {
      int newSize;
      cin >> newSize;
      graph->resize(newSize);

    } else if (command == SHOW_COMMAND) {
      graph->show();

    } else if (command == GETHELP_COMMAND) {
      cout << "add <первая_вершина> <вторая_вершина> - добавить связь между "
              "двумя вершинами\n"
           << "remove <первая_вершина> <вторая_вершина> - удалить связь между "
              "двумя вершинами\n"
           << "clear - очистить граф\n"
           << "resize <количество_вершин> - переконструировать граф под "
              "заданное количество вершин\n"
           << "show - вывести граф на экран в виде матрицы\n"
           << "help - помощь\n"
           << "exit - выход" << endl;

    } else if (command == EXIT_COMMAND) {
      break;

    } else {
      cout << "Введите корректную команду" << endl;
    }
  }

  delete graph;
}