# PGM Image Reader
This is a program to read images of the type P5 with .pgm extension, i.e. portable gray map.\
It stores the pixel values as a matrix, to allow easy manipulation and image processing.\
To use this code you should compile(g++) and run it.
  - It prompts to enter the <Image-Filename.pgm> or <Directory>\<Image-Filename.pgm>.
  - After a valid filename is input. It prints any comments added in the Image File and presents the Image File Details(Dimensions, Gray Value).
  - It prompts for the output <Image-Filename.pgm> or <Directory>\<Image-Filename.pgm>.
  
The Program ends.\
The pgmreader.h file has the above code, and it's usage is demonstrated in the process_image.cpp file.\
I have performed simple pixel value inversion, to demonstrate how the code inside the image_process function can be modified with much more complicated and interesting code later on.

