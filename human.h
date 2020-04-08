//
// Created by vlad on 4/8/20.
//
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <string>

#ifndef LAB_15_ZOO_CMAKE_BUILD_DEBUG_HUMAN_H_
#define LAB_15_ZOO_CMAKE_BUILD_DEBUG_HUMAN_H_





class Human {
 public:
  Human(std::string name, unsigned short age, std::string sex, float job_experience, std::string job_post) {
    passport.name = name;
    passport.age = age;
    passport.sex = sex;
    passport.job_experience = job_experience;
    passport.job_post = job_post;
  }


  std::string GetName() {
    return passport.name;
  }
  unsigned short GetAge() {
    return passport.age;
  }
  std::string GetSex() {
    return passport.sex;
  }
  float GetJobExp() {
    return passport.job_experience;
  }
  std::string GetPost() {
    return passport.job_post;
  }
  void SetJobExp(float exp) {
    passport.job_experience = exp;
  }
  void SetPost(std::string post) {
    passport.job_post = post;
  }


 private:
  struct {
  std::string name;
  unsigned short age;
  std::string sex;
  float job_experience;
  std::string job_post;
  }passport;
};

class Worker{
 public:
  Worker() {
    for (int kI = 0; kI < key_male.size(); ++kI) {
      name[key_male[kI]] = "male";
    }
    for (int kJ = 0; kJ < key_female.size(); ++kJ) {
      name[key_female[kJ]] = "female";
    }
  }
  Human TakeWorker(std::string name, std::string sex, int age, std::string post) {
    return Human(name, age, sex,0,post);
  }
  Human TakeWorker(std::string sex, int age, std::string post) {
    std::string key;
    if(sex == "male") {
      key = key_male[rand()%key_male.size()];
    } else if(sex == "female") {
      key = key_female[rand()%key_female.size()];
    }
    return Human(key,age, name[key],0, post);
  }

  Human TakeWorker(std::string sex, std::string post) {
    std::string key;
    if(sex == "male") {
      key = key_male[rand()%key_male.size()];
    } else if(sex == "female") {
      key = key_female[rand()%key_female.size()];
    }
    return Human(key, rand() % 40 + 20, name[key],0,post);
  }

  Human TakeWorker(std::string sex, int age) {
    std::string key;
    if(sex == "male") {
      key = key_male[rand()%key_male.size()];
    } else if(sex == "female") {
      key = key_female[rand()%key_female.size()];
    }
    return Human(key, age, name[key],0,"None");
  }
  Human TakeWorker(std::string sex) {
    std::string key;
    if(sex == "male") {
      key = key_male[rand()%key_male.size()];
    } else if(sex == "female") {
      key = key_female[rand()%key_female.size()];
    }
    return Human(key,rand() % 40 + 20, name[key],0,"None");
  }


 private:
  std::vector<std::string> key_male = {"Oleg", "Vlad", "Vania", "Artem"};
  std::vector<std::string> key_female = {"Katia", "Margo", "Sveta", "Sasha"};
  std::map<std::string, std::string> name;
  std::vector<std::map<std::string, std::string>> list;

};



#endif //LAB_15_ZOO_CMAKE_BUILD_DEBUG_HUMAN_H_

