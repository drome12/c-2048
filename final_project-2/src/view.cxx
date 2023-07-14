#include "view.hxx"
#include <iostream>


static int const grid_size = 128;
static ge211::Color const base_color{255, 255, 255}; // white
static ge211::Color const home_screen_color{0, 0, 0}; // white
static ge211::Color const COLOR_2{204, 192, 179};
static ge211::Color const COLOR_4 = {237, 224, 200};
static ge211::Color const COLOR_8 = {242, 177, 121};
static ge211::Color const COLOR_16 = {245, 149, 99};
static ge211::Color const COLOR_32 = {246, 124, 95};
static ge211::Color const COLOR_64 = {246, 94, 59};
static ge211::Color const COLOR_128 = {237, 207, 114};
static ge211::Color const COLOR_256 = {237, 204, 97};
static ge211::Color const COLOR_512 = {237, 200, 80};
static ge211::Color const COLOR_1024 = {237, 197, 63};
static ge211::Color const COLOR_2048 = {237, 194, 46};
static ge211::Color const COLOR_4096 = {162, 228, 184};
static ge211::Color const COLOR_8192 = {124, 252, 0};
static ge211::Color const lost_color{255, 0, 0}; // red






View::View(Model const& model)
        : model_(model),
          base_tile(ge211::geometry::Dims<int>(grid_size-2, grid_size-2),base_color),
          two(ge211::geometry::Dims<int>(grid_size-2, grid_size-2),COLOR_2),
          two_text("2",sans100_),
          four(ge211::geometry::Dims<int>(grid_size-2, grid_size-2),COLOR_4),
          four_text("4",sans100_),
          eight(ge211::geometry::Dims<int>(grid_size-2, grid_size-2),COLOR_8),
          eight_text("8", sans100_),
          sixteen(ge211::geometry::Dims<int>(grid_size-2, grid_size-2),
                  COLOR_16),
          sixteen_text("16",sans100_),
          thirty_two(ge211::geometry::Dims<int>(grid_size-2, grid_size-2),
                     COLOR_32),
          thirty_two_text("32",sans100_),


          sixty_four(ge211::geometry::Dims<int>(grid_size-2, grid_size-2),
                     COLOR_64),
          sixty_four_text("64",sans100_),
          one_twenty_eight(ge211::geometry::Dims<int>(grid_size-2, grid_size-2),
                           COLOR_128),
          one_twenty_eight_text("128", sans100_),
          two_fifty_six(ge211::geometry::Dims<int>(grid_size-2, grid_size-2),
                        COLOR_256),
          two_fifty_six_text("256",sans100_),
          five_twelve(ge211::geometry::Dims<int>(grid_size-2, grid_size-2),
                      COLOR_512),
          five_twelve_text("512",sans100_),
          ten_twenty_four(ge211::geometry::Dims<int>(grid_size-2, grid_size-2),
                          COLOR_1024),
          ten_twenty_four_text("1024",sans100_),
          twenty_forty_eight(ge211::geometry::Dims<int>(grid_size-2, grid_size-2),
                             COLOR_2048),
          twenty_forty_eight_text("2048",sans100_),
          forty_ninety_six(ge211::geometry::Dims<int>(grid_size-2, grid_size-2),
                           COLOR_4096),
          forty_ninety_six_text("4096", sans100_),
          eighty_one_ninety_two(ge211::geometry::Dims<int>(grid_size-2, grid_size-2),
                                COLOR_8192),
          eighty_one_ninety_two_text("8192",sans100_),
          game_over(ge211::Dims<int>(grid_size*4, grid_size*4+100),
                    lost_color),
          game_not_started(ge211::Dims<int>(grid_size*4, grid_size*4),
                           home_screen_color),
          game_title("2048", sans100_),
          instructions("Welcome to 2048. Press 'r' to start a game.",
                       home_Screen),
          credits("Game designed by Natalie Pizer and David "
                  "Rome",home_Screen),
          you_lost("YOU LOST!", sans100_),
          instructions_game_lost("Press 'r' to restart"
                                 ".", home_Screen),
          you_won("YOU WON!", home_Screen),
          instructions_game_won("Keep going or Press 'r' to start a new game.",
                                home_Screen),
          high_score("High Score:", home_Screen),
          two_score("2", home_Screen),
          four_score("4",home_Screen),
          eight_score("8",home_Screen),
          sixteen_score("16",home_Screen),
          thirty_two_score("32",home_Screen),
          sixty_four_score("64",home_Screen),
          one_twenty_eight_score("128",home_Screen),
          two_fifty_six_score("256",home_Screen),
          five_twelve_score("512", home_Screen),
          ten_twenty_four_score("1024",home_Screen),
          twenty_forty_eight_score("2048",home_Screen),
          forty_ninety_six_score("4096", home_Screen),
          eighty_one_ninety_two_score("8192",home_Screen)









{ }

void
View::draw(ge211::Sprite_set& set)
{
    if(!model_.isGameStarted()){
        set.add_sprite(game_not_started, {0,0},5);
        set.add_sprite(game_title,{grid_size+70,180},6);
        set.add_sprite(instructions,{60,50},6);
        set.add_sprite(credits, {40,380},6);
    }
    if(model_.isGameStarted()&& !model_.game_over()){
        set.add_sprite(high_score,{10,520},1);
        if(model_.score()== 2){
            set.add_sprite(two_score,{120,520},1);

        }
        if(model_.score()== 4){
            set.add_sprite(four_score,{120,520},1);

        }
        if(model_.score()== 8){
            set.add_sprite(eight_score,{120,520},1);

        }
        if(model_.score()== 16){
            set.add_sprite(sixteen_score,{120,520},1);

        }
        if(model_.score()== 32){
            set.add_sprite(thirty_two_score,{120,520},1);

        }
        if(model_.score()== 64){
            set.add_sprite(sixty_four_score,{120,520},1);

        }
        if(model_.score()== 128){
            set.add_sprite(one_twenty_eight_score,{120,520},1);

        }
        if(model_.score()== 256){
            set.add_sprite(two_fifty_six_score,{120,520},1);

        }
        if(model_.score()== 512){
            set.add_sprite(five_twelve_score,{120,520},1);

        }
        if(model_.score()== 1024){
            set.add_sprite(ten_twenty_four_score,{120,520},1);

        }
        if(model_.score()== 2048){
            set.add_sprite(twenty_forty_eight_score,{120,520},1);

        }
        if(model_.score()== 4096){
            set.add_sprite(forty_ninety_six_score,{120,520},1);

        }
        if(model_.score()== 8192){
            set.add_sprite(eighty_one_ninety_two_score,{120,520},1);

        }


    }
    if(model_.game_over()){
        set.add_sprite(game_over,{0,0},6);
        set.add_sprite(you_lost,{120,50},7);
        set.add_sprite(instructions_game_lost,{170,300},7);


    }
    if(model_.game_won()&&!model_.game_over()){
        set.add_sprite(you_won,{10,550},7);
        set.add_sprite(instructions_game_won,{10,580},7);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            auto new_cord = board_to_screen(Position(i, j));
            set.add_sprite(base_tile, new_cord, 0);
            if (model_.get_piece_at_position(i, j) == 2) {
                set.add_sprite(two, new_cord, 1);
                set.add_sprite(two_text, {new_cord.x + 48, new_cord.y+18 }, 2);
            } else if (model_.get_piece_at_position(i, j) == 4) {
                set.add_sprite(four, new_cord, 1);
                set.add_sprite(four_text,
                               {new_cord.x + 48, new_cord.y+18},
                               2);
            } else if (model_.get_piece_at_position(i, j) == 8) {
                set.add_sprite(eight, new_cord, 1);
                set.add_sprite(eight_text,
                               {new_cord.x + 48, new_cord.y+18},
                               2);
            } else if (model_.get_piece_at_position(i, j) == 16) {
                set.add_sprite(sixteen, new_cord, 1);
                set.add_sprite(sixteen_text,
                               {new_cord.x + 30, new_cord.y+18},
                               2);
            }
            else if (model_.get_piece_at_position(i, j) == 32) {
                set.add_sprite(thirty_two, new_cord, 1);
                set.add_sprite(thirty_two_text,
                               {new_cord.x + 30, new_cord.y+18},
                               2);
            }
            else if (model_.get_piece_at_position(i, j) == 64) {
                set.add_sprite(sixty_four, new_cord, 1);
                set.add_sprite(sixty_four_text,
                               {new_cord.x + 30, new_cord.y+18},
                               2);
            }
            else if (model_.get_piece_at_position(i, j) == 128) {
                set.add_sprite(one_twenty_eight, new_cord, 1);
                set.add_sprite(one_twenty_eight_text,
                               {new_cord.x+17, new_cord.y+18},
                               2);
            }
            else if (model_.get_piece_at_position(i, j) == 256) {
                set.add_sprite(two_fifty_six, new_cord, 1);
                set.add_sprite(two_fifty_six_text,
                               {new_cord.x+17, new_cord.y+18},
                               2);
            }
            else if (model_.get_piece_at_position(i, j) == 512) {
                set.add_sprite(five_twelve, new_cord, 1);
                set.add_sprite(five_twelve_text,
                               {new_cord.x+17, new_cord.y+18},
                               2);
            }
            else if (model_.get_piece_at_position(i, j) == 1024) {
                set.add_sprite(ten_twenty_four, new_cord, 1);
                set.add_sprite(ten_twenty_four_text,
                               {new_cord.x+2, new_cord.y+18},
                               2);
            }
            else if (model_.get_piece_at_position(i, j) == 2048) {
                set.add_sprite(twenty_forty_eight, new_cord, 1);
                set.add_sprite(twenty_forty_eight_text,
                               {new_cord.x+2, new_cord.y+18},
                               2);
            }
            else if (model_.get_piece_at_position(i, j) == 4096) {
                set.add_sprite(forty_ninety_six, new_cord, 1);
                set.add_sprite(forty_ninety_six_text,
                               {new_cord.x+2, new_cord.y+18},
                               2);
            }
            else if (model_.get_piece_at_position(i, j) == 8192) {
                set.add_sprite(eighty_one_ninety_two, new_cord, 1);
                set.add_sprite(eighty_one_ninety_two,
                               {new_cord.x+2, new_cord.y+18},
                               2);
            }


        }
    }
}

View::Dimensions
View::initial_window_dimensions() const
{
    // You can change this if you want:
    return Dimensions(grid_size*4, grid_size*4+100);
}

std::string
View::initial_window_title() const
{
    // You can change this if you want:
    return "2048";
}

View::Position
View::board_to_screen(Model::Position pos) const {
    return {pos.x* grid_size,pos.y* grid_size}; // convert grid to pixel size
}

Model::Position
View::screen_to_board(View::Position pos) const {
    return {pos.x/grid_size,pos.y/grid_size}; // convert from pixels to game position
}