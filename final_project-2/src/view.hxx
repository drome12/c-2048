#pragma once

#include "model.hxx"

class View
{
public:
    /// View dimensions will use `int` coordinates.
    using Dimensions = ge211::Dims<int>;

    /// View positions will use `int` coordinates.
    using Position = ge211::Posn<int>;

    /// View rectangles will use `int` coordinates.
    using Rectangle = ge211::Rect<int>;

    explicit View(Model const& model);
    void draw(ge211::Sprite_set& set);
    Dimensions initial_window_dimensions() const;
    std::string initial_window_title() const;
    View::Position board_to_screen(Model::Position pos) const;
    Model::Position screen_to_board(View::Position pos) const;
private:
    Model const& model_;
    ge211::Font sans100_{"sans.ttf", 50};

    ge211::Rectangle_sprite const base_tile;
    ge211::Rectangle_sprite const two;
    ge211::Text_sprite const two_text;
    ge211::Rectangle_sprite const four;
    ge211::Text_sprite const four_text;
    ge211::Rectangle_sprite const eight;
    ge211::Text_sprite const eight_text;
    ge211::Rectangle_sprite const sixteen;
    ge211::Text_sprite const sixteen_text;
    ge211::Rectangle_sprite const thirty_two;
    ge211::Text_sprite const thirty_two_text;
    ge211::Rectangle_sprite const sixty_four;
    ge211::Text_sprite const sixty_four_text;
    ge211::Rectangle_sprite const one_twenty_eight;
    ge211::Text_sprite const one_twenty_eight_text;
    ge211::Rectangle_sprite const two_fifty_six;
    ge211::Text_sprite const two_fifty_six_text;
    ge211::Rectangle_sprite const five_twelve;
    ge211::Text_sprite const five_twelve_text;
    ge211::Rectangle_sprite const ten_twenty_four;
    ge211::Text_sprite const ten_twenty_four_text;
    ge211::Rectangle_sprite const twenty_forty_eight;
    ge211::Text_sprite const twenty_forty_eight_text;
    ge211::Rectangle_sprite const forty_ninety_six;
    ge211::Text_sprite const forty_ninety_six_text;
    ge211::Rectangle_sprite const eighty_one_ninety_two;
    ge211::Text_sprite const eighty_one_ninety_two_text;
    ge211::Rectangle_sprite const game_over;
    ge211::Rectangle_sprite const game_not_started;
    ge211::Font home_Screen{"sans.ttf", 20};
    ge211::Text_sprite const game_title;
    ge211::Text_sprite const instructions;
    ge211::Text_sprite const credits;
    ge211::Text_sprite const you_lost;
    ge211::Text_sprite const instructions_game_lost;
    ge211::Text_sprite const you_won;
    ge211::Text_sprite const instructions_game_won;
    ge211::Text_sprite const high_score;
    ge211:: Text_sprite const two_score;
    ge211:: Text_sprite const four_score;
    ge211:: Text_sprite const eight_score;
    ge211:: Text_sprite const sixteen_score;
    ge211:: Text_sprite const thirty_two_score;
    ge211:: Text_sprite const sixty_four_score;
    ge211:: Text_sprite const one_twenty_eight_score;
    ge211:: Text_sprite const two_fifty_six_score;
    ge211:: Text_sprite const five_twelve_score;
    ge211:: Text_sprite const ten_twenty_four_score;
    ge211:: Text_sprite const twenty_forty_eight_score;
    ge211:: Text_sprite const forty_ninety_six_score;
    ge211:: Text_sprite const eighty_one_ninety_two_score;



















};
