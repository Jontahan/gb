#ifndef EMU_DEF
#define EMU_DEF

#include "cpu.h"
#include "gpu.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <QObject>
#include <QString>

/*
    The emulator class can be seen as the
    actual Game Boy unit, consisting of
    different circuits/components that
    have different responsibilities
*/

class emulator : public QObject{
    Q_OBJECT
private:
    unsigned char* memory;
    unsigned char* registers;
    bool* F;

    struct ROM{
    	std::string name;
    	int size;
    	char* cartridge;
    };

    component::cpu* cpu;
    component::gpu* gpu;

    ROM* loadROM(const char*); // TODO move to romloader
public:
    void step();
    void play(const char*);
    std::vector<unsigned char> getFrame(int);
signals:
    void debug(QString);
};

#endif
