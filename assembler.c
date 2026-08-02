#include<stdio.h>
#include<C:\Codes\Projects\16bit_virtual_machine\assembler_functions.c>

int main(){

    src = fopen("code.txt","r");
    dest = fopen("code.bin","wb");

    read_data_from_file_convert_to_binary();

    fclose(dest);
    fclose(src);

return 0;
}