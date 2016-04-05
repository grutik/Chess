#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Main.h"
#include "Board.h"

Board board;
ALLEGRO_BITMAP *field_light = NULL;
ALLEGRO_BITMAP *field_dark = NULL;
ALLEGRO_BITMAP *field_selected = NULL;
ALLEGRO_BITMAP *bmpChessPieces = NULL;

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;


int main(int argc, char **argv)
{
	if (InitializeBasicAllegroObjects() == -1)
		return -1;

	LoadBitmaps();

	if (CreateEvents() == -1)
		return -1;

	board = Board();

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_start_timer(timer);


	RunMainGameLoop();


	al_destroy_bitmap(field_light);
	al_destroy_bitmap(field_dark);
	al_destroy_bitmap(field_selected);
	al_destroy_bitmap(bmpChessPieces);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}


int InitializeBasicAllegroObjects()
{
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	if (!al_install_mouse()) {
		fprintf(stderr, "failed to initialize the mouse!\n");
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}

	al_init_image_addon();

	return 0;
}

void OnFieldSelected(int x, int y)
{
	int fieldX = x / FIELD_SIZE;
	int fieldY = y / FIELD_SIZE;

	Field* currentField = board.fields[fieldX][fieldY];

	if (board.selectedField != nullptr || currentField->fig != nullptr) // Obs³uguj, jeœli jakaœ figura jest ju¿ wybrana LUB podjêto próbê zaznaczenia figury (zabezpiecznie przed zaznaczeniem pustego pola)
		if (board.selectedField == nullptr) { // Gdy ¿adne pole nie by³o wczeœniej wybrane
			if (board.IsWhiteTurn() == currentField->fig->IsWhite()) { // Wybierz figurê, jeœli jej kolor jest zgodny z kolorem bie¿¹cego gracza
				board.selectedField = currentField;
				board.selectedField->Select();
			}
		}
		else {
			if (board.selectedField == currentField) { // Gdy klikniêto w to samo pole drugi raz
				board.selectedField->Unselect();
				board.selectedField = nullptr;
			}
			else
			{
				// Gdy jedno z pól by³o wczeœniej zaznaczone, a teraz klikniêto w inne
				board.TryMoveFigure(currentField);
			}
		}
}

void LoadBitmaps() {
	bmpChessPieces = al_load_bitmap(FIGURE_SPRITES_IMG_PATH);
	al_convert_mask_to_alpha(bmpChessPieces, al_map_rgb(255, 0, 255));

	CreateFieldBitmap(&field_light, 0, 180, 0);
	CreateFieldBitmap(&field_dark, 50, 100, 50);
	CreateFieldBitmap(&field_selected, 0, 0, 200);


	al_set_target_bitmap(al_get_backbuffer(display));
}

int CreateEvents() {
	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(field_light);
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_mouse_event_source());

	return 0;
}

bool CreateFieldBitmap(ALLEGRO_BITMAP** bitmap, int r, int g, int b) {
	*bitmap = al_create_bitmap(FIELD_SIZE, FIELD_SIZE);
	if (!*bitmap) {
		fprintf(stderr, "failed to create bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return false;
	}
	al_set_target_bitmap(*bitmap);
	al_clear_to_color(al_map_rgb(r, g, b));
	return true;
}

void DrawBoard() {
	for (int i = 0; i < board.numberOfFields; i++)
	{
		for (int j = 0; j < board.numberOfFields; j++)
		{
			Field field = *board.fields[i][j];
			ALLEGRO_BITMAP *field_color;

			// Wybór koloru pola
			if (field.selected)
				field_color = field_selected;
			else
				if (field.color == 1)
					field_color = field_light;
				else
					field_color = field_dark;

			int xPosition = FIELD_SIZE*field.x;
			int yPosition = FIELD_SIZE*field.y;

			// Rysowanie pola
			al_draw_bitmap(field_color, xPosition, yPosition, 0);

			// Rysowanie figury znajduj¹cej siê na tym polu
			if (field.fig != nullptr)
			{
				int row = field.fig->IsWhite() ? 0 : 100;
				int col = 0;

				al_draw_bitmap_region(bmpChessPieces, field.fig->GetSpriteOffset() * FIELD_SIZE, row, FIELD_SIZE, FIELD_SIZE, xPosition, yPosition, 0);
			}
		}
	}
}

void RunMainGameLoop() {

	bool redraw = true;

	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) { // Gdy klikniêto
			OnFieldSelected(ev.mouse.x, ev.mouse.y);
			redraw = true;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) { // Przemalowanie planszy
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			DrawBoard();
			al_flip_display();
		}
	}
}
