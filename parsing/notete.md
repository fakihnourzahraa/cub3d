texture:
Cub3D uses 4 textures because each wall has a direction (N, S, E, W), and raycasting needs to know which wall face the player sees to draw the correct image.
ana hon bas he eml detect lal line msln start with no or whatever ,then extract the path(extract path),validafe path(path exist,file readble),store path in his corect locat
In parse_textures, we identify texture lines (NO, SO, WE, EA), extract and validate the texture file paths, ensure no duplicates, and store the paths for later image loading.

color:
we read and store the floor and ceiling colors from the .cub file
Cub3D draws:
Walls → textures (NO, SO, WE, EA)
Floor → flat color
Ceiling (sky) → flat color
Without colors:
floor & ceiling would be black or random
scene looks broken
So:parse_colors gives your world a floor and sky
ok so:we detect the color line(f || c),extract the rgb color(f 220,110,0)->(220,110,0)
we split it into 3 part,we convert it to integ,
validate the value(exacl 3 val,betrween 0 and 255, no dup)
Red → << 16 && Green → << 8 &&Blue → no shift
MLX accepts ONE number for a color,not 3 (r,g,b)
So we must place the values inside this box.
<< = “MOVE LEFT TO MAKE SPACE”

!!..Walls use textures because raycasting hits vertical surfaces and needs detailed images, while floor and ceiling are flat planes not hit by rays, so they are drawn as simple colors for efficiency.