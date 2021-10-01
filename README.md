# PGM Image Reader
I have written this program to read images of the type P5 with .pgm extension, i.e. portable gray map.\
It stores the unsigned char of the image as a matrix, to allow easy manipulation and image processing.

Usage:
  - Compile the code "**p5_matrix.cpp**"(Which simply reads and write the Image) or "**process_image.cpp**"(Which inverts the value of a character with 255-character in addition to reading and writing) using the **command line**(eg. **g++ process_image.cpp -o process_image**). 
  - Run the Compiled Code(eg. **.\process_image**)
  - It prompts to **enter the Image File name with extension(.pgm)**(If the P5 image file is in the same folder where the program is running) or **enter the path relative to the directory where the program is running along with extension(.pgm)**(If the P5 image file is in a different folder, eg. **Image_Files\barbara.pgm**).
  - After a valid filename is input. It prints any comments added in the Image File and presents the Image File Details(Dimensions, Gray Value).
  - It prompts for the output name of the file to which the image will be written **enter <Image-Filename.pgm>** or **enter** <**Directory>\\<Image-Filename.pgm>**.(eg. **Output_Files\out-barbara.pgm**)
  - The Program ends.
 
The pgmreader.h file has the above code, and it's usage is demonstrated in the process_image.cpp file.\
I have performed simple char value inversion, to demonstrate how the code inside the image_process function can be modified with much more complicated and interesting code later on.\
The input and output image files are put in the respective folders for reference.
