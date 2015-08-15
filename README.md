C. elegans simulation
======

This program simulate the C. elegans brain and body in a virtual environment.<br/>
[Click here to see the video of the simulation](https://youtu.be/WAYeeMcu1tY "C.elegans brain and body simulation")

Instructions
======
I tested the program only on Linux , so here's the instructions to build the program on Linux.<br/>
This does not mean that you can't compile the program on other platforms.

You need to install SDL2 and OpenGL libraries.<br/>
On ubuntu just run this:

	$ sudo apt-get install libsdl2-dev

Then clone the repository to your computer, go to the 'src' directory and run:<br/>

    $ sudo sh compile.sh
	$ ./Celegans

To 'turn on' the worm, hold the F key for few seconds.<br/>

You can control the simulation with the keyboard:<br/>
S = show brain and muscle data<br/>
F = give food to the worm<br/>
N = touch the worm nose<br/>
A = touch anterior<br/>
P = touch posterior<br/>
Q = quit<br/>


License
======
The MIT License (MIT)

Copyright (c) 2015 Carlo Meroni

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
