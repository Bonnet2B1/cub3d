# My First 3D Game : Cub3D

## How to install Cub3D

To play this game, copy the following commands in your terminal.

	cd ~    # go to your home directory
	git clone https://github.com/Bonnet2B1/Cub3D.git    # clone the repository
	cd Cub3D    # go to the game folder
	git clone https://github.com/codam-coding-college/MLX42.git    # install graphics library
	cd MLX42    # go to the graphics library folder
	cmake -B build    # build here refers to the output folder.
	cmake --build build -j4    # or do make -C build -j4
	cd ~    # go back to your home directory

## How to play Cub3D

To play this game, copy the following commands in your terminal.

	cd ~/Cub3D    # go to the game folder
	make    # compile the game
	./Cub3D maps/maze.cub    # play the game with the map (here maze.cub)

### Controls

Use 'W', 'A', 'S' and 'D' keys to move the player.
Use the left and right arrows to move the camera.
If you press the M key, you can use your mouse/trackpad to move the camera.
Press 'E' while looking at a special wall to discover features about the game.


## How to uninstall Cub3D (or if something goes wrong)

To uninstall this game, copy the following commands in your terminal.

	cd ~    # go to your home directory
	rm -rf Cub3D    # remove the game folder
