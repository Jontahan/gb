// to be passed through constructor
#include "../include/gpu.h"

using namespace component;

/*

struct sprattr{
    int x, y, id, flags;
};

void draw_sprite(sprattr spr){
    // spr.id = address of tile/sprite bitmap
    for(int yy = 0; yy < 8; ++yy){
	int byte1 = RAM[spr.id + 2 * yy], byte2 = RAM[spr.id + 2 * yy + 1];
	int and_bit = 0x80;
	for(int xx = 0; xx < 8; ++xx){
	    LCD[(spr.x - 8 + xx) % 256][(spr.y - 16 + yy) % 256] = (byte1 & and_bit ? 0x1 : 0x0) + (byte2 & and_bit ? 0x2 : 0x0); 
	}
    }
}

void draw_background(){
    int addr = 0x9800;
    for(int yy = 0; yy < 32; ++yy){
	for(int xx = 0; xx < 32; ++xx){
	    int tileaddr = 0x8000 + RAM[addr] * 16;
	    addr++;
	}
    }
}
*/
gpu::gpu(unsigned char* mem){
    this->memory = mem;
}

std::vector<unsigned char> gpu::getFrame(){
    std::vector<unsigned char> LCD(256 * 256);
    for(int y = 0; y < 256; ++y)
        for(int x = 0; x < 256; ++x)
            LCD[256 * y + x] = (x / 4) % 3;
    return LCD;
}
    


