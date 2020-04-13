//
// Created by vlad on 4/13/20.
//
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <string>

#include "human.h"

#ifndef LAB_15_ZOO__FIVELAB_H_
#define LAB_15_ZOO__FIVELAB_H_

class StorageZoo {
 public:
  StorageZoo(float count = 0) { this->count = count; }
  StorageZoo(const StorageZoo &count){}
  void showStorage() {
    std::cout << count;
  }
  void test(){
    std::cout << "StorageZoo";
  }
 private:

  float count = 0;
};

class Delivery {
 public:
  static StorageZoo makeDelivery(float count){
    return StorageZoo(count);
  }
  static void test(){
    std::cout << "Delivery\n";
  }
 protected:
  void stsy(){
    std::cout << "HELLO";
  }
};

class AutoDeliveryStorage : public Delivery, public StorageZoo {
 public:
  AutoDeliveryStorage(
      ) : Delivery(), StorageZoo(){
    Delivery::test();
    StorageZoo::test();
  }

};

#endif //LAB_15_ZOO__FIVELAB_H_
