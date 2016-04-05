const float FPS = 1;
const int SCREEN_W = 800;
const int SCREEN_H = 800;
const int FIELD_SIZE = 100;
const char* FIGURE_SPRITES_IMG_PATH = "Chess_Pieces_Sprite_100.bmp";

int main(int argc, char ** argv);

///
/// \brief £aduje bibliotekê allegro, inicjalizuje mysz, timer, ekran
///
int InitializeBasicAllegroObjects();

///
/// \brief Obs³uga zdarzenia zwi¹zanego z wybraniem pola
///
void OnFieldSelected(int x, int y);

///
/// \brief Wczytanie kolorów pól i bitmapy z figurami
///
void LoadBitmaps();

///
/// \brief Inicjalizacja zdarzeñ
///
int CreateEvents();

///
/// \brief Pomocnicza funkcja tworz¹ca bitmapê danego koloru o rozmiarze pola szachownicy
///
bool CreateFieldBitmap(ALLEGRO_BITMAP** bitmap, int r, int g, int b);

///
/// \brief G³ówna funkcja rysuj¹ca.
///
/// Rysuje szachownicê, nastêpnie umieszcza na niej figury
///
void DrawBoard();

///
/// \brief G³ówna pêtla gry, obs³uga zdarzeñ
///
void RunMainGameLoop();