# lem-in
Ants farm, where every ant must be able to find way to 'exit' room if it possible.

how to:
```
make
./lem-in < map_file.map

At the beginning from standart output the program recieves information about number of ants had to be leaded through path, room names (can be numbers, words, characters etc.) with coordinates and links. Here is an example:
5
just_room_name 0 2
##start
0 2 0
##end
end_room 2 6
2 4 2
3 4 4
0-1
0-2
2-3
3-4
4-1
Comments "##start" and "##end" are provided to show the start and end room information. We don't care about any other comments.
```
