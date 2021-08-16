#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Reading text files
    // streams categories: text + binary
    FILE *fp;
    fp = fopen("hello.txt", "r"); // open file for reading
    char c = fgetc(fp); // read single char
    printf("%c\n", c);


    // reading whole file in loop
    while ((c = fgetc(fp)) != EOF)
        printf("%c", c);

    fclose(fp);

    // reading line at a time
    char s[1024];
    int linecount = 0;
    fp = fopen("quote.txt", "r");

    while (fgets(s, sizeof s, fp) != NULL)
        printf("%d: %s", ++linecount, s);

    fclose(fp);


    // formatted input
    char name[1024];
    float length;
    int mass;

    fp = fopen("whales.txt", "r");

    while (fscanf(fp, "%s %f %d", name, &length, &mass) != EOF)
        printf("%s whale, %d tonnes, %.1f meters\n", name, mass, length);

    fclose(fp);
    
    // writing text files
    fp = fopen("output.txt", "w"); 

    fputc('B', fp);
    fputc('\n', fp);
    fprintf(fp, "x = %d\n", 32);
    fputs("Hello, world!\n", fp);

    fclose(fp);

    // binary file IO
    // gets raw stream of bytes
    FILE *fpb;
    unsigned char bytes[] = {5, 37, 0, 88, 255, 12};

    fpb = fopen("output.bin", "wb");  // wb -> write binary
    // In the call to fwrite, the arguments are:
    //
    // * Pointer to data to write
    // * Size of each "piece" of data
    // * Count of each "piece" of data
    // * FILE*

	fwrite(bytes, sizeof(char), sizeof bytes, fpb);
	fclose(fpb);

	fpb = fopen("output.bin", "rb");
    
    unsigned char ch;
    while (fread(&ch, sizeof(char), 1, fpb) > 0)
        printf("%d\n", ch);

    fclose(fpb);

    // because of endianness, numbers (and structs) arent representated the same across
    //  diff architecutures and compilers, making portability and issue
    //  Solution: Serialize the data -> Protocol Buffers
    //  TLDR: Serialize binary data when writing to stream

    return 0;
}


