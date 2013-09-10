#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char c;
    FILE *file;
    file = fopen("text.txt", "r");
    bool estaComentado = false;
    bool esDobleSlash = false;
    while (c != EOF)
    {
        c = fgetc(file);


        if(c == 47) //slasj
        {
            c= fgetc(file);
            if (c == 42) //estrella
            {
                estaComentado = true;
            }
            else if ( c == 47)
            {
                estaComentado = true;
                esDobleSlash = true;
            }
        }

        else if (c== 42)
        {
            c = fgetc(file);
            if (c == 47)
            {
                estaComentado= false;
            }
        }

        else if (estaComentado == true && esDobleSlash == true)
        {
            if (c == 10)
                {
                    esDobleSlash = false;
                    estaComentado = false;
                    printf("%c",c);
                }

        }

        else if (estaComentado == false)
        {
            if (c != 10)
            {
                printf("%c",c);
            }

        }


    }
}
