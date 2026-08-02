#include<stdio.h>
#include<inttypes.h>

FILE *src;

uint8_t Register[4];

void decode_opcode(uint8_t inst, uint8_t dest, uint8_t immediate, uint8_t src);

int main(){

    src = fopen("code.bin","rb");

    if(src == NULL){
        printf("Error, couldn't open file!\n");
        return 0;
    }

    uint8_t instruction_set;

    while(fread(&instruction_set,sizeof(uint8_t),1,src)==1){

        uint8_t inst;
        uint8_t dest;
        uint8_t immediate;
        uint8_t src;

        inst = (instruction_set & (3 << 6)) >> 6;
        dest = (instruction_set & (3 << 4)) >> 4;
        immediate = (instruction_set & (1 << 3)) >> 3;
        src = instruction_set & 7;
        
        decode_opcode(inst,dest,immediate,src);

    }

    for(int i=0;i<4;i++){
        printf("R%d:  %d\n",i,Register[i]);
    }

return 0;
}

void decode_opcode(uint8_t inst, uint8_t dest, uint8_t immediate, uint8_t src){

    switch(inst){
        case 0:
        {
            if(immediate == 1){
                Register[dest] = Register[src];
                break;
            }

            Register[dest] = src;

            break;
        }

        case 1:
        {
            if(immediate == 1){
                Register[dest] += Register[src];
                break;
            }

            Register[dest] += src;

            break;
        }

        case 2:
        {
            if(immediate == 1){
                Register[dest] -= Register[src];
                break;
            }

            Register[dest] -= src;

            break;
        }

    }

}