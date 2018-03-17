
# My @42Born2Code Projects
None of those projects are production-ready. I mostly experienced, and played around with the languages when working on those projects, trying to achieve additional features for bonuses when available.

## [Lem-in](https://github.com/Itokoyamato/42_projects/tree/master/lem_in)
Grade: **125**/100 *(Done with **@Technowix**)*

This is an initiation to pathfinding algorithm, the program will take an anthill into the form of a text file, (number of ants, rooms and tunnels) and will make ants reach the exit in the least number of turns possible.
For example, the anthill bellow is defined by this :
```
#Number of ants
3
#Rooms
2 5 0
##start
0 1 2
##end
1 9 2
3 5 4
#And here the tunnels
0-2
0-3
2-1
3-1
2-3

#This is the output that the program will send to us, all the movements
L1-3 L2-2
L1-1 L2-1 L3-3
L3-1
```
Using the bonus WebGL visualizer, it looks like this:

![Lem_in WebGL visualizer](https://i.imgur.com/ppjvM95.png)

*(The animation is running here, showing ants runnings trough tunnels, turn by turn)*

## [Camagru](https://github.com/Itokoyamato/42_projects/tree/master/camagru)
Grade: **125**/100

The first project of the web branch. Camagru is a php based website that allows users to register and login to take or upload pictures and then apply stickers to them. Pictures are then put into a gallery where other users can like and comment them.

While I did produce several more features than what requested, my lack of planning made the end-of-project refactoring somewhat difficult, hence the code is far from being well structured.

[Camagru demo](https://itokoyamato.net/42/camagru/)

## [Filler](https://github.com/Itokoyamato/42_projects/tree/master/filler)
Grade: **96**/100

The goal of this project is to code an AI for the game of Filler, for which we have a virtual machine. Two AI battle on a board of set size, each turn they are given a piece (shaped sort of like a tretiminos) and need to place it on the board, with at least one cell overlapping one of his previous pieces, while never overlapping his opponent. The goal is to be the last to put a piece down, and so trying to corner your opponent in being unable to do so.

This project was kind of hurried, as I was missing one project to be able to start the web branch at a set date, but ended up being decently good.

<img src="/screenshots/filler.gif?raw=true" width="500px">

## [Fractol](https://github.com/Itokoyamato/42_projects/tree/master/fractol)
Grade: **113**/100

A fractal visualizer coded in C. Supports [Julia](https://en.wikipedia.org/wiki/Mandelbrot_set), [Mandelbrot](https://en.wikipedia.org/wiki/Mandelbrot_set) and [burningship](https://en.wikipedia.org/wiki/Burning_Ship_fractal). Pushed a little further than asked with a smoothing of colors, as well as a settings menu to allow user to change colors which was reused from the FdF project.

<img src="/screenshots/fractol.gif?raw=true" width="500px">

## [Fil de Fer (Wireframe)](https://github.com/Itokoyamato/42_projects/tree/master/fdf)
Grade: **125**/100

A wireframe representation of given maps, with movement and rotation support, as well as color chart based on height. Included a settings menu that adds background gradient settings and the ability to edit any color of the wireframe.

<img src="/screenshots/fdf.gif?raw=true" width="500px">

## [Fillit](https://github.com/Itokoyamato/42_projects/tree/master/fillit)
Grade: **100**/100 *(Done with **@Technowix**)*

Program is given a set of tetriminos and must place them in the smallest rectangle possible.

# Other utility projects
#### [Piscine PHP](https://github.com/Itokoyamato/42_projects/tree/master/piscine_php)
Grade: **63**/100 - A two week course initiation to PHP. Ended up only doing the first week, as I was focusing on another project during the second week.
#### [Get_next_line](https://github.com/Itokoyamato/42_projects/tree/master/get_next_line)
Grade: **121**/100 - A function that reads the next line of a given file. Supports multiple file descriptors.
#### [libft](https://github.com/Itokoyamato/42_projects/tree/master/libft)
Grade: **115**/100 - A library composed of the recreation of small libC functions used in most projects.