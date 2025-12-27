cd ~
mkdir -p cub3d
cd cub3d

# Copy EVERYTHING from Windows to WSL
cp -r /mnt/c/Users/miraw/Downloads/cub3d/* .

# Fix line endings
sudo apt install dos2unix -y
find . -type f \( -name "*.c" -o -name "*.h" \) -exec dos2unix {} \;
dos2unix Makefile

cd ~/cub3d
rm -rf minilibx-linux
git clone https://github.com/42Paris/minilibx-linux.git

cd ~/cub3d
make

./cub3D test.cub


cd ~/cub3d
cp -r /mnt/c/Users/miraw/Downloads/cub3d/* .
find . -type f \( -name "*.c" -o -name "*.h" \) -exec dos2unix {} \; && dos2unix Makefile
rm -rf minilibx-linux && git clone https://github.com/42Paris/minilibx-linux.git
make
./cub3D test.cub