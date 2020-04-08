#include <iostream>
#include <cmath>
#include <cctype>
#include <vector>
#include <ctime>
#include <set>
#include <string>
#include <map>

#include "zoo.h"
#include "human.h"

int main() {
  srand(time(NULL));
  setlocale(LC_ALL, "rus");

  Zoo zoo;
  zoo.showAllAnimals();
  zoo.showAllWorkers();

  return 0;
}
