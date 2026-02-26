# LeCub3D

*This project has been created as part of the 42 curriculum by strieste, cbezenco*

# Description

This project is inspired by Wolf3D, a world-known FPS game. The objective was to create a dynamic view within a maze, in which you must find your way. To achieve this result, the ray-casting technique was used.

# Instructions

- To compile this project, enter the command 'make' in order to create the program.
- To execute the program, enter './cub3d' + a file with the .cub extension, containing the map.
- The map has to respect some rules :
    - It must only be composed of only 6 possible characters : 0 for an empty space, 1 for a wall, and N, S, E, or W for the player's starting position and spawning orientation.
    - The map must be closed/surrounded by walls, if not the program must return
an error.
    - Before the map content, 6 elements has to be specified : the north, south, west, and east texture's paths + the RGB colors of the floor and ceiling. 


# Resources

- Raycasting : https://lodev.org/cgtutor/raycasting.html
- Minilibx : https://harm-smits.github.io/42docs/


valgrind --track-fds=yes;
