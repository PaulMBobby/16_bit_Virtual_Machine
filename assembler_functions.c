#include<stdio.h>
#include<string.h>
#include<inttypes.h>

FILE *src, *dest;

void read_data_from_file_convert_to_binary(){

    char buff[50];
    
    while(fgets(buff,sizeof(buff),src)!=NULL){

        char inst[5];
        char des[4];
        char sc[4];

        uint8_t opcode=0;
        uint8_t dest_reg = 0;
        uint8_t src_reg = 0;
        uint8_t immediate_flag = 0;

        int i=0;
        int inst_index = 0;
        int des_index = 0;
        int sc_index = 0;

        while(buff[i]!=' ' && buff[i]!='\0'){
            inst[inst_index] = buff[i];
            i++;
            inst_index++;
        }
        inst[inst_index] = '\0';
        i++;

        printf("Instruction: %s\n",inst);

        while(buff[i]!=',' && buff[i]!='\0'){
            des[des_index] = buff[i];
            i++;
            des_index++;
        }
        des[des_index] = '\0';

        if (buff[i] == ',') i++;

        printf("Destination Register: %s\n",des);

        while(buff[i]!='\n' && buff[i]!='\0'){
            sc[sc_index] = buff[i];
            i++;
            sc_index++;
        }
        sc[sc_index] = '\0';

        printf("Source Register: %s\n",sc);

        // binary for instruction

        if(strcmp(inst,"MOV")==0){
            opcode = 1; 
        }
        else if(strcmp(inst,"ADD")==0){
            opcode = 2;
        }
        else if(strcmp(inst,"SUB")==0){
            opcode = 3;
        }
        else if(strcmp(inst,"AND")==0){
            opcode = 4;
        }
        else if(strcmp(inst,"OR")==0){
            opcode = 5;
        }
        else if(strcmp(inst,"XOR")==0){
            opcode = 6;
        }
        else if(strcmp(inst,"NOT")==0){
            opcode = 7;
        }
        else if(strcmp(inst,"INC")==0){
            opcode = 8;
        }
        else if(strcmp(inst,"DEC")==0){
            opcode = 9;
        }
        else if(strcmp(inst,"EQ")==0){
            opcode = 10;
        }
        
        for(int i=0;des[i]!='\0';i++){
            if(des[i]>='0' && des[i]<='9'){
                int digit = des[i] - '0';
                dest_reg = dest_reg * 10 + digit;
            }
        }

        for(int i=0;sc[i]!='\0';i++){
            if(sc[i]>='A' && sc[i]<='Z'){
                immediate_flag = 1;
            }
            else if(sc[i]>='0' && sc[i]<='9'){
                int digit = sc[i] - '0';
                src_reg = src_reg * 10 + digit;
            }
        }

        uint16_t final_bit = (opcode << 11) | (dest_reg << 6) | (immediate_flag << 5) | (src_reg);

        fwrite(&final_bit,sizeof(final_bit),1,dest);

    }

}

    

