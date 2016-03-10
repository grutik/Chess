#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Main.h"
#include "Board.h"

const float FPS = 60;
const int SCREEN_W = 800;
const int SCREEN_H = 800;
const int FIELD_SIZE = 100;

Board board;
ALLEGRO_BITMAP *field_light;
ALLEGRO_BITMAP *field_dark;
ALLEGRO_BITMAP *field_selected;
ALLEGRO_BITMAP *bmpChessPieces;

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;

void draw_board() {
	for (int i = 0; i < board.numberOfFields; i++)
	{
		for (int j = 0; j < board.numberOfFields; j++)
		{
			// Simply draw gameboard
			Field field = board.fields[i][j];
			ALLEGRO_BITMAP *field_color;

			// Set field color
			if (field.selected)
				field_color = field_selected;
			else
				if (field.color == 1)
					field_color = field_light;
				else
					field_color = field_dark;

			int xPosition = FIELD_SIZE*field.x;
			int yPosition = FIELD_SIZE*field.y;

			al_draw_bitmap(field_color, xPosition, yPosition, 0);

			// Draw figure
			if (field.currentFigure != nullptr)
			{
				al_draw_bitmap_region(bmpChessPieces, (static_cast<int>(field.currentFigure->type) - 1) * FIELD_SIZE, 0, FIELD_SIZE, FIELD_SIZE, xPosition, yPosition, 0);
			}
		}
	}
}

int main(int argc, char **argv)
{
	board = Board();


	display = NULL;
	event_queue = NULL;
	timer = NULL;

	field_light = NULL;
	field_dark = NULL;
	field_selected = NULL;

	float bouncer_x = SCREEN_W / 2.0 - FIELD_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - FIELD_SIZE / 2.0;
	bool redraw = true;

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
	bmpChessPieces = al_load_bitmap("C:\\Users\\Grutik\\Documents\\Visual Studio 2015\\Projects\\Chess\\Chess\\Chess_Pieces_Sprite.bmp");
	al_convert_mask_to_alpha(bmpChessPieces, al_map_rgb(255, 0, 255));

	CreateFieldBitmap(&field_light, 0, 200, 0);
	CreateFieldBitmap(&field_dark, 50, 50, 50);
	CreateFieldBitmap(&field_selected, 0, 0, 200);

	al_set_target_bitmap(al_get_backbuffer(display));

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

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_start_timer(timer);

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
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			ToggleField(ev.mouse.x, ev.mouse.y);
			redraw = true;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			draw_board();

			al_flip_display();
		}
	}

	al_destroy_bitmap(field_light);
	al_destroy_bitmap(field_dark);
	al_destroy_bitmap(field_selected);
	al_destroy_bitmap(bmpChessPieces);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}

void ToggleField(int x, int y)
{
	int fieldX = x / FIELD_SIZE;
	int fieldY = y / FIELD_SIZE;

	if (board.fields[fieldX][fieldY].selected)
		board.fields[fieldX][fieldY].Unselect();
	else
		board.fields[fieldX][fieldY].Select();
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
