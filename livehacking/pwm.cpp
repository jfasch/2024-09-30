#define PWM1_BASE 0x1000
#define PWM2_BASE 0x2000
#define PERIOD_OFF 4
#define DUTY_OFF 8

class PWM
{
public:
    PWM(base_addr)
    {
        _off = 0x4000 + base_addr;
    }

private:
    void* _off;
};


int main()
{
    // // init pwm params
    // void* devices_base = 0x4000;
    // void* pwm1 = devices_base + PWM1_BASE;
    // void* pwm2 = devices_base + PWM2_BASE;

    // // set pwm1 params
    // pwm1 + PERIOD_OFF = ...;
    // pwm1 + DUTY_OFF = ...;

    // // set pwm2 params
    // pwm2 + PERIOD_OFF = ...;
    // pwm2 + DUTY_OFF = ...;

    PWM pwm1(PWM1_BASE);
    PWM pwm2(PWM2_BASE);

    pwm1.set_duty(...);
    pwm1.set_period(...);

    pwm2.set_duty(...);
    pwm2.set_period(...);


   // hier geschieht was mit dem aufgesetzten pwm
    ...
}
