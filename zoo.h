//
// Created by vlad on 4/7/20.
//
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <string>

#include "human.h"

#ifndef LAB_15_ZOO__ZOO_H_
#define LAB_15_ZOO__ZOO_H_

class Animal {
 public:
  Animal(){
    name = "Кіт";
    color = "Білий";
    voice = "May";
    enviroment = "Будинок";
    count_of_paw = 4;
    count_of_wings = 0;
    can_fly = false;
    can_swim = false;
  }
  Animal(
      std::string name,
      std::string color,
      std::string voice,
      std::string enviroment,
      int count_of_paw,
      bool can_swim,
      float count_of_wings,
      bool can_fly
  ) {
    this->name = name;
    this->color = color,
    this->voice = voice;
    this->enviroment = enviroment;
    this->count_of_paw = count_of_paw;
    this->can_swim = can_swim;
    this->count_of_wings = count_of_wings;
    this->can_fly = can_fly;
  }
  virtual void Animalvoice() {
    std::cout << voice;
  }
  virtual std::string GetName() {
    return name;
  }
  virtual std::string GetColor() {
    return color;
  }
  virtual std::string GetEnv() {
    return enviroment;
  }
 protected:
  std::string name;
  std::string color;
  std::string voice;
  std::string enviroment;
  int count_of_paw;
  float count_of_wings;
  bool can_fly;
  bool can_swim;
};

class Mammals : public Animal {
 public:
  Mammals(std::string name,
          std::string color,
          std::string voice,
          std::string enviroment,
          int count_of_paw,
          bool can_swim,
          bool can_fly) : Animal(name, color, voice, enviroment, count_of_paw, can_swim, count_of_wings, can_fly) {}
  void showInformation() {
    std::cout << "\nName       - " << name
              << "\nColor      - " << color
              << "\nVoice      - " << voice
              << "\nEnviroment - " << enviroment
              << "\nPaws       - " << count_of_paw
              << ((can_swim) ? "\n  Can swimming!" : "\n   Can't swimming(( ")
              << ((can_fly) ? "\n   Can fly!" : "") << std::endl;
  }
 private:


};

class Flying : public Animal {
 public:
  Flying(std::string name,
         std::string color,
         std::string voice,
         std::string enviroment,
         int count_of_paw,
         float count_of_wings) : Animal(name,color, voice, enviroment, count_of_paw, can_swim, count_of_wings, can_fly) {}

  void showInformation() {
    std::cout << "\nName       - " << name
              << "\nColor      - " << color
              << "\nVoice      - " << voice
              << "\nEnviroment - " << enviroment
              << "\nPaws       - " << count_of_paw;
              (can_fly) ? (std::cout << "\nWings     -  " << count_of_wings) : std::cout << "" << std::endl;
  }

 private:
};

class Zoo {
 public:
  Zoo() {
    malkeAnimal();
    makeWorkers();
  }
  void showAllAnimals() {
    for (int kI = 0; kI < AnimalsM.size(); ++kI) {
      AnimalsM[kI].showInformation();
    }
    for (int kJ = 0; kJ < AnimalsF.size(); ++kJ) {
      AnimalsF[kJ].showInformation();
    }
  }
  static void showZooDocs() {
    std::cout << "\nFor create Zoo use: Zoo {name your zoo};"
                 "\nFor show all animals in new zoo use: {name}.showAllAnimals();"
                 "\nFor show all workers in new zoo use: {name}.showAllWorkers();"
                 "\nFor add new worker use: {name}.SwtWorker({your worker});";
  }
  Animal GetAnimal() {
    return AllAnimals[rand()%AllAnimals.size()];
  }
  std::vector<Animal> GetAllAnimals() {
    return AllAnimals;
  }
  std::vector<Human> AllWorkers() {
    return workers;
  }

  void showAllWorkers() {
    std::cout  << "\nІм'я\tВік\tСтать\tДосвід\tПосада" <<std::endl;
    for (int kI = 0; kI < workers.size(); ++kI) {
      std::cout << workers[kI].GetName() << "\t"
                 << workers[kI].GetAge() << "\t"
                 << workers[kI].GetSex() << "\t"
                 << workers[kI].GetJobExp() << "\t\t"
                 << workers[kI].GetPost() << std::endl;
    }
  }
  void SetWorker(Human worker) {
    workers.push_back(worker);
  }
 private:
  std::vector<Animal> AllAnimals;
  std::vector<Flying> AnimalsF;
  std::vector<Mammals> AnimalsM;
  Worker worker;
  std::vector<Human> workers;
  void malkeAnimal(){
    AnimalsM.push_back(Mammals("Вовк","Сірий","Аууууу","Ліс",4, false, false));
    AnimalsM.push_back(Mammals("Лев","Оранжевий","Грррр","Африка",4, false, false));
    AnimalsM.push_back(Mammals("Черепаха","Зелений","-","Європа",4, true, false));
    AnimalsM.push_back(Mammals("Літуча миш","Сірий","-","Печери",2, false, true));
    AnimalsF.push_back(Flying("Голуб","Сірий","хкууу-хуу-ху-хуу","Місто",2,45.0));
    AnimalsF.push_back(Flying("Лелека", "Білий","кл-кл-кл","Село",2,90));
    AnimalsF.push_back(Flying("Орел","Коричневий","кхаааа","Євразія і Африка",2,200));
    AnimalsF.push_back(Flying("Фламінго","Рожевий","Кгааа-кгаа", "Африка",2,160));

    for (int kI = 0; kI < AnimalsF.size(); ++kI) {
      AllAnimals.push_back(AnimalsF[kI]);
    }
    for (int kJ = 0; kJ < AnimalsM.size(); ++kJ) {
      AllAnimals.push_back(AnimalsM[kJ]);
    }
  }
  void makeWorkers() {
    workers.push_back(worker.TakeWorker("male"));
    workers.push_back(worker.TakeWorker("Alex", "male",25,"Прибиральник"));
    workers.push_back(worker.TakeWorker("female"));
    workers.push_back(worker.TakeWorker("female","Директор"));
    workers.push_back(worker.TakeWorker("male","Доглядач звірів"));
  }
};

#endif //LAB_15_ZOO__ZOO_H_
