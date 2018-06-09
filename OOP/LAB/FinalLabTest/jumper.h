#ifndef JUMPER_H
#define JUMPER_H
#include <string>
#include <fstream>
class Jumper
{
public:
    std::string name;
    double speed;
    int duration;
    int windSpeed;
    int windDirection; //-1 fata, 1 spate
    double distance;

public:
    std::string getName();
    double getSpeed();
    int getDuration();
    int getWindSpeed();
    int getWindDirection();
    int getDistance();
    void setDistance(double distance);
    Jumper();
    Jumper(std::string name, double speed, int duration, int windSpeed, int windDirection);
    Jumper(Jumper *jumper);
    friend std::ifstream &operator>>(std::ifstream &in, Jumper &jumper);
};

#endif // JUMPER_H
