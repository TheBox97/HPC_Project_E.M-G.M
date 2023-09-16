#ifndef HEADER_UPDATE
#define HEADER_UPDATE
#include <stdlib.h>
#include<stdio.h>








void updateCell(const int row,const int col,const int y_size,char*OldGrid,char*NewGrid){
    char alive=(char) 0;
    short int lives=0;              //conteggio dei vicini vivi 
    int dim=y_size;


if(col==0){
    for(int i=(row-1);i<(row+2);i=i+2){             //CONTROLLA LA RIGA SOPRA E SOTTO 
            for(int j=(col);j<(col+2);j++){
                if(OldGrid[j+i*dim]==alive){
                    lives+=1;
                }
            }
            if(OldGrid[(y_size-1)+i*dim]==alive)       //controlla gli estremi della riga sopra e sotto 
                lives+=1;
        }

if(OldGrid[(col+1)+row*dim]==alive)             // controllo della riga in centro 
lives+=1;

if(OldGrid[(y_size-1)+row*dim]==alive)
lives+=1;
}
else if(col==(y_size-1)){                       //ANALOGO AL CASO PRIMA MA SPECULARE
for(int i=(row-1);i<(row+2);i=i+2){
            for(int j=(col-1);j<(col+1);j++){
                if(OldGrid[j+i*dim]==alive){
                    lives+=1;
                }
            }
            if(OldGrid[i*dim]==alive)
                lives+=1;
        }

if(OldGrid[(col-1)+row*dim]==alive)
lives+=1;
if(OldGrid[row*dim]==alive)
lives+=1;
}

else{
        for(int i=(row-1);i<(row+2);i=i+2){             //controllo delle righe sopra e sotto
            for(int j=(col-1);j<(col+2);j++){
                if(OldGrid[j+i*dim]==alive){
                    lives+=1;
                }
            }
        }

        for(int j=(col-1);j<(col+2);j=j+2){             //controllo della riga centrale
            if(OldGrid[j+row*dim]==alive){
                lives+=1;
            }
        }
}

NewGrid[col+row*dim]=(lives==3 | lives==2)?alive:(char)255;     //aggiornamento in base al numero di vivi 
};


void updateUP(const int col,const int x_size,const int y_size,char*OldGrid,char*NewGrid,char* upper){
   char alive=(char) 0;
   const int row=0;
    short int lives=0;
    int dim=y_size;


if(col==0){
    if(OldGrid[1]==alive)           //riga gentrale 
                lives+=1;
    if(OldGrid[(y_size-1)]==alive)
                lives+=1;
    for(int j=(col);j<(col+2);j++){         //riga sotto
        if(OldGrid[j+(row+1)*dim]==alive)
            lives+=1;
        }
            if(OldGrid[(y_size-1)+(row+1)*dim]==alive)  //riga sotto esterno
                lives+=1;
    for(int j=(col);j<(col+2);j++){          //upper    
        if(upper[j]==alive)
            lives+=1;
        }
            if(upper[(y_size-1)]==alive) 
                lives+=1;                               // upper esterno

}

else if(col==(y_size-1)){               //analogo ma speculare
    if(OldGrid[0]==alive)
                lives+=1;
    if(OldGrid[(y_size-2)]==alive)
                lives+=1;
    for(int j=(col-1);j<(col+1);j++){
        if(OldGrid[j+(row+1)*dim]==alive)
            lives+=1;
        }
            if(OldGrid[(row+1)*dim]==alive)
                lives+=1;
    for(int j=(col-1);j<(col+1);j++){                   
        if(upper[j]==alive)
            lives+=1;
        }
            if(upper[0]==alive)
                lives+=1;                              
}

else{
for(int j=(col-1);j<(col+2);j=j+2){     //riga centrale
   if(OldGrid[j+row*dim]==alive){
      lives+=1;
    }
}
for(int j=(col-1);j<(col+2);j++){       //riga sotto
   if(OldGrid[j+(row+1)*dim]==alive){
      lives+=1;
    }
}
for(int j=(col-1);j<(col+2);j++){                       //upper 
   if(upper[j]==alive){
      lives+=1;
    }                                                   
}
}
NewGrid[col+row*dim]=(lives==3 | lives==2)?alive:(char)255;//aggiornamento in base al numero di vite

};


void updateDOWN(const int col,const int x_size,const int y_size,char*OldGrid,char*NewGrid,char* lower){// ANALOGO AD UPDATEUP MA SPECULARE
   char alive=(char) 0;
   const int row=(x_size-1);
    short int lives=0;
    int dim=y_size;

 if(col==0){
    if(OldGrid[1+row*dim]==alive)
                lives+=1;
    if(OldGrid[(y_size-1)+row*dim]==alive)
                lives+=1;
    for(int j=(col);j<(col+2);j++){
        if(OldGrid[j+(row-1)*dim]==alive)
            lives+=1;
        }
            if(OldGrid[(y_size-1)+(row-1)*dim]==alive)
                lives+=1;
    for(int j=(col);j<(col+2);j++){                 //PEZZO DA CAMBIARE PER MPI (CONSIDERA LA PRIMA LINEA COME QUELLA SOTTO) 
        if(lower[j]==alive)
            lives+=1;
        }
            if(lower[(y_size-1)]==alive)
                lives+=1;                           //FINE PEZZO

}

else if(col==(y_size-1)){
    if(OldGrid[row*dim]==alive)
                lives+=1;
    if(OldGrid[(y_size-2)+row*dim]==alive)
                lives+=1;
    for(int j=(col-1);j<(col+1);j++){
        if(OldGrid[j+(row-1)*dim]==alive)
            lives+=1;
        }
            if(OldGrid[(row-1)*dim]==alive)
                lives+=1;
    for(int j=(col-1);j<(col+1);j++){                    //PEZZO DA CAMBIARE PER MPI (CONSIDERA LA PRIMA LINEA COME QUELLA SOTTO) 
        if(lower[j]==alive)
            lives+=1;
        }
            if(lower[0]==alive)
                lives+=1;                                 //FINE PEZZO  
}

else{
    for(int j=(col-1);j<(col+2);j=j+2){
        if(OldGrid[j+row*dim]==alive){
        lives+=1;
    }
}
for(int j=(col-1);j<(col+2);j++){
   if(OldGrid[j+(row-1)*dim]==alive){
      lives+=1;
    }
}
for(int j=(col-1);j<(col+2);j++){                    //PEZZO DA CAMBIARE PER MPI (CONSIDERA LA PRIMA LINEA COME QUELLA SOTTO) 
   if(lower[j]==alive){
      lives+=1;
    }                                               
}                                                   //FINE PEZZO
}
NewGrid[col+row*dim]=(lives==3 | lives==2)?alive:(char)255;

};

void update1LINE(const int col,const int x_size,const int y_size,char*OldGrid,char*NewGrid,char* upper,char* lower){
   char alive=(char) 0;
   const int row=0;
    short int lives=0;
    int dim=y_size;


if(col==0){
    if(OldGrid[1]==alive)
                lives+=1;
    if(OldGrid[(y_size-1)]==alive)
                lives+=1;
    for(int j=(col);j<(col+2);j++){
        if(lower[j]==alive)
            lives+=1;
        }
            if(lower[(y_size-1)]==alive)
                lives+=1;
    for(int j=(col);j<(col+2);j++){          //PEZZO DA CAMBIARE PER MPI (CONSIDERA L'ULTIMA LINEA COME QUELLA SOPRA)   
        if(upper[j]==alive)
            lives+=1;
        }
            if(upper[(y_size-1)]==alive) 
                lives+=1;                               // FINE PEZZO 

}

else if(col==(y_size-1)){
    if(OldGrid[0]==alive)
                lives+=1;
    if(OldGrid[(y_size-2)]==alive)
                lives+=1;
    for(int j=(col-1);j<(col+1);j++){
        if(lower[j]==alive)
            lives+=1;
        }
            if(lower[0]==alive)
                lives+=1;
    for(int j=(col-1);j<(col+1);j++){                   //PEZZO DA CAMBIARE PER MPI (CONSIDERA L'ULTIMA LINEA COME QUELLA SOPRA) 
        if(upper[j]==alive)
            lives+=1;
        }
            if(upper[0]==alive)
                lives+=1;                               //FINE PEZZO
}

else{
for(int j=(col-1);j<(col+2);j=j+2){
   if(OldGrid[j+row*dim]==alive){
      lives+=1;
    }
}
for(int j=(col-1);j<(col+2);j++){
   if(lower[j]==alive){
      lives+=1;
    }
}
for(int j=(col-1);j<(col+2);j++){                       //PEZZO DA CAMBIARE PER MPI (CONSIDERA L'ULTIMA LINEA COME QUELLA SOPRA) 
   if(upper[j]==alive){
      lives+=1;
    }                                                   //FINE PEZZO
}
}
NewGrid[col+row*dim]=(lives==3 | lives==2)?alive:(char)255;

};


#endif