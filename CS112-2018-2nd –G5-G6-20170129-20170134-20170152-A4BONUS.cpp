#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char cimage[SIZE][SIZE][RGB];
void loadImage (char imageFileName[]){
    readRGBBMP(imageFileName,image);
    readRGBBMP(imageFileName,cimage);
}
void loadcImage (char cimageFileName[]){
    readRGBBMP(cimageFileName,cimage);
}
void saveImage () {
   char imageFileName[100];
   cout << "Enter the target image file name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
}
void BWImage (){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            int k=0;
            if (cimage[i][j][k]+cimage[i][j][k+1]+cimage[i][j][k+2]>127*3){
                image[i][j][k]=255;
                image[i][j][k+1]=255;
                image[i][j][k+2]=255;
            }
            else{
                image[i][j][k]=0;
                image[i][j][k+1]=0;
                image[i][j][k+2]=0;
            }
        }
    }
}
void IImage (){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
           int k=0;
           if (image[i][j][k]==0&&image[i][j][k+1]==0&&image[i][j][k+2]==0){
               image[i][j][k]=255;
               image[i][j][k+1]=255;
               image[i][j][k+2]=255;
           }
           else if(image[i][j][k]==255&&image[i][j][k+1]==255&&image[i][j][k+2]==255){
               image[i][j][k]=0;
               image[i][j][k+1]=0;
               image[i][j][k+2]=0;
           }
           else{
               image[i][j][k]=255-image[i][j][k];
               image[i][j][k+1]=255-image[i][j][k+1];
               image[i][j][k+2]=255-image[i][j][k+2];
           }
        }
    }
}
void MImage (){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
          int k=0;
          image[i][j][k]=(cimage[i][j][k]+image[i][j][k])/2;
          image[i][j][k+1]=(cimage[i][j][k+1]+image[i][j][k+1])/2;
          image[i][j][k+2]=(cimage[i][j][k+2]+image[i][j][k+2])/2;
        }
    }
}
void FImage (string q){
    int k=0;
    if(q=="1"){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            image[i][j][k]=cimage[SIZE-1-i][j][k];
            image[i][j][k+1]=cimage[SIZE-1-i][j][k+1];
            image[i][j][k+2]=cimage[SIZE-1-i][j][k+2];
        }
    }}
    else{
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            image[i][j][k]=cimage[i][SIZE-1-j][k];
            image[i][j][k+1]=cimage[i][SIZE-1-j][k+1];
            image[i][j][k+2]=cimage[i][SIZE-1-j][k+2];
        }
    }}
}
void RImage (string q){
    int k=0;
    if(q=="3"){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            image[i][j][k]=cimage[j][SIZE-1-i][k];
            image[i][j][k+1]=cimage[j][SIZE-1-i][k+1];
            image[i][j][k+2]=cimage[j][SIZE-1-i][k+2];
        }
    }}
    else if(q=="2"){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            image[i][j][k]=cimage[SIZE-1-i][SIZE-1-j][k];
            image[i][j][k+1]=cimage[SIZE-1-i][SIZE-1-j][k+1];
            image[i][j][k+2]=cimage[SIZE-1-i][SIZE-1-j][k+2];
        }
    }}
    else{
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            image[i][j][k]=cimage[SIZE-1-j][i][k];
            image[i][j][k+1]=cimage[SIZE-1-j][i][k+1];
            image[i][j][k+2]=cimage[SIZE-1-j][i][k+2];
        }
    }}

}
void DLImage (string q){
    int k=0;
    if(q=="1"){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            image[i][j][k]=image[i][j][k]/2;
            image[i][j][k+1]=image[i][j][k+1]/2;
            image[i][j][k+2]=image[i][j][k+2]/2;
        }
    }}
    else{
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            if(image[i][j][k]<170)
                image[i][j][k]=image[i][j][k]*3/2;
            else
                image[i][j][k]=255;
            if(image[i][j][k+1]<170)
                image[i][j][k+1]=image[i][j][k+1]*3/2;
            else
                image[i][j][k+1]=255;
            if(image[i][j][k+2]<170)
                image[i][j][k+2]=image[i][j][k+2]*3/2;
            else
                image[i][j][k+2]=255;
    }}
}}
void DImage (){
    bool b[SIZE][SIZE]={};
    int k=0;
    BWImage();
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            if(image[i][j][k]==0&&image[i][j][k+1]==0&&image[i][j][k+2]==0){
                if(image[i+1][j][k]==0&&image[i+1][j][k+1]==0&&image[i+1][j][k+2]==0&&
                   image[i+1][j+1][k]==0&&image[i+1][j+1][k+1]==0&&image[i+1][j+1][k+2]==0&&
                   image[i+1][j-1][k]==0&&image[i+1][j-1][k+1]==0&&image[i+1][j-1][k+2]==0&&
                   image[i][j+1][k]==0&&image[i][j+1][k+1]==0&&image[i][j+1][k+2]==0&&
                   image[i][j-1][k]==0&&image[i][j-1][k+1]==0&&image[i][j-1][k+2]==0&&
                   image[i-1][j][k]==0&&image[i-1][j][k+1]==0&&image[i-1][j][k+2]==0&&
                   image[i-1][j-1][k]==0&&image[i-1][j-1][k+1]==0&&image[i-1][j-1][k+2]==0&&
                   image[i-1][j+1][k]==0&&image[i-1][j+1][k+1]==0&&image[i-1][j+1][k+2]==0)
                    b[i][j]=true;
            }
        }
    }
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            if (b[i][j]==true){
                image[i][j][k]=255;
                image[i][j][k+1]=255;
                image[i][j][k+2]=255;
    }}}
}
void E1Image (){
    int m=0;
    for (int i = 0,k=0; i < SIZE; i+=2,k++) {
        for (int j = 0,l=0; j< SIZE; j+=2,l++) {
            image[i][j][m]=cimage[k][l][m];
            image[i+1][j][m]=cimage[k][l][m];
            image[i][j+1][m]=cimage[k][l][m];
            image[i+1][j+1][m]=cimage[k][l][m];
            image[i][j][m+1]=cimage[k][l][m+1];
            image[i+1][j][m+1]=cimage[k][l][m+1];
            image[i][j+1][m+1]=cimage[k][l][m+1];
            image[i+1][j+1][m+1]=cimage[k][l][m+1];
            image[i][j][m+2]=cimage[k][l][m+2];
            image[i+1][j][m+2]=cimage[k][l][m+2];
            image[i][j+1][m+2]=cimage[k][l][m+2];
            image[i+1][j+1][m+2]=cimage[k][l][m+2];
        }
    }
}
void E2Image (){
    int m=0;
    for (int i = 0,k=0; i < SIZE; i+=2,k++) {
        for (int j = 0,l=SIZE/2; j< SIZE; j+=2,l++) {
            image[i][j][m]=cimage[k][l][m];
            image[i+1][j][m]=cimage[k][l][m];
            image[i][j+1][m]=cimage[k][l][m];
            image[i+1][j+1][m]=cimage[k][l][m];
            image[i][j][m+1]=cimage[k][l][m+1];
            image[i+1][j][m+1]=cimage[k][l][m+1];
            image[i][j+1][m+1]=cimage[k][l][m+1];
            image[i+1][j+1][m+1]=cimage[k][l][m+1];
            image[i][j][m+2]=cimage[k][l][m+2];
            image[i+1][j][m+2]=cimage[k][l][m+2];
            image[i][j+1][m+2]=cimage[k][l][m+2];
            image[i+1][j+1][m+2]=cimage[k][l][m+2];
        }
    }
}
void E3Image (){
    int m=0;
    for (int i = 0,k=SIZE/2; i < SIZE; i+=2,k++) {
        for (int j = 0,l=0; j< SIZE; j+=2,l++) {
            image[i][j][m]=cimage[k][l][m];
            image[i+1][j][m]=cimage[k][l][m];
            image[i][j+1][m]=cimage[k][l][m];
            image[i+1][j+1][m]=cimage[k][l][m];
            image[i][j][m+1]=cimage[k][l][m+1];
            image[i+1][j][m+1]=cimage[k][l][m+1];
            image[i][j+1][m+1]=cimage[k][l][m+1];
            image[i+1][j+1][m+1]=cimage[k][l][m+1];
            image[i][j][m+2]=cimage[k][l][m+2];
            image[i+1][j][m+2]=cimage[k][l][m+2];
            image[i][j+1][m+2]=cimage[k][l][m+2];
            image[i+1][j+1][m+2]=cimage[k][l][m+2];
        }
    }
}
void E4Image (){
    int m=0;
    for (int i = 0,k=SIZE/2; i < SIZE; i+=2,k++) {
        for (int j = 0,l=SIZE/2; j< SIZE; j+=2,l++) {
            image[i][j][m]=cimage[k][l][m];
            image[i+1][j][m]=cimage[k][l][m];
            image[i][j+1][m]=cimage[k][l][m];
            image[i+1][j+1][m]=cimage[k][l][m];
            image[i][j][m+1]=cimage[k][l][m+1];
            image[i+1][j][m+1]=cimage[k][l][m+1];
            image[i][j+1][m+1]=cimage[k][l][m+1];
            image[i+1][j+1][m+1]=cimage[k][l][m+1];
            image[i][j][m+2]=cimage[k][l][m+2];
            image[i+1][j][m+2]=cimage[k][l][m+2];
            image[i][j+1][m+2]=cimage[k][l][m+2];
            image[i+1][j+1][m+2]=cimage[k][l][m+2];
        }
    }
}
void SImage (string q){
    if(q=="1"){
    int m=0;
    memset(image, 255, sizeof(image));
    for (int i = 0,k=0; k < SIZE/2; i+=2,k++) {
        for (int j = 0,l=0; l< SIZE/2; j+=2,l++) {
            image[k][l][m]=(cimage[i][j][m]+cimage[i+1][j][m]+cimage[i][j+1][m]+cimage[i+1][j+1][m])/4;
            image[k][l][m+1]=(cimage[i][j][m+1]+cimage[i+1][j][m+1]+cimage[i][j+1][m+1]+cimage[i+1][j+1][m+1])/4;
            image[k][l][m+2]=(cimage[i][j][m+2]+cimage[i+1][j][m+2]+cimage[i][j+1][m+2]+cimage[i+1][j+1][m+2])/4;
        }
    }
    }
    else if(q=="2"){
    int m=0;
    memset(image, 255, sizeof(image));
    for (int i = 0,k=0; k < SIZE/3; i+=3,k++) {
        for (int j = 0,l=0; l< SIZE/3; j+=3,l++) {
            image[k][l][m]=(cimage[i][j][m]+cimage[i][j+1][m]+cimage[i][j+2][m]+cimage[i+1][j][m]+cimage[i+1][j+1][m]+cimage[i+1][j+2][m]+cimage[i+2][j][m]+cimage[i+2][j+1][m]+cimage[i+2][j+2][m])/9;
            image[k][l][m+1]=(cimage[i][j][m+1]+cimage[i][j+1][m+1]+cimage[i][j+2][m+1]+cimage[i+1][j][m+1]+cimage[i+1][j+1][m+1]+cimage[i+1][j+2][m+1]+cimage[i+2][j][m+1]+cimage[i+2][j+1][m+1]+cimage[i+2][j+2][m+1])/9;
            image[k][l][m+2]=(cimage[i][j][m+2]+cimage[i][j+1][m+2]+cimage[i][j+2][m+2]+cimage[i+1][j][m+2]+cimage[i+1][j+1][m+2]+cimage[i+1][j+2][m+2]+cimage[i+2][j][m+2]+cimage[i+2][j+1][m+2]+cimage[i+2][j+2][m+2])/9;
        }
    }
    }
    else{
    int m=0;
    memset(image, 255, sizeof(image));
    for (int i = 0,k=0; k < SIZE/4; i+=4,k++) {
        for (int j = 0,l=0; l< SIZE/4; j+=4,l++) {
            image[k][l][m]=(cimage[i][j][m]+cimage[i][j+1][m]+cimage[i][j+2][m]+cimage[i][j+3][m]+cimage[i+1][j][m]+cimage[i+1][j+1][m]+cimage[i+1][j+2][m]+cimage[i+1][j+3][m]+cimage[i+2][j][m]+cimage[i+2][j+1][m]+cimage[i+2][j+2][m]+cimage[i+2][j+3][m]+cimage[i+3][j][m]+cimage[i+3][j+1][m]+cimage[i+3][j+2][m]+cimage[i+3][j+3][m])/16;
            image[k][l][m+1]=(cimage[i][j][m+1]+cimage[i][j+1][m+1]+cimage[i][j+2][m+1]+cimage[i][j+3][m+1]+cimage[i+1][j][m+1]+cimage[i+1][j+1][m+1]+cimage[i+1][j+2][m+1]+cimage[i+1][j+3][m+1]+cimage[i+2][j][m+1]+cimage[i+2][j+1][m+1]+cimage[i+2][j+2][m+1]+cimage[i+2][j+3][m+1]+cimage[i+3][j][m+2]+cimage[i+3][j+1][m+1]+cimage[i+3][j+2][m+1]+cimage[i+3][j+3][m+1])/16;
            image[k][l][m+2]=(cimage[i][j][m+2]+cimage[i][j+1][m+2]+cimage[i][j+2][m+2]+cimage[i][j+3][m+2]+cimage[i+1][j][m+2]+cimage[i+1][j+1][m+2]+cimage[i+1][j+2][m+2]+cimage[i+1][j+3][m+2]+cimage[i+2][j][m+2]+cimage[i+2][j+1][m+2]+cimage[i+2][j+2][m+2]+cimage[i+2][j+3][m+2]+cimage[i+3][j][m+3]+cimage[i+3][j+1][m+2]+cimage[i+3][j+2][m+2]+cimage[i+3][j+3][m+2])/16;
        }
    }
    }
}

int main()
{
    char imageFileName[100];
    char cimageFileName[100];
    cout<<"Ahlan ya user ya hbibi.\nPlease enter file name of the image to process:\n>>";
    cin.getline(imageFileName,100);
    strcat (imageFileName, ".bmp");
    loadImage(imageFileName);
    cout<<"1- Black & White Filter\n2- Invert Filter\n";
    cout<<"3- Merge Filter\n4- Flip Image\n";
    cout<<"5- Darken and Lighten Image\n6- Rotate Image\n7- Detect Image Edges\n";
    cout<<"8- Enlarge Image\n9- Shrink Image\n>>";
    string n;
    while(true){
        cin>>n;
        if (n=="1"||n=="2"||n=="3"||n=="4"||n=="5"||n=="6"||n=="7"||n=="8"||n=="9")
            break;
        else
            cout<<"choose from 1 or 2 or 3 or 4 or 5 or 6 or 7 or 8 or 9 \n>>";
    }
    if (n=="1"){
        BWImage();
        saveImage ();
    }
    else if (n=="2"){
        IImage();
        saveImage ();
    }
    else if (n=="3"){
        cout<<"enter the name of another image\n>>";
        cin.ignore();
        cin.getline(cimageFileName,100);
        strcat (cimageFileName, ".bmp");
        loadcImage(cimageFileName);
        MImage();
        saveImage ();
    }
    else if (n=="4"){
        string q;
        cout<<"1- to flip the image horizontally\n2- to flip the image vertically\n>>";
        while(true){
        cin>>q;
        if (q=="1"||q=="2")
            break;
        else
            cout<<"choose from 1 or 2\n>>";
        }
        FImage(q);
        saveImage ();
    }
    else if (n=="6"){
        string q;
        cout<<"1- to rotate the image clockwise by 90º\n2- to rotate the image clockwise by 180º\n3- to rotate the image clockwise by 270º\n>>";
        while(true){
        cin>>q;
        if (q=="1"||q=="2"||q=="3")
            break;
        else
            cout<<"choose from 1 or 2 or 3\n>>";
        }
        RImage(q);
        saveImage ();
    }
    else if  (n=="5"){
        string q;
        cout<<"1- to make the image darker by 50% \n2- to make the image lighter by 50% \n>>";
        while(true){
        cin>>q;
        if (q=="1"||q=="2")
            break;
        else
            cout<<"choose from 1 or 2\n>>";
        }
        DLImage(q);
        saveImage ();
    }
    else if (n=="7"){
        DImage();
        saveImage ();
    }
    else if (n=="8"){
        string q;
        cout<<"1- First quarter\n2- Second quarter\n3- third quarter\n4- fourth quarter\n>>";
        while(true){
        cin>>q;
        if (q=="1"||q=="2"||q=="3"||q=="4")
            break;
        else
            cout<<"choose from 1 or 2 or 3 or 4\n>>";
        }
        if (q=="1"){
            E1Image();
        }
        else if(q=="2"){
            E2Image();
        }
        else if(q=="3"){
            E3Image();
        }
        else{
            E4Image();
        }
        saveImage ();
    }
    else if (n=="9"){
        string q;
        cout<<"1- to shrink the image dimensions to 1/2\n2- to shrink the image dimensions to 1/3\n3- to shrink the image dimensions to 1/4\n>>";
        while(true){
        cin>>q;
        if (q=="1"||q=="2"||q=="3")
            break;
        else
            cout<<"choose from 1 or 2 or 3\n>>";
        }
        SImage(q);
        saveImage ();
    }
    return 0;
}
