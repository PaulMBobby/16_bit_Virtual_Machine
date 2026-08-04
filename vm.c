#include<stdio.h>
#include<inttypes.h>

FILE *bin;

uint16_t Register[32];
uint16_t Memory[65536];
uint16_t PC = 0;
uint8_t status_register;

void decode_opcode(uint8_t inst, uint8_t dest, uint8_t immediate, uint8_t src);
void read_from_memory();

int main(){

    bin = fopen("code.bin","rb");

    if(bin == NULL){
        printf("Error, couldn't open file!\n");
        return 0;
    }

    uint16_t instruction_set;

    int i=0;

    while(fread(&instruction_set,sizeof(uint16_t),1,bin)==1){

        Memory[i] = instruction_set;
        i++;

    }

    read_from_memory();

    printf("<-------------------Hardware Register------------------->\n");
    for(int i=0;i<32;i++){
        printf("R%d: %d\t\t",i,Register[i]);

        if((i+1)%4==0){
            printf("\n");
        }
    }
    
    uint8_t temp_status = status_register;
    printf("<-------------------Status Register------------------->\n");
    for(int i=0;i<8;i++){
        printf("%d\t",(temp_status>>7) & 1);
        temp_status = temp_status << 1;
    }

return 0;
}

void read_from_memory(){

    while(1){

        uint16_t instruction = Memory[PC];

        if(instruction == 0){
            break;
        }

        uint8_t inst;
        uint8_t dest;
        uint8_t immediate;
        uint8_t src;

        inst = (instruction & (31 << 11)) >> 11;
        dest = (instruction & (31 << 6)) >> 6;
        immediate = (instruction & (1 << 5)) >> 5;
        src = instruction & 31;
        
        decode_opcode(inst,dest,immediate,src);

        PC++;

    }
    
}

void decode_opcode(uint8_t inst, uint8_t dest, uint8_t immediate, uint8_t src){

    switch(inst){
        case 1:
        {
            if(immediate == 1){
                Register[dest] = Register[src];
                break;
            }

            Register[dest] = src;

            break;
        }

        case 2:
        {
            if(immediate == 1){
                Register[dest] += Register[src];
                break;
            }

            Register[dest] += src;

            break;
        }

        case 3:
        {
            if(immediate == 1){
                Register[dest] -= Register[src];
                break;
            }

            Register[dest] -= src;

            break;
        }

        case 4:
        {
            if(immediate == 1){
                Register[dest] &= Register[src];
                break;
            }

            Register[dest] &= src;

            break;
        }

        case 5:
        {
            if(immediate == 1){
                Register[dest] |= Register[src];
                break;
            }

            Register[dest] |= src;

            break;
        }

        case 6:
        {
            if(immediate == 1){
                Register[dest] ^= Register[src];
                break;
            }

            Register[dest] ^= src;

            break;
        }

        case 7:
        {
            if(immediate == 1){
                Register[dest] = ~Register[src];
                break;
            }

            Register[dest] = ~src;

            break;
        }

        case 8:
        {
            Register[dest] = Register[dest] + 1;
            break;
        }

        case 9:
        {
            Register[dest] = Register[dest] - 1;
            break;
        }

        case 10:
        {
            int temp = Register[dest] - Register[src];
            if(temp == 0){
                status_register |= 1;
            }
            else{
                status_register &= 0;
            }

            break;
        }

    }

}