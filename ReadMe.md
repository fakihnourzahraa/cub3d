# cub3D

A 3D graphical representation of a maze from a first-person perspective, inspired by Wolfenstein 3D

# Description

cub3D is a raycasting engine built from scratch in C using the miniLibX graphics library. The project creates a pseudo-3D perspective by casting rays from the player's position and calculating wall distances to render a realistic maze environment.

# Key Features

- **Raycasting Engine**: Full DDA (Digital Differential Analysis) algorithm implementation
- **Textured Walls**: Different textures for each cardinal direction (North, South, East, West)
- **Player Movement**: Smooth WASD movement with arrow key rotation
- **Collision Detection**: Prevents walking through walls
- **Custom Maps**: Parse and validate `.cub` map files
- **RGB Colors**: Customizable floor and ceiling colors
- **Error Handling**: Comprehensive validation and clean error messages

# Technical Highlights

- **No fish-eye effect**: Proper perpendicular distance calculations
- **Optimized rendering**: Targeting 60+ FPS
- **Memory safe**: No leaks, proper cleanup
- **Norm compliant**: Follows 42 coding standards

# Installation

# Prerequisites

- miniLibX library
- X11 development libraries

# Instructions

```bash
make

./cub3D map.cub
```

# Controls

W - Move forward
S - Move backward
A - Move left
D - Move right
← - Rotate left
→ - Rotate right
ESC / x button - Exit program


### Map File Format

.cub file 

NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111

### Map Rules

Valid Maps:
- Must be surrounded by walls
- Contains exactly one player position (N/S/E/W)
- Only uses valid characters: `0`, `1`, `N`, `S`, `E`, `W`, space
- Lines can have different lengths (spaces handled correctly)
- Colors in rgb values

## 🧮 How Raycasting Works

### The Concept

Raycasting creates a 3D perspective from a 2D map by:

1. **Casting rays** from the player's position for each screen column
2. **Traversing the grid** using DDA until hitting a wall
3. **Calculating distance** to determine wall height
4. **Drawing vertical slices** with appropriate textures
5. **Rendering floor and ceiling** with solid colors

# Most Important Formulas

```c
// Ray direction for each screen column
ray_dir_x = player_dir_x + camera_plane_x * camera_x
ray_dir_y = player_dir_y + camera_plane_y * camera_x

// Distance to next grid line
delta_dist_x = fabs(1 / ray_dir_x)
delta_dist_y = fabs(1 / ray_dir_y)

// Perpendicular wall distance (prevents fish-eye effect)
perp_wall_dist = (map_x - player_x + (1 - step_x) / 2) / ray_dir_x

// Wall height calculation
line_height = (int)(screen_height / perp_wall_dist)
```

# Resources

# Parsing

# Execution 
- https://lodev.org/cgtutor/raycasting.html
- https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/

# AI Usage
- Understanding raycasting at a more tecnical level
- Debugging and stress testing
- Helped trace fish eye cause
- Assisted with crashes and overlooked parts of the code
- Basic intialization and cleanup

# Work Division

- nfakih: Raycasting engine, rendering, camera rotation
- miwehbe: Parsing, map validation, memory managment

*Made with lots coffee and debugging at 42 Beirut*