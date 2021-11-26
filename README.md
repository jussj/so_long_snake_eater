# so long snake eater
*so long snake eater* is a small 2D project part of 42 school's curriculum. the goal of the game is to collect snake's favorite food 
with the minimum number of moves before leaving the jungle and kicking some soviet asses.

## installation
* clone the repo
* if not installed yet, clone the minilibx repo at the root (available at [this address](https://github.com/42Paris/minilibx-linux.git))
* make
* choose the map you prefer in the dedicated folder at the root of the repository, create your own (go to map rules for further informations), and pass it as an argument: ```./so_long_snake_eater [path/to/any/map.ber]```

**...or just copy/past the following lines in the command line:**
```
git clone https://github.com/jussj/so_long_snake_eater.git &&
cd so_long_snake_eater &&
git clone https://github.com/42Paris/minilibx-linux.git &&
make &&
./so_long_snake_eater maps/map_1.ber
```
## map rules
* the map must have ```.ber``` extension
* use ```1``` to create walls, the map must be rectangular and closed
* use ```0``` for empty spaces
* use ```C``` for collectibles, at least one otherwise it's no fun :(
* use ```E``` for exit(s), at least one for obvious reasons
* use ```P``` to initialize player's position
