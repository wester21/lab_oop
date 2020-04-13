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
#include "fivelab.h"

int main() {
  srand(time(NULL));
  setlocale(LC_ALL, "rus");

  StorageZoo *storage_zoo = new StorageZoo(1000);

  storage_zoo->showStorage();

  std::cout << std::endl;
  StorageZoo(Delivery::makeDelivery(100)).showStorage();
  AutoDeliveryStorage();


  Zoo::showZooDocs();
  std::cout << "\nPress ENTER to continue";
  getchar();

  Zoo zoo;
  zoo.showAllAnimals();
  zoo.showAllWorkers();

  return 0;
}
