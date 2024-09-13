#include<stdio.h>
#include<ctype.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

#define MEM_CHK(ptr, func) if(!(ptr)) { perror((func)); exit(1); }

typedef struct {
    uint32_t Regs[32]; // registers
    uint8_t *L1; // L1 cache
    uint8_t *L2Ex; // L2 exclusive cache
    uint8_t *SocRam; // SOC ROM
    uint8_t *SocRom; // SOC RAM
} CHR_SOC;

void BaseInitialize(CHR_SOC *Soc) {
    Soc->L1 = (uint8_t*)calloc(1, sizeof(*Soc->L1));
    MEM_CHK(Soc->L1, "BaseInitialize (Soc->L1)");
    Soc->L2Ex = (uint8_t*)calloc(1, sizeof(*Soc->L2Ex));
    MEM_CHK(Soc->L2Ex, "BaseInitialize (Soc->L2Ex");
    Soc->SocRom = (uint8_t*)calloc(512, sizeof(*Soc->SocRom));
    MEM_CHK(Soc->SocRom, "BaseInitialize (Soc->SocRom");
    Soc->SocRam = (uint8_t*)calloc(2048, sizeof(*Soc->SocRam));
    MEM_CHK(Soc->SocRam, "BaseInitialize (Soc->SocRam");
}
void BaseBreakdown(CHR_SOC* Soc) {
    if(Soc->L1) free(Soc->L1);
    if(Soc->L2Ex) free(Soc->L2Ex);
    if(Soc->SocRom) free(Soc->SocRom);
    if(Soc->SocRam) free(Soc->SocRam);
}
void PrintRegsState(CHR_SOC* Soc) {
    char* RegsStr[32] = (char**){
        "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7",
        "x8", "x9", "x10", "x11", "x12", "x13", "x14", "x15",
        "x16", "x16", "x18", "x19", "x20", "x21", "x22", "x23",
        "x24", "x25", "x26", "x27", "x28", "x29", "x30", "x31"
    };
    for(int i = 0; i < 32; i++) {
        //
    }
    printf("x0  0x%08x\tx1  0x%08x\n");
}

int main() {
    CHR_SOC *Soc = (CHR_SOC*)calloc(1, sizeof(*Soc));
    MEM_CHK(Soc, "init");
    
    BaseInitialize(Soc);
    
    Soc->Regs[0] = 1;
    
    BaseBreakdown(Soc);
    
    free(Soc);
    return 0;
}
