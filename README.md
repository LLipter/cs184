# HW0 - Getting Started

## Part 1 - Setting up your machine

### A. Install C++

In CS 184, all of your projects will be done in C++. If you are new to the language, please read a handy [primer we wrote](https://docs.google.com/document/d/12aFzdekyJv5Ju6aTACT0Pk0ypByxhIKbmtLEEOn8cXM/edit) that gives a quick overview of important C++ specific concepts. 

First, make sure to install the appropriate version of C++ on your machine. 

On Mac, first go install XCode through the Mac App Store. Once you've done that, open up your terminal and run ```xcode-select --install```. You should now be able to run ```g++ --version``` without any errors. On Windows, install Visual Studio.

Aside from C++, we highly recommend that you use an real IDE, not Sublime Text or Visual Studio Code, in order to work on your projects in this class. Many of the projects require serious debugging, made exponentially easier through the use of an IDE. We highly recommend [CLion](https://www.jetbrains.com/clion/), XCode for Mac users, or Visual Studio for Windows users.

### B. Install CMake

We will be using [CMake](http://www.cmake.org/) to build the assignments. If you don't have CMake (version >= 2.8) on your personal computer, you can install it using apt-get on Linux or Macports/Homebrew on OS X. Alternatively, you can [download](https://cmake.org/download/) it directly from the CMake website.

If you are on Windows, it might be helpful to take a look [here](https://docs.google.com/document/d/1fPwMXKZ66YZnH-z0cM7cUw7ApN6Xc0N-q9EYggrG5u4/edit).

### C. Building the Test Code

To build the code, start in the folder that GitHub made or that was created when you unzipped the download. Run 

    mkdir build; cd build

to create a build directory and enter it, then 

    cmake ..

to have CMake generate the appropriate Makefiles for your system, then to actually compile the code run

    make 

If both of these commands ran without any errors, you should see a ```triangle_test``` executable file under the ```build``` directory. Run this file by typing

    ./triangle_test

If all goes well, you should see a window pop up with a yellow triangle.


## Part 2 - Basic C++/Linear Algebra Practice

Fill in the ```mult``` function at the top of ```triangle_test.cpp``` by implementing a 3 dimensional matrix-vector multiplication. Do not use the built-in CGL multiplication function! Read the CGL source files for ```matrix3x3.cpp``` and ```vector3D.cpp``` in order to get a better idea for how to use the two parameters. Once the function is properly implemented, you should see the yellow triangle rotated 90 degrees.

Remember to run ```make``` to compile your edits.

If you are feeling ambitious, try instantiating the matrix to perform a scaling operation or shifting operation. We'll learn more formally about these later on in the course.

## Part 3 - Going Above and Beyond (Optional)

Take a look at the ```render``` function in ```triangle_test.cpp```. Notice the following commands:

* ```glColor3f(1.0, 1.0, 0.0)``` tells our computer to render the following shapes using the RGB value (1.0, 1.0, 0.0), or yellow.
* ```glBegin(GL_TRIANGLES)``` tells our computer that we want to render triangles with the following vertices we will specify.
* ```glVertex3f(x, y, z)``` tells our computer to draw a vertex at a particular location.

With the above setup, if we specify six vertices, our computer will render one triangle with the first three vertices, and another triangle with the second three vertices. Try modifying the given render code to draw "something interesting". It could be a cool picture, your name, an interesting pattern... Feel free to share your creative work on Piazza!

## Submission
There is no submission for this homework. However, we highly recommend that you finish the homework, to prevent any issues when you start on the projects for this class.