#ifndef _GAMECONSTANTS_H
#define _GAMECONSTANTS_H

using uint = unsigned int;

const static inline uint CELL_SIZE = 32;
const static inline uint ALONG_WIDTH = 10;
const static inline uint ALONG_HEIGHT = 20;
const static inline uint WINDOW_WIDTH = CELL_SIZE*ALONG_WIDTH;
const static inline uint WINDOW_HEIGHT = CELL_SIZE*ALONG_HEIGHT;
const static inline uint COLOR_SHIFT = 50;
const static inline uint BLOCKS_AMOUNT = 4; //Do not set above than 6
const static inline uint SCOREBOARD_WIDTH = WINDOW_WIDTH/3;
const static inline uint SCOREBOARD_HEIGHT = WINDOW_HEIGHT;
const static inline char* FONT_PATH  = "resource/game_over.ttf";
const static inline uint DEFAULT_TEXT_SIZE = 24;
const static inline float DEFAULT_TICK_DELAY = 0.5;

#endif