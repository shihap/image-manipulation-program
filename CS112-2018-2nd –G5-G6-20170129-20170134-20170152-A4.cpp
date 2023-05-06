#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char cimage[SIZE][SIZE];
void loadImage (char imageFileName[]){
    readGSBMP(imageFileName,image);
    readGSBMP(imageFileName,cimage);
}
void loadcImage (char cimageFileName[]){
    readGSBMP(cimageFileName,cimage);
}
void saveImage () {
   char imageFileName[100];
   cout << "Enter the target image file name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}
void BWImage (){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            if (image[i][j]>127)
                image[i][j]=255;
            else
                image[i][j]=0;
        }
    }
}
void IImage (){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            if (image[i][j]==255)
                image[i][j]=0;
            else if(image[i][j]==0)
                image[i][j]=255;
            else
                image[i][j]=255-image[i][j];
        }
    }
}
void MImage (){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            image[i][j]=(cimage[i][j]+image[i][j])/2;
        }
    }
}
void FImage (string q){
    if(q=="2"){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            image[i][j]=cimage[SIZE-1-i][j];
        }
    }}
    else{
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            image[i][j]=cimage[i][SIZE-1-j];
        }
    }}
}
void RImage (string q){
    if(q=="1"){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            image[i][j]=cimage[SIZE-1-j][i];
        }
    }}
    else if(q=="2"){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            image[i][j]=cimage[SIZE-1-i][SIZE-1-j];
        }
    }}
    else{
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            image[i][j]=cimage[j][SIZE-1-i];
        }
    }}

}
void DLImage (string q){
    if(q=="1"){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            image[i][j]=image[i][j]/2;
        }
    }}
    else{
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
        if(image[i][j]<170)
            image[i][j]=image[i][j]*1.5;
        else
            image[i][j]=255;
        }
    }}
}
void DImage (){
    bool b[SIZE][SIZE]={};
    BWImage();
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            if(image[i][j]==0){
                if(image[i+1][j]==0&&image[i+1][j+1]==0&&image[i+1][j-1]==0&&image[i][j+1]==0&&image[i][j-1]==0&&image[i-1][j]==0&&image[i-1][j-1]==0&&image[i-1][j+1]==0)
                    b[i][j]=true;
            }
        }
    }
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            if (b[i][j]==true)
                image[i][j]=255;
    }}

}
void E1Image (){
    for (int i = 0,k=0; i < SIZE; i+=2,k++) {
        for (int j = 0,l=0; j< SIZE; j+=2,l++) {
            image[i][j]=cimage[k][l];
            image[i+1][j]=cimage[k][l];
            image[i][j+1]=cimage[k][l];
            image[i+1][j+1]=cimage[k][l];
        }
    }}
void E2Image (){
    for (int i = 0,k=0; i < SIZE; i+=2,k++) {
        for (int j = 0,l=SIZE/2; j< SIZE; j+=2,l++) {
            image[i][j]=cimage[k][l];
            image[i+1][j]=cimage[k][l];
            image[i][j+1]=cimage[k][l];
            image[i+1][j+1]=cimage[k][l];
        }
    }}
void E3Image (){
    for (int i = 0,k=SIZE/2; i < SIZE; i+=2,k++) {
        for (int j = 0,l=0; j< SIZE; j+=2,l++) {
            image[i][j]=cimage[k][l];
            image[i+1][j]=cimage[k][l];
            image[i][j+1]=cimage[k][l];
            image[i+1][j+1]=cimage[k][l];
        }
    }}
void E4Image (){
    for (int i = 0,k=SIZE/2; i < SIZE; i+=2,k++) {
        for (int j = 0,l=SIZE/2; j< SIZE; j+=2,l++) {
            image[i][j]=cimage[k][l];
            image[i+1][j]=cimage[k][l];
            image[i][j+1]=cimage[k][l];
            image[i+1][j+1]=cimage[k][l];
        }
    }}
void SImage (string q){
    memset(image, 255, sizeof(image));
    if(q=="1"){
    for (int i = 0,k=0; k < SIZE/2; i+=2,k++) {
        for (int j = 0,l=0; l< SIZE/2; j+=2,l++)
            image[k][l]=(cimage[i][j]+cimage[i+1][j]+cimage[i][j+1]+cimage[i+1][j+1])/4;
    }}
    else if(q=="2"){
    for (int i = 0,k=0; k < SIZE/3; i+=3,k++) {
        for (int j = 0,l=0; l< SIZE/3; j+=3,l++)
            image[k][l]=(cimage[i][j]+cimage[i][j+1]+cimage[i][j+2]+cimage[i+1][j]+cimage[i+1][j+1]+cimage[i+1][j+2]+cimage[i+2][j]+cimage[i+2][j+1]+cimage[i+2][j+2])/9;
    }}
    else{
    for (int i = 0,k=0; k < SIZE/4; i+=4,k++) {
        for (int j = 0,l=0; l< SIZE/4; j+=4,l++)
            image[k][l]=(cimage[i][j]+cimage[i][j+1]+cimage[i][j+2]+cimage[i][j+3]+cimage[i+1][j]+cimage[i+1][j+1]+cimage[i+1][j+2]+cimage[i+1][j+3]+cimage[i+2][j]+cimage[i+2][j+1]+cimage[i+2][j+2]+cimage[i+2][j+3]+cimage[i+3][j]+cimage[i+3][j+1]+cimage[i+3][j+2]+cimage[i+3][j+3])/16;
    }}
}
void MIImage(string q){
    if(q=="1"){
        for (int i = 0; i < SIZE; i++){
            for (int j = SIZE/2-1; j< SIZE; j++){
                image[i][j]=cimage[i][SIZE-1-j];
            }
        }
    }
    if(q=="3"){
        for (int i = SIZE/2-1; i < SIZE; i++){
            for (int j = 0; j< SIZE; j++){
                image[i][j]=cimage[SIZE-1-i][j];
            }
        }

    }
    if(q=="4"){
        for (int i =0 ; i < SIZE/2-1; i++){
            for (int j = 0; j< SIZE; j++){
                image[i][j]=cimage[SIZE-1-i][j];
            }
        }
    }
    if(q=="2"){
        for (int i = 0; i < SIZE; i++){
            for (int j =0 ; j< SIZE/2-1; j++){
                image[i][j]=cimage[i][SIZE-1-j];
            }
        }
    }
}
void SHImage(string x){
    memset(image, 255, sizeof(image));
    for(int n=0;n<4;n++){
        if(x[n]=='1'){
        if(n==0){
        for (int i = 0,k=0; i < SIZE/2; i++,k++) {
            for (int j = 0,l=0; j< SIZE/2; j++,l++) {
                image[k][l]=cimage[i][j];
            }
        }}
        if(n==1){
        for (int i = 0,k=0; i < SIZE/2; i++,k++) {
            for (int j = 0,l=SIZE/2-1; j< SIZE/2; j++,l++) {
                image[k][l]=cimage[i][j];
            }
        }}
        if(n==2){
        for (int i = 0,k=SIZE/2-1; i < SIZE/2; i++,k++) {
            for (int j = 0,l=0; j< SIZE/2; j++,l++) {
                image[k][l]=cimage[i][j];
            }
        }}
        if(n==3){
        for (int i = 0,k=SIZE/2-1; i < SIZE/2; i++,k++) {
            for (int j = 0,l=SIZE/2-1; j< SIZE/2; j++,l++) {
                image[k][l]=cimage[i][j];
            }
        }}}
        if(x[n]=='2'){
        if(n==0){
        for (int i = 0,k=0; i < SIZE/2; i++,k++) {
            for (int j = SIZE/2,l=0; j< SIZE; j++,l++) {
                image[k][l]=cimage[i][j];
            }
        }}
        if(n==1){
        for (int i = 0,k=0; i < SIZE/2; i++,k++) {
            for (int j = SIZE/2,l=SIZE/2-1; j< SIZE; j++,l++) {
                image[k][l]=cimage[i][j];
            }
        }}
        if(n==2){
        for (int i = 0,k=SIZE/2-1; i < SIZE/2; i++,k++) {
            for (int j = SIZE/2,l=0; j< SIZE; j++,l++) {
                image[k][l]=cimage[i][j];
            }
        }}
        if(n==3){
        for (int i = 0,k=SIZE/2-1; i < SIZE/2; i++,k++) {
            for (int j = SIZE/2,l=SIZE/2-1; j< SIZE; j++,l++) {
                image[k][l]=cimage[i][j];
            }
        }}}
        if(x[n]=='3'){
        if(n==0){
        for (int i = SIZE/2,k=0; i < SIZE; i++,k++) {
            for (int j = 0,l=0; j< SIZE/2; j++,l++) {
                image[k][l]=cimage[i][j];
            }
        }}
        if(n==1){
        for (int i = SIZE/2,k=0; i < SIZE; i++,k++) {
            for (int j = 0,l=SIZE/2-1; j< SIZE/2; j++,l++) {
                image[k][l]=cimage[i][j];
            }
        }}
        if(n==2){
        for (int i = SIZE/2,k=SIZE/2-1; i < SIZE; i++,k++) {
            for (int j = 0,l=0; j< SIZE/2; j++,l++) {
                image[k][l]=cimage[i][j];
            }
        }}
        if(n==3){
        for (int i = SIZE/2,k=SIZE/2-1; i < SIZE; i++,k++) {
            for (int j = 0,l=SIZE/2-1; j< SIZE/2; j++,l++) {
                image[k][l]=cimage[i][j];
            }
        }}}
        if(x[n]=='4'){
        if(n==0){
        for (int i = SIZE/2,k=0; i < SIZE; i++,k++) {
            for (int j = SIZE/2,l=0; j< SIZE; j++,l++) {
                image[k][l]=cimage[i][j];
            }
        }}
        if(n==1){
        for (int i = SIZE/2,k=0; i < SIZE; i++,k++) {
            for (int j = SIZE/2,l=SIZE/2-1; j< SIZE; j++,l++) {
                image[k][l]=cimage[i][j];
            }
        }}
        if(n==2){
        for (int i = SIZE/2,k=SIZE/2-1; i < SIZE; i++,k++) {
            for (int j = SIZE/2,l=0; j< SIZE; j++,l++) {
                image[k][l]=cimage[i][j];
            }
        }}
        if(n==3){
        for (int i = SIZE/2,k=SIZE/2-1; i < SIZE; i++,k++) {
            for (int j = SIZE/2,l=SIZE/2-1; j< SIZE; j++,l++) {
                image[k][l]=cimage[i][j];
            }
        }}}}
}
void BImage(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image[i][j]=(image[i-1][j-1]+image[i-1][j]+image[i-1][j+1]+image[i-1][j-2]+image[i-1][j+2]
                         +image[i][j]+image[i][j-1]+image[i][j+1]+image[i][j-2]+image[i][j+2]
                         +image[i+1][j-1]+image[i+1][j]+image[i+1][j+1]+image[i+1][j-2]+image[i+1][j+2]
                         +image[i+2][j-1]+image[i+2][j]+image[i+2][j+1]+image[i+2][j-2]+image[i+2][j+2]
                         +image[i-2][j-1]+image[i-2][j]+image[i-2][j+1]+image[i-2][j-2]+image[i-2][j+2])/25;
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
    cout<<"8- Enlarge Image\n9- Shrink Image\na- Mirror 1/2 Image\nb- Shuffle Image\nc- Blur Image\n>>";
    string n;
    while(true){
        cin>>n;
        if (n=="1"||n=="2"||n=="3"||n=="4"||n=="5"||n=="6"||n=="7"||n=="8"||n=="9"||n=="a"||n=="b"||n=="c")
            break;
        else
            cout<<"choose from 1 or 2 or 3 or 4 or 5 or 6 or 7 or 8 or 9 or a or b or c\n>>";
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
    else if(n=="a"){
        string q;
        cout<<"1- Left 1/2\n2- Right 1/2\n3- Upper 1/2\n4- Lower 1/2\n>>";
        cin>>q;
        MIImage(q);
        saveImage();
    }
    else if(n=="b"){
        string q;
        cout<<"Enter the order you want the quarters in the new image\n>>";
        while(true){
            cin>>q;
            stringstream ss;
            ss<<q;
            int x;
            ss>>x;
            if(x%10000!=x){
                cout<<"Wrong Input,please enter again : ";
            }
            else{
                break;
            }
        }
        SHImage(q);
        saveImage();
    }
    else if(n=="c"){
        BImage();
        saveImage();
    }
    return 0;
}
