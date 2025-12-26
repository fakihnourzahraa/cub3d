map:
.p: the character N, S, etc..
.p_x: x position of player 
.p_y: y position of player
alsoo validate theres only one player

Keyboard controls:
← / → arrows → rotate (look left / right)
W → move forward
S → move backward
A → move left
D → move right
ESC → close the window and exit cleanly
Mouse:
Clicking the red cross (X) must close the program cleanly

The program takes one argument:
A scene file with extension .cub

. Map rules

The map uses ONLY these characters:
0 → empty space
1 → wall
N, S, E, W → player start position + facing direction

Rules:
The map must be closed (surrounded by walls 1)
If not closed → Error
The map is always the last thing in the file
Spaces are allowed inside the map and must be handled correctly
The map must be parsed exactly as written

Before the map, you must define:
Textures
NO → North wall texture
SO → South wall texture
WE → West wall texture
EA → East wall texture

Why 4 textures (NO, SO, WE, EA)
Because a wall looks different depending on the direction you see it from.
Each wall has two sides, but in raycasting we care about which direction the wall is facing

shu hye raycasting:hye technique to createa 3d view from 2d map

The cub3D project is about:
Reading a 2D map from a .cub file
Placing the player inside it
Using raycasting to display a 3D maze
Allowing the player to:
Move
Rotate
See textured walls
Goal:Build your first 3D engine using math + miniLibX

What is the Parsing part responsible for?
Parsing = reading + checking the .cub file
The parsing part must:
🔹 Read the file
Check extension .cub
🔹 Parse textures
NO, SO, WE, EA
Check:
All exist
No duplicates
Valid paths
🔹 Parse colors
F (floor)
C (ceiling)
RGB values in [0–255]
🔹 Parse the map
Allowed characters: 0 1 N S E W and spaces
Exactly one player position
Map is closed by wall
Map is last in the file
Parsing = validation + data preparation


What is the Raycasting part responsible for?
Raycasting is the engine of the game.
It must:
🔹 Handle player view
Player position (x, y)
Player direction (dirX, dirY)
Camera plane
🔹 Cast rays
One ray per screen column
Detect wall hit (DDA algorithm)
Calculate distance
🔹 Choose correct texture
NO / SO / WE / EA
Based on wall direction
🔹 Draw the scene
Ceiling color
Wall texture slices
Floor color
🔹 Handle movement & rotation
W A S D → move
← → → rotate
👉 Raycasting = math + rendering

so cub3D is a project where we parse a 2D map from a file and use raycasting to render a textured 3D view of a maze, handling movement, rotation, and collisions.

.Parsing → Understand and validate the world
.Raycasting → Render and display the world

Parsing = reading the .cub file and converting it into data structures the engine can use.

*parsing:Reads the .cub file(check file extension,read libne by line),Extracts textures(path must be available,NO,SO,WE,EA,must appear once),Extracts colors(floor(f),ceiling(c),rgb[0-255]),Parses the map(Allowed characters only,Exactly one player (N S E W), save(player position,playing direction)),Validates the map(rectangualr(or handled right),closed by wall),Error handling.


Raycasting = using math to draw a 3D view from the parsed map.

*Raycasting:Uses player data(pos,dir,camere plane),Shoots rays(One ray per screen column,Moves through the 2D map,Stops at walls) ,
*Raycasting:Uses player data(pos,dir,camere plane),Shoots rays(One ray per screen column,Moves through the 2D map,Stops at walls) ,Calculates distance(Distance to wall hit),Chooses textures(NO / SO / WE / EA,Based on wall orientation),Draws the screen(Ceiling color,Textured walls,Floor color),Handles movement & rotation

Why must the map be closed?
To prevent rays and player movement from escaping the map, which would cause undefined behavior.

Why only one player?
Raycasting needs a single point of view to calculate rays correctly.

Format: IDENTIFIER<space(s)>./path_to_texture
Examples:
  NO ./textures/north.xpm     ✓
  NO    ./textures/north.xpm  ✓ (multiple spaces OK)
  NO./textures/north.xpm      ✗ (no space = error)
  SO /textures/south.xpm      ✓ (no ./ is OK)

Valid characters: 0, 1, N, S, E, W, space
- '0' = empty space (walkable)
- '1' = wall
- N/S/E/W = player start position + direction
- space = void (treated as wall during flood fill)

IMPORTANT:
- Map preserves spaces (don't trim!)
- Map lines can have different lengths
- Player: exactly ONE N/S/E/W character

NO ./path_to_the_north_texture  ← Line 1: North texture
SO ./path_to_the_south_texture  ← Line 2: South texture
WE ./path_to_the_west_texture   ← Line 3: West texture
EA ./path_to_the_east_texture   ← Line 4: East texture
                                ← Line 5: EMPTY (OK before map)
F 220,100,0                     ← Line 6: Floor color (RGB)
C 225,30,0                      ← Line 7: Ceiling color (RGB)
                                ← Line 8: EMPTY (OK before map)
        1111111111111111111111111  ← Line 9: MAP STARTS HERE
        1000000000110000000000001  ← Leading spaces count!
        1011000001110000000000001
        1001000000000000000001
111111111011000001110000000000001  ← No leading spaces
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111  ← Player at 'N'
11110111 1110101 101111010001    ← SPACE in middle!
11111111 1111111 111111111111    ← SPACE in middle!

****
NO ./path_to_the_north_texture  ← Line 1: North texture
SO ./path_to_the_south_texture  ← Line 2: South texture
WE ./path_to_the_west_texture   ← Line 3: West texture
EA ./path_to_the_east_texture   ← Line 4: East texture
Each texture is an image file (.xpm format) that gets displayed on the walls depending on which direction the wall is facing.
N (North)
         ↑
         |
    1111111111
    1        1
W ← 1   P→   1 → E (East)
    1        1
    1111111111
         |
         ↓
        S (South)
If they face a wall on the NORTH side → show north.xpm texture
If they face a wall on the SOUTH side → show south.xpm texture
If they face a wall on the WEST side → show west.xpm texture
If they face a wall on the EAST side → show east.xpm texture


typedef struct s_map
{
    char    **grid;      // ← YOU fill this (2D array of map)
    int     width;       // ← YOU calculate (longest line length)
    int     height;      // ← YOU calculate (number of lines)
    char    p;           // ← YOU find this (N/S/E/W character)
    int     p_x;         // ← YOU find this (player column)
    int   
	  p_y;         // ← YOU find this (player row)
    char    **ff_grid;   // ← YOU create this (for flood fill)
}   t_map;
typedef struct s_textures
{
    t_img   *north;         // ← NOUR fills (loads image)
    t_img   *south;         // ← NOUR fills
    t_img   *west;          // ← NOUR fills
    t_img   *east;          // ← NOUR fills
    char    *north_path;    // ← YOU fill (path string)
    char    *south_path;    // ← YOU fill
    char    *west_path;     // ← YOU fill
    char    *east_path;     // ← YOU fill
    int     floor_color;    // ← YOU fill (RGB as int)
    int     sky_color;      // ← YOU fill (RGB as int)
}   t_textures;

empty lines between config are OK butt empty lines INSIDE map are NOT OK
Spaces in map are VALID characters
Spaces must be PRESERVED (don't trim!)
Spaces affect map width calculation
Spaces are treated as walls/void in flood fill
