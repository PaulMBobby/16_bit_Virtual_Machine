#include<stdio.h>
#include<string.h>
#include<inttypes.h>


FILE *src, *dest;

void read_data_from_file_convert_to_binary(){

    char buff[50];
    
    while(fgets(buff,sizeof(buff),src)!=NULL){

        char inst[10];
        char des[3];
        char sc[4];

        uint8_t opcode;
        uint8_t dest_reg;
        uint8_t src_reg;
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
        i++;

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
            opcode = 00; 
        }
        else if(strcmp(inst,"ADD")==0){
            opcode = 01;
        }
        else if(strcmp(inst,"SUB")==0){
            opcode = 02;
        }

        // binary for Destination Register

        if(strcmp(des,"R0")==0){
            dest_reg = 00;
        }
        else if(strcmp(des,"R1")==0){
            dest_reg = 01;
        }
        else if(strcmp(des,"R2")==0){
            dest_reg = 02;
        }
        else if(strcmp(des,"R3")==0){
            dest_reg = 03;
        }

        // binary for Source Register

        if(sc[0]=='R'){
            immediate_flag = 1;
        }

        if(strcmp(sc,"00")==0){
            src_reg = 00;
        }
        else if(strcmp(sc,"1")==0){
            src_reg = 01;
        }
        else if(strcmp(sc,"2")==0){
            src_reg = 02;
        }
        else if(strcmp(sc,"3")==0){
            src_reg = 03;
        }
        else if(strcmp(sc,"4")==0){
            src_reg = 04;
        }
        else if(strcmp(sc,"5")==0){
            src_reg = 05;
        }
        else if(strcmp(sc,"6")==0){
            src_reg = 06;
        }
        else if(strcmp(sc,"7")==0){
            src_reg = 07;
        }
        else if(strcmp(sc,"R0")==0){
            src_reg = 00;
        }
        else if(strcmp(sc,"R1")==0){
            src_reg = 01;
        }
        else if(strcmp(sc,"R2")==0){
            src_reg = 02;
        }
        else if(strcmp(sc,"R3")==0){
            src_reg = 03;
        }

        uint8_t final_bit = (opcode << 6) | (dest_reg << 4) | (immediate_flag << 3) | (src_reg);

        fwrite(&final_bit,sizeof(final_bit),1,dest);

    }

}

    

