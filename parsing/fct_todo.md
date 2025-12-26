Functions you need:

parse_cub_file(char *filename, t_game *game)

Main entry point called from main.c
Orchestrates the entire parsing process
Calls all other parsing functions in order
Returns success/failure


read_entire_file(char *filename)

Opens the .cub file
Reads ALL lines using get_next_line()
Stores them in a char ** array (array of strings)
Returns this array (or NULL on error)


validate_file_extension(char *filename)

Check if filename ends with .cub
Return 1 if valid, 0 if not



The flow:
parse_cub_file():
1. Validate extension (.cub)
2. Read entire file into char **lines
3. Call parse_textures(lines, game)
4. Call parse_colors(lines, game)
5. Call parse_map(lines, game)
6. Free the lines array
7. Return success

parse_utils.c - String Utilities
What it does:
Helper functions for string manipulation and validation.
Functions you need:

skip_whitespace(char *str)

Skip spaces and tabs at the beginning of a string
Return pointer to first non-whitespace character


is_whitespace(char c)

Check if character is space or tab
Return 1 if yes, 0 if no


is_empty_line(char *line)

Check if line is empty or only whitespace
Return 1 if empty, 0 if has content


starts_with(char *str, char *prefix)

Check if string starts with a prefix
Example: starts_with("NO ./path", "NO") → returns 1
Useful for identifying texture/color lines


extract_path(char *line)

Extract the path from a line like "NO ./textures/north.xpm"
Skip identifier (NO, SO, etc.)
Skip whitespace
Return the path part as new allocated string


ft_isdigit(char c)

Check if character is a digit
Return 1 if yes, 0 if no


ft_atoi_safe(char *str, int *result)

Convert string to integer safely
Check for overflow
Return 1 on success, 0 on error
Store result in *result


count_lines(char **lines)

Count how many lines in a char ** array
Return the count


free_string_array(char **arr)

Free a char ** array properly
Free each string, then the array itself




error_handling.c - Error Messages & Exit
What it does:
Centralized error handling - display errors and clean up.
Functions you need:

error_exit(char *message, t_game *game)

Print "Error\n" to stderr
Print the custom error message to stderr
Free all allocated memory in game
Exit the program with exit code 1


print_error(char *message)

Print "Error\n" to stderr
Print the custom message to stderr
Return 0 (so you can use it like: return print_error("msg");)


validate_file_access(char *filepath)

Check if file exists and is readable
Use access() or try to open() it
Return 1 if valid, 0 if not


cleanup_parsing(t_game *game)

Free map grid if allocated
Free texture paths if allocated
Free any temporary parsing data
Don't exit, just clean up



Error messages you'll need:

"Invalid file extension (must be .cub)"
"Failed to open file"
"Invalid texture path"
"Invalid color format"
"Invalid map character"
"Map is not closed by walls"
"Missing player spawn point"
"Multiple player spawn points"
"Missing texture configuration (NO/SO/WE/EA)"
"Missing color configuration (F/C)"
"Invalid RGB values (must be 0-255)"

✅✅✅
✅ validate_file_extension()     
✅read_entire_file()            
✅parse_cub_file() - SKELETON  
✅skip_whitespace()             
✅is_empty_line()                
✅count_lines()                  
✅free_string_array()      
✅print_error()                
✅validate_file_access()         
tarrarararrarrararrarara