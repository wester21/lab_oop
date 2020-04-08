//
// Created by vlad on 4/7/20.
//
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <string>


#ifndef LAB_15_ZOO__ZOO_H_
#define LAB_15_ZOO__ZOO_H_

class Animal {
 public:
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
              << ((can_fly) ? "\n   Can fly!" : "");
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
              (can_fly) ? (std::cout << "\nWings     -  " << count_of_wings) : std::cout << "";
  }

 private:
};

class Zoo {
 public:
  Zoo() {
    malkeAnimal();
  }
  Animal GetAnimal() {
    return AllAnimals[rand()%AllAnimals.size()];
  }
  std::vector<Animal> GetAllAnimals() {
    return AllAnimals;
  }
 private:
  std::vector<Animal> AllAnimals;
  std::vector<Flying> AnimalsF;
  std::vector<Mammals> AnimalsM;
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
};

#endif //LAB_15_ZOO__ZOO_H_
