# cub3d
<p> 
  <img src="./cub.gif" alt="My Project GIF" width="800" height="600">
</p>
<p>
  Raycasting is a rendering technique to create a 3D perspective in a 2D map. Back when computers were slower it wasn't possible to run real 3D engines in realtime, and raycasting was the first solution. Raycasting can go very fast, because only a calculation has to be done for every vertical line of the screen. The most well known game that used this technique, is of course Wolfenstein 3D.
</p>
<p>
  <img alt="" src="https://lodev.org/cgtutor/images/wolf3d.jpg" style="width: 320px; height: 200px;">
</p>
<p>
  The project implements:
  <ul>
   <li>Сoliseum</li>
   <li>Mouse control</li>
   <li>Minimap</li>
  </ul>
</p>
<h3>
  Compiling the program
</h3>
<p>
  After cloning repository, your may write <b>make all</b> for Makefile at console current directory or <b>make bonus</b>
  <p>Also your use CMake</p>
</p>
<h3>
  Execute programm
</h3>
<p>
  ./cub gets *.cub file that looks like this:
NO ./txts_xpm/WOLF1.xpm
SO ./txts_xpm/WOLF2.xpm
WE ./txts_xpm/WOLF3.xpm
EA ./txts_xpm/WOLF4.xpm

F 255,0,98
C 3,213,255

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010000001
11000001110101011111011110N01
11110111 1110101 101111010001
11111111 1111111 111111111111

</p>
