#include <stdio.h>
#include <stdlib.h>


//fopen , fclose 
int open_file_close (const char *filepath)
{
    File *file_stream = NULL;

    file_stream = fopen(filepath, "r");

    /*check if pionter is null*/

    if (file_stream == NULL)
    {
        fprintf(stderr, "could not open file '%s'\n", filepath);
        return -1;
    }
    fprintf(stderr, "succesfully opened file '%s'\n", filepath);
    fclose(file_stream);
    return 0;
}
int create_file_close(const char *filepath)
{
    File *file_stream = NULL
    file_stream = fopen(filepath, "w");

    if(!file_stream)
    {
        fprintf(stderr, "could not open/create file '%s'\n", filepath);
        return -1;
 
   }
    fprintf(stderr, "succsefully open/create file '%s'\n", filepath);
    fclose(file_stream);
    return 0
}

int create_file_close(const char *filepath)
{
    File *file_stream = NULL
    file_stream = fopen(filepath, "w");

    if(!file_stream)
    {
        fprintf(stderr, "could not open/create file '%s'\n", filepath);
        return -1;
 
   }
    fprintf(stderr, "succsefully open/create file '%s'\n", filepath);
    fclose(file_stream);
    return 0
}
// fgets , fscanf
int read_int_from_file(const char *filepath, int *out)
{
        File *file_stream = NULL;
        int matches

    file_stream = fopen(filepath, "r");

    /*check if pionter is null*/

    if (file_stream == NULL)
    {
        fprintf(stderr, "could not open file '%s'\n", filepath);
        return -1;
    }
    fprintf(stderr, "succesfully opened file '%s'\n", filepath);
    matches = fscanf(file_stream, "data we are looking for", out);

     fprintf(stderr, "total matches  '%d'\n", matches);


    fclose(file_stream);
    return 0;
}

// fputs , fprintf
 

// fseek , ftell,  rewinf



int main(void)
{
    int result;


}