#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display();
int main()
{
    char a[10], ad[10], label[10], opcode[10], operand[10], symbol[10],mnemonic[10],code[10];
    int start, diff, i, address, add, len, actual_len, finaddr, prevaddr, j = 0, length;
    FILE *fp1, *fp2, *fp3, *fp4, *fp5,*fp6;
    fp1 = fopen("output.txt", "w");
    fp2 = fopen("symtab.txt", "r");
    fp3 = fopen("intermediate.txt", "r");
    fp4 = fopen("objcode.txt", "w");
   fp5=fopen("length.txt", "r");
   fp6=fopen("optab.txt", "r");
   fscanf(fp5,"%d",&length);
    fscanf(fp3, "%s\t%s\t%s", label, opcode, operand);

     fclose(fp3);
  fp3 = fopen("intermediate.txt", "r");
  fscanf(fp3, "\t%s\t%s\t%s", label, opcode, operand);
    if (strcmp(opcode, "START") == 0)
    {
        fprintf(fp1, "\t%s\t%s\t%s\n", label, opcode, operand);
        int val=atoi(operand);
        fprintf(fp4, "H^%6s^%06d^%d\n", label, val, length);
        fscanf(fp3, "%d%s%s%s", &address, label, opcode, operand);
        
        fprintf(fp4, "T^%06d^%d", val, length);
    }

    while (strcmp(opcode, "END") != 0)
    {
        if (strcmp(opcode, "BYTE") == 0)
        {
            fprintf(fp1, "%d\t%s\t%s\t%s\t", address, label, opcode, operand);
            len = strlen(operand);
            actual_len = len - 3;
            fprintf(fp4, "^");
            for (i = 2; i < (actual_len + 2); i++)
            {   int val=operand[i];
                itoa(val, ad, 16);
                fprintf(fp1, "%s", ad);
                fprintf(fp4, "%s", ad);
            }
        }
 else if (strcmp(opcode, "WORD") == 0)
        {
            len = strlen(operand);
            itoa(atoi(operand), a, 10);
            fprintf(fp1, "%d\t%s\t%s\t%s\t00000%s\n", address, label, opcode, operand, a);
            int val=atoi(operand);
            fprintf(fp4, "^%06d", val);
        }else if ( (strcmp(opcode, "RESW") == 0)) {
            
            fprintf(fp1, "%d\t%s\t%s\t%s\n", address, label, opcode, operand);
           int val =atoi(operand);
             while(val!=0){
                fprintf(fp4,"^******");
                val--;
             }
        }

        else if ((strcmp(opcode, "RESB") == 0) ) {
            
            fprintf(fp1, "%d\t%s\t%s\t%s\n", address, label, opcode, operand);
           int val= atoi(operand);

             fprintf(fp4, "^");
             while(val!=0){
                fprintf(fp4,"**");
            val--;
             }
        }
else{
    fscanf(fp6,"%s,%s",mnemonic,code);
            while (strcmp(opcode, mnemonic) != 0){
                    fscanf(fp6,"%s%s",mnemonic,code);
            }
            {
                rewind(fp2);
                fscanf(fp2, "%s%d", symbol, &add);
                while (strcmp(operand, symbol) != 0)
                    fscanf(fp2, "%s%d", symbol, &add);
                fprintf(fp1, "%d\t%s\t%s\t%s\t%s%d\n", address, label, opcode, operand, code, add);
                fprintf(fp4, "^%s%d", code, add);
            }
        }
         fscanf(fp3, "%d%s%s%s", &address, label, opcode, operand);
    }

    fprintf(fp1, "%d\t%s\t%s\t%s\n", address, label, opcode, operand);
    fprintf(fp4, "\nE^00%d", start);
    fclose(fp4);
    fclose(fp3);
    fclose(fp2);
    fclose(fp1);
    fclose(fp5);
    display();
    return 0;
}

void display() {
    char ch;
    FILE *fp1, *fp2, *fp3, *fp4;
     printf("\nIntermediate file is converted into object code");
     printf("\n\nThe contents of Intermediate file:\n\n");
    fp3 = fopen("intermediate.txt", "r");
    ch = fgetc(fp3);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp3);
    }
    fclose(fp3);

    printf("\n\nThe contents of Symbol Table :\n\n");
    fp2 = fopen("symtab.txt", "r");
    ch = fgetc(fp2);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp2);
    }
    fclose(fp2);

    printf("\n\nThe contents of Output file :\n\n");
    fp1 = fopen("output.txt", "r");
    ch = fgetc(fp1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp1);
    }
    fclose(fp1);

    printf("\n\nThe contents of Object code file :\n\n");
    fp4 = fopen("objcode.txt", "r");
    ch = fgetc(fp4);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp4);
    }
    fclose(fp4);

}