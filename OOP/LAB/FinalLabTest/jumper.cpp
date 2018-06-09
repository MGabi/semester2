#include "jumper.h"
#include <fstream>
#include <string>
#include <iostream>


std::string Jumper::getName()
{
    return this->name;
}

double Jumper::getSpeed(){
    return this->speed;
}

int Jumper::getDuration(){
    return this->duration;
}

int Jumper::getWindSpeed(){
    return this->windSpeed;
}

int Jumper::getWindDirection(){
    return this->windDirection;
}

int Jumper::getDistance(){
return this->distance;
}

void Jumper::setDistance(double distance){
    this->distance = distance;
}

Jumper::Jumper(){}

Jumper::Jumper(std::string name,
               double speed,
               int duration,
               int windSpeed,
               int windDirection){
    this->name = name;
    this->speed = speed;
    this->duration = duration;
    this->windSpeed = windSpeed;
    this->windDirection = windDirection;
    this->distance = -1;
}

Jumper::Jumper(Jumper* jumper)
{
    this->name = jumper->getName();
    this->speed = jumper->getSpeed();
    this->duration = jumper->getDuration();
    this->windSpeed = jumper->getWindSpeed();
    this->windDirection = jumper->getWindDirection();
    this->distance = -1;
}

std::ifstream &operator>>(std::ifstream &in, Jumper &jumper) {
    std::string name;
    std::string speed;
    std::string duration;
    std::string windSpeed;
    std::string windDirection;

    getline(in, name, ';');
    getline(in, speed, ';');
    getline(in, duration, ';');
    getline(in, windSpeed, ';');
    getline(in, windDirection, '\n');

    jumper.name = name;
//    std::string::size_type sz;
//    jumper.speed = std::stod(speed, &sz);
    jumper.speed = std::atof(speed.c_str());
    jumper.duration = std::atoi(duration.c_str());
    jumper.windSpeed = std::atoi(windSpeed.c_str());
    jumper.windDirection = std::atoi(windDirection.c_str());

    return in;
}
