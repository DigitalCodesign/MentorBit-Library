#include "Arduino.h"

#ifndef MentorPort_h
#define MentorPort_h

class MentorPort {

    public:
        struct Port {
            char type;
            uint8_t location;
            uint8_t gpios[8];
        };

        MentorPort() {};
        virtual void configPort(const Port& port) {};

};

#endif