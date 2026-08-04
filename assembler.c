#include<stdio.h>
#include<C:\Codes\Projects\16_bit_virtual_machine\assembler_functions.c>

int main(){

    src = fopen("program.txt","r");
    dest = fopen("code.bin","wb");

    if (src == NULL) {
        printf("ERROR: Could not open code.txt. Check your file path.\n");
        return 1;
    }

    read_data_from_file_convert_to_binary();

    fclose(dest);
    fclose(src);

return 0;
}