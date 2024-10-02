#include <iostream>

class Sensor
{
public:
    virtual ~Sensor() = default;
    virtual double get_temperature() = 0;
};

class Sensor1 : public /*immer!*/ Sensor
{
public:
    double get_temperature() override
    {
        return 1.1;
    }
};

class Sensor2 : public /*immer!*/ Sensor
{
public:
    double get_temperature() override
    {
        return 2.2;
    }
};

class Sensor3 : public Sensor
{
public:
    Sensor3(size_t len)
    : _mem(new char[len]) {}

    ~Sensor3() override
    {
        delete[](_mem);
    }
    
    double get_temperature() override
    {
        return 3.3;
    }

private:
    char* _mem;
};

int main()
{
    Sensor* sensors[3];
    sensors[0] = new Sensor1;
    sensors[1] = new Sensor2;
    sensors[2] = new Sensor3(666);

    for (Sensor* s: sensors)
        std::cout << s->get_temperature() << std::endl;    // <-- dynamic dispatch

    for (Sensor* s: sensors)
        delete s;

    return 0;
}
