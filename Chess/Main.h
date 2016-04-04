const float FPS = 1;
const int SCREEN_W = 800;
const int SCREEN_H = 800;
const int FIELD_SIZE = 100;
const char* FIGURE_SPRITES_IMG_PATH = "Chess_Pieces_Sprite_100.bmp";

int main(int argc, char ** argv);

int InitializeBasicAllegroObjects();

void LoadBitmaps();

int CreateEvents();

bool CreateFieldBitmap(ALLEGRO_BITMAP** bitmap, int r, int g, int b);

void OnFieldSelected(int x, int y);

void DrawBoard();

void RunMainGameLoop();