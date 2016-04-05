const float FPS = 1;
const int SCREEN_W = 800;
const int SCREEN_H = 800;
const int FIELD_SIZE = 100;
const char* FIGURE_SPRITES_IMG_PATH = "Chess_Pieces_Sprite_100.bmp";

int main(int argc, char ** argv);

///
/// \brief �aduje bibliotek� allegro, inicjalizuje mysz, timer, ekran
///
int InitializeBasicAllegroObjects();

///
/// \brief Obs�uga zdarzenia zwi�zanego z wybraniem pola
///
void OnFieldSelected(int x, int y);

///
/// \brief Wczytanie kolor�w p�l i bitmapy z figurami
///
void LoadBitmaps();

///
/// \brief Inicjalizacja zdarze�
///
int CreateEvents();

///
/// \brief Pomocnicza funkcja tworz�ca bitmap� danego koloru o rozmiarze pola szachownicy
///
bool CreateFieldBitmap(ALLEGRO_BITMAP** bitmap, int r, int g, int b);

///
/// \brief G��wna funkcja rysuj�ca.
///
/// Rysuje szachownic�, nast�pnie umieszcza na niej figury
///
void DrawBoard();

///
/// \brief G��wna p�tla gry, obs�uga zdarze�
///
void RunMainGameLoop();