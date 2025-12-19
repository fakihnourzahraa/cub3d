# cub3d

# nour

git rm --cached -r minilibx-linux
What is Raycasting?
Raycasting is a rendering technique that creates a 3D perspective from a 2D map. It's essentially a clever optical illusion - you're not actually creating a 3D world, you're drawing 2D vertical slices that look 3D.
The Core Concept
Imagine you're standing in a maze with a flashlight. You sweep the flashlight from left to right across your field of view. For each direction the light points:

The light travels forward until it hits a wall
You measure how far the light traveled
Closer walls = taller on screen, farther walls = shorter

That's raycasting!
How It Works Step-by-Step
1. The Player
Position: (x, y) coordinates on the 2D map
Direction: A vector showing where you're facing
Camera Plane: A perpendicular vector that defines your field of view
2. Casting Rays
For each vertical column on your screen (e.g., 1920 columns for 1920px width):
Screen column 0   → Ray pointing slightly left
Screen column 960 → Ray pointing straight ahead  
Screen column 1919 → Ray pointing slightly right
Each ray is calculated as:
cray_direction = player_direction + camera_plane * camera_x
// where camera_x ranges from -1 (left edge) to +1 (right edge)
3. DDA Algorithm (Digital Differential Analysis)
This is how each ray finds the wall:
c// Starting from player position
current_map_x = (int)player_x;
current_map_y = (int)player_y;

// Step through the grid
while (not hit wall) {
    // Calculate distance to next grid line in X
    // Calculate distance to next grid line in Y
    
    // Move to whichever is closer
    if (distance_x < distance_y) {
        move in X direction;
        check if map[x][y] == '1' (wall);
    } else {
        move in Y direction;
        check if map[x][y] == '1' (wall);
    }
}
4. Calculate Wall Height
Once you hit a wall:
cperpendicular_distance = distance * cos(angle); // Fix fish-eye
wall_height = screen_height / perpendicular_distance;
Key insight: The farther away = smaller wall height
5. Draw the Wall Slice
cdraw_start = (screen_height - wall_height) / 2;  // Top of wall
draw_end = (screen_height + wall_height) / 2;    // Bottom of wall

// Draw ceiling above the wall (color C)
// Draw the wall (with texture)
// Draw floor below the wall (color F)
```

## Visual Example
```
Top view (2D map):
     
    1 1 1 1 1 1
    1 0 0 0 0 1
    1 0 P → 0 1    P = Player facing right
    1 0 0 0 0 1
    1 1 1 1 1 1

What player sees (3D view):

    Ray 1 (left):   hits wall far away   = short wall slice
    Ray 2 (center): hits wall close      = tall wall slice
    Ray 3 (right):  hits wall far away   = short wall slice

    Result on screen:
    ┌───────────────────────┐
    │ ceiling               │
    │ ▓▓   ▓▓▓▓▓▓▓▓   ▓▓   │  ← Wall heights vary by distance
    │ ▓▓   ▓▓▓▓▓▓▓▓   ▓▓   │
    │ floor                 │
    └───────────────────────┘
Important Concepts for cub3D
1. Field of View (FOV)
The camera plane length determines your FOV. Common values:

Camera plane length ≈ 0.66 gives ~66° FOV (like Wolfenstein 3D)

2. Fish-Eye Correction
You MUST use perpendicular distance, not euclidean distance:
c// WRONG - creates fish-eye effect
distance = euclidean_distance(player, wall_hit);

// CORRECT - straight walls
distance = perpendicular_distance;
3. Which Side Hit?
Track whether you hit:

Vertical wall (North/South texture)
Horizontal wall (East/West texture)

4. Texture Mapping
For each wall slice:
c1. Determine which texture (N/S/E/W)
2. Calculate where on the wall you hit (0.0 to 1.0)
3. Sample the texture at that X position
4. Stretch/shrink texture vertically to match wall height
The Math You Need
Rotation (arrow keys):
cold_dir_x = dir_x;
dir_x = dir_x * cos(rotation_speed) - dir_y * sin(rotation_speed);
dir_y = old_dir_x * sin(rotation_speed) + dir_y * cos(rotation_speed);

// Same for camera plane
Movement (WASD):
c// Forward: move in direction you're facing
new_x = pos_x + dir_x * move_speed;
new_y = pos_y + dir_y * move_speed;

// Strafe: move perpendicular to direction
new_x = pos_x + plane_x * move_speed;
new_y = pos_y + plane_y * move_speed;
Why It's Fast
Raycasting is fast because:

Only checks 2D map - no 3D geometry
One ray per column - minimal calculations
Early termination - stops when it hits a wall
Integer grid - simple collision checks

Common Pitfalls

Fish-eye effect - Use perpendicular distance
Wrong texture side - Track horizontal vs vertical hits
Texture stretching - Calculate texture coordinates carefully
Off-by-one errors - Be careful with grid boundaries
Floating point precision - Small errors compound

Learning Resources
The classic tutorial: Lode's Raycasting Tutorial

Search for "Lode Vandevenne raycasting tutorial"
It explains everything with diagrams and code
Essential reading for this project

Bottom Line
Raycasting is like this:

For each screen column, shoot a ray
Find where it hits a wall (DDA)
Calculate wall distance
Draw a vertical line (taller if closer)
Apply the correct texture

You're essentially drawing the world one vertical slice at a time, left to right across the screen.
Does this clarify things? Would you like me to explain any specific part in more detail (DDA algorithm, texture mapping, rotation math, etc.)?

To calculate each ray’s direction:

rayDir = direction + cameraPlane * cameraX
Where:

direction = player direction vector
cameraX = a value from -1 (left edge) to +1 (right edge)
cameraPlane = left/right direction vector (FOV)
This means:

The leftmost ray = dir - plane
The center ray = dir
The rightmost ray = dir + plane
So the rays sweep across the FOV — and that’s how the screen gets rendered column by column.

