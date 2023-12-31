#ifndef HEADER_CONVERTER
#define HEADER_CONVERTER
#include <stdlib.h>
#include<stdio.h>


void color(char* image,char* grid,int cell_size,int y_size,int row,int column){
for(int i=0;i<cell_size;i++){
    for(int j=0;j<cell_size;j++){
        image[(column*cell_size+j)+(row*cell_size+i)*cell_size*y_size]=grid[column+row*y_size];
    }
}
};




char* read_text_image(int xsize,int ysize,const char*image_name){
char*image;
FILE* image_file;
char*line=NULL;
size_t k=0,n=1;
image=(char*) calloc(xsize*ysize,sizeof(char));
image_file=fopen(image_name,"r");
for (int i=0;i<xsize;i++){
    for(int j=0;j<ysize;j++)
    image[j+i*ysize]=fgetc(image_file);
    fgetc(image_file);
    
}


    fclose (image_file);
    return image;

};



void write_pgm_image( void *image, int xsize,int ysize, const char *image_name)
{
const int maxval=255;
FILE* image_file;
image_file=fopen(image_name,"w");
fprintf(image_file, "P5\n#generated by\n#Enrico Malcapi\n%d %d\n%d\n", ysize, xsize, maxval);
fwrite(image,1,xsize*ysize,image_file);
fclose(image_file);
};



#endif
